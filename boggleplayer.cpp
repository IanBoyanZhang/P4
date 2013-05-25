#include "BaseBogglePlayer.h"
#include "BogglePlayer.h"


//void BogglePlayer::buildLexicon(const set<string>& word_list);

void BogglePlayer::setBoard(unsigned int rows, unsigned int cols, string** diceArray){
	//destroyBoard();
	//createBoard(rows, cols);
	for(unsigned int r=0; r<rows; r++){
		for(unsigned int c=0; c<cols; c++){
			this->boboard[r][c] = diceArray[r][c];

		}
	}
}



//bool BogglePlayer::getAllValidWords(unsigned int minimum_word_length, set<string>* words);
//bool BogglePlayer::isInLexicon(const string& word_to_check);
//BogglePlayer::vector<int> isOnBoard(const string& word_to_check);
//void  BogglePlayer::getCustomBoard(string** &new_board, unsigned int *rows, unsigned int *cols);
