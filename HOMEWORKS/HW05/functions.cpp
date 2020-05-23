#include "headerfile.h"

namespace Personal_Management{

	/*University*/
	University::University(){

		contribution = 0;
	}
	int University:: get_contribution(){ return contribution; }
	void University:: modify_contribution(const int& modi){ this->contribution += modi;}
	/*Employee class*/
	Employee::Employee(){
	
		pid = happiness = 0;
		name  = surename = " ";
		emp = nullptr; 
	}
	Employee::Employee(const Employee& old_emp){

		this->pid = old_emp.pid;
		this->happiness = old_emp.happiness;
		this->name = old_emp.name;
		this->surename = old_emp.surename;
		this->emp = old_emp.emp;

	}
	Employee& Employee ::operator +(const Employee& old_emp){

		if ( this == &old_emp)
			return *this;
		else{

			this->pid = old_emp.pid;
			this->happiness = old_emp.happiness;
			this->name = old_emp.name;
			this->surename = old_emp.surename;
			this->emp = old_emp.emp;
			return *this;
		}
	}

	Employee::~Employee(){

	}

	int Employee:: get_pid(){ return pid;}
	int Employee:: get_happiness(){ return happiness;}
	
	string Employee:: get_name(){ return name;}
	string Employee:: get_surename(){ return surename; }
	
	University* Employee:: get_emp(){ return emp;}

	void Employee:: set_pid(const int& a){ this->pid = a; }
	void Employee:: modify_happiness(const int& a){ this->happiness += a; }
	void Employee:: set_name(const string& st){ this->name = st;}
	void Employee:: set_surename(const string& st){ this->surename = st; }
	void Employee:: set_emp(University* p){ emp = p;}
	
	void Employee::drinkTea(const int& random_act){
		
		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.

		modify_happiness(5);
		emp->modify_contribution(-2);

		cout<<name<< " "<<surename<<" have "<<act_name<<".Therefore "<<name<< " "<<surename
		<<" drinkTea."<<"Happiness of "<<name<< " "<<surename<< "is "<<happiness<< ",contribution of uni is "<< emp->get_contribution()<<endl;
	}
	void Employee::submitPetition(const int& random_act){

		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.
		
		modify_happiness(1);
		emp->modify_contribution(-2);

		cout<<name<< " "<<surename<<" have "<<act_name<<".Therefore "<< name<< " "<<surename
		<< " submitPetition."<<"Happiness of "<<name<< " "<<this->surename<< "is "<<happiness
		<<",contribution of uni is "<<this->emp->get_contribution()<<endl;
	}
	void Employee::employ(){}
	
	/*AcademicPersonnel*/
	AcademicPersonnel::AcademicPersonnel(){}

	void AcademicPersonnel:: seeSuccessfulStudent(const int& random_act){

		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.
		
		modify_happiness(10);
		get_emp()->modify_contribution(0);

		cout<<this->get_name() << " "<< this->get_surename() <<" have "<<act_name<<".Therefore "<< this->get_name() << " "<<this->get_surename()
		<< " seeSuccessfulStudent."<<"Happiness of "<<this->get_name() << " "<<this->get_surename() << "is "<<this->get_happiness()
		<<",contribution of uni is "<<this->get_emp()->get_contribution()<<endl;
	}
	void AcademicPersonnel:: makePublish(const int& random_act){

		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.

		modify_happiness(2);
		get_emp()->modify_contribution(5);

		cout<<this->get_name() << " "<< this->get_surename() <<" have "<<act_name<<".Therefore "<< this->get_name() << " "<<this->get_surename()
		<< " makePublish."<<"Happiness of "<<this->get_name() << " "<<this->get_surename() << "is "<<this->get_happiness()
		<<",contribution of uni is "<<this->get_emp()->get_contribution()<<endl;
	}
	
