#include "player.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void main(){
string** diceArray ={{"b","p","l"},{"i","q","a"},{"r","e","p"}};
BogglePlayer::setBoard(3, 3, diceArray);
std::vector<int> result = BogglePlayer::isOnBoard("lap");
for(int i = 0; i < 3; i++)
	cout << result[i] << endl;
}

