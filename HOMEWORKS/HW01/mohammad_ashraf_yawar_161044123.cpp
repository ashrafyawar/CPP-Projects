#include<iostream>
#include <fstream>
#include<vector>
#include<string>
#include <sstream>
#include<cstring>//i used this library in order to use strtok to tokanize my strins file.
using namespace std;
#define COURS_QUANTITY 8
#define CLASS_QUANTITY 6
#define LIMIT 40//i used this limit size to make use of strtok which expect a string to tokinize while getting it from the file
struct daily_classes{//struct holds the spilited version of each coures day and corresponding start ad end hours.

	string day_name;
	int start_class;
	int end_class;

};
struct Cours{
	
	int id;
	int code;
	int credit;
	int total_hours;
	int is_ovelap;

	vector<daily_classes> lecture_dates;
	string name;
};

struct Classroom{
	
	int id;
	string c_no;
	int capacity;
	int student_inroom;
};
class student{
	
	private:

		string name;
		string surename;
		int student_no;
		int level;
		int credit_right;
		int current_credit;
	public:
		vector<int> courses_list;//holds indexes of the corresponding selected subjects.
		vector<int> overlap_right;
		
		student();//dafault constructor.
		
		int get_st_num();
		int enrollCours(const Cours&,const int&);
		int disenroll(const Cours st_couses[COURS_QUANTITY],const int&);
		void enterClassroom(Classroom&,bool&);
		void quitClassroom(Classroom&);
		void set_student(const string&,const string&,const int&,const int&);//sets the student and creats an object for it.		
		string extractSchedule(const Cours st_couses[COURS_QUANTITY]);//prints one students info
		
		friend bool student_exist(const vector<student>&,int&);//checks for existing of a student in the list after registration.
		friend bool check_same_student(const vector<student>&,const string&,const string&,const int&,const int&);// check for duplicate students.
		friend bool credit_overlap(const vector<student>&,const int&,const int&);//checks for credit ovelap and gives warning if credit is ovelapted.
	 	friend bool check_for_same_id(const vector<student>&,const int&);
	 	friend bool courses_overlap(student&,const int&,Cours coures[COURS_QUANTITY]);//controls overlap of the subjects.

};
void fill_daily_class_struct( struct daily_classes&,char*,int&,int&);
void test();

