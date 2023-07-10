#pragma once
#include <iostream>
#include <map>
#include <string>
#include <random>
#include <vector>


using namespace std;



class kard {
public:
	char mast;
	string znach;

	kard() {}
	kard(char dop_mast, string dop_znach) {
		mast = dop_mast;
		znach = dop_znach;
	}

	


	void Print() {
		
		if (znach == "10") {
			cout << " _________ " << endl;
			cout << "|         |" << endl;
			cout << "|" << znach << mast << "      |" << endl;
			cout << "|         |" << endl;
			cout << "|    "<< mast <<"    |" << endl;
			cout << "|         |" << endl;
			cout << "|      " << znach << mast << "|" << endl;
			cout << "|_________|" << endl;
		}
		else {
			cout << " _________ " << endl;
			cout << "|         |" << endl;
			cout << "|" << znach << mast << "       |" << endl;
			cout << "|         |" << endl;
			cout << "|    " << mast << "    |" << endl;
			cout << "|         |" << endl;
			cout << "|       " << znach << mast << "|" << endl;
			cout << "|_________|" << endl;
		}
		cout << endl;
	}

	~kard() {}

};
class deck {
private:
	vector<kard> kards;


	static const string znachK[13];
public:
	deck() {}

	void Gen() {
		char j = 3;
		for (int i = 0; i < 52; i++) {
			for (int u = 0; u < 13; u++) {
				kard dop_kard{ j, znachK[u] };
				kards.push_back(dop_kard);
				i++;
			}
			j++;
		}
	}

	void Add(char dop_mast, string dop_znach) {
		kard dop_k (dop_mast, dop_znach);
		
		kards.push_back(dop_k);
	}

	deck& operator =(deck& oper) {
		kards = oper.kards;
		return *this;
	}

	deck(vector<kard>::iterator dop_iter) {
		kard dop_kard(dop_iter._Ptr->mast, dop_iter._Ptr->znach);
		kards.push_back(dop_kard);
	}

	

	vector<kard>::iterator GetOne() {

		vector<kard>::iterator MyIter1 = kards.begin();
		

		return MyIter1;
	}
	
	void DeleteFirst() {
		vector<kard>::iterator MyIter1 = kards.begin();
		kards.erase(MyIter1);
	}

    vector<kard> GetKolod() {
		return kards;
	}
	int GetSize() {
		return kards.size();
	}

	void Clear() {
		kards.clear();
	}

	void Shaffle() {
		vector<kard>::iterator My_iter = kards.begin();
		vector<kard> dop_deck(kards);
		vector<kard>::iterator dop_iter = dop_deck.begin();
		int dop = 0;
		int dop1 = 0;
		for (; My_iter != kards.end(); My_iter++) {
			dop1 = rand() % 52;
			dop_iter._Ptr->mast = My_iter._Ptr->mast;
			dop_iter._Ptr->znach = My_iter._Ptr->znach;
			My_iter._Ptr->mast = kards[dop1].mast;
			My_iter._Ptr->znach = kards[dop1].znach;
			kards[dop1].mast = dop_iter._Ptr->mast;
			kards[dop1].znach = dop_iter._Ptr->znach;
			dop++;
		}

	}
	void Print() {
		
		for (auto tmp : kards) {
			tmp.Print();
		}
	}

	void PrintFirst() {
		vector<kard>::iterator MyIter = kards.begin();
		MyIter._Ptr->Print();
		
	}

	~deck() {
	}
};


const string deck::znachK[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Â", "Ä", "Ê", "Ò" };

ostream& operator <<(ostream& out, const vector<kard>::iterator& sourth) {
	out << sourth._Ptr->znach << " " << sourth._Ptr->mast;
	return out;
}