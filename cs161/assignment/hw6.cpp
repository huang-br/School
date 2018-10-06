/***********************************************************************************
 * Program: struct.cpp
 * Autho: Brian Huang
 * Date 12/06/2015
 * Description: Creates a schedule based on the users input.
***********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

//bool checker(struct course classes,int num_days[],int num_courses);

struct course{
	string name;
	string *days;
	int start_hour, start_minute;
	int end_hour, end_minute;
};

int main(){
	int *num_days,num_courses,start_hr,end_hr,start_min,end_min;
	string day_name,class_name;
	course *courses;

//Getting the number of courses.
	cout << "How many courses? ";
	cin >> num_courses;
	num_days = new int[num_courses];
	courses=new course[num_courses];

//Getting the course name.
	for(int i=0; i< num_courses; i++){
	cout <<"Enter the course name: ";
	cin >> class_name;
	courses[i].name=class_name;
	//Getting the number of days.
	cout <<"Number of days? ";
	cin >> num_days[i];
	cout << endl;
	courses[i].days=new string[num_days[i]];
	// Getting the day of the week.
		for(int j=0; j < num_days[i]; j++){
			cout << "What days of the week are they on? ";
			cin >> day_name;
			courses[i].days[j] = day_name;
		}
	//Getting the times.
	cout <<"Please use the 24 hour system." << endl;
	cout <<"What hour does this class start? ";
	cin >> start_hr;
	courses[i].start_hour = start_hr;
	cout <<"At what minute does this class start? ";
	cin >> start_min;
	courses[i].start_minute = start_min;
	cout <<"What hour does this class end? ";
	cin >> end_hr;
	courses[i].end_hour = end_hr;
	cout <<"What minute does this class end? ";
	cin >> end_min;
	courses[i].end_minute = end_min;
	}

// Printing the days of the week.
	for(int k=0; k < num_courses; k++){
		cout << courses[k].name << ": " << courses[k].start_hour << ":" << courses[k].start_minute << "-" << courses[k].end_hour << ":" << courses[k].end_minute<< endl;
		for(int l=0; l<num_days[k]; l++){
			cout << courses[k].days[l] << endl;
		}
		cout << endl;
	}
	return 0;
}

/*bool checker(struct course classes, int num_days[], int num_courses)
{
	//What this is trying to do is to check if the days match.
	//The first loop is suppose to establish the class that you
	//are checking. The second loop estabilshes the day and the
	//third establishes the day you are checking against. The 
	//checking happens in the if statement. The statement is
	//suppose to see check a day of a class and see if it is the
	//same as the next class in the struct and run through its days
	//to see if it is equal. Then if it was true then I would run
	//through another loop to check the times.
	for(int i=0; i<num_courses-1; ++i){
		for(int j=0; j<num_days[i]; ++j){
			for(int k=0; k<num_days[i+1]; ++k){
				if (classes[i].days[j]==classes[i+1].days[k]){
					return 0;
				}
			}
		}		
	}		
}*/

