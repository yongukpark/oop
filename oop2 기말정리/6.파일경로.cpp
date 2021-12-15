#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream example;
	example.open("C:/Users/Administrator/Desktop/a.txt"); //절대 주소'
	
	if (example.is_open()) {
		example << "절대주소\n";
		for (int i = 1; i < 10; i++) {
			example << i << "줄\n";
		}
	}
	else {
		cout << "파일 없음";
	}

	example.close();


	example.open("./txt연습/a.txt"); //상대 주소

	if (example.is_open()) {
		example << "상대주소\n";
		for (int i = 1; i < 10; i++) {
			example << i << "줄\n";
		}
	}
	else {
		cout << "파일 없음";
	}

	example.close();

}
