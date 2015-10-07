#include <iostream>
#include <bitset>
#include <vector>
#include <cstdlib>

char Base64_i2c(int index){
    if ( index > -1 && index < 26 )
        return 'A'+index;
    else if ( index > 25 && index < 52 )
        return 'a'+(index-26);
    else if ( index > 51 && index < 62 )
        return '0'+(index-52);
    else if ( index == 62)
        return '+';
    else if ( index == 63)
        return '/';
    else
        return '\0';
}

int Base64_c2i(char c){
    if ( c >= 'A' && c <= 'Z' )
        return c-'A';
    else if ( c >= 'a' && c <= 'z' )
        return c-'a'+26;
    else if ( c >= '0' && c <= '9' )
        return c-'0'+52;
    else if ( c == '+' )
        return 62;
    else if ( c == '/' )
        return 63;
    else
        return '\0';
}

void test_Base64_i2c(){
    std::cout << "index " <<  0 << "   char " << Base64_i2c(0) << std::endl;
    std::cout << "index " << 25 << "  char " << Base64_i2c(25) << std::endl;
    std::cout << "index " << 26 << "  char " << Base64_i2c(26) << std::endl;
    std::cout << "index " << 51 << "  char " << Base64_i2c(51) << std::endl;
    std::cout << "index " << 52 << "  char " << Base64_i2c(52) << std::endl;
    std::cout << "index " << 61 << "  char " << Base64_i2c(61) << std::endl;
    std::cout << "index " << 62 << "  char " << Base64_i2c(62) << std::endl;
    std::cout << "index " << 63 << "  char " << Base64_i2c(63) << std::endl;
}

void test_Base64_c2i(){
    std::cout << "char " << 'A' << "  index " << Base64_c2i('A') << std::endl;
    std::cout << "char " << 'Z' << "  index " << Base64_c2i('Z') << std::endl;
    std::cout << "char " << 'a' << "  index " << Base64_c2i('a') << std::endl;
    std::cout << "char " << 'z' << "  index " << Base64_c2i('z') << std::endl;
    std::cout << "char " << '0' << "  index " << Base64_c2i('0') << std::endl;
    std::cout << "char " << '9' << "  index " << Base64_c2i('9') << std::endl;
    std::cout << "char " << '+' << "  index " << Base64_c2i('+') << std::endl;
    std::cout << "char " << '/' << "  index " << Base64_c2i('/') << std::endl;
}

std::string Base64_encode_block(std::string block_dec){
    if( block_dec.size() != 3 ) {
        std::cout << "ERROR: Block size is " << block_dec.size() << ", it must be 3!!!" << std::endl;
        return "";
    }
    unsigned char d1=block_dec[0], 
                  d2=block_dec[1],
                  d3=block_dec[2],
                  e1,e2,e3,e4;

    e1 = d1 >> 2;
    e2 = (unsigned char) (d1 << 6) >> 2 | (d2 >> 4);
    e3 = (unsigned char) (d2 << 4) >> 2 | d3 >> 6;
    e4 = (unsigned char) (d3 << 2) >> 2;

    std::string block_enc("1234");
    block_enc[0] = Base64_i2c(e1);
    block_enc[1] = Base64_i2c(e2);
    block_enc[2] = Base64_i2c(e3);
    block_enc[3] = Base64_i2c(e4);

    return block_enc;
}

std::string Base64_encode(std::string message){
    if( message.size()%3 != 0 ) {
        std::cout << "WARNING: Message size is " << message.size() << ", it must be a multiple of 3, trailing with spaces!" << std::endl;
        while( message.size()%3 != 0 ) message += " ";
    }
    int chunk = message.size()/3;
    std::vector<std::string> chunks;
    std::string message_enc;
    for(int i=0; i<chunk; i++){
        chunks.push_back(message.substr(3*i,3));
        message_enc += Base64_encode_block(chunks[i]);
    }
    return message_enc;
}

std::string Base64_decode_block(std::string block_enc){
    if( block_enc.size() != 4 ) {
        std::cout << "ERROR: Block size is " << block_enc.size() << ", it must be 4!!!" << std::endl;
        return "";
    }
    unsigned char e1=block_enc[0], 
                  e2=block_enc[1],
                  e3=block_enc[2],
                  e4=block_enc[3],
                  d1,d2,d3;

    d1 = Base64_c2i(e1) << 2 | Base64_c2i(e2) >> 4;
    d2 = Base64_c2i(e2) << 4 | Base64_c2i(e3) >> 2;
    d3 = Base64_c2i(e3) << 6 | Base64_c2i(e4);

    std::string block_dec("123");
    block_dec[0] = d1;
    block_dec[1] = d2;
    block_dec[2] = d3;

    return block_dec;
}

std::string Base64_decode(std::string message){
    if( message.size()%4 != 0) {
        std::cout << "ERROR: Message size is " << message.size() << ", it must be a multiple of 4. Quitting..." << std::endl;
        exit(111);
    }
    int chunk = message.size()/4;
    std::vector<std::string> chunks;
    std::string message_dec;
    for(int i=0; i<chunk; i++){
        chunks.push_back(message.substr(4*i,4));
        message_dec += Base64_decode_block(chunks[i]);
//      std::cout << chunks[i] << std::endl;
    }
    return message_dec;
}
