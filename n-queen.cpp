#include <iostream>
#include <stdlib.h>
using namespace std;

#define N 100

int solution[N][N];

class NQueensBT
{
  public:

  /* initialize the solution 2D with all zero's */
  NQueensBT(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        solution[i][j] = 0;
      }
    }
  }

  void solve(int n) {
    /* 0 is the initial position of queen solution[0][0] */
    if(placeQueens(0, n)){
      //print the result
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << solution[i][j] <<' ';
        }
        cout << endl;
      }
    }else{
      cout <<"NO SOLUTION EXISTS" << endl;
    }
  }

  bool placeQueens(int queen, int n) {
    // will place the Queens one at a time, for column wise
    if(queen==n){
      //if we are here that means we have solved the problem
      return true;
    }
    for (int row = 0; row < n; row++) {
      // check if queen can be placed row,col
      if (canPlace(solution, row, queen)) {
        // place the queen
        solution[row][queen] = 1;
        // solve  for next queen
        if(placeQueens(queen+1, n)){
          return true;
        }
        //if we are here that means above placement didn't work
        //BACKTRACK
        solution[row][queen]=0;
      }
    }
    //if we are here that means we haven't found solution
    return false;

  }

  // check if queen can be placed at matrix[row][column]
  bool canPlace(int matrix[][N], int row, int column) {
    // since we are filling one column at a time,
    // we will check if no queen is placed in that particular row
    for (int i = 0; i < column; i++) {
      if (matrix[row][i] == 1) {
        return false;
      }
    }
    // we are filling one column at a time,so we need to check the upper and
    // diagonal as well
    // check upper diagonal
    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--) {
      if (matrix[i][j] == 1) {
        return false;
      }
    }

    // check lower diagonal
    for (int i = row, j = column; i < N && j >= 0; i++, j--) {
      if (matrix[i][j] == 1) {
        return false;
      }
    }
    // if we are here that means we are safe to place Queen at row,column
    return true;
  }

};


int main(int argc, char **argv)
{
    if( argc < 2) {
      cout << endl;
      cout <<"Error!!!, Enter the Number of Queen: " << endl;
      cout << endl;
      exit(0);
    }
    int n = atoi(argv[1]);
    NQueensBT *q = new NQueensBT(n);
    q->solve(n);

    delete q;

    return 0;
}
