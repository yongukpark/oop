#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream myfile;
	myfile.open("example.txt");

	string name;
	int account;
	while (cin >> name >> account) { //���� �Է¹޾Ƽ� ����
		myfile << name<<' ' << account << '\n';
	}

	myfile.close();

	ifstream myfile1;
	myfile1.open("example.txt");

	string name1;
	int account1;

	if (myfile1.is_open()) { 
		while (myfile1 >> name1 >> account1) { //getline�� �޸� space�� �������� ������
			cout << name1 << account1 <<'\n';
		}
	}
	else {
		cout << "No file";	
	}

	myfile1.close();
}