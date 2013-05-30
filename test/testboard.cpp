#include "player.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){
//BogglePlayer boggle;

/*  BaseBogglePlayer * p = new BogglePlayer();
  set<string> lex;
  string wordA("a");
  string wordX("x");
  lex.insert(wordA);
  lex.insert("z");
  string row0[] = {"D","C"};
  string row1[] = {"b","A"};
  string* board[] = {row0,row1};
  set<string> words;
  vector<int> locations;

  p->buildLexicon(lex);

  p->setBoard(2,2,board);
*/

BogglePlayer * boggle = new BogglePlayer();
//string row0[] = {"b","pp","l"};
string row0[] = {"le","g","e"};
//string row1[] = {"i","e","a"};
string row1[] = {"i","boa","bog"};
//string row2[] = {"r","e","p"};
string row2[] = {"r","d","j"};
//string** diceArray ={{"b","p","l"},{"i","q","a"},{"r","e","p"}};
string* diceArray[] = {row0, row1, row2};
boggle->setBoard(3, 3, diceArray);
std::vector<int> result = boggle->isOnBoard("boggleboard");
if(result.empty())
   	cout << "empty vector" << endl;
else
{
for(int i = 0; i < result.size(); i++)
	cout << "result is " << result[i] << endl;
}
return 0;
}



