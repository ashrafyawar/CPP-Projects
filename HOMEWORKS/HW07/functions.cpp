#include "headerfile.h"
#include"uni.h"
double totalmoney = 0;
void read_file(fstream& inpfile,vector<Persons>& per_vec){

	string name,surename;
	char occ;
	Persons one_per;
	inpfile>> name;
	while(!inpfile.eof()){
		
		inpfile>>surename;
		inpfile>>occ;
	
		one_per.name = name;
		one_per.surename = surename;
		one_per.accuracy = occ;

		per_vec.push_back(one_per);
		inpfile>> name;
	}
}//end of function
namespace Personal_Management{
	
	/*complex*/
	complex::complex(){ real_cont_do = imagin_cont_do = real_cont_int = imagin_cont_int = 0;}
  	complex complex:: operator++() {
   
	  	++real_cont_do;
	  	++imagin_cont_do;
		++real_cont_int;
		++imagin_cont_int;
    	 return complex(real_cont_do,imagin_cont_do,real_cont_int,imagin_cont_int);
  	}
	complex complex:: operator++(int){
  
	    // save the orignal value
	    complex T(real_cont_do,imagin_cont_do,real_cont_int,imagin_cont_int);

		++real_cont_do;
	  	++imagin_cont_do;
		++real_cont_int;
		++imagin_cont_int;
	     return T; 
  	}
  	complex complex:: operator--() {
   
	  	--real_cont_do;
	  	--imagin_cont_do;
		--real_cont_int;
		--imagin_cont_int;
    	 return complex(real_cont_do,imagin_cont_do,real_cont_int,imagin_cont_int);
  	}
	complex complex:: operator--(int){
  
	    // save the orignal value
	    complex T(real_cont_do,imagin_cont_do,real_cont_int,imagin_cont_int);

		--real_cont_do;
	  	--imagin_cont_do;
		--real_cont_int;
		--imagin_cont_int;
	     return T; 
  	}
  	complex::complex(const double& a1,const double& b1,const int& a2,const int& b2){ 
				
		real_cont_do = a1;
		imagin_cont_do = b1;
		real_cont_int = a2;
		imagin_cont_int = b2;
	}
	void complex:: set_contri(const double& real,const double& imagin){
				
		bool is_integer = true;

		is_integer  = is_int(real);
		if(is_integer)
			real_cont_int = real;
		else
			real_cont_do = real;
		
		is_integer = is_int(imagin);
		if(is_integer)
			imagin_cont_int = imagin;
		else
			imagin_cont_do = imagin;
	}
	double complex:: get_real_do(){ return real_cont_do;}
	double complex:: get_imagin_do(){ return imagin_cont_do;}
	int complex:: get_real_int(){ return real_cont_int;}
	int complex:: get_imagin_int(){ return imagin_cont_int;}
	void complex:: modify_values(const double& real,const double& imagin){
				
		bool is_integer = true;

		is_integer  = is_int(real);
		if(is_integer)
			real_cont_int += real;
		else
			real_cont_do += real;
		
		is_integer = is_int(imagin);
		if(is_integer)
			imagin_cont_int += imagin;
		else
			imagin_cont_do += imagin;
	}
	complex& complex ::operator +(const complex& old_emp){

		if ( this == &old_emp)
			return *this;
		else{

			this->real_cont_do = old_emp.real_cont_do;
			this->imagin_cont_do = old_emp.imagin_cont_do;
			this->real_cont_int = old_emp.real_cont_int;
			this->imagin_cont_int = old_emp.imagin_cont_int;
			return *this;
		}
	}

	/*Employee class*/
	Employee::Employee(){
	
		pid = happiness = 0;
		name  = surename = '\0';
		this->u_name ='\0';
		lec_count = 0;
		emptr = first_w = second_w = NULL;

	}
	Employee::Employee(const Employee& old_emp){

		this->pid = old_emp.pid;
		this->happiness = old_emp.happiness;
		this->name = old_emp.name;
		this->surename = old_emp.surename;
		this->u_name = old_emp.u_name;

	}
	Employee& Employee ::operator +(const Employee& old_emp){

		if ( this == &old_emp)
			return *this;
		else{

			this->pid = old_emp.pid;
			this->happiness = old_emp.happiness;
			this->name = old_emp.name;
			this->surename = old_emp.surename;
			this->u_name = old_emp.u_name;
			return *this;
		}
	}
	Employee::~Employee(){}
	int Employee:: get_happiness(){ return happiness;}
	string Employee:: get_name(){ return name;}
	string Employee:: get_surename(){ return surename; }
	string Employee:: get_u_name(){ return u_name;}
	string Employee ::get_prof_type(){ return prof_type;}
	void Employee:: set_u_name(string& st){ this->u_name = st;}
	void Employee:: modify_happiness(const int& a){ this->happiness += a; }
	void Employee:: set_name(const string& st){ this->name = st;}
	void Employee:: set_surename(const string& st){ this->surename = st; }
	void Employee::set_prof_type(const string& st){ prof_type = st;}
	void Employee::drinkTea(){this->modify_happiness(5);}
	void Employee::submitPetition(){this->modify_happiness(1);}

