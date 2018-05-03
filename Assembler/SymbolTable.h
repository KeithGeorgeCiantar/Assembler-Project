#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#pragma once

class SymbolTable {
	public:
		map <string, int> symbols;
		static int next_symbol_value;

		SymbolTable();
		~SymbolTable();

		bool checkIfContained(string x);
		void addNewSymbol(string x);
		void addNewSymbol(string x, int addr); //this method is to add the label, where labels have ROM addresses which correspond to the line number

		int getSymbolAddress(string x);

		//void printTable();
};