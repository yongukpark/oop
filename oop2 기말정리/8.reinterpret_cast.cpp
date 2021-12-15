#include <iostream>
#include <string>
using namespace std;

int main() {
	int a = 40;
	char b;
	b = static_cast<char>(a);
	cout << b << '\n';


	int a2 = 40;
	int* ptr1 = reinterpret_cast<int*>(a2);
	int* ptr2 = &a2;
	char* b2 = reinterpret_cast<char*> (ptr2);
	cout << *b2;

}