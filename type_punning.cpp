// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Big_Struct
{
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	int a4 = 4;
	int a5 = 5;
	int a6 = 6;

	int* get_array_like_access()
	{
		return &a1;
	}
};


int main()
{
	// copying the memory of a into the memory of value.
	int a = 40;
	int* pa = &a;
	double value = *(double*)&a;
	cout << a << endl;
	cout << value << endl;

	// now take the first 4 bytes of value and recast it to an int
	char* c = (char*)&value; //got the address of first byte
	int A = *(int*)c;
    cout << A << endl;
	
    // access the data members exploiting memory access.
	Big_Struct s;
	int* ptr = s.get_array_like_access();

	// access a5
    std::cout << ptr[4] << endl;

	// write on a4;
	ptr[3] = 69;
	std::cout << ptr[3] << endl;


	return 0;
}