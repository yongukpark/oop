#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream output("output.txt");
	output << "123456789";
	output.seekp(5); //seekp : seekg의 쓰기 형태 
	
	output << "*";

	output.seekp(1);

	output << "*";

	output.seekp(-1, ios::end); //뒤에서 첫번째 인덱스
	output << "*";
	output.close();
}