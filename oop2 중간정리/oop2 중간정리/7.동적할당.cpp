#include <iostream>
using namespace std;

//정적할당은 스택에 저장 / 동적할당은 힙에 저장
//동적할당이 속도가 좀 더 빠름
//정적할당은 함수가 끝나면 사라짐 / 동적할당은 delete 시켜줘야 사라짐

class point {

public:
	point(int a, int b) {
		x = a;
		y = b;
	}
private:
	int x;
	int y;
};

int main() {
	//변수 선언, 삭제
	int num = 3; //정적 : 스택 저장
	int* pnum = new int(3); //동적 : 힙에 저장
	cout << num;
	cout << "\n" << pnum;
	cout << "\n" << *pnum;
	delete pnum;

	//배열 선언, 삭제
	int* panum = new int[5]{ 1,2,3,4,5 };
	cout << "\n" << panum;
	cout << "\n" << *panum << '\n';
	delete[] panum;

	//이차원 배열 선언, 삭제
	int** paanum = new int* [5];
	for (int i = 0; i < 5; i++) {
		paanum[i] = new int[5];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			paanum[i][j] = i * j;
			cout << paanum[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < 5; i++) {
		delete[] paanum[i];
	}


	delete[] paanum;

	//포인터 선언, 삭제

	point* p = new point(1, 3);

	delete p;
}