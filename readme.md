# MCUPlatform

## Prerequisites
### Windows
1. CMake  : https://cmake.org/download/
2. Mingw  : https://sourceforge.net/projects/mingw-w64/
3. Python : https://www.python.org/downloads/windows/
4. STM32 ST-LINK utility: https://www.st.com/en/development-tools/stsw-link004.html
5. OpenOCD: https://gnutoolchains.com/arm-eabi/openocd/

### Linux
1. CMake:  sudo apt-get install cmake
2. Build-Essentials: sudo apt-get install build-essential
3. Python: sudo apt-get install python
4. Stlink: https://github.com/texane/stlink
5. OpenOCD:sudo apt-get install openocd 


## Build Project 
```
 python run.py Build [Project Name]
```
## Rebuild Project
```
python ./run.py Rebuild
```
## Clean Project
```
python ./run.py Clean
```
## Flash software in target
```
python ./run.py Flash
```

## Credits
Jenifer Blanco jenifer_blanco@hotmail.com

Gabriel Dobato dobatog@gmail.com

Amine Chalandi


