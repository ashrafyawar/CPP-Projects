#include"uni.h"
#include"standfunc.h"
#include "headerfile.h"
using namespace Personal_Management;
int main(){

	fstream inpfile;
	inpfile.open("personnellist.txt");
	srand(time(NULL));//used to extract the appropriate name of the action

	vector<Persons> per_vec;//holds all the persons from the list.
	string command;
	Employee *emp_ptr;
	Employee *all_emp[ARR_SIZE];
	read_file(inpfile,per_vec);//read appropriate data to desired vector objects.

	do{	
		cout<<"(input)>";cin>>command;
		if(command == "L"){
			
			Libral_University(per_vec,emp_ptr);
			delete emp_ptr;
		}
		else if(command == "Com"){

			Comonist_uni(per_vec,all_emp);
			for(int i = 0; i < 4 ; ++i)//deleting array
				delete all_emp[i];
		}
		else if(command == "Cap"){
			Capitalist_uni(per_vec);
		}

		for (int i = 0; i < EMP_COUNT; ++i)//set the list as default to be used in the future tasks.
			per_vec[i].uniset ="empty";
		}while(command !="exit");

	inpfile.close();
	return 0;
}