#include "boggleutil.h"
#include <queue>
#include <string>
using namespace std;

void Graph::BFS(std::string s, int irow, int icol){
queue<std::string> Q;
bool **explored = new bool [borows][bocols];
for(int r=0; r<borows; r++){
	for (int c=0; c<bocols; c++){
		explored[r][c]=false;
	}
}
Q.enqueue(s);
explored[irow][icol]=true;
while (!Q.isEmpty()){
	std::string v = Q.dequeue();
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
		if(!explored[r][c])
			Q.enqueue(boboard[r][c]);
			explored[r][c]=true;
	}

}
}
delete [][] explored;
}