	/*Lecturer*/
	Lecturer:: Lecturer(){set_prof_type("Lecturer");}
	void Lecturer:: giveLesson(){ this->modify_happiness(1);}
	void Lecturer:: giveHW(){ this->modify_happiness(-2);}
	void Lecturer::work(Actions act,const string& job_name){
		string st;
		st =  action_name(act);
		cout<<get_name()<<" "<<get_surename()<<" have "<<st <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}

	ComLec:: ComLec(){set_prof_type("ComLec"); lec_count = 0;}
	void ComLec:: giveLesson(){modify_happiness(1);}
	void ComLec:: giveHW(){modify_happiness(-2);}
	void ComLec::work(Actions act,const string& job_name){

		string act_name;//action name
		act_name  = action_name(act);//get equivalent enum name for action.

		cout<<"(output)> "<<get_name()<<" "<<get_surename()<<" have "<<act_name <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}
	
	LibLec:: LibLec(){set_prof_type("LibLec");}
	void LibLec:: giveLesson(){this->modify_happiness(1);}
	void LibLec:: giveHW(){this->modify_happiness(-2);}
	void LibLec::work(Actions act,const string& job_name){
		string st;
		st = action_name(act);
		cout<<"(output)> University has "<<st<<". I did "<<job_name<<". My happiness is "<<
		get_happiness()<<" and my money is ";
	}

	BrokerLecturer:: BrokerLecturer(){set_prof_type("BrokerLecturer");}
	void BrokerLecturer:: giveLesson(){this->modify_happiness(1);}
	void BrokerLecturer:: giveHW(){this->modify_happiness(-2);}
	void BrokerLecturer::work(Actions act,const string& job_name){}

	WorkerLecturer:: WorkerLecturer(){set_prof_type("WorkerLecturer");}
	void WorkerLecturer:: giveLesson(){ this->modify_happiness(1); }
	void WorkerLecturer:: giveHW(){this->modify_happiness(-2);}
	void WorkerLecturer::work(Actions act,const string& job_name){
		string st;
		st =  action_name(act);
		cout<<get_name()<<" "<<get_surename()<<" have "<<st <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}

	/*ResearchAssistant*/
	ResearchAssistant :: ResearchAssistant(){set_prof_type("ResearchAssistant");}
	void ResearchAssistant:: research(){ this->modify_happiness(3);}
	void ResearchAssistant:: readHW(){ this->modify_happiness(-3);}
	void ResearchAssistant::work(Actions act,const string& job_name){
		string st;
		st =  action_name(act);
		cout<<get_name()<<" "<<get_surename()<<" have "<<st <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}

	ComResAssist :: ComResAssist(){set_prof_type("ComResAssist");lec_count = 0;}
	void ComResAssist:: research(){modify_happiness(3);}
	void ComResAssist:: readHW(){modify_happiness(-3);}
	void ComResAssist::work(Actions act,const string& job_name){

		string act_name;//action name
		act_name  = action_name(act);//get equivalent enum name for action.

		cout<<"(output)> "<<get_name()<<" "<<get_surename()<<" have "<<act_name <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}
	
	LibResAssist :: LibResAssist(){set_prof_type("LibResAssist");}
	void LibResAssist:: research(){this->modify_happiness(3);}
	void LibResAssist:: readHW(){this->modify_happiness(-3);}
	void LibResAssist::work(Actions act,const string& job_name){
		string st;
		st = action_name(act);
		cout<<"(output)> University has "<<st<<". I did "<<job_name<<". My happiness is "<<
		get_happiness()<<" and my money is ";
	}