int main(){																			
	
	test();
	
	return 0;
}//end of main function.
void test(){
																						
	fstream inputfile;																    
	ofstream outputfile;//creat file pointer.											
																						
	vector<student> student_obj;//creat object of students class.						
	daily_classes temp_struct;															
	
	student temp_obj;																	
																						
	string get_name,get_surename,get_txt_file,classrooms,courses,check_st;	
	string extract_string;
	
	int get_student_no = 0,get_level = 0,i,subject_no = 0;
	int start_time,end_time,k = 0,dis_index;
	
	bool overlapp;
	bool test = true,check = true,cred_overlap = false,result=true,same_id = true;//bool variables used down.
	
	char hours[LIMIT];//used to pars the file.txt data the size of estemated and defined on the top
	char* pointer,*temp_pointer;//used to tokinize the string.
  
	Cours one_cours[COURS_QUANTITY] = {0};//array of structure for courses.
	Classroom one_classroom[CLASS_QUANTITY] = {0};//array of structure for classes.
	
	inputfile.open("courses_classrooms.txt");
	
	//courses>>>
	inputfile >> courses;
	for (i = 0; i < COURS_QUANTITY; ++i){//this loop gets inout from the file and places into the corresponding classes and struct types for courses
		
		k = 0;
		inputfile >> one_cours[i].id >> one_cours[i].name >>one_cours[i].code;//course name and id
		inputfile >> one_cours[i].credit>>one_cours[i].total_hours>>hours;//course credit an total hours.
		
		pointer  = strtok(hours,"_");
		while(pointer!=NULL){//tokinizes the rest part 
			
			temp_pointer  = pointer;

			pointer = strtok(NULL,"-");
			start_time = stoi(pointer);

			pointer = strtok(NULL,",");
			end_time = stoi(pointer);
			
			fill_daily_class_struct(temp_struct,temp_pointer,start_time,end_time);
			one_cours[i].lecture_dates.push_back(temp_struct);
			pointer = strtok(NULL,"_");
			++k;
		}
	}
	//classroom>>>
	inputfile>>classrooms;
	for (i = 0; i < CLASS_QUANTITY; ++i)//get info for classroom struct.
		inputfile >> one_classroom[i].id >> one_classroom[i].c_no >>one_classroom[i].capacity;

	i = 0;
	do{//this do while loop is the main part of program which takes input in varias forms and performs accordingly 
		
		cout<<"(input)>> ";
		cin>>get_name;//get first input.
		
		if(get_name == "-e"){

			cin >>get_student_no>>subject_no;
			test = student_exist(student_obj,get_student_no);//control if the student exists or not.
			
			if (test == true){
			
				cout << " ERROR:NO STUDENT"<<endl;
			}
			else if(test == false){

				--subject_no;//adjesting the index.		
				cred_overlap = credit_overlap(student_obj,get_student_no,one_cours[subject_no].credit);//condition to credit overlap.
				
				if(cred_overlap == true){//credit ovelap warning!!!
					cout << " BLOCK! CREDIT !!!"<<endl;
				}
				else if(cred_overlap == false){//check for overlap;

					for(int i = 0; i < student_obj.size(); ++i){//look for particular student.
						
						if(student_obj[i].get_st_num() == get_student_no){//finds the student from the vector list.
							overlapp = courses_overlap(student_obj[i],subject_no,one_cours);
							break;
						}
					}
				}
				if(cred_overlap == false and  true == overlapp ){

					for(int t = 0; t < student_obj.size(); ++t){//look for index of desired student in vector object.
						
						if(student_obj[t].get_st_num() == get_student_no){
						
							student_obj[t].enrollCours(one_cours[subject_no],subject_no);//enrolling a course
							cout <<"DONE!"<<endl;
						}
					}
				}
			}
		}
		else if (get_name == "-de"){//first input as -de
			
			cin >>get_student_no>>dis_index;//get student id and index of the course which we wana disenroll.
			test = student_exist(student_obj,get_student_no);//control if the student exists or not.
			
			if (test == true)
				cout << " ERROR:NO STUDENT"<<endl;
			else{
				for (int i = 0; i < student_obj.size(); ++i){
					if(student_obj[i].get_st_num() == get_student_no){//find the desired student.
						--dis_index;	
						student_obj[i].disenroll(one_cours,dis_index);
					}
				}
				cout<<"DONE!"<<endl;
	
			}
		}
		else if(get_name == "-ns"){//condition for first input string

			cin >> get_name >>get_surename>>get_student_no>>get_level;
	
			check = check_same_student(student_obj,get_name,get_surename,get_student_no,get_level);//check for duplicate students. 
			same_id =  check_for_same_id(student_obj,get_student_no);//check for duplicate id 

			if (check==true){
				cout << "DUPLICATE STUDENT!"<<endl;
			}
			else if(same_id==true){
				cout <<"DUPLICATE ID !"<<endl;
			}
			else{//this block of else statment check for capacity of classes and then if there is space in classes registers the name of that student there.
				
				student_obj[i].enterClassroom(one_classroom[0],result);//down ward condition to set students to the appropriate classes.
				
				if(result==true){
					
					temp_obj.set_student(get_name,get_surename,get_student_no,get_level);//temprarly object used to manipulation.
					student_obj.push_back(temp_obj);//assigning temp obj to the corresponding vector class index.
				}
				cout<<"DONE!"<<endl;
			}
		}
		else if(get_name == "-o"){//condition for first input as '-o'
			
			cin >> check_st;
			if(check_st == "-f"){
				
				cin >> get_txt_file;
				if(isdigit(get_txt_file[0])){//print one student to file

					get_student_no = stoi(get_txt_file);
					cin>>get_txt_file;
					
					outputfile.open(get_txt_file);//open file
					for (int t = 0; t < student_obj.size(); ++t){
						
						if(student_obj[t].get_st_num() == get_student_no){
							
							extract_string = student_obj[t].extractSchedule(one_cours);//print to file			
							outputfile << extract_string <<endl;
							break;
						}
					}
					outputfile.close();
				}
				else{//all student details to file

					outputfile.open(get_txt_file);//open file
					for(int t = 0; t < student_obj.size(); ++t){
					
						extract_string = student_obj[t].extractSchedule(one_cours);
						outputfile << extract_string<<endl;
					}					
					outputfile.close();
				}
				cout<<"DONE!"<<endl;

			}
			else if(isdigit(check_st[0])){// one student details on screen

				for (int t = 0; t < student_obj.size(); ++t){//find the index of the student
						
					if(student_obj[t].get_st_num()== get_student_no){
						
						extract_string = student_obj[t].extractSchedule(one_cours);
						cout<<extract_string<<endl;
						break;
					}						
				}
				cout<<"DONE!"<<endl;

			}
			else{//all student details on screen

				for (int t = 0; t < student_obj.size(); ++t){

					cout<<"       >>";
					extract_string = student_obj[t].extractSchedule(one_cours);//print all st details on screen
					cout<<extract_string<<endl;	
				}
				cout<<"DONE!"<<endl;
			}	
		}
		else if (get_name == "-list"){//input as list
						
			for(i = 1; i <=COURS_QUANTITY; ++i)
				cout <<"("<<i<<")"<<" "<< one_cours[i-1].name<<" ";
			
			cout<<endl;
		}
		i++;//increment vector class by one
	}while(get_name!="exit");
	inputfile.close();
}
void fill_daily_class_struct(struct daily_classes& temp_struct,char* pointer,int& start_time,int& end_time){//fills the daily_class named struc and returns the struct to be used.

	temp_struct.day_name = pointer;
	temp_struct.start_class = start_time;
	temp_struct.end_class  = end_time;
}
void student::set_student(const string& st_name,const string& st_sur_name,const int& st_number,const int& st_level){

	this->name = st_name;
	this->surename  = st_sur_name;
	this->student_no  = st_number;
	this->level  = st_level;
	
	//check and fill the credit rights
	if (st_level == 1)
		this->credit_right = 20;
	else if (st_level == 2)
		this->credit_right = 21;
	else if(st_level == 3)
		this->credit_right = 22;
	else if(st_level == 4)
		this->credit_right = 23;

}
void student :: enterClassroom(Classroom& come_class,bool& result){
	
	if ((come_class.student_inroom +1) <= come_class.capacity){
		
		++(come_class.student_inroom);		
		result = true;
	}
	else{
		
		cout << "NO CAPACITY!!!"<<endl;
		result = false;
	}
}
int student :: get_st_num(){ return student_no; }

