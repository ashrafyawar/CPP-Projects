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

struct Classroom{
	
	int id = 0;
	string c_no =" ";
	int capacity = 0;
	int student_inroom = 0;

	vector<int> co_id_list;
	vector<int> lec_id_list;
};
class Lecturer{	

	public:

		Lecturer();
		bool proposeCourse(vector<Cours>& ,const string& ,const int& ,const int& ,const int& ,const string& );
		void assignCourse(vector<Cours>& ,const string& ,const int& ,const int& ,const int& ,const string& );
		void assignCourse(const vector<Cours>& coures_vec,const int&);
		void set_lec(const int&,const string&,const string&,const string&);
		void fill_lecturers_professions(const char*);
		void set_courese_Dates(vector<Cours>&);
		int get_prof_cout();
		string get_lec_name();
		int get_lec_personal_id();
		void set_prof_count(int&a);
		int get_cours_count();
		string get_lec_title();
		void set_cours_count(int& a);
		bool is_field_professions_match(const string&);//checks for matching of the cours field and lectures professions.

		friend  bool is_all_assigned(Lecturer Lec_arr[LECTURERS_QUANTITY]);
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
		void arrangeTimeTable(Lecturer&,const vector<Cours>&);
		void arrangeTimeTable(vector<Cours>&,const int&,const char&);
		void print_timetable(Lecturer& Lec_arr);
		void set_timetable_arranged_fun();
		int check_timetable_arranged();
		void arrangeClassroom(vector<Cours>&,vector<Classroom>&,const int&,const int&,const char&);
		void arrangeClassroom( Lecturer& one_lec);
	private:

	int is_timetable_arranged;
	int pid;
	int password;	

};

void fill_coures(fstream& cr_cl_f,vector<Cours>& coures_vec);
void fill_class(fstream& cr_cl_f,vector<Classroom>& classes_vec);
void fill_lectureres(fstream& Lec_file,Lecturer Lec_arr[LECTURERS_QUANTITY]);
int assignCourses_to_lecturers(Cours& coures_vec,Lecturer& Lec_arr,const int& course_index,const char& one);
bool  is_all_assigned(Lecturer Lec_arr[LECTURERS_QUANTITY],int& index);
bool check_cours_existence(const vector<Cours>& coures_vec,const int& course_id);
bool check_class_existence(const vector<Classroom>& classes_vec,const int& class_id);
bool is_comma_exist(const string& test_st);
bool is_cours_assingned_to_class(const vector<Cours>& coures_vec,const int& course_id);
string generte_day_name(const int& random);
#endif