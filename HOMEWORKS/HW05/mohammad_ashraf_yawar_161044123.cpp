
#include "headerfile.h"
using namespace Personal_Management;
int main(){

	fstream inpfile;
	inpfile.open("personnellist.txt");

	vector<Lecturer> Lec_vec;//vectors of desired types
	vector<ResearchAssistant> Re_vec;//vectors of desired types
	vector<Secretary> Sec_vec;//vectors of desired types
	vector<Officer> Of_vec;//vectors of desired types
	
	University Uni;//make university object
	University *Uniptr = nullptr;//unive ptr 
	Uniptr = &Uni;
	
	int i,random_act,random,index;
	bool flag = false;
	srand(time(NULL));//used to extract the appropriate name of the action

	read_file(inpfile,Lec_vec,Re_vec,Sec_vec,Of_vec);//read appropriate data to desired vector objects.
	Employ(Uniptr,Lec_vec,Re_vec,Sec_vec,Of_vec);//function employes the  desired employees.

	for (i = 0; i < RAND_ACT; ++i){//50 actions will be performed untill the end of this loop.s
		flag = false;
		random_act = rand() % (solution - document + 1) + document;//generate random action amog actions
		if(random_act == document){//action number 1
			
			while(flag == false){//iterates untill it finds a not nullptr and condition flag == true.

				random = rand() % ((Of_vec.size()-1) - 0 + 1) + 0;
				if(Of_vec[random].get_emp() !=nullptr){
					Of_vec[random].makeDoc(random_act);
					flag = true;
				}
			}
		}
		else if(random_act == slackness){//action number 2

			random = rand() % (4 - 1 + 1) + 1;

			if(random == 1){//lecturer vec

				index = FindSmallestIndex(Lec_vec);
				Lec_vec[index].drinkTea(random_act);
			}
			else if(random == 2){//research assinstant vec

				index = FindSmallestIndex(Re_vec);
				Re_vec[index].drinkTea(random_act);
			}
			else if(random == 3){//security vec
				
				index = FindSmallestIndex(Sec_vec);
				Sec_vec[index].drinkTea(random_act);
			}
			else if(random == 4){//officer vec

				index = FindSmallestIndex(Of_vec);
				Of_vec[index].drinkTea(random_act);
			}
		}
		else if(random_act == project){//action number 3

			index = FindSmallestIndex(Re_vec);
			Re_vec[index].research(random_act);
		}
		else if(random_act == lesson){//action number 4

			index = FindSmallestIndex(Lec_vec);
			Lec_vec[index].giveLesson(random_act);
		}
		else if(random_act == seminar){//action number 5

			random = rand() % (2 - 1 + 1) + 1;
			if(random == 1){//lecturer vec

				index = FindSmallestIndex(Lec_vec);
				Lec_vec[index].seeSuccessfulStudent(random_act);
			}
			else if(random == 2){//research assinstant vec

				index = FindSmallestIndex(Re_vec);
				Re_vec[index].seeSuccessfulStudent(random_act);
			}
		}
		else if(random_act == academicPaper){//action number 6

			random = rand() % (2 - 1 + 1) + 1;
			if(random == 1){//lecturer vec

				index = FindSmallestIndex(Lec_vec);
				Lec_vec[index].makePublish(random_act);
			}
			else if(random == 2){//research assinstant vec

				index = FindSmallestIndex(Re_vec);
				Re_vec[index].makePublish(random_act);
			}
		}
		else if(random_act == administration){//action number 

			random = rand() % (2 - 1 + 1) + 1;
			if(random == 1){//lecturer vec

				index = FindSmallestIndex(Sec_vec);
				Sec_vec[index].manageProcess(random_act);
			}
			else if(random == 2){//research assinstant vec

				index = FindSmallestIndex(Of_vec);
				Of_vec[index].manageProcess(random_act);
			}
		}
		else if(random_act == HomeworkTime){//action number 8

			while(flag == false){
				
				random = rand() % ((Lec_vec.size()-1) - 0 + 1) + 0;
				if(Lec_vec[random].get_emp() != nullptr){
					Lec_vec[random].giveHW(random_act);
					flag = true;
				}
			}
		}
		else if(random_act == homeworkTimeout){//action number 9

			while(flag == false){
				
				random = rand() % ((Re_vec.size()-1) - 0 + 1) + 0;
				if(Re_vec[random].get_emp() != nullptr){
					Re_vec[random].readHW(random_act);
					flag = true;
				}
			}
		}	
		else if(random_act == incident){//action number 10

			while(flag == false){
				
				random = rand() % ((Sec_vec.size()-1) - 0 + 1) + 0;
				if(Sec_vec[random].get_emp() != nullptr){
					Sec_vec[random].receivePetition(random_act);
					flag = true;
				}
			}
		}	
		else if(random_act == solution){//action number 11

			random = rand() % (4 - 1 + 1) + 1;

			if(random == 1){//lecturer vec

				index = FindSmallestIndex(Lec_vec);
				Lec_vec[index].submitPetition(random_act);
			}
			else if(random == 2){//research assinstant vec

				index = FindSmallestIndex(Re_vec);
				Re_vec[index].submitPetition(random_act);
			}
			else if(random == 3){//security vec
				
				index = FindSmallestIndex(Sec_vec);
				Sec_vec[index].submitPetition(random_act);	
			}
			else if(random == 4){//officer vec

				index = FindSmallestIndex(Of_vec);
				Of_vec[index].submitPetition(random_act);
			}
		}
	}

	inpfile.close();
	return 0;
}