void student :: quitClassroom(Classroom& leave_class){

	--(leave_class.student_inroom);
}
int student :: enrollCours(const Cours& enter_course,const int& sub_location){

	int remained = 0;

	this->courses_list.push_back(sub_location);
	
	if(enter_course.total_hours == 3)
		overlap_right.push_back(1);
	else if(enter_course.total_hours == (4 or 5))
		overlap_right.push_back(2);
	else if(enter_course.total_hours == 6)
		overlap_right.push_back(3);

	current_credit = current_credit +  enter_course.credit;//INCREEMNT CREDIT
	remained = credit_right - current_credit;//credit remined
	
	return remained;
}
int student :: disenroll(const Cours remove_course[COURS_QUANTITY],const int& sub_location){

	int remained = 0; 
	for (int i = 0; i < courses_list.size(); ++i){

		if (courses_list[i] == sub_location){
			courses_list.erase( courses_list.begin()+i);
		}
	}
	current_credit = current_credit -  remove_course[sub_location].credit;//dicrement CREDIT
	remained = credit_right - current_credit;//credit remined
	
	if (current_credit < 0){
		current_credit = 0;
	}
	
	return remained;
}
student :: student(){
	
	current_credit = credit_right = level = 0;
}
bool student_exist(const vector<student>& is_student_exist,int& st_no){//function searches if the student exist in the list or not.

	for (int i = 0; i < is_student_exist.size(); ++i){
		
		if(st_no == is_student_exist[i].student_no)
			return  false;	
	}
	
	return true;
}
bool check_same_student(const vector<student>& test_st,const string& st_name,const string& st_surname,const int& st_no,const int& st_level){

	for(int i = 0; i < test_st.size(); ++i){
		
		if(test_st[i].name == st_name and test_st[i].surename == st_surname and test_st[i].student_no == st_no and test_st[i].level== st_level){
		
			return true;
		}
	}
	
	return false;
}
bool credit_overlap(const vector<student>& st_vector,const int& get_student_no,const int& subject_credit){

	for (int i = 0; i < st_vector.size(); ++i){
		
		if (st_vector[i].student_no == get_student_no){
			
			if ((st_vector[i].current_credit+subject_credit) > st_vector[i].credit_right)
				return true;
			else
				return false;
		}
	}
}
string student:: extractSchedule(const Cours st_couses[COURS_QUANTITY]){

	string extract_string1,extract_string2,extract_string3,extract_string;
	int find_me = 0,i;
			
	extract_string1 = name + " " + surename+" [";
	extract_string = extract_string1;
	
	for(i = 0; i < courses_list.size(); ++i){
		
		find_me = courses_list[i];
		extract_string2 = st_couses[find_me].name +" "+ to_string(st_couses[find_me].credit) + " ";
		extract_string = extract_string + extract_string2;
	}
	extract_string3  = "] total_credit: "+to_string(current_credit)+" credit_right: "+ to_string(credit_right);
	extract_string = extract_string + extract_string3;

	return extract_string;
}
bool check_for_same_id(const vector<student>& st,const int& st_id){//check for same id.

	for (int i = 0; i < st.size(); ++i){
		
		if (st[i].student_no == st_id)
			return true;
	}
	return false;
}
bool courses_overlap(student& st,const int& sub_lo, Cours coures[COURS_QUANTITY]){

	int i,j,k,sub_index,difference_1,difference_2,small,between = 0;	
	
	for(i = 0; i < st.courses_list.size(); ++i){//till end of courese listed in a student obj

		sub_index = st.courses_list[i];

		if(st.courses_list[i] == sub_lo){//check if you are trying to retake the same course.

			cout << " CAN'T  TAKE SAME SUBJECT!"<<endl;
			return false;
		}
		else{
			
			for(j = 0; j < coures[sub_lo].lecture_dates.size();++j){//count of the days in a course.
				
				for( k = 0;k < coures[sub_index].lecture_dates.size();++k){	

					if(coures[sub_lo].lecture_dates[j].day_name == coures[sub_index].lecture_dates[k].day_name){//cnodition for day match
						
						if (coures[sub_lo].lecture_dates[j].start_class == coures[sub_index].lecture_dates[k].start_class and coures[sub_lo].lecture_dates[j].end_class == coures[sub_index].lecture_dates[k].end_class){
						
							cout<<" OVERLAP BECAUSE OF HOURS!"<<endl;
							return false;
						}
						else{				
							
							difference_1 = coures[sub_lo].lecture_dates[j].start_class - coures[sub_index].lecture_dates[j].end_class;//conditions to check diffrence of hourses overlaped
							difference_2 = coures[sub_index].lecture_dates[j].start_class - coures[sub_lo].lecture_dates[j].end_class;//conditions to check diffrence of hourses overlaped

							if (difference_1 < 0)
								difference_1 = -difference_1;//guaranty the difference
							if(difference_2 < 0)
								difference_2 = -difference_2;//guaranty the difference
							if(difference_1 < difference_2)//find the smallest diferrence among the 
								small  = difference_1;
							else if(difference_2 < difference_1)
								small = difference_2;
							else if(difference_1 == difference_2)
								small = difference_1;							
							
							if(st.overlap_right[i] > 0 && (small > 0 || small == 0) ){//total hours
							
								st.overlap_right[i] -= small;
								st.overlap_right[sub_lo] -= small;
							}
							else{
							
								cout <<"OVERLAP BECAUSE OF HOURS!"<<endl;
								return false;
							}
						}
					}
				}
			}
		}
	}
	return true;	
} 