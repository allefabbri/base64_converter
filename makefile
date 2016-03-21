all: b64_converter basic_converter

b64_converter: b64_conv.cpp b64_lib.hpp
	g++ -std=c++11 -o b64.exe b64_conv.cpp

basic_converter: basic.cpp
	g++ -std=c++11 -o basic.exe basic.cpp

clean:
	rm -rf *.exe
