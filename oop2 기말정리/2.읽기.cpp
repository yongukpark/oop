#include <iostream>
#include <fstream>
#include <string> //string���� getline
using namespace std;

int main() {
	string line;

	ifstream myfile;
	myfile.open("example.txt"); //���� ���� �б�

	if (myfile.is_open()) { //������ �������� �Ǻ�
		while (getline(myfile, line)) {
			cout << line <<'\n';
		}
	}
	else {
		cout << "������ �����ϴ�";
	}
	myfile.close();
}