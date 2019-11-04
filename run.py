#!/usr/bin/python3
#Modules Import
import os
import platform
import sys

#Variables
ERROR = -1
PROJECT_LIST = ["Stm32F429_FreeRTOS", "Stm32L475_FreeRTOS","Stm32L475_IoTOS","Stm32L475_Osek"]

#Check platform
PLATFORM   =  platform.system()
if PLATFORM == "Windows":
  ECHO        = "@echo"
  CMAKE       = "cmake"
  CMAKEFORMAT = "MinGW"
  MAKE        = "mingw32-make"
elif PLATFORM == "Linux":
  ECHO        = "echo"
  CMAKE       = "cmake"
  CMAKEFORMAT = "Unix"
  MAKE        = "make"
else:
  print("Host platform not supported")
  exit(1)

#Functions defintions
def usage():
  print('Invalid Option, usage: ') 
  print(sys.argv[0] + " [Build]   [Project]")
  print(sys.argv[0] + " [ReBuild]")
  print(sys.argv[0] + " [Clean]")
  print(sys.argv[0] + " [Flash]")
  print(sys.argv[0] + " [UTest]   [Unit]")
  print("Project List: ")
  print(*PROJECT_LIST)

def generateFiles(target):
  project = str(target)
  if PLATFORM == "Windows" :
    os.system ('IF NOT EXIST build ( MKDIR build ) ')
    os.system ('cd build && ' + CMAKE + ' -G "MinGW Makefiles" -D"CMAKE_TOOLCHAIN_FILE=windows.cmake" -DPROJECT=' + project + ' ../cmake/target')
  else :
    os.system ('mkdir -p build')
    os.system ('cd build && ' + CMAKE + ' -D"CMAKE_TOOLCHAIN_FILE=linux.cmake" -DPROJECT=' + project + ' ../cmake/target' )

def getTargetInfo():
  if(os.path.exists('build/target.info')):
    targetInfo       = open('build/target.info','r')
    return targetInfo
  else:
    return ERROR

def build():
  if (len(sys.argv) < 3):
    usage()
  else: 
    target = sys.argv[2]
    generateFiles(target)
    makeTarget = target + ".elf"
    os.system ('cd build && ' + MAKE + ' ' + makeTarget + ' -j' )

def rebuild():
  if not (getTargetInfo() == ERROR):
    target = getTargetInfo().readlines()[0].strip()
    generateFiles(target)
    makeTarget = target + ".elf"
    os.system ('cd build && ' + MAKE + ' clean' )
    os.system ('cd build && ' + MAKE + ' ' + makeTarget + ' -j' )
  else:
    print("no built target found, please build target before")

def clean():
  if PLATFORM == "Windows" :
    os.system ('RMDIR /Q/S build')
  else:
    os.system ('rm -rf build')
  print('build directory cleaned')

def utest():
  if (len(sys.argv) < 3):
    usage()
  else: 
    unit = sys.argv[2]
    if PLATFORM == "Windows" :
      os.system ('IF NOT EXIST build ( MKDIR build/utest ) ')
      os.system ('cd build/utest && ' + CMAKE + ' -G "MinGW Makefiles"  ../../cmake/utest')
    else :
      os.system ('mkdir -p build/utest')
      os.system ('cd build/utest && ' + CMAKE + ' ../../cmake/utest' )  
    os.system ('cd build/utest' + CMAKE + ' ../../cmake/utest' )  
    os.system ('cd build/utest && ' + MAKE + ' ' + unit + ' -j' + '&&' + './' + unit )

def flash():
  if not (getTargetInfo() == ERROR):
    targetDebuger = getTargetInfo().readlines()[1].strip()
    if targetDebuger == "STLINK":
      target        = getTargetInfo().readlines()[0].strip()
      targetBinary  = "./build/bin/" + target + "/" + target + ".hex" 
      if PLATFORM == "Windows" :
        os.system('ST-LINK_CLI -c SWD -p ' + targetBinary + ' -Rst -Run')
      else :
        os.system('st-flash --format ihex write ' + targetBinary)
    else:
      print('Debuger not supported')
  else:
    print("no built target found, please build target before")

def optionParser(option):
  switcher = {
    "Build"    : build,
    "Rebuild"  : rebuild,
    "Clean"    : clean,
    "Flash"    : flash,
    "UTest"    : utest 
  }
  func = switcher.get(option, usage)
  func()


#Main Routine
if len(sys.argv) > 1 :
  runOption = sys.argv[1]
  optionParser(runOption)
else :
  usage()


