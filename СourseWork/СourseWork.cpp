#include <iostream>
#include "Koloda.h"
#include <windows.h>
#include"Player.h"
#include"Сroupier.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1521);
	SetConsoleOutputCP(1521);
	srand(time(NULL));

	deck koloda1;
	koloda1.Gen();

	

koloda1.Shaffle();





	//koloda1.Print();
//	cout << endl << endl;
cout << "Введите количество денег на вашем балансе" << endl;
int MyMoney = 0;
cin >> MyMoney;

if (MyMoney < 25) {
	cout << "У вас не достаточно средств" << endl;
}
else {
	int y = 0;
	int MyBid = 0;
	


	
	
	int vibor = 0;
	int h = 0;
	int w = 2;
	while (w != 1) {
		y = 0;
		while (y != 1) {

			cout << "Введите свою ставку(введеное число должно нацело делиться на 5)" << endl;
			cin >> MyBid;
			if (MyBid > MyMoney) {
				cout << "Не достаточно средств" << endl;
			}
			else if ((MyBid % 5) == 0) {
				MyMoney -= MyBid;
				y = 1;
			}
			else {
				cout << "Ошибка" << endl;
			}
		}
		Player My(MyMoney, MyBid, 1, koloda1);
		My.Print();
		int g = 0;
		while (g != 1) {
			cout << "Выберите действие со своми картами(1 - Взять ещё карт; 2 - Играть Дабл; 3 - Играть Сплит; 4 - Отказаться от карт; 0 - Выход)" << endl;
			
			if ((My.GetScore() > 8) && (My.GetScore() < 12)) {
				cout << "Крупье говорит:<<Вы можете использовать дабл>>" << endl;
			}
			cin >> vibor;
			switch (vibor) {
			case 1:
				while (h != 1) {
					My.GetOneKard(koloda1);
					My.Print();

					if (My.GetScore() == 0) {
						h = 1;
					}
					int yesNo1 = 0;
					if (h == 0) {
						cout << "Взять ещё?(1-да; 2-нет)" << endl;
						cin >> yesNo1;
						if (yesNo1 == 2) {
							h = 1;
						}
					}
				}
				g = 1;
				break;
			case 2:
				if (My.PlayDouble(koloda1) == false) {
					break;
				}
				My.Print();
				g = 1;
				break;
			case 3:
				if (My.PlaySplit(koloda1) == false) {
					break;
				}
				My.Print();
				g = 1;
				break;
			case 4:
				My.DealCards();
				My.Print();
				g = 1;
				break;
			case 0:
				break;
			}
		}



		Croupier croup(koloda1);
		croup.Print(true);

		croup.IsWin(My);
		MyMoney = My.GetMoney();

		croup.Print(false);
		My.Print();

		cout << "Хотите выйти из игры?(1 - да; 2 - нет)" << endl;
		cin >> w;
	}



}

}
/*
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	cout << "Масти: ";
	for (char i = 3; i < 7; i++)
		cout << i;
	cout << endl;
	system("pause");
}*/