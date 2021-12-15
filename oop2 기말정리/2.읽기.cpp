#include <iostream>
#include <fstream>
#include <string> //string전용 getline
using namespace std;

int main() {
	string line;

	ifstream myfile;
	myfile.open("example.txt"); //파일 열고 읽기

	if (myfile.is_open()) { //파일의 존재유무 판별
		while (getline(myfile, line)) {
			cout << line <<'\n';
		}
	}
	else {
		cout << "파일이 없습니다";
	}
	myfile.close();
}