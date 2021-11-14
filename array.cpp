#include "array.h"
#include "stack.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include <bits.h>
Array::Array()
{
	int size,temp,counter=0;
	string getLine,num;
	goodInput = true;
	cin >> size;
	if (size == 0)
		goodInput = false;
	getchar();//takes the enter
	getline(cin, getLine);

	istringstream ss(getLine);

	while (ss >> num)
	{
		temp = stoi(num);
		if (temp < 1)
			goodInput = false;
		arr.push_back(temp);
		++counter;
	}
	if(counter!=size)
		goodInput = false;

}
void Array::func1(int x)
{
	for (int i = arr.size()-1;i >0;--i)
	{
		for (int j = i - 1;j >= 0;--j)
		{
			if (arr[i] + arr[j] == x)
				cout << arr[i] << " " << arr[j] << endl;
		}
	}
}
void Array::func2(int size,int x,int temp)
{
	
	if (1 == size )
	{
		if (temp != 0) {
			if (x == arr[0] + temp)
				cout << temp << " " << arr[0] << "\n";
		}
		return;
	}

		if (temp != 0)
		{
			if (x == arr[size - 1] + temp)
				cout << temp << " " << arr[size - 1] << "\n";
			func2(size - 1,  x, temp);
		}
		else
		{
			func2(size - 1,  x, arr[size - 1]);
			func2(size - 1,  x, 0);
		}
}
void Array::func3(int size, int x, int temp)
{
	Stack s;
	Item curr(size, x, temp, Line::START);
	int returnFromRecursion = 0;

	do
	{
		if (returnFromRecursion)
			curr = s.pop();

		if (Line::START == curr.getLine())
		{
			if (1 == curr.getSize())
			{
				if (curr.getNum() == arr[0] + curr.getTemp() && curr.getTemp() != 0)
					std::cout << curr.getTemp() << " " << arr[0] << "\n";
				returnFromRecursion = 1;
			}
			else 
			{
				if (curr.getTemp() != 0)
				{
					if (curr.getNum() == arr[curr.getSize() - 1] + curr.getTemp())
						std::cout << curr.getTemp() << " " << arr[curr.getSize() - 1] << "\n";

					curr.setLine(Line::AFTER_FIRST);
					s.push(curr); /////// 1
					curr.setSize(curr.getSize() - 1);
					curr.setLine(Line::START);
					returnFromRecursion = 0;
				}
				else
				{
					curr.setLine(Line::AFTER_SECOND);
					s.push(curr); /////// 2 
					curr.setTemp(arr[curr.getSize() - 1]);
					curr.setSize(curr.getSize() - 1);
					curr.setLine(Line::START);
					returnFromRecursion = 0;
				}
			}
		}
		/////////////////////////////////
		else if ( Line::AFTER_FIRST == curr.getLine() )
		{
			returnFromRecursion = 1;
		}
		/////////////////////////////////
		else if (Line::AFTER_SECOND == curr.getLine())
		{
			curr.setLine(Line::AFTER_THIRD);
			s.push(curr); //////// 3
			curr.setSize(curr.getSize() - 1);
			curr.setTemp(0);
			curr.setLine(Line::START);
			returnFromRecursion = 0;
		}
		/////////////////////////////////
		else if (Line::AFTER_THIRD == curr.getLine())
		{
			returnFromRecursion = 1;
		}
	}

	while (!s.isEmpty());
}


/*
* Stack s;
	Item curr(size, x, temp, Line::START), next;
	s.push(curr);

	while (!s.isEmpty())
	{
		curr = s.pop();
		switch (curr.getLine())
		{
		case Line::START:
			if (curr.getSize() == 1)
			{
				if (temp != 0) {
					if (x == arr[0] + temp)
						cout << temp << " " << arr[0] << "\n";
				}
				return;
			}
			if (temp != 0)
			{
				if (x == arr[size - 1] + temp)
					cout << temp << " " << arr[size - 1] << "\n";
			curr.setLine(Line::AFTER_FIRST);
			s.push(curr);
			next.setAll(size - 1, x, temp, Line::START);
			s.push(next);
			}
			else
			{
				curr.setLine(Line::AFTER_SECOND);
				s.push(curr);
				next.setAll(size - 1, x, arr[size-1], Line::AFTER_FIRST);
				s.push(next);
			}
			
			break;
		case Line::AFTER_FIRST:
			break;
		case Line::AFTER_SECOND:
			curr.setLine(Line::AFTER_THIRD);
			s.push(curr);
			next = { size - 1, x, temp, Line::AFTER_SECOND };
			s.push(next);
			break;
		case Line::AFTER_THIRD:
			break;
		}
	}
}

void Array::func3(int size, int x, int temp)
{
	
	
}*/


