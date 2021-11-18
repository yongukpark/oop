#include <iostream>
#include <iomanip> //setprecision
using namespace std;

int main() {
	
	double n = 1.234567;

	cout << "fixed 사용전\n";
	for (int i = 0; i < 10; i++) {
		cout << setprecision(i) << n << '\n';
		//setprecision(n) 소수점 n자리에서 반올림
	}

	cout << fixed << "\nfixed 사용후\n";
	for (int i = 0; i < 10; i++) {
		cout << setprecision(i) << n << '\n';
		//fixed를 사용하면 남는 자리 0으로 채움
	}
}