	/*Lecturer*/
	Lecturer:: Lecturer(){}
	void Lecturer:: giveLesson(const int& random_act){
		
		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.
		
		modify_happiness(1);
		get_emp()->modify_contribution(5);
		
		cout<<this->get_name() << " "<<this->get_surename() <<" have "<<act_name<<".Therefore "<<this->get_name() << " "<<this->get_surename()
		<< " giveLesson."<<"Happiness of "<<this->get_name() << " "<<this->get_surename() << "is "<<this->get_happiness()<<",contribution of uni is "<<
		this->get_emp()->get_contribution()<<endl;
	}
	void Lecturer:: giveHW(const int& random_act){
	
		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.
		
		modify_happiness(-2);
		get_emp()->modify_contribution(1);
		
		cout<<this->get_name() << " "<< this->get_surename() <<" have "<<act_name<<".Therefore "<< this->get_name() << " "<<this->get_surename()
		<< " giveHW."<<"Happiness of "<<this->get_name() << " "<<this->get_surename() << "is "<<this->get_happiness()
		<<",contribution of uni is "<<this->get_emp()->get_contribution()<<endl;

	}
	
	/*ResearchAssistant*/
	ResearchAssistant :: ResearchAssistant(){}
	void ResearchAssistant:: research(const int& random_act){

		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.

		modify_happiness(3);
		get_emp()->modify_contribution(4);

		cout<<this->get_name() << " "<<this->get_surename() <<" have "<<act_name<<".Therefore "<<this->get_name() << " "<<this->get_surename()
		<< " research."<<"Happiness of "<<this->get_name() << " "<<this->get_surename() << "is "<<this->get_happiness()<<",contribution of uni is "<<
		this->get_emp()->get_contribution()<<endl;

	}
	void ResearchAssistant:: readHW(const int& random_act){

		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.
		
		modify_happiness(-3);
		get_emp()->modify_contribution(2);

		cout<<this->get_name() << " "<< this->get_surename() <<" have "<<act_name<<".Therefore "<< this->get_name() << " "<<this->get_surename()
		<< " readHW."<<"Happiness of "<<this->get_name() << " "<<this->get_surename() << "is "<<this->get_happiness()
		<<",contribution of uni is "<<this->get_emp()->get_contribution()<<endl;
	}

	/*AdministrativePersonnel*/
	AdministrativePersonnel::AdministrativePersonnel(){}
	void AdministrativePersonnel:: manageProcess(const int& random_act){
		
		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.

		modify_happiness(-1);
		get_emp()->modify_contribution(2);

		cout<<this->get_name() << " "<< this->get_surename() <<" have "<<act_name<<".Therefore "<< this->get_name() << " "<<this->get_surename()
		<< " manageProcess."<<"Happiness of "<<this->get_name() << " "<<this->get_surename() << "is "<<this->get_happiness()
		<<",contribution of uni is "<<this->get_emp()->get_contribution()<<endl;

	}

	/*Secretary*/
	Secretary:: Secretary(){}
	void Secretary:: receivePetition(const int& random_act){

		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.
		
		modify_happiness(-1);
		get_emp()->modify_contribution(-1);

		cout<<this->get_name() << " "<< this->get_surename() <<" have "<<act_name<<".Therefore "<< this->get_name() << " "<<this->get_surename()
		<< " receivePetition."<<"Happiness of "<<this->get_name() << " "<<this->get_surename() << "is "<<this->get_happiness()
		<<",contribution of uni is "<<this->get_emp()->get_contribution()<<endl;
	}

	/*Officer*/
	Officer ::Officer(){}
	void Officer:: makeDoc(const int& random_act){
	
		string act_name;//action name
		act_name  = action_name(random_act);//get equivalent enum name for action.

		modify_happiness(-2);
		get_emp()->modify_contribution(3);

		cout<< this->get_name()<< " "<<this->get_surename()<<" have "<<act_name<<".Therefore "<<this->get_name()<< " "<<
		this->get_surename()<< " makeDoc."<<"Happiness of "<< this->get_name()<< " "<<this->get_surename()<< "is "<<
		this->get_happiness()<<",contribution of uni is "<< this->get_emp()->get_contribution()<<endl;

	}

