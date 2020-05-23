#include"uni.h"
#include "headerfile.h"
#include<iostream>//include libraries
#include<vector>
#include <fstream>//include libraries
#include<string>//include libraries
#include <ctime>//include libraries
#include<random>//include libraries
/*some stand alone functions*/
void Libral_University(vector<Persons>& per_vec,Employee *emp_ptr){

	string ss,st_value;
	string lec_st = "LibLec";//string constants used in implementation.
	string res_st = "LibResAssist";
	string sec_st = "LibSec";//string constants used in implementation.
	string of_st = "LibOff";//string constants used in implementation.
	
	int i,random_act;
	bool did_it = false;
	LibUni<int> *l_uni;
	LiberalEducation<int> lib_edu_obj;
	LiberalEducation<int> *lib_edu;
	lib_edu = & lib_edu_obj;

	l_uni = lib_edu->foundUni(research);
	l_uni->set_uni_name("ANADOLU UNIVERSITY");
	l_uni->set_uni_cont(0);

	cout<<"******************|Liberal Education System|*******************"<<endl;
	cout<<"Finding The Best Employee..."<<endl;
	emp_ptr = find_besteemp(per_vec,l_uni,lib_edu);

	cout<<endl<<"*************** Start Story of Actor *****************"<<endl;
	for(i = 0; i < LIB_ACT_COUNT; ++i){//50 actions will be performed untill the end of this loop.s
	
		did_it = false;
		random_act = rand() % (solution - document + 1) + document;//generate random action amog actions
		if(random_act == document and emp_ptr->get_prof_type() == of_st){//action number 1

			emp_ptr->makeDoc();//make changes in happiness of employeee
			st_value = l_uni->contribute(3);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
			emp_ptr->work(document,"makeDoc");//print the datails related to this employee
			cout<<l_uni->get_cont()<<". I contribute "<<"3"<<" to university."<<endl;
			did_it = true;
		}
		else if(random_act == slackness){//action number 2

			if(emp_ptr->get_prof_type() == lec_st){//lecturer 

				emp_ptr->drinkTea();//make changes in happiness of employeee
				st_value = l_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				emp_ptr->work(slackness,"drinkTea");//print the datails related to this employee
				cout<<l_uni->get_cont()<<". I contribute "<<"-2"<<" to university."<<endl;
				did_it = true;
			}
			else if(emp_ptr->get_prof_type() == res_st){//research assinstant 

				emp_ptr->drinkTea();//make changes in happiness of employeee
				st_value = l_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				emp_ptr->work(slackness,"drinkTea");//print the datails related to this employee
				cout<<l_uni->get_cont()<<". I contribute "<<"-2"<<" to university."<<endl;
				did_it = true;
			}
			else if(emp_ptr->get_prof_type() == sec_st){//security 						
				
				emp_ptr->drinkTea();//make changes in happiness of employeee
				st_value = l_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				emp_ptr->work(slackness,"drinkTea");//print the datails related to this employee
				cout<<l_uni->get_cont()<<". I contribute "<<"-2"<<" to university."<<endl;
				did_it = true;
			}
			else if(emp_ptr->get_prof_type() == of_st){//officer 
				
				emp_ptr->drinkTea();//make changes in happiness of employeee
				st_value = l_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				emp_ptr->work(slackness,"drinkTea");//print the datails related to this employee
				cout<<l_uni->get_cont()<<". I contribute "<<"-2"<<" to university."<<endl;
				did_it = true;
			}
		}
		else if(random_act == project and emp_ptr->get_prof_type() == res_st){//action number 3
			
			emp_ptr->research();//make changes in happiness of employeee
			st_value = l_uni->contribute(4);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
			emp_ptr->work(project,"research");//print the datails related to this employee
			cout<<l_uni->get_cont()<<". I contribute "<<"4"<<" to university."<<endl;
			did_it = true;

		}
		else if(random_act == lesson and emp_ptr->get_prof_type() == lec_st){//action number 4
				
			emp_ptr->giveLesson();//make changes in happiness of employeee
			st_value = l_uni->contribute(5);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
			emp_ptr->work(lesson,"giveLesson");//print the datails related to this employee
			cout<<l_uni->get_cont()<<". I contribute "<<"5"<<" to university."<<endl;
			did_it = true;
	
		}
		else if(random_act == HomeworkTime and emp_ptr->get_prof_type() == lec_st){//action number 8
		
			emp_ptr->giveHW();//make changes in happiness of employeee
			st_value = l_uni->contribute(1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
			emp_ptr->work(HomeworkTime,"giveHW");//print the datails related to this employee
			cout<<l_uni->get_cont()<<". I contribute "<<"1"<<" to university."<<endl;
			did_it = true;
	
		}
		else if(random_act == homeworkTimeout and emp_ptr->get_prof_type() == res_st){//action number 9
			
			emp_ptr->readHW();//make changes in happiness of employeee
			st_value = l_uni->contribute(2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
			emp_ptr->work(homeworkTimeout,"readHW");//print the datails related to this employee
			cout<<l_uni->get_cont()<<". I contribute "<<"2"<<" to university."<<endl;
			did_it = true;
		}	
		else if(random_act == incident and emp_ptr->get_prof_type() == sec_st){//action number 10
			
			emp_ptr->receivePetition();//make changes in happiness of employeee
			st_value = l_uni->contribute(-1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
			emp_ptr->work(incident,"receivePetition");//print the datails related to this employee
			cout<<l_uni->get_cont()<<". I contribute "<<"-1"<<" to university."<<endl;
			did_it = true;
		}	
		else if(random_act == solution){//action number 11

			if(emp_ptr->get_prof_type() == lec_st){//lecturer 

				emp_ptr->submitPetition();//make changes in happiness of employeee
				st_value = l_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				emp_ptr->work(incident,"submitPetition");//print the datails related to this employee
				cout<<l_uni->get_cont()<<". I contribute "<<"-2"<<" to university."<<endl;
				did_it = true;
			}
			else if(emp_ptr->get_prof_type() == res_st){//research assinstant 
				emp_ptr->submitPetition();//make changes in happiness of employeee
				st_value = l_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				emp_ptr->work(incident,"submitPetition");//print the datails related to this employee
				cout<<l_uni->get_cont()<<". I contribute "<<"-2"<<" to university."<<endl;
				did_it = true;
			}
			else if(emp_ptr->get_prof_type() == sec_st){//security 						
				
				emp_ptr->submitPetition();//make changes in happiness of employeee
				st_value = l_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				emp_ptr->work(incident,"submitPetition");//print the datails related to this employee
				cout<<l_uni->get_cont()<<". I contribute "<<"-2"<<" to university."<<endl;
				did_it = true;
			}
			else if(emp_ptr->get_prof_type() == of_st){//officer 
				
				emp_ptr->submitPetition();//make changes in happiness of employeee
				st_value = l_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				emp_ptr->work(incident,"submitPetition");//print the datails related to this employee
				cout<<l_uni->get_cont()<<". I contribute "<<"-2"<<" to university."<<endl;
				did_it = true;
			}	
		}
		else{//exaption handaling part.

			try{
				throw did_it;
			}
			catch(bool e){
				if(e == false){

					ss = action_name(random_act);
					cout<<"(output)>University has "<<ss<<". I cannot do that."<<endl;
				}
			}
		}
	}
	cout<<"(output)> After all, my happiness is "<<emp_ptr->get_happiness();
	cout<<", My money is "<<l_uni->get_cont()<<". Contribution of university is "<<l_uni->get_cont()<<endl;
}
template<class T>
Employee* find_besteemp(vector<Persons>& per_vec,LibUni<T> *l_uni,LiberalEducation<T> *lib_edu){

	Employee *emptr;
	string ss;
	int arr[ARR_SIZE] = {0},lec = 0,res = 1,sec = 2,of = 3;
	int random_act,random,i,max_ind,rand_per;
	bool stop = false;

	for(i = 0; i < LIB_ACT_COUNT; ++i){//14 actions will be performed untill the end of this loop.s
	
		random_act = rand() % (solution - document + 1) + document;//generate random action amog actions
		if(random_act == document)//action number 1
			arr[of] = arr[of] + 3;
		else if(random_act == slackness){//action number 2

			random = rand() % (4 - 1 + 1) + 1;

			if(random == lecturer)//lecturer 
				arr[lec] = arr[lec] - 2;
			else if(random == researchAssistant)//research assinstant 
				arr[res] = arr[res] - 2;
			else if(random == secretary)//security 						
				arr[sec] = arr[sec] - 2;
			else if(random == officer)//officer 
				arr[of] = arr[of] - 2;
		}
		else if(random_act == project)//action number 3
			arr[res] = arr[res] + 4;
		else if(random_act == lesson)//action number 4
			arr[lec] = arr[lec] + 5;
		else if(random_act == HomeworkTime)//action number 8
			arr[lec] = arr[lec] +1;
		else if(random_act == homeworkTimeout)//action number 
			arr[res] = arr[res] +2;
		else if(random_act == incident)//action number 10
			arr[sec] = arr[sec] -1;
		else if(random_act == solution){//action number 11

			random = rand() % (4 - 1 + 1) + 1;
			if(random == lecturer)//lecturer 
				arr[lec] = arr[lec] -2;
			else if(random == researchAssistant)//research assinstant 
				arr[res] = arr[res] -2;
			else if(random == secretary)//security 						
				arr[sec] = arr[sec] -2;
			else if(random == officer)//officer 
				arr[of] = arr[of] -2;
		}
		else{//exaption handaling part.

			try{

				if(random_act == seminar)//action number 5
					throw 1;
				else if(random_act == academicPaper)//action number 6
					throw 2;
				else if(random_act == administration)//action number
					throw 3;
			}
			catch(int e){
			}
		}
	}

	max_ind = max_index(arr);//find max one.
	stop = false;
	
	while(stop == false){//finds appropritate person to the current task if it exists.
		
		rand_per = rand() % ((EMP_COUNT-1) - 0 + 1) + 0;
		if(per_vec[rand_per].uniset =="empty"){
			per_vec[rand_per].uniset = l_uni->get_uni_name();
			stop = true;
		}
	}

	if(max_ind == lec){//if lecturer has max activity.

		cout<<"I see that there is an opportunity for being "<<
		"lecturer "<<"in the university. So I am "<<"lecturer"<<endl;
		emptr = lib_edu->giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,lecturer);
		ss =l_uni->get_uni_name();
		emptr->set_u_name(ss);
	}
	else if(max_ind == res){

		cout<<"I see that there is an opportunity for being "<<
		"researchAssistant "<<"in the university. So I am "<<"researchAssistant"<<endl;
		emptr = lib_edu->giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,researchAssistant);
		ss =l_uni->get_uni_name();
		emptr->set_u_name(ss);
	}
	else if(max_ind == sec){
		
		cout<<"I see that there is an opportunity for being "<<
		"Secretary "<<"in the university. So I am "<<"secretary"<<endl;
		emptr = lib_edu->giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,secretary);
		ss =l_uni->get_uni_name();
		emptr->set_u_name(ss);
	}
	else if(max_ind == of){

		cout<<"I see that there is an opportunity for being "<<
		"officer "<<"in the university. So I am "<<"officer"<<endl;
		emptr = lib_edu->giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,officer);
		ss =l_uni->get_uni_name();
		emptr->set_u_name(ss);
	}
	return emptr;
}
int max_index(int arr[ARR_SIZE]){//finds max index.

	int max_ind = 0;
	int max = arr[0];

    for (int c = 1; c < ARR_SIZE; c++){
        
        if(arr[c] > max){
           max = arr[c];
           max_ind = c;
        }
    }
    return max_ind;
}
void Comonist_uni(vector<Persons>& per_vec,Employee *emp_ptr[ARR_SIZE]){
	
	cout<<"******************|Comonist Education System|*******************"<<endl;

	ComUni<double> *com_uni;
	CommunistEducation<double> com_edu_obj;
	CommunistEducation<double> *com_edu;
	com_edu = &com_edu_obj;

	com_uni = com_edu->foundUni(linguistic);
	com_uni->set_uni_name("GTU UNIVERSITY");
	com_uni->set_uni_cont(0);

	bool flag = true,stop = false;
	int random_act,rand_per,j,random;
	string ss;
	

	cout<<"Employing Desired Employees..."<<endl;
	for (j = 0; j <ARR_SIZE; ++j){//loop assigns employees for the desired objects.

		stop = false;
		while(stop == false){//finds appropritate person to the current task if it exists.
			
			rand_per = rand() % ((EMP_COUNT-1) - 0 + 1) + 0;
			if(per_vec[rand_per].uniset =="empty"){
				per_vec[rand_per].uniset = com_uni->get_uni_name();
				stop = true;
			}
		}
		if(j == 0){
			cout<<"(output)> "<<com_uni->get_uni_name()<<" requests "<<"Lecturer"<<endl;
			emp_ptr[j] = com_edu->giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,lecturer);
			ss = com_uni->get_uni_name();
			emp_ptr[j]->set_u_name(ss);
			cout<<"(output)> "<<"CommunistEducation gives job to "<<" "<<emp_ptr[j]->get_name()<<" "<<emp_ptr[j]->get_surename()<<" as "<<"Lecturer"<<endl;
		}
		else if( j == 1){
			cout<<"(output)> "<<com_uni->get_uni_name()<<" requests "<<"ResearchAssistant"<<endl;
			emp_ptr[j] = com_edu->giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,researchAssistant);
			ss = com_uni->get_uni_name();
			emp_ptr[j]->set_u_name(ss);
			cout<<"(output)> "<<"CommunistEducation gives job to "<<" "<<emp_ptr[j]->get_name()<<" "<<emp_ptr[j]->get_surename()<<" as "<<"ResearchAssistant"<<endl;
		}
		else if(j == 2){
			cout<<"(output)> "<<com_uni->get_uni_name()<<" requests "<<"Secretary"<<endl;
			emp_ptr[j] = com_edu->giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,secretary);
			ss = com_uni->get_uni_name();
			emp_ptr[j]->set_u_name(ss);
			cout<<"(output)> "<<"CommunistEducation gives job to "<<" "<<emp_ptr[j]->get_name()<<" "<<emp_ptr[j]->get_surename()<<" as "<<"Secretary"<<endl;
		}
		else if( j == 3){
			cout<<"(output)> "<<com_uni->get_uni_name()<<" requests "<<"Officer"<<endl;
			emp_ptr[j] = com_edu->giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,officer);
			ss = com_uni->get_uni_name();
			emp_ptr[j]->set_u_name(ss);
			cout<<"(output)> "<<"CommunistEducation gives job to "<<" "<<emp_ptr[j]->get_name()<<" "<<emp_ptr[j]->get_surename()<<" as "<<"Officer"<<endl;
		}
	}
	cout<<endl<<"Start Story Of Actors..."<<endl;
	while(flag == true){//itrates untill every employee has max 3 jobs done.
		
		random_act = rand() % (solution - document + 1) + document;//generate random action amog actions
		if(random_act == document and emp_ptr[3]->lec_count < LIMIT){//action number 1>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		
			emp_ptr[3]->makeDoc();com_uni->contribute(3);
			emp_ptr[3]->work(document,"makeDoc");emp_ptr[3]->lec_count += 1;
			cout<<com_uni->get_cont()<<endl;
		}
		else if(random_act == slackness){//action number 2

			random = rand() % (4 - 1 + 1) + 1;
			if(random == 1 and emp_ptr[0]->lec_count < LIMIT){//lecturer vec

				emp_ptr[0]->drinkTea();com_uni->contribute(-2);
				emp_ptr[0]->work(slackness,"drinkTea");emp_ptr[0]->lec_count += 1;
				cout<<com_uni->get_cont()<<endl;
			}
			else if(random == 2 and emp_ptr[1]->lec_count < LIMIT){//research assinstant vec

				emp_ptr[1]->drinkTea();com_uni->contribute(-2);
				emp_ptr[1]->work(slackness,"drinkTea");emp_ptr[1]->lec_count += 1;
				cout<<com_uni->get_cont()<<endl;
			}
			else if(random == 3 and emp_ptr[2]->lec_count < LIMIT){//security vec
				
				emp_ptr[2]->drinkTea();com_uni->contribute(-2);
				emp_ptr[2]->work(slackness,"drinkTea");emp_ptr[2]->lec_count += 1;
				cout<<com_uni->get_cont()<<endl;
			}
			else if(random == 4 and emp_ptr[3]->lec_count < LIMIT){//officer vec

				emp_ptr[3]->drinkTea();com_uni->contribute(-2);
				emp_ptr[3]->work(slackness,"drinkTea");emp_ptr[3]->lec_count += 1;
				cout<<com_uni->get_cont()<<endl;
			}
		}
		else if(random_act == project and emp_ptr[1]->lec_count < LIMIT){//action number 3

			emp_ptr[1]->research();com_uni->contribute(4);
			emp_ptr[1]->work(project,"research");emp_ptr[1]->lec_count += 1;
			cout<<com_uni->get_cont()<<endl;
		}
		else if(random_act == lesson and emp_ptr[0]->lec_count < LIMIT){//action number 4

			emp_ptr[0]->giveLesson();com_uni->contribute(5);
			emp_ptr[0]->work(lesson,"giveLesson");emp_ptr[0]->lec_count += 1;
			cout<<com_uni->get_cont()<<endl;
		}
		else if(random_act == HomeworkTime and emp_ptr[0]->lec_count < LIMIT){//action number 8

			emp_ptr[0]->giveHW();com_uni->contribute(1);
			emp_ptr[0]->work(HomeworkTime,"giveHW");emp_ptr[0]->lec_count += 1;
			cout<<com_uni->get_cont()<<endl;
		}
		else if(random_act == homeworkTimeout and emp_ptr[1]->lec_count < LIMIT){//action number 9

			emp_ptr[1]->readHW();com_uni->contribute(2);
			emp_ptr[1]->work(homeworkTimeout,"readHW");emp_ptr[1]->lec_count += 1;
			cout<<com_uni->get_cont()<<endl;
		}	
		else if(random_act == incident and emp_ptr[2]->lec_count < LIMIT){//action number 10

			emp_ptr[2]->receivePetition();com_uni->contribute(-1);
			emp_ptr[2]->work(incident,"receivePetition");emp_ptr[2]->lec_count += 1;
			cout<<com_uni->get_cont()<<endl;
		}	
		else if(random_act == solution){//action number 11

			random = rand() % (4 - 1 + 1) + 1;

			if(random == 1 and emp_ptr[0]->lec_count < LIMIT){//lecturer vec

				emp_ptr[0]->submitPetition();com_uni->contribute(-2);
				emp_ptr[0]->work(solution,"submitPetition");emp_ptr[0]->lec_count += 1;
				cout<<com_uni->get_cont()<<endl;
			}
			else if(random == 2 and emp_ptr[1]->lec_count < LIMIT){//research assinstant vec

				emp_ptr[1]->submitPetition();com_uni->contribute(-2);
				emp_ptr[1]->work(solution,"submitPetition");emp_ptr[1]->lec_count += 1;
				cout<<com_uni->get_cont()<<endl;
			}
			else if(random == 3 and emp_ptr[2]->lec_count < LIMIT){//security vec
			
				emp_ptr[2]->submitPetition();com_uni->contribute(-2);
				emp_ptr[2]->work(solution,"submitPetition");emp_ptr[2]->lec_count += 1;
				cout<<com_uni->get_cont()<<endl;	
			}
			else if(random == 4 and emp_ptr[3]->lec_count < LIMIT){//officer vec

				emp_ptr[3]->submitPetition();com_uni->contribute(-2);
				emp_ptr[3]->work(solution,"submitPetition");emp_ptr[3]->lec_count += 1;
				cout<<com_uni->get_cont()<<endl;
			}
		}
		else{//exeption handaling part
			try{

				if(random_act == seminar)//action number 5
					throw 1;
				else if(random_act == academicPaper)//action number 6
					throw 2;
				else if(random_act == administration)//action number
					throw 3;
			}
			catch(int e){
				if(e == 1)
					cout<<"(output)> seminar can't be executed because of execption!!!"<<endl;
				else if(e == 2)
					cout<<"(output)> academicPaper can't be executed because of execption!!!"<<endl;
				else if(e == 3)
					cout<<"(output)> administration can't be executed because of execption!!!"<<endl;
			}
		}
		if((emp_ptr[0]->lec_count + emp_ptr[1]->lec_count + emp_ptr[2]->lec_count + emp_ptr[3]->lec_count) >= 12){
			flag = false;
		}
	}
}
void Capitalist_uni(vector<Persons>& per_vec){
	
	cout<<"******************|Capitalist Education System|*******************"<<endl;
	int index;
	CapUni<int> *cap_uni;//some pointers 
	CapitalistEducation<int> cap_edu_obj;//some pointers 
	CapitalistEducation<int> *cap_edu;//some pointers 
	cap_edu = &cap_edu_obj;//some pointers 

	cap_uni = cap_edu->foundUni(technical);//University creation and assigment.
	cap_uni->set_uni_name("MIT UNIVERSITY");//University creation and assigment.
	cap_uni->set_uni_cont(0);//University creation and assigment.

	BrokerLecturer *LEC_B = NULL;BrokerResAssist *RES_B = NULL;//Brokers pointers
	BrokerSecretary *SEC_B = NULL;BrokerOfficer *OF_B = NULL;//Brokers pointers

    LEC_B = new BrokerLecturer;RES_B = new BrokerResAssist;//allocating space for Brokers  
    SEC_B = new BrokerSecretary;OF_B = new BrokerOfficer;//allocating space for Brokers

    LEC_B->first_w = new WorkerLecturer; LEC_B->second_w = new WorkerLecturer;//allocating space for Wrokers of each Brokers.
    RES_B->first_w = new WorkerResAssist; RES_B->second_w = new WorkerResAssist;//allocating space for Wrokers of each Brokers.
    SEC_B->first_w = new WorkerSecretary; SEC_B->second_w = new WorkerSecretary;//allocating space for Wrokers of each Brokers.
    OF_B->first_w = new WorkerOfficer; OF_B->second_w = new WorkerOfficer;//allocating space for Wrokers of each Brokers.

	LEC_B->emptr = RES_B;//Assigment and linkage of Brokers 
	LEC_B->emptr->emptr = SEC_B;//Assigment and linkage of Brokers 
	LEC_B->emptr->emptr->emptr = OF_B;//Assigment and linkage of Brokers 

	index = NewBroker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	LEC_B->set_name(per_vec[index].name);//set emp name
	LEC_B->set_surename(per_vec[index].surename);//set emp surename.

	index = NewBroker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	RES_B->set_name(per_vec[index].name);//set emp name
	RES_B->set_surename(per_vec[index].surename);//set emp surename.

	index = NewBroker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	SEC_B->set_name(per_vec[index].name);//set emp name
	SEC_B->set_surename(per_vec[index].surename);//set emp surename.

	index = NewBroker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	OF_B->set_name(per_vec[index].name);//set emp name
	OF_B->set_surename(per_vec[index].surename);//set emp surename.

	index = NewWorker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	LEC_B->first_w->set_name(per_vec[index].name);//set emp name
	LEC_B->first_w->set_surename(per_vec[index].surename);//set emp surename.

	index = NewWorker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	LEC_B->second_w->set_name(per_vec[index].name);//set emp name
	LEC_B->second_w->set_surename(per_vec[index].surename);//set emp surename.

	index = NewWorker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	RES_B->first_w->set_name(per_vec[index].name);//set emp name
	RES_B->first_w->set_surename(per_vec[index].surename);//set emp surename.

	index = NewWorker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	RES_B->second_w->set_name(per_vec[index].name);//set emp name
	RES_B->second_w->set_surename(per_vec[index].surename);//set emp surename.

	index = NewWorker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	SEC_B->first_w->set_name(per_vec[index].name);//set emp name
	SEC_B->first_w->set_surename(per_vec[index].surename);//set emp surename.

	index = NewWorker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	SEC_B->second_w->set_name(per_vec[index].name);//set emp name
	SEC_B->second_w->set_surename(per_vec[index].surename);//set emp surename.

	index = NewWorker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	OF_B->first_w->set_name(per_vec[index].name);//set emp name
	OF_B->first_w->set_surename(per_vec[index].surename);//set emp surename.

	index = NewWorker(per_vec);//genrate desired new employee and then set him/her as desired job.
	per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
	OF_B->second_w->set_name(per_vec[index].name);//set emp name
	OF_B->second_w->set_surename(per_vec[index].surename);//set emp surename.
	
	/*the above code would take same space when i would use loops or something like that so i had manualy do it by hand*/
	Start(per_vec,LEC_B,RES_B,SEC_B,OF_B,cap_uni);
	cout<<"(output)>CapUni's Brokers Have Total Money of: "<<(totalmoney+LEC_B->GetMoney()+RES_B->GetMoney()+ SEC_B->GetMoney()+ OF_B->GetMoney())<<endl;
	
	delete LEC_B;delete RES_B;delete SEC_B;delete OF_B;//deallocating spaces.
	delete LEC_B->first_w;delete LEC_B->second_w;//deallocating spaces.
	delete RES_B->first_w;delete RES_B->second_w;//deallocating spaces.
	delete SEC_B->first_w;delete SEC_B->second_w;//deallocating spaces.
	delete OF_B->first_w;delete OF_B->second_w;//deallocating spaces.
	totalmoney = 0;
}
void Start(vector<Persons>& per_vec,BrokerLecturer *LEC_B,BrokerResAssist *RES_B,BrokerSecretary *SEC_B,BrokerOfficer *OF_B,CapUni<int> *Cap_Uni){

	int rand_per,random_act,i,worker,random,index;
	Employee *head = NULL,*headtemp = NULL;
	for(i = 0; i < CAP_ACT_COUT; ++i){//50 actions will be performed untill the end of this loop.s
		cout<<"(output)>";
		random_act = rand() % (solution - document + 1) + document;//generate random action amog actions
		worker = rand() % (2 - 1 + 1) + 1;//generate random action amog actions
		if(random_act == document){//action number 1
			if(worker == 1){
				
				OF_B->first_w->makeDoc();//make changes in happiness of employeee
				Cap_Uni->contribute(3);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				OF_B->SetMoney(3.0/2);
				OF_B->first_w->work(document,"makeDoc");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
			else{

				OF_B->second_w->makeDoc();//make changes in happiness of employeee
				Cap_Uni->contribute(3);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				OF_B->SetMoney(3.0/2);
				OF_B->second_w->work(document,"makeDoc");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
		}
		else if(random_act == slackness){//action number 2

			random = rand() % (4 - 1 + 1) + 1;
			if(random == lecturer){//lecturer 
				
				if(worker == 1){
					
					LEC_B->first_w->drinkTea();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					LEC_B->SetMoney(-2.0/2);
					LEC_B->first_w->work(slackness,"drinkTea");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
				else{

					LEC_B->second_w->drinkTea();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					LEC_B->SetMoney(-2.0/2);
					LEC_B->second_w->work(slackness,"drinkTea");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
			}
			else if(random == researchAssistant){//research assinstant

				if(worker == 1){
					
					RES_B->first_w->drinkTea();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					RES_B->SetMoney(-2.0/2);
					RES_B->first_w->work(slackness,"drinkTea");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
				else{

					RES_B->second_w->drinkTea();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					RES_B->SetMoney(-2.0/2);
					RES_B->second_w->work(slackness,"drinkTea");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
			}
			else if(random == secretary){//security 						
				
				if(worker == 1){
					
					SEC_B->first_w->drinkTea();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					SEC_B->SetMoney(-2.0/2);
					SEC_B->first_w->work(slackness,"drinkTea");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
				else{

					SEC_B->second_w->drinkTea();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					SEC_B->SetMoney(-2.0/2);
					SEC_B->second_w->work(slackness,"drinkTea");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
		
			}
			else if(random == officer){//officer 
			
				if(worker == 1){
					
					OF_B->first_w->drinkTea();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					OF_B->SetMoney(-2.0/2);
					OF_B->first_w->work(slackness,"drinkTea");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
				else{

					OF_B->second_w->drinkTea();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					OF_B->SetMoney(-2.0/2);
					OF_B->second_w->work(slackness,"drinkTea");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
			}
		}
		else if(random_act == project){//action number 3
			
			if(worker == 1){
				
				RES_B->first_w->research();//make changes in happiness of employeee
				Cap_Uni->contribute(4);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				RES_B->SetMoney(4.0/2);
				RES_B->first_w->work(project,"research");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
			else{

				RES_B->second_w->research();//make changes in happiness of employeee
				Cap_Uni->contribute(4);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				RES_B->SetMoney(4.0/2);
				RES_B->second_w->work(project,"research");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
		}
		else if(random_act == lesson){//action number 4
		
			if(worker == 1){
				
				LEC_B->first_w->giveLesson();//make changes in happiness of employeee
				Cap_Uni->contribute(5);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				LEC_B->SetMoney(5.0/2);
				LEC_B->first_w->work(lesson,"giveLesson");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
			else{

				LEC_B->second_w->giveLesson();//make changes in happiness of employeee
				Cap_Uni->contribute(5);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				LEC_B->SetMoney(5.0/2);
				LEC_B->second_w->work(lesson,"giveLesson");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
		}
		else if(random_act == HomeworkTime){//action number 8

			if(worker == 1){
				
				LEC_B->first_w->giveHW();//make changes in happiness of employeee
				Cap_Uni->contribute(1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				LEC_B->SetMoney(1.0/2);
				LEC_B->first_w->work(HomeworkTime,"giveHW");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
			else{

				LEC_B->second_w->giveHW();//make changes in happiness of employeee
				Cap_Uni->contribute(1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				LEC_B->SetMoney(1.0/2);
				LEC_B->second_w->work(HomeworkTime,"giveHW");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
		}
		else if(random_act == homeworkTimeout){//action number 9
			
			if(worker == 1){
				
				RES_B->first_w->readHW();//make changes in happiness of employeee
				Cap_Uni->contribute(2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				RES_B->SetMoney(2.0/2);
				RES_B->first_w->work(homeworkTimeout,"readHW");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
			else{

				RES_B->second_w->readHW();//make changes in happiness of employeee
				Cap_Uni->contribute(2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				RES_B->SetMoney(2.0/2);
				RES_B->second_w->work(homeworkTimeout,"readHW");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
		}	
		else if(random_act == incident){//action number 10
			
			if(worker == 1){
				
				SEC_B->first_w->receivePetition();//make changes in happiness of employeee
				Cap_Uni->contribute(-1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				SEC_B->SetMoney(-1.0/2);
				SEC_B->first_w->work(incident,"receivePetition");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
			else{

				SEC_B->second_w->receivePetition();//make changes in happiness of employeee
				Cap_Uni->contribute(-1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
				SEC_B->SetMoney(-1.0/2);
				SEC_B->second_w->work(incident,"receivePetition");//print the datails related to this employee
				cout<<Cap_Uni->get_cont()<<endl;
			}
		}	
		else if(random_act == solution){//action number 11

			random = rand() % (4 - 1 + 1) + 1;
			if(random == lecturer){//lecturer 

				if(worker == 1){
					
					LEC_B->first_w->submitPetition();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					LEC_B->SetMoney(-2.0/2);
					LEC_B->first_w->work(solution,"submitPetition");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
				else{

					LEC_B->second_w->submitPetition();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					LEC_B->SetMoney(-2.0/2);
					LEC_B->second_w->work(solution,"submitPetition");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}	
			}
			else if(random == researchAssistant){//research assinstant 

				if(worker == 1){
					
					RES_B->first_w->submitPetition();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					RES_B->SetMoney(-2.0/2);
					RES_B->first_w->work(solution,"submitPetition");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
				else{

					RES_B->second_w->submitPetition();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					RES_B->SetMoney(-2.0/2);
					RES_B->second_w->work(solution,"submitPetition");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}	
			}
			else if(random == secretary){//security 						
				
				if(worker == 1){
					
					SEC_B->first_w->submitPetition();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					SEC_B->SetMoney(-2.0/2);
					SEC_B->first_w->work(solution,"submitPetition");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
				else{

					SEC_B->second_w->submitPetition();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					SEC_B->SetMoney(-2.0/2);
					SEC_B->second_w->work(solution,"submitPetition");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}	
			}
			else if(random == officer){//officer 
				
				if(worker == 1){
					
					OF_B->first_w->submitPetition();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					OF_B->SetMoney(-2.0/2);
					OF_B->first_w->work(solution,"submitPetition");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}
				else{

					OF_B->second_w->submitPetition();//make changes in happiness of employeee
					Cap_Uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
					OF_B->SetMoney(-2.0/2);
					OF_B->second_w->work(solution,"submitPetition");//print the datails related to this employee
					cout<<Cap_Uni->get_cont()<<endl;
				}	
			}	
		}
		else{

			try{

				if(random_act == seminar){//action number 5
					throw 1;
				}
				else if(random_act == academicPaper){//action number 6
					throw 2;
				}
				else if(random_act == administration){//action number
					throw 3;
				}
			}
		
			catch(int e){

				if(e == 1)
					cout<<"seminar can't be executed because of execption!!!"<<endl;
				else if(e == 2)
					cout<<"academicPaper can't be executed because of execption!!!"<<endl;
				else if(e == 3)
					cout<<"administration can't be executed because of execption!!!"<<endl;
			}
		}
		head = LEC_B;//head pointer to the brokers.
		while(head!=NULL){//this loop basically iteratea untill the end of four brokers and chekc whether if they have raised thier money 
						 // and resets the certain borkers money and collects them into a global variable.
			if(head->GetMoney() >= THRESHOLD){
			
				if(head->get_prof_type() == "BrokerLecturer")
					headtemp = new WorkerLecturer;//allocate worker object according to the desire
				else if(head->get_prof_type() == "BrokerResAssist")
					headtemp = new WorkerResAssist;
				else if(head->get_prof_type() == "BrokerSecretary")
					headtemp = new WorkerSecretary;//allocate worker object according to the desire
				else if(head->get_prof_type() == "BrokerOfficer")
					headtemp = new WorkerOfficer;//allocate worker object according to the desire
				
				totalmoney += head->GetMoney();//save the brokers value
				head->SetToZero();
				
				cout<<"(output)>MR/MRS "<<head->get_name()<<" Has Reasched Threshold Limit!!!, so He Has To Resign One Of His/Her Employees..."<<endl;
				if(head->first_w->get_happiness() < head->second_w->get_happiness()){

					cout<<"(output)>"<<head->first_w->get_name() <<" Is Resigning..."<<endl;
					reset_emp(per_vec,head->first_w->get_name(),head->first_w->get_surename());
					delete head->first_w;//deallocatin resigned workers
					head->first_w = headtemp;//new workers signed
					index = NewWorker(per_vec);//genrate desired new employee and then set him/her as desired job.
					per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
					head->first_w->set_name(per_vec[index].name);//set emp name
					head->first_w->set_surename(per_vec[index].surename);//set emp surename.
					cout<<"(output)> New Employee Named: "<<head->first_w->get_name()<<" Has Been Signed..."<<endl;
				}
				else{

					cout<<"(output)>"<<head->second_w->get_name() <<" Is Resigning..."<<endl;
					reset_emp(per_vec,head->second_w->get_name(),head->second_w->get_surename());
					delete head->second_w;//deallocatin resigned workers
					head->second_w = headtemp;//new workers signed
					index = NewWorker(per_vec);//genrate desired new employee and then set him/her as desired job.
					per_vec[index].uniset = "CapUni"; //set university name i could have done it through pointers but for that i had to make all my classes template..
					head->second_w->set_name(per_vec[index].name);//set emp name
					head->second_w->set_surename(per_vec[index].surename);//set emp surename.
					cout<<"(output)>New Employee Named: "<<head->second_w->get_name()<<" Has BeenN Signed..."<<endl;
				}
			}
			head = head->emptr;
		}
	}
}
string action_name(const int& value){

	switch(value){
		
		case 1:
			return "document";
			break;
		case 2:
			return "slackness";
			break;
		case 3:
			return "project";
			break;
		case 4:
			return "lesson";
			break;
		case 5:
			return "seminar";
			break;
		case 6:
			return "academicPaper";
			break;
		case 7:
			return "administration";
			break;
		case 8:
			return "HomeworkTime";
			break;
		case 9:
			return "homeworkTimeout";
			break;
		case 10:
			return "incident";
			break;
		case 11:
			return "solution";
			break;
		default:
		cout<<"WRONG ACTION!"<<endl;	
	}
}
bool is_any_match(Employee **emp_ptr,const string& st,const string& uni_name){//function finds if any required person is in the list

	int i = 0;
	while(i < EMP_COUNT){

		if(emp_ptr[i]->get_prof_type() == st and uni_name == emp_ptr[i]->get_u_name()){
			return true;
		}
		i++;		
	}
	return false;
}
void reset_emp(vector<Persons>& per_vec,const string& name,const string& surename){

	bool found = false;
	int random = 0;
	
	while(found == false){

		random = rand() % ((EMP_COUNT-1) - 0 + 1) + 0;
		if(per_vec[random].name == name and per_vec[random].surename == surename){
			per_vec[random].uniset ="empty";
			return;
		}
	}
	return;
}
bool is_int(const double& a){

	double d;
	int c;
	c = (int)a;d = c;
	if(d == a){
		return true;
	}
	else{
		return false;	
	}
}
int NewBroker(vector<Persons>& per_vec){

	int random;
	while(1){
		random = rand() % ((EMP_COUNT-1) - 0 + 1) + 0;
		if(per_vec[random].accuracy == 'B' and per_vec[random].uniset == "empty")
			return random;
	}
}
int NewWorker(vector<Persons>& per_vec){

	int random;
	while(1){
		random = rand() % ((EMP_COUNT-1) - 0 + 1) + 0;
		if(per_vec[random].accuracy == 'W' and per_vec[random].uniset == "empty")
			return random;
	}
}