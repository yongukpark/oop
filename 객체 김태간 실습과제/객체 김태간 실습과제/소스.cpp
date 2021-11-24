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
				cout << "�ٽ��Է��Ͽ� �ֽʽÿ�\n";
				break;
			}
		}
	}
	void write() {
		outFile.open(fileName, ios::app);
		if (outFile.is_open()) {
			cout << "�ۼ��� ������ �Է��Ͽ� �ֽʽÿ�\n";
			string s;
			cin >> s;
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
			while (getline(inFile, line)) {
				cout << line << '\n';
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