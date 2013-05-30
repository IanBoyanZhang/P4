//#include "BaseBogglePlayer.h"
#include "player.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
std::vector<int> location;
int borows, bocols;
string** boboard;

//void BogglePlayer::buildLexicon(const set<string>& word_list);

void BogglePlayer::setBoard(unsigned int rows, unsigned int cols, string** diceArray){
borows = rows;
bocols = cols;
  boboard = new std::string*[rows];
  for(unsigned int r=0; r < rows; r++) {
    boboard[r] = new std::string[cols];
  }

	for(unsigned int r=0; r<rows; r++){
		for(unsigned int c=0; c<cols; c++){
		//	this->boboard[r][c] = diceArray[r][c];
			boboard[r][c] = diceArray[r][c];
			//std::cout << boboard[r][c] << std::endl;	
			std::cout << diceArray[r][c] << " ";
		}
	}
	cout << endl;
}



//bool BogglePlayer::getAllValidWords(unsigned int minimum_word_length, set<string>* words);
//bool BogglePlayer::isInLexicon(const string& word_to_check);

vector<int> BogglePlayer::isOnBoard(const string& word_to_check){
//int rows = sizeof(this->boboard) / sizeof(this->boboard[0]);
//int cols = sizeof(this->boboard[0]) / sizeof(this->boboard[0][0]);
bool iffind = false;
int idx;
	for(unsigned int r=0; r<borows; r++){
		for(unsigned int c=0; c<bocols; c++){
			for(idx=0; idx<word_to_check.size()&&idx<boboard[r][c].size(); idx++)
				if(boboard[r][c][idx]!=word_to_check[idx]){
					break;
				}	
			if(idx==boboard[r][c].size()){

				location.push_back(r*bocols+c);
				iffind = BogglePlayer::findword(r, c, word_to_check, idx);	
			}

		}
	}
if (!iffind){
	location.clear();
	return location;
}
else
{
//	for (std::vector<int>::iterator it = location.begin(); it!=location.end(); it++)
//		cout << *it << "" << endl;
	return location;
}
}

bool BogglePlayer::findword(int irow, int icol, const string& word_to_check, int i){
	int rstart, cstart, rend, cend;
	int idx, l=1;
	if(irow-1<0) 
		rstart=irow;
	else 
		rstart=irow-1;
	if(icol-1<0)
		cstart=icol;
	else 
 		cstart=icol-1;
	if(irow+1>borows-1) 
		rend=irow;
	else 
		rend=irow+1;
	if(icol+1>bocols-1)
		cend=icol;
	else 
 		cend=icol+1;
//	cerr << "irow is " << irow << " icol is " << icol << " rstart is " << rstart << "rend is " << rend << " cstart is " << cstart << " cend is " << cend << endl;  
//	cerr << "i is " << i << endl;
	for(int r=rstart; r<=rend; r++){
		for(int c=cstart; c<=cend; c++){
			for(idx=0; idx<boboard[r][c].size()&&i<word_to_check.size(); idx++, i++)	
				if (boboard[r][c][idx]!=word_to_check[i]){
					break;
				}
//			cerr << "boboard is " << boboard[r][c] << endl;
//			cerr << "idx is " << idx << endl;
//			cerr << "boboard size is " << boboard[r][c].size() << endl;
			if(idx==boboard[r][c].size()){
				location.push_back(r*bocols+c);
//				cerr << "i is " << i << endl;;
//				cerr << "word_to_check size " << word_to_check.size()<< endl;;
//				cerr << "location is " << r*bocols+c << endl;;
				if(i<word_to_check.size()){
					return findword(r, c, word_to_check, i);
}
				else
					return true;
			}
		}
	}
		return false;

}
//void  BogglePlayer::getCustomBoard(string** &new_board, unsigned int *rows, unsigned int *cols);
