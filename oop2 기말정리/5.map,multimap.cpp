#include <iostream>
#include <map>

using namespace std;

int main() {
	map<int, string> exam;

	exam.insert({ 1,"가" });
	exam.insert({ 4,"라" });
	exam.insert({ 3,"다" });
	exam.insert({ 2,"나" });

	for (auto iter = exam.begin(); iter != exam.end(); iter++) {
		cout << "key : " << iter->first << "    value : " << iter->second << '\n';
	}

	for (int i = 1; i <= 4; i++) {
		cout << exam[i] << ' ';
	}
}