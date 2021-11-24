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
			cout << "1. ���� �ۼ� 2. ���� ��� 3. ����\n�Է� : ";
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
				cout << "�ٽ��Է��Ͽ� �ֽʽÿ�\n";
			}

		}
	}
	void write() {
		outFile.open(fileName, ios::app);
		if (outFile.is_open()) {
			cout << "�ۼ��� ������ �Է��Ͽ� �ֽʽÿ�\n";
			
			string s;
			getline(cin, s);

			outFile << s << '\n';
		}
		else {
			cout << "���� ���� ����\n";
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
			cout << "���� ���� ����\n";
		}
		inFile.close();
	}
};

int main() {
	Filesystem fs("test.txt");
}
 


