#include <iostream>
#include <string>
#include <vector>
#include "Encoder.h"
#include "SymbolTable.h"

#pragma once

using namespace std;

class Parser {
	private:
		vector<string> file;
		vector<string> binary;
		SymbolTable symbol_table;

	public:
		Parser(vector<string> f) { file = f; }
		~Parser();

		void iterateVector();

		void firstPass(); //this checks labels only
		void secondPass(); //this check @symbols

		vector<string> outputBinary();

		int commandType(string x);

		string symbol(int type, string x);

		string dest(int type, string x);
		string comp(int type, string x);
		string jump(int type, string x);

		bool checkIsNumeric(string x);

		//void printOutput();
};