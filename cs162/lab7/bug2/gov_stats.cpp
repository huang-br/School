#include "nation.h"
#include "state.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
   int which_state;
   state s[50];
#ifdef DEBUG
   string name;
   cout << "Name? ";
   cin >> name;
#else
#endif
   
   cout << "Which state do you want to set the pop? (1-50):";
   cin >> which_state;
#ifdef DEBUG
   s[which_state-1].set_pop(300000);
   s[which_state-1].set_name(name);
   s[which_state-1].display_pop();
#else
   s[which_state].set_pop(300000);

   s[which_state].display_pop();
#endif
   return 0;
}
