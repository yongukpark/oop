#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack <int> s1;
	stack <int> s2;
	cout << "i\n";
	for (int i = 0; i < 10; i++) {
		s1.push(i);
		cout << s1.top() << ' ';

	}
	cout << "\ni*i\n";

	for (int i = 0; i < 10; i++) {
		s2.push(i * i);
		cout << s2.top() << ' ';
	}

	
}