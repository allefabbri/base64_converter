#include <iostream>
#include <cstdlib>

#include "b64_lib.hpp"

int main(int argc, char** argv){
	if( argc != 3 ){
		std::cout << "---- BASE64 ENC/DEC ----" << std::endl;
		std::cout << "Usage:    " << argv[0] << " -[e/d] \"message to Encrypt/Decrypt\" (include double quotes)" << std::endl << std::endl;
		std::cout << "Running DEMO mode." << std::endl;
	    std::string message = "I love ENCRYPTION!", encoded;
    	std::cout << "Message         : " << message << std::endl;
    	std::cout << "Message encoded : " << (encoded = Base64_encode(message)) << std::endl;
		std::cout << "Message decoded : " << Base64_decode(encoded) << std::endl << std::endl;
		exit(1);
	}

	if( std::string(argv[1]) == "-e" ){
		std::string message(argv[2]);
		std::cout << Base64_encode(message) << std::endl;
	}

	if( std::string(argv[1]) == "-d" ){
		std::string message(argv[2]);
		std::cout << Base64_decode(message) << std::endl;
	}

	return 0;
}
