#include <string>

using namespace std;

#pragma once

class Encoder {
	public:
		Encoder();
		~Encoder();

		static string numericAddress(string x);
		static string numericAddress(int x);

		static string dest(string x);
		static string comp(string x);
		static string jump(string x);
};