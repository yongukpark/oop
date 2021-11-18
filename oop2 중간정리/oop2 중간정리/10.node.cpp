#include <iostream>
using namespace std;

class 동물 {
private:
public:
	virtual void 울음소리() = 0;
	virtual void 다리개수() = 0;
	virtual void 종류() = 0;

	virtual ~동물() {
		cout << "동물삭제" << '\n';
	}
};

class 개 : public 동물 {
public:
	virtual void 울음소리() {
		cout << "왈왈" << '\n';
	}
	virtual void 다리개수() {
		cout << "4개" << '\n';
	}
	virtual void 종류() {
		cout << "포유류" << '\n';
	}

	virtual ~개() {
		cout << "개삭제" << '\n';
	}
};

class 토끼 : public 동물 {
public:
	virtual void 울음소리() {
		cout << "낑낑" << '\n';
	}
	virtual void 다리개수() {
		cout << "4개" << '\n';
	}
	virtual void 종류() {
		cout << "설치류" << '\n';
	}

	virtual ~토끼() {
		cout << "토끼삭제" << '\n';
	}
};

int main() {
	개 개1;
	개1.울음소리();
	개1.다리개수();
	개1.종류();

	토끼 토끼1;
	토끼1.울음소리();
	토끼1.다리개수();
	토끼1.종류();
}