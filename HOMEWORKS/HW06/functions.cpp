#include "headerfile.h"
namespace My_Struct{

	void read_file(fstream& inpfile,vector<Persons>& per_vec){

		string name,surename;
		Persons one_per;
		inpfile>> name;
		while(!inpfile.eof()){
			
			inpfile>>surename;
			
			one_per.name = name;
			one_per.surename = surename;
			
			per_vec.push_back(one_per);
			inpfile>> name;
		}

	}//end of function
}
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

	/*Officer*/
	Officer ::Officer(){ set_prof_type("Officer");}
	void Officer:: makeDoc(){this->modify_happiness(-2);}

	void Officer::work(Actions act,const string& job_name){
		
		string st;
		st =  action_name(act);

		cout<<get_name()<<" "<<get_surename()<<" have "<<st <<". Therefore,"<<get_name()<<" "<<
		get_surename() <<" "<< job_name<<". Happiness of "<<get_name()<<" "<<get_surename()<<" is "<<
		get_happiness()<<", contribution of uni is ";
	}

	/*some stand alone functions*/
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

	int find_emp_ind(Employee **emp_ptr,const string& st,const string& uni_name){

		bool found = false;
		int random = 0;
		
		while(found == false){
			random = rand() % ((EMP_COUNT-1) - 0 + 1) + 0;
			if(emp_ptr[random]->get_prof_type() == st and uni_name == emp_ptr[random]->get_u_name()){
				return random;
			}
		}
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

}//end of namespace

