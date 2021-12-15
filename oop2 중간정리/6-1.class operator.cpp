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
	os << d.year << "�� " << d.month << "�� " << d.day << "��\n";
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
	Date day1 = (today++)++; //if day�� 1�� �� today++���� today�� day�� 1�����Ͽ� 2���ǰ� temp�� day�� 1�� �� ä ����
							 //�� ������ day�� 1�� temp�� ���� temp2�� �� ���� �����ϰ� temp2�� ���
							 //����� ������ today���� ���� ���� day1�� ���� today�� 1�� ������(������ ������ �߰��߰� ������� temp�� ����Ǳ⿡ �� ����� ������ �����)
	cout << day1;
	cout << today;
	Date& day2 = ++today;
	cout << today;
	cout << day2;
	day2++;
	cout << day2;
	cout << today;
}