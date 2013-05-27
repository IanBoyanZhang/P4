//#include "BaseBogglePlayer.h"
#include "player.h"
#include <vector>
#include <string>
using namespace std;
std::vector<int> location;

//void BogglePlayer::buildLexicon(const set<string>& word_list);

void BogglePlayer::setBoard(unsigned int rows, unsigned int cols, string** diceArray){
	//destroyBoard();
	//createBoard(rows, cols);
	for(unsigned int r=0; r<rows; r++){
		for(unsigned int c=0; c<cols; c++){
			this->boboard[r][c] = diceArray[r][c];
			cout << this->boboard[r][c] << endl;	
		}
	}
}



//bool BogglePlayer::getAllValidWords(unsigned int minimum_word_length, set<string>* words);
//bool BogglePlayer::isInLexicon(const string& word_to_check);

BogglePlayer::vector<int> isOnBoard(const string& word_to_check){
int rows = sizeof(boboard) / sizeof(boboard[0]);
int cols = sizeof(boboard[0]) / sizeof(boboard[0][0]);
bool iffind = false;
	for(unsigned int r=0; r<rows; r++){
		for(unsigned int c=0; c<cols; c++){
			if(boboard[r][c]==word_to_check[0]){
				location[0]=r*cols+c;
				iffind = findword(r, c, word_to_check, 1);	
			}
		}
	}
if (!iffind)
	return location.clear();
else
	return location;

}

bool findword(int irow, int icol, const string& word_to_check, int i){
	int rows = sizeof(boboard) / sizeof(boboard[0]);
	int cols = sizeof(boboard[0]) / sizeof(boboard[0][0]);
	if(irow-1<0) 
		rstart=irow;
	else 
		rstart=irow-1;
	if(icol-1<0)
		cstart=icol;
	else 
 		cstart=icol-1;
	if(irow+1>borows) 
		rend=irow;
	else 
		rend=irow+1;
	if(icol+1>bocols)
		cend=icol;
	else 
 		cend=icol+1;
	for(int r=rstart; r<=rend; r++){
	for(int c=cstart; c<=cend; c++){
		if (boboard[r][c]==word_to_check[i]){
			location[i]=r*cols+c;
			if(i<word_to_check.size-1)
				return findword(r, c, word_to_check[i+1]);
			else
				return true;
		}
		return false;
	}
	}

}
//void  BogglePlayer::getCustomBoard(string** &new_board, unsigned int *rows, unsigned int *cols);
