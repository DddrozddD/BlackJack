#pragma once
#include <iostream>
#include "BasePlayer.h"
#include "Koloda.h"

class Player : public BasePlayer {
private:
	int num;
	int bid;
	int money;
	deck SplitDeck;
	int SplitScore;
	int BidSplit;
	bool isSplit = false;
	bool isBlackJack = false;
public:
	Player() : BasePlayer() {}
	Player(int mon, int stav, int numder, deck& BaseDeck) : money{ mon }, bid{ stav }, num{ numder } {
		BasePlayer::GenKol(BaseDeck);
		if (score == 21) {
			bid += bid + bid / 2;
			money += bid;
			bid = 0;
			score = 0;
		}
	}

	bool PlayDouble(deck& BaseDeck) {
		if ((bid * 2) > money) {
			cout << "������������ �������" << endl;
			return false;
		}
		if (kolodP.GetSize() == 2) {
			for (auto tmp : kolodP.GetKolod()) {
				if (tmp.znach == "�") {
					score -= 10;
				}
			}
		}
		money -= bid;
		bid = bid * 2;
		BasePlayer::PlusKard(BaseDeck);
		BaseDeck.DeleteFirst();
		if (score > 21) {
			score = 0;
		}
		return true;
	}

	bool GetIsSplit() {
		return isSplit;
	}

	
	int GetSplitScore() {
		return SplitScore;
	}

	void SetMoney(int mon) {
		money = mon;
	}
	int GetBid() {
		return bid;
	}
	void SetBid(int Bid) {
		bid = Bid;
	}


	bool PlaySplit(deck& BaseDeck) {
		if ((bid * 2) > money) {
			cout << "������������ �������" << endl;
			return false;
		}

		if (kolodP.GetSize() == 2) {
			for (auto tmp : kolodP.GetKolod()) {
				if (tmp.znach == "�") {
					score -= 10;
				}
			}
		}

		BidSplit = bid;
		money -= bid;
		vector<kard>::iterator My_iter = kolodP.GetOne();
		SplitDeck.Add(My_iter._Ptr->mast, My_iter._Ptr->znach);
		SplitScore += BasePlayer::SetScore(My_iter._Ptr->znach);
		score -= BasePlayer::SetScore(My_iter._Ptr->znach);
		kolodP.DeleteFirst();

		
		SplitDeck.Print();
		cout << endl;

		kolodP.Print();
		cout << endl;
		

		cout << "���������� ����� ����� � ������ ����� " << kolodP.GetKolod().begin() << endl;
		BasePlayer::PlusKard(BaseDeck);
		

		

		kolodP.Print();
		cout << endl;


		cout << "���������� ����� ����� � ������ ����� " << SplitDeck.GetKolod().begin() << endl;
		vector<kard>::iterator My_iter1 = BaseDeck.GetOne();
		SplitDeck.Add(My_iter1._Ptr->mast, My_iter1._Ptr->znach);
		SplitScore += BasePlayer::SetScore(My_iter1._Ptr->znach);
		BaseDeck.DeleteFirst();
		SplitDeck.Print();
		cout << endl;

		int yesNo1 = 2;
	
		while (yesNo1 != 0) {
			cout << "��������� ��� ����� � ������ ����� " << kolodP.GetKolod().begin() << "?(1 - ��, 0 - ���)" << endl;
			cin >> yesNo1;
			if (yesNo1 == 1) {
				BasePlayer::PlusKard(BaseDeck);
				
				kolodP.Print();
				cout << endl;
				if (score > 21) {
					yesNo1 = 0;
					score = 0;
				}
			}
		}

		int yesNo2 = 2;

		while (yesNo2 != 0) {
			cout << "��������� ��� ����� � ������ ����� " << SplitDeck.GetKolod().begin() << "?(1 - ��, 0 - ���)" << endl;
			cin >> yesNo2;
			
			if (yesNo2 == 1) {
				vector<kard>::iterator My_iter3 = BaseDeck.GetOne();
				SplitDeck.Add(My_iter3._Ptr->mast, My_iter3._Ptr->znach);
				SplitScore += BasePlayer::SetScore(My_iter3._Ptr->znach);
				BaseDeck.DeleteFirst();
				SplitDeck.Print();
				cout << endl;
				if (SplitScore > 21) {
					yesNo2 = 0;
					SplitScore = 0;
				}
			}
		}

		isSplit = true;
		return true;
	}
	
	void Print() {
		if (isSplit == false) {
			cout << "����� �" << num << endl;
			cout << "������:" << money << endl;
			cout << "������:" << bid << endl;
			cout << "�����:" << endl;
			kolodP.Print();
			
			cout << "����:" << score << endl << endl;
		}
		else {
			cout << "����� �" << num << endl;
			cout << "������:" << money << endl;
			cout << "������ 1 :" << bid << endl;
			cout << "������ 2 :" << BidSplit << endl;
			cout << "���� �����:" << endl;
 			kolodP.Print();

			cout << "������ �����:" << endl;
			SplitDeck.Print();
			
			cout << "���� ������ ����:" << score << endl;
			cout << "���� ������ ����:" << SplitScore << endl << endl;
		}

	}


	void GetOneKard(deck& BaseDeck) {
		if (kolodP.GetSize() == 2) {
			for (auto tmp : kolodP.GetKolod()) {
				if (tmp.znach == "�") {
					score -= 10;
				}
			}
		}
		vector<kard>::iterator My_iter2 = BaseDeck.GetOne();
		kolodP.Add(My_iter2._Ptr->mast, My_iter2._Ptr->znach);
		score += BasePlayer::SetScore(My_iter2._Ptr->znach);
		BaseDeck.DeleteFirst();

		if (score > 21) {
			score = 0;
		}
	}

	int GetSplitBid() {
		return BidSplit;
	}
	void SetSplitBid(int Bid) {
		BidSplit = Bid;
	}

	int GetMoney() {
		return money;
	}

	void DealCards() {
		BasePlayer::Clear();
		bid = 0;
	}

	~Player() {}
};