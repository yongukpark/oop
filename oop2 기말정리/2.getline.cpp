#include <iostream>
#include <string> //string ���� getline
using namespace std;

int main() {

	//string s;
	//cin >> s;
	//cout << s;
	////getline�� ���� ���� ��� ���⸦ �ν� ����

	//1.string���� �� ���
	string s2;
	getline(cin,s2);
	cout << s2 << '\n';
	
	//2.char �迭�� �� ���
	char s3[30];
	cin.getline(s3, 10);
	cout << s3;

}