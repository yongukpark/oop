#include <iostream>]
#include <random>
#include <iomanip>
#include <string>
using namespace std;

class Game {
private:
	int total_num = 0;
	int total_price = 0;
public:
	Game(){}
	Game(int num1, int num2) {
		cout << "\n\n=============================== Game Start ===============================\n\n";
		total_num = num1;
		total_price = num2;
	}

	void setNum(int a) {
		total_num -= a;
	}
	void setPrice(int a) {
		total_price += a;
	}

	int getNum() {
		return total_num;
	}
	int getPrice() {
		return total_price;
	}
};

class Player : public Game{
private:
	string name;
	int player_num;
	int total_num;
	int total_price;
public:
	Player(string name, int num1 , Game& g) {
		this->name = name;
		player_num = num1;
		total_num = g.getNum();
		total_price = g.getPrice();
	}
	void show() {
		cout << setw(2) << player_num <<"번: "<<setw(7) << name<< " | ";
	}
	void setName() {
		this->name = "탈락";
	}
	int getNum() {
		return this->player_num;
	}
	string getName() {
		return this->name;
	}
};


int main() {
	
	default_random_engine engine{ static_cast<unsigned int> (time(0)) };
	uniform_int_distribution<unsigned int> randomNum(1, 55);	
	
	Game g(55, 0);

	string arr[55] = { "공병학", "정지원", "조형우", "이지윤", "정동주", "이예진", "고나현", "주수진", "강신정", "강정연",
						 "권민우", "김동호", "김민범", "김민수", "김영진", "김욱권", "김지웅", "김진성", "노우현", "도가현",
						 "문순원", "박윤서", "박지호", "박찬혁", "백권희", "손계영", "신서현", "안나겸", "안시헌", "엄수빈",
						 "오다솔", "유인선", "윤찬혁", "이기문", "이승우", "이주한", "이태호", "이희선", "임재훈", "임준현",
						 "임찬우", "장승운", "정건우", "정교원", "정영락", "조민규", "조희승", "조희원", "천정익", "최지우",
						 "한동헌", "한민재", "김나현", "유성환", "김태간" };

	Player* playerArr[55];

	int check[56] = { 0, };
	int start_count = 0;
	while(start_count<55){
		int a = randomNum(engine);
		if (check[a] == 0) {
			Player* p = new Player(arr[start_count], a, g);
			playerArr[start_count] = p;
			start_count++;
			check[a] = 1;
		}
	}

	for (int i = 0; i < 55; i++) {
		playerArr[i]->show();
		if ((i + 1) % 5 == 0) {
			cout << '\n';
		}
	}
	cout << "\n============================ 참가인원 : " << g.getNum() << "명 =============================";
	cout << "\n============================ 총  상금 \\ " << g.getPrice() << "억 =============================\n";

	srand(time(0));

	int dice = (rand() % 6) + 2;
	cout << "|. 주사위(2 ~ 7) 게임 : " << dice << "\n\n";
	int dice_count = 0;
	

	for (int i = 0; i < 55; i++) {
		if ((playerArr[i]->getNum() % dice) == 0) {
			playerArr[i]->setName();
			dice_count++;
		}
		playerArr[i]->show();
		if ((i + 1) % 5 == 0) {
			cout << '\n';
		}
	}
	g.setNum(dice_count);
	g.setPrice(dice_count);
	cout << "\n============================ 참가인원 : " << g.getNum() << "명 =============================";
	cout << "\n============================ 총  상금 \\ " << g.getPrice() << "억 =============================\n";



	const int prime_arr[16] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53 };
	const int non_prime_arr[39] = { 1,4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30,32,33,34,35,36,38,39,40,42,44,45,46,48,49,50,51,52,54,55 };
	cout << "||. 프라임 게임 : 소수 or 합성수\n\n";
	while (1) {
		cout << "다음 중 선택하세요\n1) 소수 2) 합성수  : ";
		int prime_check;
		cin >> prime_check;

		int prime_count = 0;
		try {
			if (prime_check == 1) {
				for (int i = 0; i < 55; i++) {
					for (int j = 0; j < 16; j++) {
						if (playerArr[i]->getNum() == prime_arr[j]) {
							if (playerArr[i]->getName() != "탈락") {
								playerArr[i]->setName();
								prime_count++;
							}
							break;
						}
					}
					playerArr[i]->show();
					if ((i + 1) % 5 == 0) {
						cout << '\n';
					}
				}
				g.setNum(prime_count);
				g.setPrice(prime_count);
				cout << "\n============================ 참가인원 : " << g.getNum() << "명 =============================";
				cout << "\n============================ 총  상금 \\ " << g.getPrice() << "억 =============================\n";
				break;
			}
			else if (prime_check == 2) {
				for (int i = 0; i < 55; i++) {
					for (int j = 0; j < 39; j++) {
						if (playerArr[i]->getNum() == non_prime_arr[j]) {
							if (playerArr[i]->getName() != "탈락") {
								playerArr[i]->setName();
								prime_count++;
							}
							break;
						}
					}
					playerArr[i]->show();
					if ((i + 1) % 5 == 0) {
						cout << '\n';
					}
				}
				g.setNum(prime_count);
				g.setPrice(prime_count);
				cout << "\n============================ 참가인원 : " << g.getNum() << "명 =============================";
				cout << "\n============================ 총  상금 \\ " << g.getPrice() << "억 =============================\n";
				break;
			}
			else {
				throw out_of_range("다시 입력하여 주세요\n");
			}
		}
		catch (out_of_range& i){
			cout << i.what();
		}
	}

	cout << "|||. 제비뽑기 게임 : 단 한명\n\n";
	
	int res_num = 0;
	int res_count = 0;

	while (1) {
		srand(time(0));
		int res = rand() % 55 + 1;
		for (int i = 0; i < 55; i++) {
			if ((playerArr[i]->getNum() == res) && (playerArr[i]->getName() != "탈락")) {
				res_num = i+1;
				break;
			}
		}
		if (res_num != 0) {
			break;
		}
	}


	for (int i = 0; i < 55; i++) {
		if (i+1 != res_num) {
			if (playerArr[i]->getName() != "탈락") {
				playerArr[i]->setName();
				res_count++;
			}
		}
		playerArr[i]->show();
		if ((i + 1) % 5 == 0) {
			cout << '\n';
		}
	}

	g.setNum(res_count);
	g.setPrice(res_count);
	cout << "\n최종우승자 : ";
	playerArr[res_num - 1]->show();
	cout << "\n\n";
	cout << "\n============================ 참가인원 : " << g.getNum() << "명 =============================";
	cout << "\n============================ 총  상금 \\ " << g.getPrice() << "억 =============================\n";

}