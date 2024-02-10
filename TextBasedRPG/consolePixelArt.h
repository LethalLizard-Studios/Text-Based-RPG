#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void printPixelart(string str) {
	stringstream obj(str);

	string temp;

	while (obj >> temp) {
		cout << temp <<" HI!";
	}
}