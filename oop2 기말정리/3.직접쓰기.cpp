#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream myfile;
	myfile.open("example.txt");

	string name;
	int account;
	while (cin >> name >> account) { //직접 입력받아서 쓰기
		myfile << name<<' ' << account << '\n';
	}

	myfile.close();

	ifstream myfile1;
	myfile1.open("example.txt");

	string name1;
	int account1;

	if (myfile1.is_open()) { 
		while (myfile1 >> name1 >> account1) { //getline과 달리 space를 기준으로 가져옴
			cout << name1 << account1 <<'\n';
		}
	}
	else {
		cout << "No file";	
	}

	myfile1.close();
}