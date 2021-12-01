#include <iostream>
#include <list>

using namespace std; 

int main() {
	list <int> li;

	li.push_back(10);
	li.push_back(15);
	li.push_back(5);
	li.push_back(10);
	li.push_back(15);
	li.push_back(5);
	li.push_back(10);
	li.push_back(15);
	li.push_back(5);

	for (auto iter = li.begin(); iter != li.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << '\n';

	li.sort();
	for (auto iter = li.begin(); iter != li.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << '\n';

	li.remove(5);
	for (auto iter = li.begin(); iter != li.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << '\n';	
	
	li.unique();
	for (auto iter = li.begin(); iter != li.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << '\n';
}