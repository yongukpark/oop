#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Date {
public:
	friend istream& operator >> (istream&, Date&);
	friend ostream& operator << (ostream&, const Date&);
	Date& operator++();
	Date operator++(int);
private:
	int year;
	int month;
	int day;
};

istream& operator>>(istream& is, Date& d) {
	is >> setw(4) >> d.year >> d.month >> d.day;
	return is;
}

ostream& operator <<(ostream& os, const Date& d) {
	os << d.year << "년 " << d.month << "월 " << d.day << "일\n";
	return os;
}

Date& Date::operator++() {
	this->day++;
	return *this;
}

Date Date::operator++(int) {
	Date temp = *this;
	this->day++;
	return temp;
}

int main() {
	Date today;
	cin >> today;
	cout << today;
	Date day1 = (today++)++; //if day가 1일 때 today++에서 today의 day가 1증가하여 2가되고 temp의 day는 1이 된 채 저장
							 //그 다음에 day가 1인 temp가 들어가서 temp2에 그 값을 저장하고 temp2가 출력
							 //결론은 기존의 today값과 같은 값이 day1에 들어가고 today도 1만 증가함(나머지 증가는 중간중간 사라지는 temp에 저장되기에 이 명령이 끝나면 사라짐)
	cout << day1;
	cout << today;
	Date& day2 = ++today;
	cout << today;
	cout << day2;
	day2++;
	cout << day2;
	cout << today;
}