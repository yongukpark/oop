#include <iostream> 
#include <vector>
using namespace std;


class Parent {
public:
	virtual void virtualShow() {
		cout << "Parent";
	}

	void nonVirtualShow() {
		cout << "Parent";
	}
	virtual ~Parent() {
		cout << "~p";
	}
};

class Child : public Parent {
public:
	virtual void virtualShow() {
		cout << "Child";
	}
	void nonVirtualShow() {
		cout << "Child";
	}
	virtual ~Child() {
		cout << "~c";
	}
};

class Childchild : public Child {
public:
	virtual void virtualShow() {
		cout << "Cchild";
	}
	void nonVirtualShow() {
		cout << "Cchild";
	}
	virtual ~Childchild() {
		cout << "~cc";
	}
};

int main() {

	Childchild cc;
	Child c;
	Parent p;

	vector <Parent*> vecPtr = { &p ,&c, &cc };

	for (Parent* ptr : vecPtr) {
		cout << "virtual function : ";
		ptr->virtualShow();
		cout << '\n';
		cout << "non-virtual function : ";
		ptr->nonVirtualShow();
		cout << '\n';
	}
}