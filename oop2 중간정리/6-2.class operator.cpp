#include <iostream>	
using namespace std;

class oper {
public:
	oper();
	oper(int, int);
	oper operator+(oper&);
	oper operator-(oper&);
	oper operator*(oper&);
	oper operator/(oper&);
	oper& operator++();
	oper operator++(int);
	friend ostream& operator<<(ostream&, oper&);
private:
	int x = 0, y = 0;
};

oper::oper() {

}

oper::oper(int x, int y) {
	this->x = x;
	this->y = y;
}

oper oper::operator+(oper& op) {
	int x1 = this->x + op.x;
	int y1 = this->y + op.y;
	return oper(x1, y1);
}

oper oper::operator-(oper& op) {
	int x1 = this->x - op.x;
	int y1 = this->y - op.y;
	return oper(x1, y1);
}

oper oper::operator*(oper& op) {
	int x1 = this->x * op.x;
	int y1 = this->y * op.y;
	return oper(x1, y1);
}

oper oper::operator/(oper& op) {

	int x1 = this->x / op.x;
	int y1 = this->y / op.y;
	return oper(x1, y1);
}

ostream& operator<<(ostream& os, oper& op) {
	os << op.x << ' ' << op.y;
	return os;
}

oper& oper::operator++() {
	this->x++;
	this->y++;
	return *this;

}

oper oper::operator++(int) {
	oper temp;
	temp.x = this->x;
	temp.y = this->y;
	this->x++;
	this->y++;
	return temp;
}

int main() {

	oper x(64, 9);
	oper y(2, 3);
	oper add_xy = x + y;
	oper sub_xy = x - y;
	oper mul_xy = x * y;
	oper div_xy = x / y;

	cout << add_xy << '\n';
	cout << sub_xy << '\n';
	cout << mul_xy << '\n';
	cout << div_xy << '\n';

}