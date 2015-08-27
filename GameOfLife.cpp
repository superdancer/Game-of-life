#include "GameOfLife.hpp"
#include <iostream>
#include<time.h>
#include <unistd.h>
using namespace std;
  const int row=25,col=50;
  int arr[row][col];
GameOfLife::GameOfLife()
{
    a=12,b=13,c=14,d=15;
    arr[a][b]=1,arr[a][c]=1,arr[a][d]=1,arr[b][c]=1,arr[b][d]=1,arr[c][d]=1,arr[a][a]=1,arr[b][b]=1,arr[c][c]=1;
}

GameOfLife::~GameOfLife()
{
}


int GameOfLife::aliveNeighbours(int i,int j)
{
    int count=0;
    cout<<"    "<<endl;
    cout<<arr[i-1][j-1]<<arr[i-1][j]<<arr[i-1][j+1]<<endl;
    cout<<arr[i][j-1]<<" "<<arr[i][j+1]<<endl;
    cout<<arr[i+1][j-1]<<arr[i+1][j]<<arr[i+1][j+1]<<endl;
    count=arr[i-1][j-1]+arr[i][j-1]+arr[i+1][j-1]+arr[i+1][j]+arr[i-1][j]+arr[i+1][j+1]+arr[i][j+1]+arr[i-1][j+1];
    return count;
}

bool GameOfLife::isEdge(int i,int j)
{

    if(0==i||0==j||row-1==i||col-1==j) return true;
    else return false;
}
int GameOfLife::calcNextGeneration(int m,int n)
{
    int num;
    if(isEdge(m,n))
    {
	arr[m][n]=0;
    }
    else
    {
	num=aliveNeighbours(m,n);
	if (num<2||num>3)
	{
	    arr[m][n]=0;
	}
	else if(2==num)
	{
	    if(0==arr[m][n]) arr[m][n]=0;
	    else arr[m][n]=1;
	}
	else if(3==num)
	{
	    arr[m][n]=1;
	}
    }
    return arr[m][n];
}
void GameOfLife::initializeArray()
{
    cin>>a>>b>>c>>d;
    arr[a][b]=1,arr[a][c]=1,arr[a][d]=1,arr[b][c]=1,arr[b][d]=1,arr[c][d]=1,arr[a][a]=1,arr[b][b]=1,arr[c][c]=1,arr[d][d]=1,arr[c][a]=1,arr[b][a]=1;

}
