#include <iostream>	
#include <fstream>
using namespace std;

int main() {
	ofstream myfile;
	myfile.open("example.txt"); //������ ������ ������ ����, ������ ���� �����

	myfile << "hello world\n";
	myfile << "HELLO WORLD\n";


	myfile.open("example.txt",ios::app);  //"ios::app"�� ���̸� ������ ���� �̾���Ѵ� , ������ ����� ó������ �� (����)

	myfile << "hello world\n";
	myfile << "HELLO WORLD\n";

	myfile.close(); //������ ������ ������ �ݾƾ���
}