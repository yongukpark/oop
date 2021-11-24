#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Filesystem {
private:
	ofstream outFile;
	ifstream inFile;
	string fileName;

public:
	Filesystem(string File) {	
		fileName = File;
		while (1) {
			cout << "1. 파일 작성 2. 파일 출력 3. 종료\n입력 : ";
			int a;
			cin >> a;
			switch (a)
			{
			case 1:
				write();
				break;
			case 2:
				read();
				break;
			case 3:
				return;
			default:
				cout << "다시입력하여 주십시요\n";
				break;
			}
		}
	}
	void write() {
		outFile.open(fileName, ios::app);
		if (outFile.is_open()) {
			cout << "작성할 내용을 입력하여 주십시요\n";
			string s;
			cin >> s;
			outFile << s << '\n';
		}
		else {
			cout << "파일 열기 오류\n";
		}
		outFile.close();
	}
	void read() {
		inFile.open(fileName);
		string line;
		if (inFile.is_open()) {
			while (getline(inFile, line)) {
				cout << line << '\n';
			}
		}
		else {
			cout << "파일 열기 오류\n";
		}
		inFile.close();
	}
};

int main() {
	Filesystem fs("test.txt");
}