using namespace std;
#include "array.h"
#include <fstream>
#include <chrono>
#include <iomanip> 

void main()
{
	Array arr;
	int x;
	cin >>x;
	double time_taken1, time_taken2, time_taken3;

	if (arr.getIfGoodInput())
	{
		///////////////////////////  Iterative function  

		auto start1 = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);

		cout << "Iterative:" << endl;
		arr.func1(x);

		auto end1 = chrono::high_resolution_clock::now();
		time_taken1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
		time_taken1 *= 1e-9;

		///////////////////////////  Recursive function  

		auto start2 = chrono::high_resolution_clock::now();

		cout << "Recursive:" << endl;
		arr.func2(arr.getArrSize(), x, 0);

		auto end2 = chrono::high_resolution_clock::now();
		time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
		time_taken2 *= 1e-9;

		///////////////////////////  Recursion implemented using stack function  

		auto start3 = chrono::high_resolution_clock::now();

		cout << "Recursion implemented using stack:" << endl;
		arr.func3(arr.getArrSize(), x, 0);

		auto end3 = chrono::high_resolution_clock::now();
		 time_taken3 = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();
		time_taken3 *= 1e-9;

		// write to file the time for each function

		ofstream myfile("Measure.txt"); // The name of the file
		myfile << "Time taken by Iterative function is : " << fixed << time_taken1 << setprecision(9) << " sec" << endl;
		myfile << "Time taken by Recursive function is : " << fixed << time_taken2 << setprecision(9) << " sec" << endl;
		myfile << "Time taken by Recursive implemented using stack function is : " << fixed << time_taken3 << setprecision(9) << " sec" << endl;
		myfile.close();

	}
	else
		cout << "wrong input" << endl;
}
