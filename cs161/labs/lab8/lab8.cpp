#include <iostream>

#define COLS 3

using namespace std;

void towers(int disks, int b[][COLS], int from_col, int to_col, int spare){
	if(disks >=1){
		towers(disks-1, b, from_col, spare, to_col)

		towers(disks-1, b, spare, to_col, from_col)
int main(){

