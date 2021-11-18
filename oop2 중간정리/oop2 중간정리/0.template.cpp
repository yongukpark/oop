#include <iostream>;
using namespace std;

template <typename T>
T maximum(T value1, T value2, T value3) {
	T maximumValue = value1;
	if (value2 > maximumValue) {
		maximumValue = value2;
	}

	if (value3 > maximumValue) {
		maximumValue = value3;
	}
	return maximumValue;
}

int main() {

	cout << "int maxi : " << maximum(1, 2, 3) << '\n';
	cout << "float maxi : " << maximum(1.0, 2.0, 3.0) << '\n';
	cout << "char maxi : " << maximum('C', 'B', 'D') << '\n';

}