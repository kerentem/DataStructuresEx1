#pragma once

#include <vector>
#include <iostream>
using namespace std;
class Array
{
private:
	vector<int> arr;
	bool goodInput;
public:
	Array();
	void func1(int x);
	void func2(int size, int x, int temp);
	void func3(int size, int x, int temp);

	bool getIfGoodInput() {return goodInput; };
	int getArrSize() { return arr.size(); };
};

