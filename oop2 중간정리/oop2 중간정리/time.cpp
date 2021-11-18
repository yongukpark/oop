#include <iostream>
#include <string>
#include <stdexcept> //for invalid_argument 
#include "Time.h"
using namespace std;

Time::Time(int h, int m, int s) { //�������� : ���ʴ��
	hour = h;
	minute = m;
	second = s;
}

Time::~Time() { //�Ҹ���� : ���� -> ���� -> static �������� �ݴ��
	cout << "�Ҹ���\n";
}

void Time::setTime(int h, int m, int s) {
	if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
		hour = h;
		minute = m;
		second = s;
	}
	else {
		throw invalid_argument( //try-catch���� ���
			"hour, minute and/or second was out of range");
	}
}