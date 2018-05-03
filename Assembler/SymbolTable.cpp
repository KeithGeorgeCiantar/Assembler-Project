#include "SymbolTable.h"

int SymbolTable::next_symbol_value = 16;

SymbolTable::SymbolTable() {
	symbols.insert(pair <string, int>("R0", 0));
	symbols.insert(pair <string, int>("R1", 1));
	symbols.insert(pair <string, int>("R2", 2));
	symbols.insert(pair <string, int>("R3", 3));
	symbols.insert(pair <string, int>("R4", 4));
	symbols.insert(pair <string, int>("R5", 5));
	symbols.insert(pair <string, int>("R6", 6));
	symbols.insert(pair <string, int>("R7", 7));
	symbols.insert(pair <string, int>("R8", 8));
	symbols.insert(pair <string, int>("R9", 9));
	symbols.insert(pair <string, int>("R10", 10));
	symbols.insert(pair <string, int>("R11", 11));
	symbols.insert(pair <string, int>("R12", 12));
	symbols.insert(pair <string, int>("R13", 13));
	symbols.insert(pair <string, int>("R14", 14));
	symbols.insert(pair <string, int>("R15", 15));
	symbols.insert(pair <string, int>("SCREEN", 16384));
	symbols.insert(pair <string, int>("KBD", 24576));
	symbols.insert(pair <string, int>("SP", 0));
	symbols.insert(pair <string, int>("LCL", 1));
	symbols.insert(pair <string, int>("ARG", 2));
	symbols.insert(pair <string, int>("THIS", 3));
	symbols.insert(pair <string, int>("THAT", 4));
}

SymbolTable::~SymbolTable() {}

bool SymbolTable::checkIfContained(string x) {
	bool check;

	map<string, int>::iterator it;

	it = symbols.find(x);

	if (it != symbols.end()) {
		check = true;
	} else {
		check = false;
	}

	return check;
}

void SymbolTable::addNewSymbol(string x) {
	if (!checkIfContained(x)) {
		if (next_symbol_value < 16384) {
			symbols.insert(pair <string, int>(x, next_symbol_value));
			next_symbol_value++;
		}
	}
}

void SymbolTable::addNewSymbol(string x, int addr) {
	if (!checkIfContained(x)) {
		symbols.insert(pair <string, int>(x, addr));
	}
}

int SymbolTable::getSymbolAddress(string x) {
	int address = 0;
	
	map<string, int>::iterator it;

	it = symbols.find(x);

	if (it != symbols.end()) {
		address = it->second;
	}

	return address;
}

/*void SymbolTable::printTable() {
	map<string, int>::iterator it;

	it = symbols.begin();

	while (it != symbols.end()) {
		cout << it->first << "       " << it->second << endl;
		
		it++;
	}
}*/