	/*some stand alone functions*/
	void read_file(fstream& inpfile,vector<Lecturer>& Lec_vec,vector<ResearchAssistant>& Re_vec,vector<Secretary>& Sec_vec,vector<Officer>& Of_vec){

		string input,name,surename;
		Lecturer single_Lec;
		ResearchAssistant single_Re;
		Secretary single_Sec;
		Officer single_Of;

		inpfile>> input;
		while(!inpfile.eof()){
			
			if(input == "Lecturer"){
				
				inpfile >> name >> surename;
				single_Lec.set_name(name);
				single_Lec.set_surename(surename);
				Lec_vec.push_back(single_Lec);				
			}
			else if(input == "ResearchAssistant"){
				
				inpfile >> name >> surename;
				single_Re.set_name(name);
				single_Re.set_surename(surename);
				Re_vec.push_back(single_Re);
			}
			else if(input == "Secretary"){
			
				inpfile >> name >> surename;
				single_Sec.set_name(name);
				single_Sec.set_surename(surename);
				Sec_vec.push_back(single_Sec);
			}
			else if(input == "Officer"){
				
				inpfile >> name >> surename;
				single_Of.set_name(name);
				single_Of.set_surename(surename);
				Of_vec.push_back(single_Of);
			}
			inpfile>> input;
		}

	}//end of function
	void Employ(University* Uniptr,vector<Lecturer>& Lec_vec,vector<ResearchAssistant>& Re_vec,vector<Secretary>& Sec_vec,vector<Officer>& Of_vec){

		//Employ first elements of the all vector objects once...
	
		int i,random = 0;
		bool flag = false;
		
		Lec_vec[0].set_emp(Uniptr);
		Re_vec[0].set_emp(Uniptr);
		Sec_vec[0].set_emp(Uniptr);
		Of_vec[0].set_emp(Uniptr);

		for (i = 0; i < (EMP_COUNT - 4); ++i){

			random = rand() % (4 - 1 + 1) + 1;//generate random number between 			
			flag = false;
			
			if(random == 1){

				while(flag == false){
					
					random = rand() % ((Lec_vec.size()-1) - 0 + 1) + 0;			
					if(Lec_vec[random].get_emp() == nullptr){

						Lec_vec[random].set_emp(Uniptr);		
						flag = true;
					}
				}
			}
			else if(random == 2){

				while(flag == false){

					random = rand() % ((Re_vec.size()-1) - 0 + 1) + 0;			
					if(Re_vec[random].get_emp() == nullptr){

						Re_vec[random].set_emp(Uniptr);	
						flag = true;
					}
				}
			}
			else if(random == 3){

				while(flag == false){

					random = rand() % ((Sec_vec.size()-1) - 0 + 1) + 0;			
					if(Sec_vec[random].get_emp() == nullptr){

						Sec_vec[random].set_emp(Uniptr);
						flag = true;
					}
				}
			}
			else if(random == 4){

				while(flag == false){

					random = rand() % ((Of_vec.size()-1) - 0 + 1) + 0;			
					if(Of_vec[random].get_emp() == nullptr){
						
						Of_vec[random].set_emp(Uniptr);
						flag = true;
					}
				}
			}
		}

	}//end of function
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
	int FindSmallestIndex(vector<Lecturer>& Lec_vec){

		int i = 0,index = 0;
		int min = Lec_vec[0].get_happiness();

       for(i = 0; i < Lec_vec.size(); i++){
           
            if(min > Lec_vec[i].get_happiness() and Lec_vec[i].get_emp() != nullptr){
                min = Lec_vec[i].get_happiness();
                index = i;
            }
        }
        return index;
	}
	int FindSmallestIndex(vector<ResearchAssistant>& Re_vec){

		int i = 0,index = 0;
		int min = Re_vec[0].get_happiness();

       for(i = 0; i < Re_vec.size(); i++){

            if(min > Re_vec[i].get_happiness() and Re_vec[i].get_emp() != nullptr){
                min = Re_vec[i].get_happiness();
                index = i;
            }
        }
        return index;
	}
	int FindSmallestIndex(vector<Secretary>& Sec_vec){

		int i = 0,index = 0;
		int min = Sec_vec[0].get_happiness();

       for(i = 0; i < Sec_vec.size(); i++){
           
            if(min > Sec_vec[i].get_happiness() and Sec_vec[i].get_emp() != nullptr){
                min = Sec_vec[i].get_happiness();
                index = i;
            }
        }
        return index;
	}
	int FindSmallestIndex(vector<Officer>& Of_vec){

		int i = 0,index = 0;
		int min = Of_vec[0].get_happiness();

       for(i = 0; i < Of_vec.size(); i++){
           
            if(min > Of_vec[i].get_happiness() and Of_vec[i].get_emp() != nullptr){
                min = Of_vec[i].get_happiness();
                index = i;
            }
        }
        return index;
	}
}//end of namespace

