#include <stdio.h>
#include <stdlib.h>

using namespace std;

int wantp = 0;
int wantq = 0;
int turn = 1;

void p()
{
    while (1) 
    {
      cout << "process p non-critical section\n";
      wantp = 1;
      while (wantq){
        if (turn == 2)
          {
          wantp = 0;
          while (!(turn == 1));
          wantp = 1;
          }
      }         

      cout << "process p critical section\n";
      turn = 2;
      wantp = 0;
    }
    return p;
}

void q()
{
    while (1) 
    {
      cout << "process q non-critical section\n";
      wantq = 1;
      while (wantp){
        if (turn == 1)
          {
          wantq = 0;
          while (!(turn == 2));
          wantq = 1;
        }
      }  
      cout << "process q critical section\n";
      turn = 1;
      wantq = 0;
    }
    return q;
}

main() {
  cobegin {
    p();
    q();
    return 0;
  }
}
