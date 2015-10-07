# base64_converter

This simple **C++** library implements the binary-to-text encoding known as *Base64*.

#### Building
Compile and run the source ``b64_conv.cpp`` with your favorite C++ compiler  (mine is ``g++``)
```
g++ -o conv.exe b64_conv.cpp
```
Tested on **Ubuntu 14.04.3 LTS** under *GCC 4.8.4* and on **Windows 10** under *cl 19.00*.

#### Usage
Main usage is
```
./conv.exe -[e/d] "message to Encrypt/Decrypt" (include double quotes)
```
but there is also a Demo mode, accessible by running the program without arguments.

#### Examples
```
# ./conv.exe -e "ABC"
# QUJD
# ./conv.exe -d "QUJD"
# ABC
```
