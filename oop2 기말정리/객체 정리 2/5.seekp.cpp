#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream output("output.txt");
	output << "123456789";
	output.seekp(5); //seekp : seekg�� ���� ���� 
	
	output << "*";

	output.seekp(1);

	output << "*";

	output.seekp(-1, ios::end); //�ڿ��� ù��° �ε���
	output << "*";
	output.close();
}