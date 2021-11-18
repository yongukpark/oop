#include <iostream>
using namespace std;

class Game{

public:

	Game() {
		cout << "===== 숫자 야구 게임 =====\n";
		while (1) {
			cout << "\n기능을 선택하세요.\n1. 게임 생성 / 2. 게임 시작 / 3. 최근 결과 / 0. 게임 종료\n응답 : ";
			setnumber();
			switch (getnumber()){
			case 1:
				createGame();
				break;
			case 2:
				startGame();
				break;
			case 3:
				printResult();
				break;
			case 0:
				exitGame();
				break;
			}
		}
	}

	void createGame(){
		cout << "== 게임 생성 ==\n\n정답을 입력하세요 : ";	
		setquestion();
	}
	void startGame() {
		count = 0;
		cout << "== 게임 시작 ==\n게임이 시작되었습니다\n";

		while (1) {
			setcount();
			cout << "\n3자리 숫자를 입력하세요.\n응답 : ";
			int strike = 0;
			int ball = 0;
			setanswer();
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (question[i] == answer[j]) {
						if (i == j) {
							strike++;
						}
						else {
							ball++;
						}
					}
				}
			}
			if (strike == 3) {
				cout << strike << " 스트라이크 " << ball << " 볼\n정답입니다 !\n";
				break;
			}
			else {
				cout << strike << " 스트라이크 " << ball << " 볼\n틀렸습니다 !\n";
			}
		}
	}
	void printResult() {
		cout << "최근 게임의 정답은 " << getquestion() << "입니다.\n이 게임은 "<<count<<"회 만에 정답을 맞췄습니다.\n";

	}
	void exitGame() {
		exit(0);
	}
	
	void setnumber() {
		int a;
		cin >> a;
		number = a;
	}
	int getnumber() {
		return number;
	}
	void setquestion() {
		do {
			question[0] = rand() % 10;
			question[1] = rand() % 10;
			question[2] = rand() % 10;
		} 		
		while ((question[0] == question[1]) || (question[1] == question[2]));
	}
	int getquestion() {
		return 100*(question[0]-81)+10*(question[1]-81)+question[2]-81;
	}
	void setanswer() {
		cin >> answer;
	}
	int getanswer() {
		return (answer[0]-81)*100+(answer[1]-81)*10+answer[2]-81;
	}
	void setcount() {
		count++;
	}
	int getcount() {
		return count;
	}
	

private:
	int count = 0;
	int number;
	char question[4] = { '1','2','3','0' };
	char answer[4] = { 0, };
};


int main() {
	Game g;
	return 0;
}