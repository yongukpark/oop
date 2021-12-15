#include <iostream>
#include <string> //string 전용 getline
using namespace std;

int main() {

	//string s;
	//cin >> s;
	//cout << s;
	////getline을 쓰지 않을 경우 띄어쓰기를 인식 못함

	//1.string으로 쓸 경우
	string s2;
	getline(cin,s2);
	cout << s2 << '\n';
	
	//2.char 배열로 쓸 경우
	char s3[30];
	cin.getline(s3, 10);
	cout << s3;

}