#include <iostream>	
#include <fstream>
using namespace std;

int main() {
	ofstream myfile;
	myfile.open("example.txt"); //파일이 있으면 파일을 열고, 없으면 새로 만든다

	myfile << "hello world\n";
	myfile << "HELLO WORLD\n";


	myfile.open("example.txt",ios::app);  //"ios::app"을 붙이면 파일을 열고 이어쓰기한다 , 없으면 지우고 처음부터 씀 (조심)

	myfile << "hello world\n";
	myfile << "HELLO WORLD\n";

	myfile.close(); //끝나면 파일을 무조건 닫아야함
}