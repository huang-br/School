#include "state.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
   state s[50];
   int which_state;
#ifdef DEBUG

#else
   char str1[] = "Oregon";
#endif
   
   cout << "Which state do you want? (1-50)";
   cin >> which_state;

   s[which_state-1].set_pop(300000);

#ifdef DEBUG
   s[which_state-1].setName();
#else
   s[which_state-1].set_name(str1);
#endif

   s[which_state-1].display_pop();

   return 0;
}
