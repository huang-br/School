#include "nation.h"
#include "state.h"
#include <iostream>
using namespace std;

int main() {
   nation n;
   char name[100];
#ifdef DEBUG
   state s[5];
#else
   state s;
#endif

   for(int i=0; i<5; i++) {
       cout << "Enter the state name: ";
       cin.getline(name,100);
#ifdef DEBUG
       s[i].set_name(name);
#else
       s.set_name(name);
#endif

#ifdef DEBUG
       n.set_state(s[i],i);
#else
       n.set_state(s,i);
#endif
   }

   for(int i=0; i<5; i++)
       n.getstate(i).display_name();

   return 0;
}
