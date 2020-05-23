#ifndef STRUCTS_CLASSES_H
#define STRUCTS_CLASSES_H

#include<iostream>
#include <fstream>
#include<vector>
#include <string>
#include<cstring>
#include <random>
#include<ctime>

using namespace std;
#define COURS_QUANTITY 18
#define CLASS_QUANTITY 6	
#define LECTURERS_QUANTITY 7
#define LEC_LIMIT 50//
#define TEMPORAR 30//used to maintain the parsing during the program.
#define ELEC_CO_LIM_H 3//limit total hours for elective course

namespace all_classes{//namespace for all the classes used in this project
	class Classroom;
	struct student_info{
		
		int count_hrs;
		int st_id;
		bool st_in_class;
		bool filled;
		string st_name;
		vector<int> keep_hours;
	};

	struct daily_classes{//struct holds the spilited version of each coures day and corresponding start ad end hours.

		string day_name;
		int start_class;
		int end_class;

	};
	struct Cours{
		
		int id = 0;
		int code = 0;
		int credit = 0;
		int total_hours = 0;
		int is_Mandatory = 0;
		int is_assigned = 0;
		int is_date_assigned = 0;
		int is_assigned_to_class = 0;
		string name;
		string field;

		vector<daily_classes> lecture_dates;
		vector<int> classes_ids_vec;
	};
	class student{
		
		private:

			string name;    
			string surename;
			int student_no;
			int level;
			int credit_right;
			int current_credit;
			int in_a_class;
			int class_id;
		public:
				
			student();
			
			student(const student&);
			student& operator =(const student&);
			~student();

			vector<int> courses_list;//holds indexes of the corresponding selected subjects.
			vector<int> overlap_right;
						
			int get_st_num();
			int get_st_level();
			int get_st_credit_right();
			int get_st_current_credit();
			string get_st_name();
			string get_st_surename();
			int get_st_in_a_class();
			int get_class_id();

			void set_st_in_a_class(const int&);			
			void set_student(const string&,const string&,const int&,const int&);//sets the student and creats an object for it.		
			void set_class_id(const int&);
			bool is_st_in_old_class(vector<Classroom>&,const int&);

			friend bool student_exist(const vector<student>&,int&);//checks for existing of a student in the list after registration.
			friend 	bool check_same_student(const vector<student>&,const string&,const string&,const int&,const int&);
			//friend bool credit_overlap(const vector<student>&,const int&,const int&);//checks for credit ovelap and gives warning if credit is ovelapted.
		 	friend bool check_for_same_id(const vector<student>&,const int&);
		 	friend bool check_in_other_classroom(vector<student>&,const int&);
		 	//friend bool courses_overlap(student&,const int&,Cours coures[COURS_QUANTITY]);//controls overlap of the subjects.*/
	};
	class Classroom{
	
		public:

			Classroom();
			Classroom(const Classroom&);
			Classroom& operator =(const Classroom&);
			~Classroom();

			void set_class_id(const int&);
			void set_class_no(const string&);
			void set_class_capacity(const int&);
			void incerement_student_in_room(const int&);

			int get_class_id();
			int get_class_capacity();
			int get_class_student_in_room();
			string get_class_no();
			
			void set_dynamic();
			void enterClassroom(vector<student>&,const int&,const int&);
			void quitClassroom();
			
			vector<int> lec_id_list;
			vector<Cours> course_list;
			struct student_info **st_ptr;

		private:
		
			int id;
			string c_no;
			int capacity;
			int student_inroom;
	};
	class Lecturer{	

		public:

			Lecturer();
			Lecturer(const Lecturer&);
			Lecturer& operator =(const Lecturer&);
			~Lecturer();
			
			void assignCourse(vector<Cours>& ,const string& ,const int& ,const int& ,const int& ,const string& );
			void assignCourse(const vector<Cours>& coures_vec,const int&);
			void set_lec(const int&,const string&,const string&,const string&);
			void fill_lecturers_professions(const char*);
			void set_courese_Dates(vector<Cours>&);
			bool proposeCourse(vector<Cours>& ,const string& ,const int& ,const int& ,const int& ,const string& );
			bool is_field_professions_match(const string&);//checks for matching of the cours field and lectures professions.

			int get_prof_cout();
			string get_lec_name();
			int get_lec_personal_id();
			void set_prof_count(int&a);
			int get_cours_count();
			string get_lec_title();
			void set_cours_count(int& a);
			
			friend bool check_lec_exestence(Lecturer Lec_arr[LECTURERS_QUANTITY],const int&);
			friend void set_last_cours(Lecturer Lec_arr[LECTURERS_QUANTITY],Lecturer&);

			vector<Cours> parallel_date_vec;
			vector<int> courses_list;	  
			vector<string> professions;
			vector<Classroom> classrooms;
		private:

			int cours_count;
			int personal_id;
			int prof_count;
			
			string name;
			string surename;
			string title;
	};
	
	class Administrator{

		public:
		
			Administrator();
			Administrator(const Administrator&);
			Administrator& operator=(const Administrator&);
			~Administrator();

			void arrangeTimeTable(Lecturer&,const vector<Cours>&);
			void set_timetable_arranged_fun();
			void arrangeClassroom( Lecturer& one_lec);
			int check_timetable_arranged();

		private:

		int is_timetable_arranged;
		int pid;
		int password;	

	};
	
	void fill_coures(fstream&,vector<Cours>& );
	void fill_class(fstream&,vector<Classroom>&);
	void fill_lectureres(fstream&,Lecturer Lec_arr[]);
	void timetable_arrangement(Administrator& Admin,Lecturer Lec_arr[],vector<Cours>& coures_vec);
	void coureses_to_lecturers(Lecturer Lec_arr[],vector<Cours>&);
	void set_timetable(Administrator& Admin,Lecturer Lec_arr[],vector<Cours>& coures_vec);
	void arrangeClassroom(Administrator&,Lecturer Lec_arr[],vector<Classroom>&,vector<Cours>&);
	void fill_class_from_coureses(Lecturer Lec_arr[],vector<Classroom>& c_vec);
	void fill_classes_structs(vector<Classroom>&);
	void  print_attendece(vector<Classroom>&,vector<student>&, const int&);

	bool check_lec_exestence(Lecturer Lec_arr[],const int&);
	bool check_cours_existence(const vector<Cours>& coures_vec,const int&);
	bool check_class_existence( vector<Classroom>&,const int&);
	
	int assignCourses_to_lecturers(Cours& coures_vec,Lecturer& Lec_arr,const int&);
	
	string generte_day_name(const int&);
	string find_matched_day(const int&);
	
}
#endif