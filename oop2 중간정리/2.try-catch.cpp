#include <iostream>
#include <stdexcept>
#include "time.h"
using namespace std;

int main() {
	Time t;
	try { //try에서 에러?가 나면 catch로 떨어진다
		t.setTime(99, 99, 99);
	}
	catch (invalid_argument& i) {
		cout << i.what();
	}

}