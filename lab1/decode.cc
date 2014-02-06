#include <fstream> // file streams
#include <iostream>
#include <sstream>
#include <string>
#include "decode.h"

/* For any character c, decode(encode(c)) == c */
unsigned char Decode::decode(unsigned char c){
	return c-1;
}

int main(int argc, char* argv[]) {
	if(argc != 2){
		std::cerr << "Wrong syntax. " << std::endl;
		return 1;
	}
	std::ifstream input(argv[1]);
	if (!input) { // "if the file couldn’t be opened"
		std::cerr << "Could not open: " << argv[1] << std::endl;
		//exit(1);
		return 1;
	}
	std::ofstream output;
	output.open("file.dec");

	char c = input.get();;
	while(input.good()){
		output << Decode::decode(c);
		c = input.get();
	}
	input.close();
}