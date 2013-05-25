#include <queue>

queue<string> myqueue;

class Graph{
private:
std::string **boboard;

public:
Graph(unsigned int, unsigned int, string**);
~Graph();
//bool isConnected(string, string);
void BFS(string);
}

Graph::Graph(unsigned int rows, unsigned int cols, string** diceArray){

for(unsigned int r=0; r<rows; r++){
		for(unsigned int c=0; c<cols; c++){
			this->boboard[r][c] = diceArray[r][c];

		}
	}
}

Graph::~Graph(){
			delete [][] boboard;
}
