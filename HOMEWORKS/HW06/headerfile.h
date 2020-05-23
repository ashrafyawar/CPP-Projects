#ifndef HEADERFILE_H
#define HEADERFILE_H

#include<iostream>//include libraries
#include<vector>
#include <fstream>//include libraries
#include<string>//include libraries
#include <ctime>//include libraries
#include<random>//include libraries
#define EMP_COUNT 30//count of emplyed Employees
#define RAND_ACT 50//count of random actions.
#define UNI_COUNT 3
using namespace std;

enum Actions{document = 1,slackness = 2,project = 3,lesson = 4,seminar = 5,academicPaper = 6//enum type
,administration = 7,HomeworkTime = 8,homeworkTimeout = 9,incident = 10,solution = 11};
enum emp_enum{lecturer = 1,researchAssistant = 2,secretary = 3,officer = 4};
enum uni_enum{research = 1,linguistic = 2,technical = 3};

namespace My_Struct{

	struct Persons{

		string name,surename,uniset ="empty";
	};
	void read_file(fstream&,vector<Persons>&);
}

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
	class University{//university class
	
		public:
			/*i made these functions inline cause it dosn't work in any other ways to be implemented*/
			T get_cont(){ return this->cont; }
			void set_uni_cont(T a){cont = a;}
			string get_uni_name(){return this->uni_name;}
			void set_uni_name(const string& st){ this->uni_name = st;}
			string get_uni_type(){ return uni_type;}
			void set_uni_type(string& uni_t){ this->uni_type = uni_t;}
			string contribute(T element){cont = cont + element; return " ";}
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
		private:

			int pid;
			int happiness;
			string name;
			string surename;
			string u_name;
			string prof_type;
	};
	class Lecturer : public Employee{

		public:
			Lecturer();	
			void giveLesson();
			void giveHW();
			void work(Actions act,const string&);
		private:
	};
	class ResearchAssistant: public Employee{
		
		public:
			ResearchAssistant();
			void research();
			void readHW();
			void work(Actions act,const string&);
		private:
	};
	class Secretary: public Employee{
	
		public:
			Secretary();
			void receivePetition();
			void work(Actions act,const string&);
		private:
	};
	class Officer : public Employee{
		
		public:
			Officer();
			void makeDoc();
			void work(Actions,const string&);
		private:
	};
	template<class T>
	class YOK{

		public:

			YOK(){}
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
			University<T>* foundUni(uni_enum uni_t){
				University<T> *a =new University<T>;
				return a;
			}
	};
	/*some stand alone functions*/
	string action_name(const int& value);
	bool is_any_match(Employee **,const string&,const string&);
	int find_emp_ind(Employee**,const string&,const string&);

}//end of namespace
#endif