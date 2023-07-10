#pragma once
#include <iostream>
#include "BasePlayer.h"
#include "Koloda.h"
#include "Player.h"

using namespace std;

class Croupier  : public BasePlayer{
public:
	Croupier(deck& BaseDeck) {
		BasePlayer::GenKol(BaseDeck);
		int u = 0;
		while(u != 1){
			if (score <= 16) {
				BasePlayer::PlusKard(BaseDeck);
				BaseDeck.DeleteFirst();
			}
			else {
				u = 1;
			}
		}
		if (score > 21) {
			score = 0;
		}
	}

	void PlusKard(deck& BaseDeck) {
		vector<kard>::iterator My_iter2 = BaseDeck.GetOne();
		kolodP.Add(My_iter2._Ptr->mast, My_iter2._Ptr->znach);
		score += BasePlayer::SetScore(My_iter2._Ptr->znach);
		BaseDeck.DeleteFirst();
		if (score > 21) {
			score = 0;
		}

	}

	void IsWin(Player& player) {
		if (player.GetIsSplit() == false) {
			if (score < player.GetScore()) {
				player.SetMoney((player.GetBid() * 2) + player.GetMoney());
				player.SetBid(0);
			}
			else if (score > player.GetScore()) {
				player.SetBid(0);
			}
			else {
				player.SetMoney(player.GetBid() + player.GetMoney());
				player.SetBid(0);
			}
		}
		else {

			if (score < player.GetSplitScore()) {
				player.SetMoney((player.GetSplitBid() * 2) + player.GetMoney());
				player.SetSplitBid(0);
			}
			else if (score > player.GetSplitScore()) {
				player.SetSplitBid(0);
			}
			else {
				player.SetMoney(player.GetSplitBid() + player.GetMoney());
				player.SetSplitBid(0);
			}
			if (score < player.GetScore()) {
				player.SetMoney((player.GetBid() * 2) + player.GetMoney());
				player.SetBid(0);
			}
			else if (score > player.GetScore()) {
				player.SetBid(0);
			}
			else {
				player.SetMoney(player.GetBid() + player.GetMoney());
				player.SetBid(0);
			}
		}
	}

	~Croupier() {}


	void Print(bool isDark) {
		if (isDark == true) {
			cout << "Крупье" << endl;
			cout << "Карты:" << endl;
			kolodP.PrintFirst();
			cout << "Закрыта" << endl << endl;
		}
		else {
			cout << "Крупье" << endl;
			cout << "Карты:" << endl;
			kolodP.Print();
			cout << "Очки:" << score << endl << endl;
		}
	}



};