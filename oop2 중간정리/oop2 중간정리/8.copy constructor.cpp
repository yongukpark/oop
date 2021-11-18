#include <iostream>	
using namespace std;

class Array {
	friend istream& operator>>(istream&, Array&);
	friend ostream& operator<<(ostream&, const Array&);
public:
	Array(int = 10); //constructor
	Array(const Array&); //copy constructor 
	~Array();
	size_t getSize() const;
	const Array& operator=(const Array&);
	bool operator==(const Array&) const;

private:
	int size;
	int* ptr;
};

Array::Array(int a = 10) {
	size = a;
	ptr = new int[size];
}

Array::Array(const Array& copyArray) {
	size = copyArray.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = copyArray.ptr[i];
	}

}

Array::~Array() {
	delete[] ptr;
}

istream& operator>>(istream& is, Array& arr) {
	for (int i = 0; i < arr.size; i++) {
		is >> arr.ptr[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const Array& arr) {
	for (int i = 0; i < arr.size; i++) {
		cout << arr.ptr[i] << ' ';
	}
	cout << '\n';
	return os;
}

size_t Array::getSize() const {
	return size;
}

const Array& Array::operator=(const Array& arr) {
	if (&arr != this) {
		if (size != arr.size) {
			delete[] ptr;
			size = arr.size;
			ptr = new int[size];
		}
		else {
			for (int i = 0; i < size; i++) {
				ptr[i] = arr.ptr[i];
			}
		}
	}
	return *this;
}

bool Array::operator==(const Array& arr) const {
	if (size != arr.size) {
		return false;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (ptr[i] != arr.ptr[i]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	Array arr1;
	Array arr2 = arr1;
}