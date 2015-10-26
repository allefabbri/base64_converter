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
#include <iomanip>
#include <bitset>

#include "b64_lib.hpp"

void print_c(std::string title, unsigned char c){
	std::bitset<8> bit_c(c);
	std::cout << title << "   " << (int) c << "\t" << c << "\t" << bit_c << std::endl;
}

void print_c_enc(std::string title, unsigned char c){
	std::bitset<8> bit_c(c);
	std::cout << title << "   " << (int) c << "\t" << Base64_i2c(c) << "\t" << bit_c << std::endl;
}

void print_c_dec(std::string title, unsigned char c){
	std::bitset<8> bit_c(Base64_c2i(c));
	std::cout << title << "   " << c << "\t" << Base64_c2i(c) << "\t" << bit_c << std::endl;
}

int main(){
	std::cout << "---- BASE64 encoding ----" << std::endl;
	test_Base64_i2c();

	unsigned char d1='A', d2='B', d3='C';

	std::cout << std::endl;

	print_c("d1", d1);
	print_c("d2", d2);
	print_c("d3", d3);

	std::cout << std::endl;

	unsigned char e1 = d1 >> 2;
	unsigned char e2 = (unsigned char) (d1 << 6) >> 2 | (d2 >> 4);
	unsigned char e3 = (unsigned char) (d2 << 4) >> 2 | d3 >> 6;
	unsigned char e4 = (unsigned char) (d3 << 2) >> 2;
	print_c_enc("e1", e1);
	print_c_enc("e2", e2);
	print_c_enc("e3", e3);
	print_c_enc("e4", e4);

	std::cout << std::endl << "---- BASE64 decoding ----" << std::endl;
	test_Base64_c2i();

	unsigned char E1='Q', E2='U', E3='J', E4='D';

	std::cout << std::endl;

	print_c_dec("E1", E1);
	print_c_dec("E2", E2);
	print_c_dec("E3", E3);
	print_c_dec("E4", E4);

	unsigned char D1 = Base64_c2i(E1) << 2 | Base64_c2i(E2) >> 4;
	unsigned char D2 = Base64_c2i(E2) << 4 | Base64_c2i(E3) >> 2;
	unsigned char D3 = Base64_c2i(E3) << 6 | Base64_c2i(E4);

	std::cout << std::endl;

	print_c("D1", D1);
	print_c("D2", D2);
	print_c("D3", D3);

	return 0;
}