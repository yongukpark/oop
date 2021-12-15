#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream input("example.txt");
	if (input.fail()) {
		cout << "����" << '\n';
		return 1;
	}

	int index = 0;
	while (!input.eof()) {
		input.seekg(index); //'index'�� �ε����� Ŀ�� �̵�
		cout << index << ' ' << (char)input.peek() << '\n';
		//Ŀ���� �ִ� �ε����� ���� char���·� ���
		index++;
	}

	input.seekg(0,ios::end); //end�� ���̸� �ڿ��� ���� �� 0,-1,-2...
	cout << "������ ���̴� : " << input.tellg();
	//tellg�� ó������ Ŀ���� �ִ� ��ġ���� ������ ���� ����

	input.close();
	return 0; 

}