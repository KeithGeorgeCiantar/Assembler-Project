#include "Parser.h"

Parser::~Parser() {}

void Parser::iterateVector() {
	firstPass();
	secondPass();

	string temp;
	string out;
	int type;
	vector<string>::iterator it = file.begin();

	while (it != file.end()) {
		temp = *it;
		type = commandType(temp);

		if (type == 1) {
			string sym;
			sym = symbol(type, temp);
			if (checkIsNumeric(sym)) {
				out = Encoder::numericAddress(sym);
				out = "0" + out;
				binary.push_back(out);
			} else {
				int address = symbol_table.getSymbolAddress(sym);
				out = Encoder::numericAddress(address);
				out = "0" + out;
				binary.push_back(out);
			}
		} else if (type == 2) {
			string c;
			string d;
			string j;
			string cdj;
			c = comp(type, temp);
			d = dest(type, temp);
			j = jump(type, temp);
			cdj = Encoder::comp(c) + Encoder::dest(d) + Encoder::jump(j);
			out = "111" + cdj;
			binary.push_back(out);
		}

		it++;
	}
}

void Parser::firstPass() {
	string temp;
	int type;
	vector<string>::iterator it = file.begin();

	int rom_line_count = 0;

	while (it != file.end()) {
		temp = *it;
		type = commandType(temp);

		string sym;
		sym = symbol(type, temp);

		if (type == 3) {
			if (!symbol_table.checkIfContained(sym)) {
				symbol_table.addNewSymbol(sym, rom_line_count);
				rom_line_count--;
			}
		}

		it++;
		rom_line_count++;
	}
}

void Parser::secondPass() {
	string temp;
	int type;
	vector<string>::iterator it = file.begin();

	while (it != file.end()) {
		temp = *it;
		type = commandType(temp);

		string sym;
		sym = symbol(type, temp);

		if (type == 1) {
			if (!checkIsNumeric(sym)) {
				if (!symbol_table.checkIfContained(sym)) {
					symbol_table.addNewSymbol(sym);
				}
			}
		}

		it++;
	}
}

vector<string> Parser::outputBinary() {	
	return binary;
}

int Parser::commandType(string x) {
	int type = 0;

	//A_COMMAND = 1
	//C_COMMAND = 2
	//L_COMMAND = 3
	
	if (x.find("@") != -1) {
		type = 1;
	} else if (x.find("=") != -1 || x.find(";") != -1) {
		type = 2;
	} else if (x.find("(") != -1) {
		type = 3;
	}

	return type;
}

string Parser::symbol(int type, string x) {
	string symbol;

	if (type == 1) {
		symbol = x.substr(1);
	} else if (type == 3) {
		int bracket = x.find(")");
		symbol = x.substr(1, bracket - 1);
	}

	return symbol;
}

string Parser::dest(int type, string x) {
	string dest;
	
	if (type == 2) {
		if (x.find("=") != -1) {
			int equals = x.find("=");
			dest = x.substr(0, equals);
		} else if (x.find(";") != -1) {
			dest = "null";
		}
	}

	return dest;
}

string Parser::comp(int type, string x) {
	string comp;

	if (type == 2) {
		if (x.find("=") != -1) {
			int equals = x.find("=");
			comp = x.substr(equals + 1);
		} else if (x.find(";") != -1) {
			int semi_colon = x.find(";");
			comp = x.substr(0, semi_colon);
		}
	}
	
	return comp;
}

string Parser::jump(int type, string x) {
	string jump;

	if (type == 2) {
		if (x.find("=") != -1) {
			jump = "null";
		} else if (x.find(";") != -1) {
			int semi_colon = x.find(";");
			jump = x.substr(semi_colon + 1);
		}
	}

	return jump;
}

bool Parser::checkIsNumeric(string x) {
	bool check;
	int count = 0;

	for (int i = 0; i < (int)(x.length()); i++) {
		if (x.at(i) >= 48 && x.at(i) <= 57) {
			count++;
		}
	}

	if (count == x.length()) {
		check = true;
	} else {
		check = false;
	}

	return check;
}

/*void Parser::printOutput() {
	vector<string>::iterator it = binary.begin();

	while (it != binary.end()) {
		cout << *it << endl;
		it++;
	}
}*/