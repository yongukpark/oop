#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main() {
	queue <int> q;
	for (int i = 0; i < 10; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
}