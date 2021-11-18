#include <iostream>
using namespace std;

class A { //int a,b,c에 접근가능함
private: //자신의 클래스 안에서만 접근가능함
	int a;
protected: //자신의 클래스 + 상속 클래스에서 안에서만 접근가능함
	int b;
public: //어디서든 접근가능함
	int c;
};

class B : public A { //int b,c 에만 접근가능함
//private :
//	int a;
//protected:
//	int b;
//public:
//	int c;

};

class C : protected A {

private:
	int a;
protected:
	int b, c;

};

class D : private A {
private:
	int a, b, c;

};

int main() { //int c에만 접근가능함

}