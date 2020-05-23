#ifndef HEADERFILE_H
#define HEADERFILE_H
#include"uni.h"
#include<iostream>//include libraries
#include<vector>
#include <fstream>//include libraries
#include<string>//include libraries
#include <ctime>//include libraries
#include<random>//include libraries
#define EMP_COUNT 30//count of emplyed Employees
#define UNI_COUNT 3
#define ARR_SIZE 4
#define LIB_ACT_COUNT 14
#define CAP_ACT_COUT 15
#define LIMIT 3
#define THRESHOLD 5
using namespace std;
enum Actions{document = 1,slackness = 2,project = 3,lesson = 4,seminar = 5,academicPaper = 6//enum type
,administration = 7,HomeworkTime = 8,homeworkTimeout = 9,incident = 10,solution = 11};
enum emp_enum{lecturer = 1,researchAssistant = 2,secretary = 3,officer = 4};
enum uni_enum{research = 1,linguistic = 2,technical = 3};

struct Persons{

	string name,surename,uniset ="empty";
	char accuracy;
};
void read_file(fstream&,vector<Persons>&);
namespace Personal_Management{//namespace for all the classes used in this project

	bool is_int(const double& a);
	class complex{

		public:

			complex();
			complex operator++();
			complex operator++(int);
			complex operator--();
			complex operator--(int);
			complex(const double&,const double&,const int&,const int&);

			void set_contri(const double&,const double&);
			double get_real_do();
			double get_imagin_do();
			int get_real_int();
			int get_imagin_int();
			void modify_values(const double& real,const double& imagin);
			complex& operator +(const complex&);

		private:
		
			double real_cont_do,imagin_cont_do;
			int real_cont_int,imagin_cont_int;
	};

	template<class T>
	class ComUni:public University<T>{

		public:

			ComUni(){}			
			
			T get_cont(){ return cont; }
			void set_uni_cont(T a){cont = a;}
			string get_uni_name(){return uni_name;}
			void set_uni_name(const string& st){ uni_name = st;}
			string get_uni_type(){ return uni_type;}
			void set_uni_type(string& uni_t){uni_type = uni_t;}
			string contribute(T element){cont += element; return " ";}
		private:	
			T cont;
			string uni_name;
			string uni_type;
	};
	template<class T>
	class LibUni:public University<T>{

		public:

			LibUni(){}			
			
			T get_cont(){ return cont; }
			void set_uni_cont(T a){cont = a;}
			string get_uni_name(){return uni_name;}
			void set_uni_name(const string& st){ uni_name = st;}
			string get_uni_type(){ return uni_type;}
			void set_uni_type(string& uni_t){ uni_type = uni_t;}
			string contribute(T element){cont += element; return " ";}
		private:
			T cont;
			string uni_name;
			string uni_type;
	};
	template<class T>
	class CapUni:public University<T>{

		public:

			CapUni(){}			
			
			T get_cont(){ return cont; }
			void set_uni_cont(T a){cont = a;}
			string get_uni_name(){return uni_name;}
			void set_uni_name(const string& st){ uni_name = st;}
			string get_uni_type(){ return uni_type;}
			void set_uni_type(string& uni_t){uni_type = uni_t;}
			string contribute(T element){cont += element; return " ";}
		private:	
			T cont;
			string uni_name;
			string uni_type;
	};

	class Employee{//employee class
		
		public:
			
			Employee();
			Employee(const Employee&);
			Employee& operator +(const Employee&);
			~Employee();
			
			int get_happiness();
			string get_name();
			string get_surename();
			string get_u_name();
			string get_prof_type();

			void set_u_name(string&);
			void modify_happiness(const int& );
			void set_name(const string&);
			void set_surename(const string&);
			void set_prof_type(const string&);
			
			void drinkTea();
			void submitPetition();
			virtual void work(Actions act,const string& st) = 0;
			virtual void makeDoc(){}
		    virtual void research(){}
		    virtual void giveLesson(){}
		    virtual void giveHW(){}
		    virtual void readHW(){}
		    virtual void receivePetition(){}
		    virtual void SetMoney(const double& num){}
		    virtual void SetToZero(){}
			virtual double GetMoney(){}

		    int lec_count = 0;
		    Employee *emptr = NULL,*first_w = NULL,*second_w = NULL;
		private:

			int pid;
			int happiness;
			string name;
			string surename;
			string u_name;
			string prof_type;
	};
	class Lecturer:public Employee{

		public:
			Lecturer();	
			virtual void giveLesson();
			virtual void giveHW();
			virtual void work(Actions act,const string&);
	};
	class ComLec: public Lecturer{
		
		public:
			ComLec();	
			void giveLesson();
			void giveHW();
			void work(Actions,const string&);
	};
	class LibLec: public Lecturer{
			
		public:
			LibLec();
			void giveLesson();
			void giveHW();
			void work(Actions,const string&);
	};
	class WorkerLecturer:public Lecturer{

		public:
			WorkerLecturer();	
			void giveLesson();
			void giveHW();
			void work(Actions,const string&);
	};
	class BrokerResAssist;
	class BrokerSecretary;
	class BrokerOfficer;
	class BrokerLecturer:public Lecturer{
		
		public:
			BrokerLecturer();	
			void giveLesson();
			void giveHW();
			void work(Actions,const string&);
			void SetMoney(const double& num){ Money += num;}
			double GetMoney(){ return Money;}
			void SetToZero(){Money = 0;}

