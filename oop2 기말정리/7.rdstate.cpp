#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	int n;

	cout << "입력전\n\n";
	cout << setw(10) << "rdstate : " << cin.rdstate() << '\n';
	cout << setw(10) << "eof : " << cin.eof() << '\n';
	cout << setw(10) << "fail : " << cin.fail() << '\n';
	cout << setw(10) << "bad : " << cin.bad() << '\n';
	cout << setw(10) << "good : " << cin.good() << '\n';

	cin >> n;

	cout << "\n입력후\n\n";
	cout << setw(10) << "rdstate : " << cin.rdstate() << '\n';
	cout << setw(10) << "eof : " << cin.eof() << '\n';
	cout << setw(10) << "fail : " << cin.fail() << '\n';
	cout << setw(10) << "bad : " << cin.bad() << '\n';
	cout << setw(10) << "good : " << cin.good() << '\n';

	cin.clear();

	cout << "\n클리어후\n\n";
	cout << setw(10) << "rdstate : " << cin.rdstate() << '\n';
	cout << setw(10) << "eof : " << cin.eof() << '\n';
	cout << setw(10) << "fail : " << cin.fail() << '\n';
	cout << setw(10) << "bad : " << cin.bad() << '\n';
	cout << setw(10) << "good : " << cin.good() << '\n';

}