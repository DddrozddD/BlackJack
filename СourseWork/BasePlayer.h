#pragma once
#include <iostream>
#include "Koloda.h"


class BasePlayer {
protected:
	deck kolodP;
	int score;
	
public:

	BasePlayer() : kolodP() {}
	BasePlayer(deck& dop_kol, int dop_sc) : score{ dop_sc } {
		kolodP = dop_kol;
	}

	void SetKolod(deck& dop_kol) {
		kolodP = dop_kol;
	}

	deck GetKolod() {
		return kolodP;
	}

	void SetScore(int ochk) {
		score = ochk;
	}

	int GetScore() {
		return score;
	}
	void Clear() {
		kolodP.Clear();
		score = 0;
	}

	int SetScore(string dop_mast) {
		
			if (dop_mast == "2") {
				return 2;
			}
			else if (dop_mast == "3") {
				return 3;
			}
			else if (dop_mast == "4") {
				return  4;
			}
			else if (dop_mast == "5") {
				return  5;
			}
			else if (dop_mast == "6") {
				return  6;
			}
			else if (dop_mast == "7") {
				return  7;
			}
			else if (dop_mast == "8") {
				return  8;
			}
			else if (dop_mast == "9") {
				return  9;
			}
			else if (dop_mast == "10") {
				return  10;
			}
			else if (dop_mast == "Â") {
				return  10;
			}
			else if (dop_mast == "Ä") {
				return  10;
			}
			else if (dop_mast == "Ê") {
				return  10;
			}
			else if (dop_mast == "Ò") {
				return  1;
			}
		
		
	}

	int SetScoreForGen(string dop_mast) {
		if (dop_mast == "2") {
			return 2;
		}
		else if (dop_mast == "3") {
			return  3;
		}
		else if (dop_mast == "4") {
			return  4;
		}
		else if (dop_mast == "5") {
			return  5;
		}
		else if (dop_mast == "6") {
			return 6;
		}
		else if (dop_mast == "7") {
			return  7;
		}
		else if (dop_mast == "8") {
			return  8;
		}
		else if (dop_mast == "9") {
			return  9;
		}
		else if (dop_mast == "10") {
			return 10;
		}
		else if (dop_mast == "Â") {
			return  10;
		}
		else if (dop_mast == "Ä") {
			return  10;
		}
		else if (dop_mast == "Ê") {
			return  10;
		}
		else if (dop_mast == "Ò") {
			return  11;
		}
	}

	void GenKol(deck& baseDeck) {

		for (int i = 0; i < 2; i++) {
			vector<kard>::iterator My_iter = baseDeck.GetOne();
			kolodP.Add(My_iter._Ptr->mast, My_iter._Ptr->znach);
			score += SetScoreForGen(My_iter._Ptr->znach);
			baseDeck.GetOne();
			baseDeck.DeleteFirst();
		}
	}

	void PlusKard(deck& BaseDeck) {


		if (kolodP.GetSize() == 2) {
			for (auto tmp : kolodP.GetKolod()) {
				if (tmp.znach == "Ò") {
					score -= 10;
				}
			}
		}
		vector<kard>::iterator My_iter;

		My_iter = BaseDeck.GetOne();
		kolodP.Add(My_iter._Ptr->mast, My_iter._Ptr->znach);
		score += SetScore(My_iter._Ptr->znach);
		BaseDeck.DeleteFirst();

	}



	~BasePlayer() {}
};