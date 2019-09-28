#Modules Import
import os
import platform
import sys

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
  print(sys.argv[0] + " [Generate] [Project name]")
  print(sys.argv[0] + " [Build]")
  print(sys.argv[0] + " [ReBuild]")
  print(sys.argv[0] + " [Clean]")
  print(sys.argv[0] + " [Flash]")
  print(sys.argv[0] + " Generate   Stm32L475_2")
  print(sys.argv[0] + " Build")
  print(sys.argv[0] + " Rebuild")
  print(sys.argv[0] + " Clean")
  print(sys.argv[0] + " Flash")

def generateFiles():
  if len(sys.argv) < 3 :
    usage()
  else: 
    PROJECT = str(sys.argv[2])
    if PLATFORM == "Windows" :
      os.system ('IF NOT EXIST build ( MKDIR build ) ')
      os.system ('cd build && ' + CMAKE + ' -G "MinGW Makefiles" -D"CMAKE_TOOLCHAIN_FILE=windows.cmake" -DPROJECT=' + PROJECT + ' ../cmake')
      os.system ('cd .. ')
    else :
      os.system ('mkdir -p build')
      os.system ('cd build && ' + CMAKE + ' -D"CMAKE_TOOLCHAIN_FILE=linux.cmake" -DPROJECT=' + PROJECT + ' ../cmake' )

def getTargetInfo():
  targetInfo       = open('build/target.info','r')
  return targetInfo

def getTargetProject():
  targetProject    = getTargetInfo().readlines()[0].strip()
  return targetProject

def build():
  makeTarget = getTargetProject() + ".elf"
  os.system ('cd build && ' + MAKE + ' ' + makeTarget + ' -j' )

def rebuild():
  os.system ('cd build && ' + MAKE + ' clean' )
  build()

def clean():
  if PLATFORM == "Windows" :
    os.system ('RMDIR /Q/S build')
  else:
    os.system ('rm -r build')
  print('build directory cleaned')

def getTargetDebuger():
  targetDebuger    = getTargetInfo().readlines()[1].strip()
  return targetDebuger

def flash():
  targetDebuger = getTargetDebuger()
  if targetDebuger == "STLINK":
    targetBinary  = "./build/bin/" + getTargetProject() + "/" + getTargetProject() + ".hex" 
    if PLATFORM == "Windows" :
      os.system('ST-LINK_CLI -c SWD -p ' + targetBinary + ' -Rst -Run')
    else :
      os.system('st-flash --format ihex write ' + targetBinary)
  else:
    print('Debuger not supported')

def optionParser(option):
  switcher = {
    "Generate" : generateFiles,
    "Build"    : build,
    "Rebuild"  : rebuild,
    "Clean"    : clean,
    "Flash"    : flash
  }
  func = switcher.get(option, usage)
  func()


#Main Routine
if len(sys.argv) > 1 :
  RUN_OPTION = sys.argv[1]
  optionParser(RUN_OPTION)
else :
  usage()


