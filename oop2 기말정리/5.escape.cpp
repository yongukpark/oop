#include <iostream>
using namespace std;

ostream& bell(ostream& output) {
	return output << '\a';
}

ostream& tab(ostream& output) {
	return output << '\t';
}

ostream& move_front(ostream& output) {
	return output << '\r';
}

int main() {
	cout << '\a'; //�˶��Ҹ��� ��
	cout << '\r'; //Ŀ���� �� ������ �̵�
	cout << '\t'; //tabġ��

	cout << bell;
	cout << tab;
	cout << move_front;

}