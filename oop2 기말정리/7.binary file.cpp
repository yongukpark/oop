#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream os;
	os.open("./txt����/test.dat", ostream::binary);
	if (os.is_open()) {
		for (int i = 0; i < 10; i++) {
			os.write((char*)&i, sizeof(int));
			//int ũ�⸸ŭ ������ ����Ͽ� ����
		}
		os.close();
	}
	else {
		cout << "���� ����";
		return 1;
	}
	
	ifstream is;
	is.open("./txt����/test.dat", ostream::binary);
	int n;
	for (int i = 0; i < 10; i++) {
		is.read((char*)&n, sizeof(int));
		cout << n;
	}

	is.close();
	return 0;
}