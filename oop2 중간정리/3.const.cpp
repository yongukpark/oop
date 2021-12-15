#include <iostream>
using namespace std;

class play {
public:

	play(int x) { //const_num이 const이므로 값 변경 안됨
		const_num = x;
	}

	play(int x) : const_num(x) {}//이러면 값 변경됨(그냥 된대) 


	//클래스 안에서의 const
	int dice = 1;
	int rolldice(void) {
		dice = rand() % 6 + 1;
		int localdice = 1;
		localdice = rand() % 6 + 1;
	}

	int const_rolldice(void) const {
		dice = rand() % 6 + 1; // 함수 밖의 변수의 값을 바꿀 수 없음
		int localdice = 1; //지역 변수는 값을 바꿀 수 있음
		localdice = rand() % 6 + 1;
	}




private:
	int num = 0;
	const int const_num = 0;
};

int main() {
	// const란
	int num = 1;
	const int pi = 3.14; //못바꾸는 상수로 만들어줌

	//포인터 +const 
	int x = 0;
	const int* const_ptr1 = &x; //값을 바꿀 수 없음
	int* const const_ptr2 = &x; //주소를 바꿀 수 없음
	const int* const const_ptr3 = &x; //값, 주소 바꿀 수 없음

	const_ptr1 = &x;  //가능(주소바꾸기)
	*const_ptr2 = x;  //가능(값바꾸기)
	*const_ptr1 = x;  //불가능(값바꾸기)
	const_ptr2 = &x;  //불가능(주소바꾸기)


}