	BrokerResAssist :: BrokerResAssist(){set_prof_type("BrokerResAssist");}
	void BrokerResAssist:: research(){this->modify_happiness(3);}
	void BrokerResAssist:: readHW(){this->modify_happiness(-3); }
	void BrokerResAssist::work(Actions act,const string& job_name){}

	WorkerResAssist :: WorkerResAssist(){set_prof_type("WorkerResAssist");}
	void WorkerResAssist:: research(){this->modify_happiness(3);}
	void WorkerResAssist:: readHW(){this->modify_happiness(-3); }
	void WorkerResAssist::work(Actions act,const string& job_name){

		string st;
		st =  action_name(act);
		cout<<get_name()<<" "<<get_surename()<<" have "<<st <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}

	/*Secretary*/
	Secretary:: Secretary(){ set_prof_type("Secretary");}
	void Secretary:: receivePetition(){ this->modify_happiness(-1);}
	void Secretary::work(Actions act,const string& job_name){
		string st;
		st =  action_name(act);
		cout<<get_name()<<" "<<get_surename()<<" have "<<st <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}

	ComSec:: ComSec(){ set_prof_type("ComSec");lec_count = 0;}
	void ComSec:: receivePetition(){this->modify_happiness(-1);}
	void ComSec::work(Actions act,const string& job_name){

		string act_name;//action name
		act_name  = action_name(act);//get equivalent enum name for action.

		cout<<"(output)> "<<this->get_name()<<" "<<this->get_surename()<<" have "<<act_name <<". Therefore,"<<this->get_name()<<" "<<
		this->get_surename() <<" "<< job_name<<". Happiness of "<<this->get_name()<<" "<<this->get_surename()<<" is "<<
		this->get_happiness()<<", contribution of uni is ";
	}

	LibSec:: LibSec(){ set_prof_type("LibSec");}
	void LibSec:: receivePetition(){this->modify_happiness(-1);}
	void LibSec::work(Actions act,const string& job_name){
		
		string st;
		st = action_name(act);
		cout<<"(output)> "<<"University has "<<st<<". I did "<<job_name<<". My happiness is "<<
		get_happiness()<<" and my money is ";
	}

	BrokerSecretary:: BrokerSecretary(){ set_prof_type("BrokerSecretary");}
	void BrokerSecretary:: receivePetition(){this->modify_happiness(-1);}
	void BrokerSecretary::work(Actions act,const string& job_name){}

	WorkerSecretary:: WorkerSecretary(){ set_prof_type("WorkerSecretary");}
	void WorkerSecretary:: receivePetition(){this->modify_happiness(-1);}
	void WorkerSecretary::work(Actions act,const string& job_name){
		string st;
		st =  action_name(act);
		cout<<get_name()<<" "<<get_surename()<<" have "<<st <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}

	/*Officer*/
	Officer ::Officer(){ this->set_prof_type("Officer");}
	void Officer:: makeDoc(){this->modify_happiness(-2);}
	void Officer::work(Actions act,const string& job_name){
		string st;
		st =  action_name(act);
		cout<<get_name()<<" "<<get_surename()<<" have "<<st <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}

	ComOff ::ComOff(){ this->set_prof_type("ComOff");lec_count = 0;}
	void ComOff:: makeDoc(){this->modify_happiness(-2);}
	void ComOff::work(Actions act,const string& job_name){

		string act_name;//action name
		act_name  = action_name(act);//get equivalent enum name for action.

		cout<<"(output)> "<<get_name()<<" "<<get_surename()<<" have "<<act_name <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}

	LibOff ::LibOff(){ this->set_prof_type("LibOff");}
	void LibOff:: makeDoc(){this->modify_happiness(-2);}
	void LibOff::work(Actions act,const string& job_name){

		string st;
		st = action_name(act);
		cout<<"(output)> "<<"University has "<<st<<". I did "<<job_name<<". My happiness is "<<
		get_happiness()<<" and my money is ";
	}

	BrokerOfficer ::BrokerOfficer(){ this->set_prof_type("BrokerOfficer");}
	void BrokerOfficer:: makeDoc(){this->modify_happiness(-2);}
	void BrokerOfficer::work(Actions act,const string& job_name){}

	WorkerOfficer ::WorkerOfficer(){ this->set_prof_type("WorkerOfficer");}
	void WorkerOfficer:: makeDoc(){this->modify_happiness(-2);}
	void WorkerOfficer::work(Actions act,const string& job_name){
		string st;
		st =  action_name(act);
		cout<<get_name()<<" "<<get_surename()<<" have "<<st <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}
}//end of namespace

