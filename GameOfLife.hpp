#ifndef HIKER_INCLUDED
#define HIKER_INCLUDED

class GameOfLife
{
public:

  int a,b,c,d;
  explicit GameOfLife();
  ~GameOfLife();

  int aliveNeighbours(int i,int j);
  bool isEdge(int i,int j);
  int calcNextGeneration(int m,int n);
  void initializeArray();

  GameOfLife(const GameOfLife &) = delete;
  GameOfLife & operator=(const GameOfLife &) = delete;
};

#endif
