#ifndef HEADERFILE_H
#define HEADERFILE_H

#include<iostream>//include libraries
#include <fstream>//include libraries
#include<string>//include libraries
#include <ctime>//include libraries
#include<random>//include libraries
#define EMP_COUNT 10//count of emplyed Employees
#define RAND_ACT 50//count of random actions.
using namespace std;

enum Actions{document = 1,slackness = 2,project = 3,lesson = 4,seminar = 5,academicPaper = 6//enum type
,administration = 7,HomeworkTime = 8,homeworkTimeout = 9,incident = 10,solution = 11};

namespace Personal_Management{//namespace for all the classes used in this project

	class University{//university class
	
		public:
			
			University();
			int get_contribution();
			void modify_contribution(const int&);
		private:
			int contribution;
	};

	class Employee{//employee class
		
		public:
			
			Employee();
			Employee(const Employee&);
			Employee& operator +(const Employee&);
			~Employee();
			
			int get_pid();
			int get_happiness();
			string get_name();
			string get_surename();
			University* get_emp();

			void set_pid(const int&);
			void modify_happiness(const int&);
			void set_name(const string&);
			void set_surename(const string&);
			void set_emp(University*);

			void drinkTea(const int&);
			void submitPetition(const int&);
			void employ();

		private:

			int pid;
			int happiness;
			string name;
			string surename;
			University *emp;
	};

	class AcademicPersonnel: public Employee{
		
		public:
			AcademicPersonnel();
			void seeSuccessfulStudent(const int&);
			void makePublish(const int&);	
	};
	class Lecturer : public AcademicPersonnel{

		public:
			Lecturer();	
			void giveLesson(const int&);
			void giveHW(const int&);
		private:

	};
	class ResearchAssistant : public AcademicPersonnel{
		
		public:
			ResearchAssistant();
			void research(const int&);
			void readHW(const int&);
	};
	class AdministrativePersonnel : public Employee{
		public:
			AdministrativePersonnel();
			void manageProcess(const int&);
		
	};
	class Secretary : public AdministrativePersonnel{
		public:
			Secretary();
			void receivePetition(const int&);
		private:
	};
	class Officer : public AdministrativePersonnel{
		public:
			Officer();
			void makeDoc(const int&);
		private:	
	};

	/*some stand alone functions*/
	void read_file(fstream&,vector<Lecturer>&,vector<ResearchAssistant>&,vector<Secretary>&,vector<Officer>&);
	void Employ(University*,vector<Lecturer>&,vector<ResearchAssistant>&,vector<Secretary>&,vector<Officer>&);
	string action_name(const int& value);
	
	int FindSmallestIndex(vector<Lecturer>&);//finds the index of object in vector which has smallest happiness value
	int FindSmallestIndex(vector<ResearchAssistant>&);//finds the index of object in vector which has smallest happiness value
	int FindSmallestIndex(vector<Secretary>&);//finds the index of object in vector which has smallest happiness value
	int FindSmallestIndex(vector<Officer>&);//finds the index of object in vector which has smallest happiness value
}//end of namespace
#endif