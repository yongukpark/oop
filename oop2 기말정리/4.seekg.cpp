#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream input("example.txt");
	if (input.fail()) {
		cout << "실패" << '\n';
		return 1;
	}

	int index = 0;
	while (!input.eof()) {
		input.seekg(index); //'index'의 인덱스로 커서 이동
		cout << index << ' ' << (char)input.peek() << '\n';
		//커서가 있는 인덱스의 값을 char형태로 출력
		index++;
	}

	input.seekg(0,ios::end); //end를 붙이면 뒤에서 부터 셈 0,-1,-2...
	cout << "파일의 길이는 : " << input.tellg();
	//tellg는 처음부터 커서가 있는 위치까지 파일의 길이 세기

	input.close();
	return 0; 

}