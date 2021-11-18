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
	cout << '\a'; //알람소리가 남
	cout << '\r'; //커서를 맨 앞으로 이동
	cout << '\t'; //tab치기

	cout << bell;
	cout << tab;
	cout << move_front;

}