#include <iostream>
using namespace std;

template <typename T, typename A>

T sum(T a, A b) {
	return a + b;
}

template <typename T>

class Person {
	T num1;
	T num2;
public:
	Person(T num1, T num2) {
		this->num1 = num1;
		this->num2 = num2;
	}
	T getAdd() {
		return this->num1 + this->num2;
	}
};

int main() {
	cout << sum(1, 3.4) << '\n';

	Person<int> person(1, 3);
	cout << person.getAdd();
}