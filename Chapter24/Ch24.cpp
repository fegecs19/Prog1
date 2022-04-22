#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;



//4.
	void f_4(){
		int i;
		while(cin >> i){
			double d = sqrt(i);
			if (i < 0){
				cout << "no square root" << endl;
			}
			else{
				cout << "sqrt(" << i << ") = " << d << endl;	
			}
		}
	}


int main()
try{

	//1.

	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of short: " << sizeof(short) << endl;
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of long: " << sizeof(long) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of double: " << sizeof(double*) << endl;
	cout << endl;

	//2.

	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	cout << "Size of a: " << sizeof(a) << endl;
	cout << "Size of b: " << sizeof(b) << endl;
	cout << "Size of c: " << sizeof(c) << endl;
	cout << "Size of d: " << sizeof(d) << endl;
	cout << "Size of e: " << sizeof(e) << endl;
	cout << endl;

	//3.

	cout << "Number of elements in a matrix: " << a.size()<< endl;
	cout << "Number of elements in b matrix: " << b.size()<< endl;
	cout << "Number of elements in c matrix: " << c.size()<< endl;
	cout << "Number of elements in d matrix: " << d.size()<< endl;
	cout << "Number of elements in e matrix: " << e.size()<< endl;
	cout << endl;


	f_4();

	
	//5.

	cin.clear();
    cin.ignore();
	cout << endl;
	cout << "Enter 10 floats: ";
	Matrix<double> m2(10);
	double d2;
	for (int i = 0; i < m2.size(); ++i)
	{
		cin >> d2;
		m2[i] = d2;
	}
	cout << "Matrix:\n" << m2 << endl;
	cout << endl;

	//6.

	int n,m;
	cout << "n value of matrix: ";
	cin >> n;
	cout << "m value of matrix: ";
	cin >> m;
	cout << endl;
	Matrix<int, 2> mult (n,m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			mult(i,j)=(i+1)*(j+1);
			cout << mult(i,j) << '\t';
		}
		cout << endl;
	}
	cout << endl;

	//7.

	Matrix<complex<double>> mc(10);
	cout << "Enter 10 complex numbers (Re, Im): ";
	complex<double> comp;
	for (int i = 0; i < 10; ++i)
	{
		cin >> comp;
		if (!cin) throw runtime_error("Problem reading complex number!");
		mc[i] = comp;
	}
	complex<double> sum;
	for (int i = 0; i < mc.size(); ++i)
	{
		sum += mc[i];
	}
	cout << "sum: " << sum << endl;
	cout << endl;
	
	//8.

	Matrix<int, 2> m3 (2,3);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> m3(i,j);
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << m3(i,j) << '\t';
		}
		cout << endl;
	}

} catch(exception& e) {
	cerr << e.what() << '\n';
	return 1;
} catch(...) {
	cerr << "Unknown exception!" << '\n';
	return 2;
}