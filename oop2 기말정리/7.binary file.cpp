#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream os;
	os.open("./txt연습/test.dat", ostream::binary);
	if (os.is_open()) {
		for (int i = 0; i < 10; i++) {
			os.write((char*)&i, sizeof(int));
			//int 크기만큼 공간을 사용하여 쓴다
		}
		os.close();
	}
	else {
		cout << "쓰기 실패";
		return 1;
	}
	
	ifstream is;
	is.open("./txt연습/test.dat", ostream::binary);
	int n;
	for (int i = 0; i < 10; i++) {
		is.read((char*)&n, sizeof(int));
		cout << n;
	}

	is.close();
	return 0;
}