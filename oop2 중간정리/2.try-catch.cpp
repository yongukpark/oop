#include <iostream>
#include <stdexcept>
#include "time.h"
using namespace std;

int main() {
	Time t;
	try { //try���� ����?�� ���� catch�� ��������
		t.setTime(99, 99, 99);
	}
	catch (invalid_argument& i) {
		cout << i.what();
	}

}