#pragma once
// #1 ������ ������
#include <string>

#ifndef TIME_H
#define TIME_H

class Time {
public:
	Time(int = 0, int = 0, int = 0); //default ��

	void setTime(int, int, int);


	~Time();
private:
	int hour = 0;
	int minute = 0;
	int second = 0;
};
#endif

