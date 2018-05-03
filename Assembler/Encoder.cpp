#include "Encoder.h"

Encoder::Encoder() {}

Encoder::~Encoder() {}

string Encoder::numericAddress(string x) {
	string address = "";
	
	address = numericAddress(stoi(x));

	return address;
}

string Encoder::numericAddress(int x) {
	string address = "";

	int number = x;

	while (number > 0) {
		string bin = to_string(number % 2);
		address = bin + address;
		number = number / 2;
	}

	if (address.length() < 16) {
		int old = address.length();
		for (int i = 0; i < (int)(16 - old - 1); i++) {
			address = "0" + address;
		}
	}

	return address;
}

string Encoder::dest(string x) {
	string str;

	if (x == "null") {
		str = "000";
	} else if (x == "M") {
		str = "001";
	} else if (x == "D") {
		str = "010";
	} else if (x == "MD") {
		str = "011";
	} else if (x == "A") {
		str = "100";
	} else if (x == "AM") {
		str = "101";
	} else if (x == "AD") {
		str = "110";
	} else if (x == "AMD") {
		str = "111";
	}

	return str;
}

string Encoder::comp(string x) {
	string str;

	if (x == "0") {
		str = "0101010";
	} else if (x == "1") {
		str = "0111111";
	} else if (x == "-1") {
		str = "0111010";
	} else if (x == "D") {
		str = "0001100";
	} else if (x == "A") {
		str = "0110000";
	} else if (x == "!D") {
		str = "0001101";
	} else if (x == "!A") {
		str = "0110001";
	} else if (x == "-D") {
		str = "0001111";
	} else if (x == "-A") {
		str = "0110011";
	} else if (x == "D+1" || x == "1+D") {
		str = "0011111";
	} else if (x == "A+1" || x == "1+A") {
		str = "0110111";
	} else if (x == "D-1") {
		str = "0001110";
	} else if (x == "A-1") {
		str = "0110010";
	} else if (x == "D+A" || x == "A+D") {
		str = "0000010";
	} else if (x == "D-A") {
		str = "0010011";
	} else if (x == "A-D") {
		str = "0000111";
	} else if (x == "D&A" || x == "A&D") {
		str = "0000000";
	} else if (x == "D|A" || x == "A|D") {
		str = "0010101";
	} else if (x == "M") {
		str = "1110000";
	} else if (x == "!M") {
		str = "1110001";
	} else if (x == "-M") {
		str = "1110011";
	} else if (x == "M+1" || x == "1+M") {
		str = "1110111";
	} else if (x == "M-1") {
		str = "1110010";
	} else if (x == "D+M" || x == "M+D") {
		str = "1000010";
	} else if (x == "D-M") {
		str = "1010011";
	} else if (x == "M-D") {
		str = "1000111";
	} else if (x == "D&M" || x == "M&D") {
		str = "1000000";
	} else if (x == "D|M" || x == "M|D") {
		str = "1010101";
	}

	return str;
}

string Encoder::jump(string x) {
	string str;

	if (x == "null") {
		str = "000";
	} else if (x == "JGT") {
		str = "001";
	} else if (x == "JEQ") {
		str = "010";
	} else if (x == "JGE") {
		str = "011";
	} else if (x == "JLT") {
		str = "100";
	} else if (x == "JNE") {
		str = "101";
	} else if (x == "JLE") {
		str = "110";
	} else if (x == "JMP") {
		str = "111";
	}

	return str;
}