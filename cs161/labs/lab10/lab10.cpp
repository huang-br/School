#include <iostream>
#include <string>

using namespace std;

struct vehicle{
	string name;
	int wheels;
	int doors;
	int power; 
};

int main(){
	//Declaring variables
	int vehicle_wheels, vehicle_doors, vehicle_power, num_people, *num_vehicle;
	string vehicle_name;
	vehicle **v;

	cout << "How many people are in the house? ";
	cin >> num_people;
	num_vehicle = new int[num_people];
	
	//Making the struct size
	v= new vehicle*[num_people];

	for(int i=0; i<num_people; ++i){
		//Getting the number of vehicles
		cout <<"Person " << i+1 <<" How many vehicles? ";
		cin >> num_vehicle[i];
		v[i]=new vehicle[num_vehicle[i]];
		for(int j=0; j<num_vehicle[i]; j++){
			cout <<"Enter the name of your vehicle: ";
			cin >> vehicle_name;
			v[i][j].name = vehicle_name;
			//Getting number of wheels
			cout <<"How many wheels? ";
			cin >> vehicle_wheels;
			v[i][j].wheels = vehicle_wheels;
			//Getting number of doors
			cout <<"How many doors? ";
			cin >> vehicle_doors;
			v[i][j].doors = vehicle_doors;
		}
	}
	//Printing
	for(int k=0; k<num_people; k++){
		cout << "Person " << k+1 << endl;
		for (int l=0; l<num_vehicle[k]; l++){
			cout <<" Name: " << v[k][l].name << " ";
			cout <<" Wheels: " << v[k][l].wheels<< " ";
			cout <<" Doors: " << v[k][l].doors<< " " << endl;
		}
		cout << endl; 
	}
	return 0;
}

