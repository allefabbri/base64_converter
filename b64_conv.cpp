// Copyright 2015, Alessandro Fabbri
// for any question, please mail rommacc@yahoo.it

/************************************************************************
* This program is free software: you can redistribute it and/or modify  *
* it under the terms of the GNU General Public License as published by  *
* the Free Software Foundation, either version 3 of the License, or     *
* (at your option) any later version.                                   *
*                                                                       *
* This program is distributed in the hope that it will be useful,       *
* but WITHOUT ANY WARRANTY; without even the implied warranty of        *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
* GNU General Public License for more details.                          *
*                                                                       *
* You should have received a copy of the GNU General Public License     *
* along with this program.  If not, see <http://www.gnu.org/licenses/>. *
************************************************************************/

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
