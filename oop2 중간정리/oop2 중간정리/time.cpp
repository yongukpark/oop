#include <iostream>
#include <string>
#include <stdexcept> //for invalid_argument 
#include "Time.h"
using namespace std;

Time::Time(int h, int m, int s) { //생성순서 : 차례대로
	hour = h;
	minute = m;
	second = s;
}

Time::~Time() { //소멸순서 : 지역 -> 전역 -> static 생성순서 반대로
	cout << "소멸자\n";
}

void Time::setTime(int h, int m, int s) {
	if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
		hour = h;
		minute = m;
		second = s;
	}
	else {
		throw invalid_argument( //try-catch문에 사용
			"hour, minute and/or second was out of range");
	}
}