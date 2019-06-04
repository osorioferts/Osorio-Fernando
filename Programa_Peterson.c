#include <stdio.h>
#include <stdlib.h>

using namespace std;

int FALSE=0;
int TRUE=1;
const int N=2;
int turn;		
int interested[N];	

void enter_region(int process)	
{
  int other;	
  other=1-process;	
  interested[process]=TRUE;	
  turn=process;	
  while((turn==process)&&(interested[other]==TRUE));
}

void leave_region(int process)	
{
  interested[process]=FALSE;
}

void p()
{
  while(1){
    cout<<"p seccion no critica"<<endl;
    enter_region(0);
    cout<<"p seccion critica"<<endl;
    leave_region(0);
    return p;
  }
}

void q()
{

  while(1){
    cout<<"q seccion no critica"<<endl;
    enter_region(1);
    cout<<"q seccion critica"<<endl;
    leave_region(1); 
    return q;
  }
}

main() {
  cobegin {
    p();
    q();  
    return 0;
  }
}
