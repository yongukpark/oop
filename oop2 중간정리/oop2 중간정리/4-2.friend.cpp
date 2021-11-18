#include <iostream>
using namespace std;

class friend1 {
public:

private:
	friend class friend2;
	string name = "¿ë¿í";
};

class friend2 {
public:
	void showName(friend1&);
private:

};

void friend2::showName(friend1& f) {
	cout << "friend1 Name :" << f.name << '\n';
}

int main() {
	friend1 f1;
	friend2 f2;
	f2.showName(f1);
}