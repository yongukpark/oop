#include <iostream>
#include <random>
using namespace std;



class Fighter {
private:
	string name = "";
	int life = 0;
	int winCount = 0;
public:

	Fighter(string name, int life, int count) {
		this->name = name;
		this->life = life;
		this->winCount = count;
	}
	Fighter() {}
	int getRandomChoice() {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int>dis(1, 3);

		return dis(gen);
	}

	string getNameI() {
		return this->name;
	}

	int getLife() {
		return this->life;
	}

	void setLife() {
		life = 5;
	}

	int getWinCount() {
		return winCount;
	}

	Fighter& operator+=(int a) { // 라이프 증가
		this->life += a;
		return *this;
	}

	Fighter& operator-=(int a) { // 라이프 감소
		this->life -= a;
		return *this;
	}

	Fighter& operator++(int) { // 라운드 승리 횟수 증가
		this->winCount++;
		return *this;
	}

	friend ostream& operator << (ostream&, const Fighter&);
};

ostream& operator << (ostream& os, const Fighter& f) {
	os << f.name << "의 현재 라이프 : " << f.life;
	return os;
}

class Game {
private:
	Fighter player;
	Fighter computer;
public:
	Game() {
		player = Fighter("플레이어", 5, 0);
		computer = Fighter("컴퓨터", 5, 0);

		while (1) {
			player.setLife();
			computer.setLife();

			gameStart();

			if (player.getLife() <= 0 || computer.getLife() >= 10) {
				cout << "컴퓨터 승\n";

				computer++;
			}
			else {
				cout << "플레이어 승\n";
				player++;
			}
			cout << '\n';

		}


	}

	void gameStart() {
		cout << "플레이어 라운드 승 : " << player.getWinCount() << '\n';
		cout << "컴퓨터 라운드 승 : " << computer.getWinCount() << "\n\n";

		while (player.getLife() > 0 && player.getLife() < 10 && computer.getLife() > 0 && computer.getLife() < 10) {
			cout << "행동 선택: 1. 공격 / 2. 반격 / 3. 회복 = ";
			int playerChoice;
			cin >> playerChoice;
			int computerChoice = computer.getRandomChoice();
			cout << "\n컴퓨터의 선택 : " << computerChoice << '\n';

			switch (playerChoice) {
			case 1:
				if (computerChoice == 1) {
					player -= 1;
					computer -= 1;
				}
				else if (computerChoice == 2) {
					player -= 1;
				}
				else {
					computer -= 2;
				}
				break;
			case 2:
				if (computerChoice == 1) {
					computer -= 1;
				}
				else if (computerChoice == 3) {
					computer += 2;
				}
				break;
			case 3:

				if (computerChoice == 1) {
					player -= 2;
				}
				else if (computerChoice == 2) {
					player += 2;
				}
				else {
					player += 1;
					computer += 1;
				}
				break;
			}

			cout << player << '\n';
			cout << computer << "\n\n";

		}

	}

};

int main() {
	Game start;

	return 0;
}