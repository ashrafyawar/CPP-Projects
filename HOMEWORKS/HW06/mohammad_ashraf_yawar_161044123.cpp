
#include "headerfile.h"
using namespace Personal_Management;
using namespace My_Struct;
int main(){

	fstream inpfile;
	inpfile.open("personnellist.txt");
	
	string  st1= "research";//string constants used in implementation.
	string  st2= "linguistic";//string constants used in implementation.
	string  st3= "technical";//string constants used in implementation.
	
	string lec_st = "Lecturer";//string constants used in implementation.
	string res_st = "ResearchAssistant";
	string sec_st = "Secretary";//string constants used in implementation.
	string of_st = "Officer";//string constants used in implementation.
	
	vector<Persons> per_vec;//holds all the persons from the list.
	
	University<int> *res_uni;//research type university pointer.
	University<double> *lin_uni;//linguistic type university pointer.
	University<complex> *tech_uni;//technical type university pointer.
	
	Employee *emp_ptr,*all_emp[EMP_COUNT];
	
	YOK<int> yok1;//yok nammed class's object.
	YOK<double> yok2;//yok nammed class's object.
	YOK<complex> yok3;//yok nammed class's object.
	
	int i,random_act,random,index,j,rand_per,uni,k,emp_ind = 0;
	bool stop = false,flag = false,is_any = false;
	string ss,st_value;
	srand(time(NULL));//used to extract the appropriate name of the action
	
	//research uni creation
	res_uni = yok1.foundUni(research);
	res_uni->set_uni_name("ANADOLU UNIVERSITY");
	res_uni->set_uni_cont(0);
	res_uni->set_uni_type(st1);
	
	//linguistic uni creation
	lin_uni = yok2.foundUni(linguistic);
	lin_uni->set_uni_name("ESKISEHIR UNIVERSITY");
	lin_uni->set_uni_cont(0.0);
	lin_uni->set_uni_type(st2);
	
	complex com_obj;
	com_obj.set_contri(0.0,0.0);
	
	//technical uni creation
	tech_uni = yok3.foundUni(technical);
	tech_uni->set_uni_name("GEBZE TECHNICAL UNIVERSITY");
	tech_uni->set_uni_cont(com_obj);
	tech_uni->set_uni_type(st3);
	
	read_file(inpfile,per_vec);//read appropriate data to desired vector objects.

	for(i = 1; i <=UNI_COUNT; ++i){//loop employees persons from the list to the appropriate universities.
		
		if (i == research){//research type university
			
			k = 0;
			for (j = 1; j <=EMP_COUNT / 3; ++j){
				
				stop = false;
				while(stop == false){//finds appropritate person to the current task if it exists.
					
					rand_per = rand() % ((EMP_COUNT-1) - 0 + 1) + 0;
					if(per_vec[rand_per].uniset =="empty"){
						per_vec[rand_per].uniset = res_uni->get_uni_name();
						stop = true;
					}
				}

				random = rand() % (4 - 1 + 1) + 1;
				if(random == lecturer){

					cout<<"(output)> "<<res_uni->get_uni_name()<<" requests "<<"Lecturer"<<endl;

					emp_ptr = yok1.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,lecturer);
					ss = res_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"Lecturer"<<endl;
				}
				else if(random == researchAssistant){

					cout<<"(output)> "<<res_uni->get_uni_name()<<" requests "<<"ResearchAssistant"<<endl;

					emp_ptr = yok1.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,researchAssistant);
					ss = res_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"ResearchAssistant"<<endl;
				}
				else if(random == secretary){

					cout<<"(output)> "<<res_uni->get_uni_name()<<" requests "<<"Secretary"<<endl;

					emp_ptr = yok1.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,secretary);
					ss = res_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"Secretary"<<endl;
				}
				else if(random == officer){

					cout<<"(output)> "<<res_uni->get_uni_name()<<" requests "<<"Officer"<<endl;

					emp_ptr = yok1.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,officer);
					ss = res_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"Officer"<<endl;
				}
				k++;
			}		
		}
		else if(i == linguistic){//linguistic type university.

			for(j = 1; j <=EMP_COUNT / 3; ++j){
				
				stop = false;
				while(stop == false){
					
					rand_per = rand() % ((EMP_COUNT-1) - 0 + 1) + 0;
					if(per_vec[rand_per].uniset =="empty"){
						per_vec[rand_per].uniset = lin_uni->get_uni_name();
						stop = true;
					}
				}

				random = rand() % (4 - 1 + 1) + 1;
				if(random == lecturer){

					cout<<"(output)> "<<lin_uni->get_uni_name()<<" requests "<<"Lecturer"<<endl;

					emp_ptr = yok2.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,lecturer);
					ss = lin_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"Lecturer"<<endl;
				}
				else if(random == researchAssistant){

					cout<<"(output)> "<<lin_uni->get_uni_name()<<" requests "<<"ResearchAssistant"<<endl;

					emp_ptr = yok2.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,researchAssistant);
					ss = lin_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"ResearchAssistant"<<endl;
				}
				else if(random == secretary){

					cout<<"(output)> "<<lin_uni->get_uni_name()<<" requests "<<"Secretary"<<endl;

					emp_ptr = yok2.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,secretary);
					ss = lin_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"Secretary"<<endl;
				}
				else if(random == officer){


					cout<<"(output)> "<<lin_uni->get_uni_name()<<" requests "<<"Officer"<<endl;

					emp_ptr = yok2.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,officer);
					ss = lin_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"Officer"<<endl;
				}
				k++;
			}
		}
		else if(i == technical){//technical university job distribution

			for (j = 1; j <=EMP_COUNT / 3; ++j){
				
				stop = false;
				while(stop == false){
					
					rand_per = rand() % ((EMP_COUNT-1) - 0 + 1) + 0;
					if(per_vec[rand_per].uniset =="empty"){
						per_vec[rand_per].uniset = tech_uni->get_uni_name();
						stop = true;
					}
				}

				random = rand() % (4 - 1 + 1) + 1;
				if(random == lecturer){

					cout<<"(output)> "<<tech_uni->get_uni_name()<<" requests "<<"Lecturer"<<endl;

					emp_ptr = yok3.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,lecturer);
					ss = tech_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"Lecturer"<<endl;
				}
				else if(random == researchAssistant){

					cout<<"(output)> "<<tech_uni->get_uni_name()<<" requests "<<"ResearchAssistant"<<endl;

					emp_ptr = yok3.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,researchAssistant);
					ss = tech_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"ResearchAssistant"<<endl;
				}
				else if(random == secretary){

					cout<<"(output)> "<<tech_uni->get_uni_name()<<" requests "<<"Secretary"<<endl;

					emp_ptr = yok3.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,secretary);
					ss = tech_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"Secretary"<<endl;
				}
				else if(random == officer){

					cout<<"(output)> "<<tech_uni->get_uni_name()<<" requests "<<"Officer"<<endl;

					emp_ptr = yok3.giveJob(per_vec[rand_per].name,per_vec[rand_per].surename,officer);
					ss = tech_uni->get_uni_name();
					emp_ptr->set_u_name(ss);
					all_emp[k] = emp_ptr;
					cout<<"(output)> "<<"YOK give job to "<<" "<<emp_ptr->get_name()<<" "<<emp_ptr->get_surename()<<" as "<<"Officer"<<endl;
				}
				k++;
			}
		}
	}

	for(uni = 1; uni <=UNI_COUNT; ++uni){//loop iterates parallel to count of universities.(3) in this case
		
		if(uni == research){
			
			cout<<endl<<"************"<<res_uni->get_uni_name()<<" EMPLOYMENT PROSIDURE ************"<<endl;
			for(i = 0; i < RAND_ACT; ++i){//50 actions will be performed untill the end of this loop.s
			
				random_act = rand() % (solution - document + 1) + document;//generate random action amog actions
				
				if(random_act == document){//action number 1
					
					is_any = is_any_match(all_emp,of_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,of_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->makeDoc();//make changes in happiness of employeee
						st_value = res_uni->contribute(3);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(document,"makeDoc");//print the datails related to this employee
						cout<<res_uni->get_cont()<<endl;
					}	
				}
				else if(random_act == slackness){//action number 2

					random = rand() % (4 - 1 + 1) + 1;

					if(random == lecturer){//lecturer 

						is_any = is_any_match(all_emp,lec_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,lec_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							st_value = res_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout<<res_uni->get_cont()<<endl;
						}	
					}
					else if(random == researchAssistant){//research assinstant 

						is_any = is_any_match(all_emp,res_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,res_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							st_value = res_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout<<res_uni->get_cont()<<endl;
						}
					}
					else if(random == secretary){//security 						
						
						is_any = is_any_match(all_emp,sec_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,sec_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							st_value = res_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout<<res_uni->get_cont()<<endl;
						}
					}
					else if(random == officer){//officer 
						
						is_any = is_any_match(all_emp,of_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,of_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							st_value = res_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout<<res_uni->get_cont()<<endl;
						}
					}
				}
				else if(random_act == project){//action number 3
					
					is_any = is_any_match(all_emp,res_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,res_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->research();//make changes in happiness of employeee
						st_value = res_uni->contribute(4);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(project,"research");//print the datails related to this employee
						cout<<res_uni->get_cont()<<endl;
					}
				}
				else if(random_act == lesson){//action number 4
						
						is_any = is_any_match(all_emp,lec_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,lec_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->giveLesson();//make changes in happiness of employeee
							st_value = res_uni->contribute(5);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(lesson,"giveLesson");//print the datails related to this employee
							cout<<res_uni->get_cont()<<endl;
						}
				}
				else if(random_act == HomeworkTime){//action number 8

					is_any = is_any_match(all_emp,lec_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,lec_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->giveHW();//make changes in happiness of employeee
						st_value = res_uni->contribute(1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(HomeworkTime,"giveHW");//print the datails related to this employee
						cout<<res_uni->get_cont()<<endl;
					}
				}
				else if(random_act == homeworkTimeout){//action number 9
					
					is_any = is_any_match(all_emp,res_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,res_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->readHW();//make changes in happiness of employeee
						st_value = res_uni->contribute(2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(homeworkTimeout,"readHW");//print the datails related to this employee
						cout<<res_uni->get_cont()<<endl;
					}
				}	
				else if(random_act == incident){//action number 10
					
					is_any = is_any_match(all_emp,sec_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,sec_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->receivePetition();//make changes in happiness of employeee
						st_value = res_uni->contribute(-1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(incident,"receivePetition");//print the datails related to this employee
						cout<<res_uni->get_cont()<<endl;
					}
				}	
				else if(random_act == solution){//action number 11

					random = rand() % (4 - 1 + 1) + 1;
					if(random == lecturer){//lecturer 

						is_any = is_any_match(all_emp,lec_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,lec_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							st_value = res_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout<<res_uni->get_cont()<<endl;
						}	
					}
					else if(random == researchAssistant){//research assinstant 

						is_any = is_any_match(all_emp,res_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,res_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							st_value = res_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout<<res_uni->get_cont()<<endl;
						}
					}
					else if(random == secretary){//security 						
						
						is_any = is_any_match(all_emp,sec_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,sec_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							st_value = res_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout<<res_uni->get_cont()<<endl;
						}
					}
					else if(random == officer){//officer 
						
						is_any = is_any_match(all_emp,of_st,res_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,of_st,res_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							st_value = res_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout<<res_uni->get_cont()<<endl;
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
			}
		}
		else if(uni == linguistic){

			cout<<endl<<"************"<<lin_uni->get_uni_name()<<" EMPLOYMENT PROSIDURE************"<<endl;
			for(i = 0; i < RAND_ACT; ++i){//50 actions will be performed untill the end of this loop.s
			
				random_act = rand() % (solution - document + 1) + document;//generate random action amog actions
				if(random_act == document){//action number 1
					
					is_any = is_any_match(all_emp,of_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,of_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->makeDoc();//make changes in happiness of employeee
						st_value = lin_uni->contribute(3);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(document,"makeDoc");//print the datails related to this employee
						cout<<lin_uni->get_cont()<<endl;
					}	
				}
				else if(random_act == slackness){//action number 2

					random = rand() % (4 - 1 + 1) + 1;

					if(random == lecturer){//lecturer 

						is_any = is_any_match(all_emp,lec_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,lec_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							st_value = lin_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout<<lin_uni->get_cont()<<endl;
						}	
					}
					else if(random == researchAssistant){//research assinstant 

						is_any = is_any_match(all_emp,res_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,res_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							st_value = lin_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout<<lin_uni->get_cont()<<endl;
						}
					}
					else if(random == secretary){//security 						
						
						is_any = is_any_match(all_emp,sec_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,sec_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							st_value = lin_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout<<lin_uni->get_cont()<<endl;
						}
					}
					else if(random == officer){//officer 
						
						is_any = is_any_match(all_emp,of_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,of_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							st_value = lin_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout<<lin_uni->get_cont()<<endl;
						}
					}
				}
				else if(random_act == project){//action number 3
					
					is_any = is_any_match(all_emp,res_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,res_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->research();//make changes in happiness of employeee
						st_value = lin_uni->contribute(4);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(project,"research");//print the datails related to this employee
						cout<<lin_uni->get_cont()<<endl;
					}
				}
				else if(random_act == lesson){//action number 4
						
						is_any = is_any_match(all_emp,lec_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,lec_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->giveLesson();//make changes in happiness of employeee
							st_value = lin_uni->contribute(5);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(lesson,"giveLesson");//print the datails related to this employee
							cout<<lin_uni->get_cont()<<endl;
						}
				}
				else if(random_act == HomeworkTime){//action number 8

					is_any = is_any_match(all_emp,lec_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,lec_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->giveHW();//make changes in happiness of employeee
						st_value = lin_uni->contribute(1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(HomeworkTime,"giveHW");//print the datails related to this employee
						cout<<lin_uni->get_cont()<<endl;
					}
				}
				else if(random_act == homeworkTimeout){//action number 9
					
					is_any = is_any_match(all_emp,res_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,res_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->readHW();//make changes in happiness of employeee
						st_value = lin_uni->contribute(2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(homeworkTimeout,"readHW");//print the datails related to this employee
						cout<<lin_uni->get_cont()<<endl;
					}
				}	
				else if(random_act == incident){//action number 10
					
					is_any = is_any_match(all_emp,sec_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,sec_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->receivePetition();//make changes in happiness of employeee
						st_value = lin_uni->contribute(-1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(incident,"receivePetition");//print the datails related to this employee
						cout<<lin_uni->get_cont()<<endl;
					}
				}	
				else if(random_act == solution){//action number 11

					random = rand() % (4 - 1 + 1) + 1;
					if(random == lecturer){//lecturer 

						is_any = is_any_match(all_emp,lec_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,lec_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							st_value = lin_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout<<lin_uni->get_cont()<<endl;
						}	
					}
					else if(random == researchAssistant){//research assinstant 

						is_any = is_any_match(all_emp,res_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,res_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							st_value = lin_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout<<lin_uni->get_cont()<<endl;
						}
					}
					else if(random == secretary){//security 						
						
						is_any = is_any_match(all_emp,sec_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,sec_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							st_value = lin_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout<<lin_uni->get_cont()<<endl;
						}
					}
					else if(random == officer){//officer 
						
						is_any = is_any_match(all_emp,of_st,lin_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,of_st,lin_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							st_value = lin_uni->contribute(-2);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout<<lin_uni->get_cont()<<endl;
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
			}
		}
		else if(uni == technical){//in this part my understanding is like i will have a complex class with two arguments real and imiginary part and ill increment or decrement contribution of university according to Action given
		
			cout<<endl<<"************"<<tech_uni->get_uni_name()<<" EMPLOYMENT PROSIDURE************"<<endl;
			for(i = 0; i < RAND_ACT; ++i){//50 actions will be performed untill the end of this loop.s
				
				random_act = rand() % (solution - document + 1) + document;//generate random action amog actions
				if(random_act == document){//action number 1
					
					is_any = is_any_match(all_emp,of_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(is_any == false){
						cout<<"NO MATCHING EMPLOYEE!!!"<<endl;
					}
					else{

							emp_ind = find_emp_ind(all_emp,of_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->makeDoc();//make changes in happiness of employeee
							com_obj.modify_values(3.1,1);
							all_emp[emp_ind]->work(document,"makeDoc");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;
						}	
				}
				else if(random_act == slackness){//action number 2

					random = rand() % (4 - 1 + 1) + 1;

					if(random == lecturer){//lecturer 

						is_any = is_any_match(all_emp,lec_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,lec_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							com_obj.modify_values(-2.0,1);
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;						}	
					}
					else if(random == researchAssistant){//research assinstant 

						is_any = is_any_match(all_emp,res_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,res_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							com_obj.modify_values(-2.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;						}
					}
					else if(random == secretary){//security 						
						
						is_any = is_any_match(all_emp,sec_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,sec_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							com_obj.modify_values(-2.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;					}
					}
					else if(random == officer){//officer 
						
						is_any = is_any_match(all_emp,of_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,of_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->drinkTea();//make changes in happiness of employeee
							com_obj.modify_values(-2.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(slackness,"drinkTea");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;					}
					}
				}
				else if(random_act == project){//action number 3
					
					is_any = is_any_match(all_emp,res_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,res_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->research();//make changes in happiness of employeee
						com_obj.modify_values(-4.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(project,"research");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;				}
				}
				else if(random_act == lesson){//action number 4
						
						is_any = is_any_match(all_emp,lec_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,lec_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->giveLesson();//make changes in happiness of employeee
							com_obj.modify_values(5.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(lesson,"giveLesson");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;						}
				}
				else if(random_act == HomeworkTime){//action number 8

					is_any = is_any_match(all_emp,lec_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,lec_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->giveHW();//make changes in happiness of employeee
						com_obj.modify_values(1.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(HomeworkTime,"giveHW");//print the datails related to this employee
						cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
						cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;
					}
				}
				else if(random_act == homeworkTimeout){//action number 9
					
					is_any = is_any_match(all_emp,res_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,res_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->readHW();//make changes in happiness of employeee
						com_obj.modify_values(2.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(homeworkTimeout,"readHW");//print the datails related to this employee
						cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;					}
				}	
				else if(random_act == incident){//action number 10
					
					is_any = is_any_match(all_emp,sec_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
					if(!is_any)
						cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
					else{

						emp_ind = find_emp_ind(all_emp,sec_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
						all_emp[emp_ind]->receivePetition();//make changes in happiness of employeee
						com_obj.modify_values(-1.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
						all_emp[emp_ind]->work(incident,"receivePetition");//print the datails related to this employee
						cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;
					}
				}	
				else if(random_act == solution){//action number 11

					random = rand() % (4 - 1 + 1) + 1;
					if(random == lecturer){//lecturer 

						is_any = is_any_match(all_emp,lec_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,lec_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							com_obj.modify_values(-2.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;						}	
					}
					else if(random == researchAssistant){//research assinstant 

						is_any = is_any_match(all_emp,res_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,res_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							com_obj.modify_values(-2.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;						}
					}
					else if(random == secretary){//security 						
						
						is_any = is_any_match(all_emp,sec_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,sec_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							com_obj.modify_values(-2.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;						}
					}
					else if(random == officer){//officer 
						
						is_any = is_any_match(all_emp,of_st,tech_uni->get_uni_name());//this function chekc whether do we realy have the matching employee who has the indecated job .
						if(!is_any)
							cout<<"THERE IS NO MATCHING EMPLOYEE!!!"<<endl;
						else{

							emp_ind = find_emp_ind(all_emp,of_st,tech_uni->get_uni_name());//randomly find and emplyee from the employee list 
							all_emp[emp_ind]->submitPetition();//make changes in happiness of employeee
							com_obj.modify_values(-2.0,1);//modify contribution since university is a tamplate class we can not change it's values through makedoc so we have to do it in this way!!!
							all_emp[emp_ind]->work(solution,"submitPetition");//print the datails related to this employee
							cout <<"["<<com_obj.get_real_do()<<" "<<com_obj.get_imagin_do()<<"i"<<"] ";
							cout << "["<<com_obj.get_real_int()<<" "<<com_obj.get_imagin_int()<<"i"<<"]"<<endl;					}
					}	
				}
				else{//exeption handaling part

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
			}
		}
	}

	/*deleting required pointers*/
	for (i = 0; i < EMP_COUNT; ++i){
		delete all_emp[i];
	}
	delete res_uni;
	delete lin_uni;
	delete tech_uni;

	inpfile.close();
	return 0;
}