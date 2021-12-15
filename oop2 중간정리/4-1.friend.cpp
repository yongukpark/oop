#include <iostream>
using namespace std;

class year
{
public:
	year(int a) {
		y = a;
	}
	void showYear() {
		cout << y << "년 ";
	}

	//friend 사용법
	friend void setYear(year&, int);
private:
	int y = 0;
};

class month
{
public:
	month(int a, const year& b) {
		m = a;
		y = b;
	}

	void showMonth() {
		y.showYear(); //class year의 함수도 사용가능
		cout << m << "월" << '\n';
	}

	//friend 사용법
	friend void setMonth(month&, int);

private:
	int m = 0;
	year y = 0; //class year에서 가져올 객체를 저장
};

void setYear(year& y, int a) {
	y.y = a;
}

void setMonth(month& m, int a) { // friend로 정의된 함수에서는 멤버변수 접근이 가능
	m.m = a;
}


int main() {
	year y(2021); //y 선언
	month m(9, y); //year 클래스에서 y 데이터 뺏어오기
	y.showYear();
	cout << '\n';
	setMonth(m, 12); //class함수가 아닌 일반함수로 멤버변수에 접근함
	m.showMonth();
}