		private:
			double Money = 0.0;	
	};
	class ResearchAssistant:public Employee{
		
		public:
			ResearchAssistant();
			void research();
			void readHW();
			void work(Actions act,const string&);
		private:
	};
	class ComResAssist:public ResearchAssistant{
		
		public:
			ComResAssist();
			void research();
			void readHW();
			void work(Actions act,const string&);
	};
	class LibResAssist:public ResearchAssistant{
		
		public:
			LibResAssist();
			void research();
			void readHW();
			void work(Actions act,const string&);
		private:
	};
	class WorkerResAssist:public ResearchAssistant{
		
		public:
			WorkerResAssist();
			void research();
			void readHW();
			void work(Actions act,const string&);
	};
	class BrokerResAssist:public ResearchAssistant{
		
		public:
			BrokerResAssist();
			void research();
			void readHW();
			void work(Actions act,const string&);
			void SetMoney(const double& num){ Money += num;}
			void SetToZero(){Money = 0;}
			double GetMoney(){ return Money;}
		private:
		double Money = 0.0;	

	};
	/*Secratary class*/
	class Secretary:public Employee{
	
		public:
			Secretary();
			void receivePetition();
			void work(Actions act,const string&);
		private:
	};
	class ComSec:public Secretary{
	
		public:
			ComSec();
			void receivePetition();
			void work(Actions act,const string&);	

	};
	class LibSec:public Secretary{
	
		public:
			LibSec();
			void receivePetition();
			void work(Actions act,const string&);
		private:
	};
	class WorkerSecretary:public Secretary{
	
		public:
			WorkerSecretary();
			void receivePetition();
			void work(Actions act,const string&);
	};
	class BrokerSecretary:public Secretary{
	
		public:
			BrokerSecretary();
			void receivePetition();
			void work(Actions act,const string&);
			void SetMoney(const double& num){ Money += num;}
			void SetToZero(){Money = 0;}
			double GetMoney(){ return Money;}
		private:
			double Money = 0.0;	
	};
	/*Worker class*/
	class Officer:public Employee{
		
		public:
			Officer();
			virtual void makeDoc();
			void work(Actions,const string&);
	};
	class ComOff:public Officer{
		
		public:
			ComOff();
			void makeDoc();
			void work(Actions,const string&);
	};
	class LibOff:public Officer{
		
		public:
			LibOff();
			void makeDoc();
			void work(Actions,const string&);
	};
	class WorkerOfficer:public Officer{
		
		public:
			WorkerOfficer();
			void makeDoc();
			void work(Actions,const string&);
	};
	class BrokerOfficer:public Officer{
		
		public:
			BrokerOfficer();
			void makeDoc();
			void work(Actions,const string&);
			void SetMoney(const double& num){ Money += num;}
			double GetMoney(){ return Money;}
			void SetToZero(){Money = 0;}

		private:
			double Money = 0.0;	
	};
	
	template<class T>
	class EducationSystem{

		public:
			virtual	Employee* giveJob(const string& name,const string& s_name,emp_enum em_t) = 0;
			virtual	University<T>* foundUni(uni_enum uni_t) = 0;	
	};
	template<class T>
	class CommunistEducation:public EducationSystem<T>{

		public:
			CommunistEducation(){}
			Employee* giveJob(const string& name,const string& s_name,emp_enum em_t){

				Employee *em_ptr;
				if(em_t == lecturer){

					em_ptr = new ComLec;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				else if(em_t == researchAssistant){
				
					em_ptr = new ComResAssist;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				else if(em_t == secretary){
				
					em_ptr = new ComSec;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				else if(em_t == officer){
				
					em_ptr= new ComOff;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				return em_ptr;
			}
			ComUni<T>* foundUni(uni_enum uni_t){
				ComUni<T> *a =new ComUni<T>;
				return a;
			}
	};
	template<class T>
	class LiberalEducation :public EducationSystem<T>{

		public:
			LiberalEducation(){}
			Employee* giveJob(const string& name,const string& s_name,emp_enum em_t){

				Employee *em_ptr;
				if(em_t == lecturer){

					em_ptr = new LibLec;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				else if(em_t == researchAssistant){
				
					em_ptr = new LibResAssist;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				else if(em_t == secretary){
				
					em_ptr = new LibSec;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				else if(em_t == officer){
				
					em_ptr= new LibOff;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				return em_ptr;
			}

			LibUni<T>* foundUni(uni_enum uni_t){

				LibUni<T> *a =new LibUni<T>;
				return a;
			}
	};
	template<class T>
	class CapitalistEducation :public EducationSystem<T>{

		public:
			CapitalistEducation(){}
			Employee* giveJob(const string& name,const string& s_name,emp_enum em_t){

				Employee *em_ptr;
				if(em_t == lecturer){

					em_ptr = new Lecturer;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				else if(em_t == researchAssistant){
				
					em_ptr = new ResearchAssistant;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				else if(em_t == secretary){
				
					em_ptr = new Secretary;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				else if(em_t == officer){
				
					em_ptr= new Officer;
					em_ptr->set_name(name);
					em_ptr->set_surename(s_name);
				}
				return em_ptr;
			}

			CapUni<T>* foundUni(uni_enum uni_t){

				CapUni<T> *a =new CapUni<T>;
				return a;
			}
	};
}//end of namespace
#endif