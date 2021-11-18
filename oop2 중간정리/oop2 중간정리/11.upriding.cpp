#include <iostream>	
using namespace std;

class GrandParent {
private:
	string name;
public:
	friend ostream& operator <<(ostream&, GrandParent&);
	GrandParent(string name) {
		this->name = name;
	}

};

ostream& operator <<(ostream& os, GrandParent& gp) {
	os << gp.name;
	return os;
}

class Parent : public GrandParent {
private:
	string name;
public:
	friend ostream& operator <<(ostream&, Parent&);
	Parent(string name1, string name2) : GrandParent(name1) {
		this->Parent::name = name2;
	}
};

ostream& operator <<(ostream& os, Parent& gp) {
	os << gp.name;
	return os;
}

class Child : public Parent {
private:
	string name;
public:
	friend ostream& operator <<(ostream&, Child&);
	Child(string name1, string name2, string name3) :Parent(name1, name2) {
		this->Child::name = name3;
	}
};

ostream& operator <<(ostream& os, Child& gp) {
	os << gp.name;
	return os;
}

int main() {
	GrandParent gp("L1");
	Parent p("L2", "M2");
	Child c("L3", "M3", "S3");
	cout << ' ' << p << ' ' << c << '\n';
	gp = p; // gp = p를 대입하고 gp를 cout하면 parent에 있는 ostream<<이 실행되는는 것("M2")가 아닌 grandparent에 있는 ostream<<이 실행됨("L2")
			// 꽤 당연한 것 같은데 헷갈리네...물론 대입 안하고 그냥 실행시켰을 때는 이름이 같은 가장 가까운 함수가 실행됨
	cout << gp << ' ' << p << ' ' << c << ' ';
	p = c;
	cout << gp << ' ' << p << ' ' << c;
}