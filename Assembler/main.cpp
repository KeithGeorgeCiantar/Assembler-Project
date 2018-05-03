#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include "Parser.h"

using namespace std;

int main(int argc, char *argv[]) {

	vector<string> file_contents;
	vector<string> binary;

	if (argc != 2) {
		cout << "Incorrect number of input arguments!!" << endl;
	} else {
		cout << "This is the input filename: " << argv[1] << endl;
		
		string input_file_name(argv[1]);

		ifstream file(input_file_name);

		while (file) {
			string line;
			getline(file, line);
			if (line != "") {
				file_contents.push_back(line);
			}
		}

		file.close();

		cout << endl;

		cout << "Removing comments..." << endl;

		vector<string>::iterator it = file_contents.begin();

		while (it != file_contents.end()) {
			string temp = *it;
			int pos = temp.find("//");
			if (temp.at(0) == '/' && temp.at(1) == '/') {
				it = file_contents.erase(it);
			} else if (pos != -1) {
				*it = temp.substr(0, pos - 1);
			} else {
				it++;
			}
		}

		cout << "Removing whitespaces..." << endl;

		for (int i = 0; i < (int)(file_contents.size()); i++) {
			file_contents[i].erase(remove(file_contents[i].begin(), file_contents[i].end(), ' '), file_contents[i].end());
		}

		cout << endl;

		Parser p(file_contents);
		p.iterateVector();
		//p.printOutput();
		binary = p.outputBinary();

		int dot = input_file_name.find(".");
		string file_name = input_file_name.substr(0, dot);
		string output_file_name = file_name + ".hack";

		ofstream outfile(output_file_name, ofstream::out | ofstream::trunc);

		if (outfile) {
			for (int i = 0; i < (int)(binary.size()); i++) {
				outfile << binary[i] << endl;
			}
		}

		outfile.close();
	}

	system("pause");

	return 0;
}