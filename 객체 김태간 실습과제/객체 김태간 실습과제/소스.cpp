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
			string a;
			getline(cin,a);

			if (a == "1") {
				write();
			}
			else if (a == "2") {
				read();
			}
			else if(a=="3"){
				break;
			}
			else {
				cout << "다시입력하여 주십시요\n";
			}

		}
	}
	void write() {
		outFile.open(fileName, ios::app);
		if (outFile.is_open()) {
			cout << "작성할 내용을 입력하여 주십시요\n";
			
			string s;
			getline(cin, s);

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
			char c[100];
			while (inFile.getline(c,100)) {
				cout << c << '\n';
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
 


