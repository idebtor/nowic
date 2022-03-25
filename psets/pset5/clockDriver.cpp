/* 
* C++ for C Coders & Data Structures
* Lecture note by idebtor@gmail.com
* This code explains:
*   - struct and its initialization
*   - using alias
*   - pointer to struct
*   - new/delete
*	- optional argument
*	- SIIS(Separation of Interface and Implementation)
*	- NMN(No Magic Number)
*
* Created by idebtor@gmail.com 
*/
#include "clock.h"

int main (void) {
  pClock clk = new Clock {11, 58, 56};
  for(int i = 0; i < 6; ++i) {
      tick(clk);
      show(clk);
  }
  runs(clk, '\r');
  delete clk;
  return 0;
}

