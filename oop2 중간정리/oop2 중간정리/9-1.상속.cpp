#include <iostream>
using namespace std;

class A { //int a,b,c�� ���ٰ�����
private: //�ڽ��� Ŭ���� �ȿ����� ���ٰ�����
	int a;
protected: //�ڽ��� Ŭ���� + ��� Ŭ�������� �ȿ����� ���ٰ�����
	int b;
public: //��𼭵� ���ٰ�����
	int c;
};

class B : public A { //int b,c ���� ���ٰ�����
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

int main() { //int c���� ���ٰ�����

}