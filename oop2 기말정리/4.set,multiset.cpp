#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> exam;

	exam.insert(1);
	exam.insert(4);
	exam.insert(3);
	exam.insert(2);

	for (auto iter = exam.begin(); iter != exam.end(); iter++) {
		cout << "key : " << *iter << '\n';

	}	

}