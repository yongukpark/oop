#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream example;
	example.open("C:/Users/Administrator/Desktop/a.txt"); //���� �ּ�'
	
	if (example.is_open()) {
		example << "�����ּ�\n";
		for (int i = 1; i < 10; i++) {
			example << i << "��\n";
		}
	}
	else {
		cout << "���� ����";
	}

	example.close();


	example.open("./txt����/a.txt"); //��� �ּ�

	if (example.is_open()) {
		example << "����ּ�\n";
		for (int i = 1; i < 10; i++) {
			example << i << "��\n";
		}
	}
	else {
		cout << "���� ����";
	}

	example.close();

}
