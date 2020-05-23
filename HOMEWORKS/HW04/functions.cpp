#include "structs_classes.h"

namespace all_classes{

	/************************************************************************************/
			/*lecturer class's related functions*/
	Lecturer:: Lecturer(){

		cours_count = 0;
		personal_id = 0;
		prof_count = 0;
		name = " ";
		surename = " ";
		title = " ";
	}
	Lecturer ::Lecturer(const Lecturer& old_lec){//copy constructor...

		this->cours_count = old_lec.cours_count;
		this->personal_id = old_lec.personal_id; 
		this->prof_count = old_lec.prof_count;
		this->name =  old_lec.name;
		this->surename = old_lec.surename;
		this->title = old_lec.title;

		for (int i = 0; i <old_lec.parallel_date_vec.size(); ++i)
			this->parallel_date_vec.push_back(old_lec.parallel_date_vec[i]);
		for (int i = 0; i < old_lec.courses_list.size(); ++i)
			this->courses_list.push_back(old_lec.courses_list[i]);
		for (int i = 0; i < old_lec.professions.size(); ++i)
			this->professions.push_back(old_lec.professions[i]);
		for (int i = 0; i < old_lec.classrooms.size(); ++i)
			this->classrooms.push_back(old_lec.classrooms[i]);
	
	}
	Lecturer:: ~Lecturer(){}
	Lecturer& Lecturer:: operator =(const Lecturer& old_lec){

		this->cours_count = old_lec.cours_count;
		this->personal_id = old_lec.personal_id; 
		this->prof_count = old_lec.prof_count;
		this->name =  old_lec.name;
		this->surename = old_lec.surename;
		this->title =old_lec.title;

		for (int i = 0; i <old_lec.parallel_date_vec.size(); ++i)
			this->parallel_date_vec.push_back(old_lec.parallel_date_vec[i]);
		for (int i = 0; i < old_lec.courses_list.size(); ++i)
			this->courses_list.push_back(old_lec.courses_list[i]);
		for (int i = 0; i < old_lec.professions.size(); ++i)
			this->professions.push_back(old_lec.professions[i]);
		for (int i = 0; i < old_lec.classrooms.size(); ++i)
			this->classrooms.push_back(old_lec.classrooms[i]);

		return *this;
	}

	int Lecturer:: get_prof_cout(){return prof_count;}
	string Lecturer:: get_lec_name(){return name;}
	int Lecturer:: get_cours_count(){return cours_count;}
	int Lecturer::get_lec_personal_id(){return personal_id;}
	string Lecturer::get_lec_title(){return title;}

	void Lecturer:: set_cours_count(int& a){cours_count  = a;}
	void Lecturer:: set_prof_count(int&a){prof_count = a;}

	bool Lecturer:: is_field_professions_match(const string& cours_field){//checks for matching of the cours field and lectures professions.

		for (int i = 0; i < get_prof_cout(); ++i){
			
			if (cours_field ==professions[i]){
				return true;		
			}
		}
		return false;
	}
	bool Lecturer:: proposeCourse(vector<Cours>& c_vec,const string& c_name,const int& c_code,const int& c_credit,const int& c_totalhours,const string& c_field){
		
		if((get_cours_count()) < 3){
		
			assignCourse(c_vec,c_name,c_code,c_credit,c_totalhours,c_field);
		}
		else{
			cout<<"CAN'T TAKE MORE THAN 3 LECTURES!"<<endl;
		}		

		return true;
	}

	void Lecturer:: assignCourse(vector<Cours>& coures_vec,const string& c_name,const int& c_code,const int& c_credit,const int& c_totalhours,const string& c_field){
		
		int a = 0,index;
		Cours temp_co_vec;
		bool found = false;

		for (int i = 0; i < get_prof_cout(); ++i){//check for the existence of the cours field in the professions list.
			
			if(c_field == professions[i]){
				found = true;
				break;
			}
		}

		if (found == false){

			cout<<"LECTURE OVERLAP!"<<endl;
			return;
		}
		else{

			temp_co_vec.name = c_name;//copy elements of one cours to temp cours
			temp_co_vec.code = c_code;//copy elements of one cours to temp cours
			temp_co_vec.credit = c_credit;//copy elements of one cours to temp cours
			temp_co_vec.total_hours = c_totalhours;//copy elements of one cours to temp cours
			temp_co_vec.field = c_field;//copy elements of one cours to temp cours
			temp_co_vec.is_Mandatory = 0;
			temp_co_vec.is_assigned = 1;
			temp_co_vec.id = (coures_vec.size()+1);
			
			a = cours_count;
			++a;
			cours_count = a;
			coures_vec.push_back(temp_co_vec);
			courses_list.push_back(temp_co_vec.id);
			}
	}
	void Lecturer:: assignCourse(const vector<Cours>& coures_vec,const int& index){

		for (int i = 0; i < coures_vec.size(); ++i){
			
			if(coures_vec[i].id == index){
				courses_list.push_back(i);
				return;
			}
		}
	}
	void Lecturer:: set_lec(const int& id,const string& name,const string& surename,const string& title){

		this->personal_id = id;
		this->name = name;
		this->surename = surename;
		this->title = title;
	}
	void Lecturer :: fill_lecturers_professions(const char* st){professions.push_back(st);}
	void Lecturer::set_courese_Dates(vector<Cours>& coures_vec){

		int a;
		struct daily_classes temp_date;

		for (int i = 0; i < this->get_cours_count() ; ++i){
			
			for (int  j= 0; j < coures_vec.size(); ++j){
			
				if(this->parallel_date_vec[i].name == coures_vec[j].name){
					
					temp_date.day_name = this->parallel_date_vec[i].lecture_dates[0].day_name;
					temp_date.start_class = this->parallel_date_vec[i].lecture_dates[0].start_class;
					temp_date.end_class = this->parallel_date_vec[i].lecture_dates[0].end_class;
					coures_vec[j].lecture_dates.push_back(temp_date);
					coures_vec[j].is_date_assigned = 1;
					break;
				}

			}
		}
	}
	/*************************************************************************************/
						/* Administrator class's related funcitons*/
	Administrator:: Administrator(){

		pid = 0;
		password = 0;
		is_timetable_arranged = 0;
	}
	Administrator:: Administrator(const Administrator& old_admin){

		pid = old_admin.pid;
		password = old_admin.password;
		is_timetable_arranged = old_admin.is_timetable_arranged;

	}
	Administrator& Administrator:: operator =(const Administrator& old_admin){

		pid = old_admin.pid;
		password = old_admin.password;
		is_timetable_arranged = old_admin.is_timetable_arranged;

		return *this;
	}
	Administrator:: ~Administrator(){}
	void Administrator::arrangeTimeTable(Lecturer& Lec_arr,const vector<Cours>& coures_vec){//arranges timetable atomatically.
		
		int random,limit,a,i,j;
		struct daily_classes temp_date;
		struct Cours temp_cours;
		bool go_on = true;

		for (i = 0; i < Lec_arr.get_cours_count(); ++i){//asssign appropriate coureses to the lecturers vecotr which holds the courers structure related with it's lecturer. 

			if (Lec_arr.get_lec_name()=="ALI"){
			
				a  = Lec_arr.courses_list[i];
				temp_cours = coures_vec[a-1];
				Lec_arr.parallel_date_vec.push_back(temp_cours);
			}
			else{

				a  = Lec_arr.courses_list[i];
				temp_cours = coures_vec[a];
				Lec_arr.parallel_date_vec.push_back(temp_cours);

			}
		}

		/*generating random numbers*/
		random = rand() % 5 + 1;
		temp_date.day_name = generte_day_name(random);//deremines the day name according to the input and returns it's corresponding string.
		
		limit = 17 - Lec_arr.parallel_date_vec[0].total_hours;
		random = rand() % (limit - 9 + 1) + 9;			
		
		temp_date.start_class = random;
		temp_date.end_class = random + Lec_arr.parallel_date_vec[0].total_hours;

		Lec_arr.parallel_date_vec[0].lecture_dates.push_back(temp_date);

		while(go_on == true){

			random = rand() % 5 + 1;				
			temp_date.day_name = generte_day_name(random);//deremines the day name according to the input and returns it's corresponding string.
			
			limit = 17 - Lec_arr.parallel_date_vec[1].total_hours;
			random = rand() % (limit - 9 + 1) + 9;			
			
			temp_date.start_class = random;
			temp_date.end_class = random + Lec_arr.parallel_date_vec[1].total_hours;

			if(temp_date.day_name == Lec_arr.parallel_date_vec[0].lecture_dates[0].day_name){
				
				go_on = true;
			}
			else{

				Lec_arr.parallel_date_vec[1].lecture_dates.push_back(temp_date);
				go_on  = false;
			}
		}

		go_on = true;
		while(go_on == true){

			random = rand() % 5 + 1;
			temp_date.day_name = generte_day_name(random);//deremines the day name according to the input and returns it's corresponding string.
			limit = 17 - Lec_arr.parallel_date_vec[2].total_hours;
			
			random = rand() % (limit - 9 + 1) + 9;			
			
			temp_date.start_class = random;
			temp_date.end_class = random + Lec_arr.parallel_date_vec[2].total_hours;
			if(temp_date.day_name == Lec_arr.parallel_date_vec[0].lecture_dates[0].day_name || temp_date.day_name == Lec_arr.parallel_date_vec[1].lecture_dates[0].day_name){
				
				go_on = true;
			}
			else{

				Lec_arr.parallel_date_vec[2].lecture_dates.push_back(temp_date);
				go_on  = false;
			}
		}
	}
	void Administrator:: set_timetable_arranged_fun(){ this->is_timetable_arranged = 1; }
	int Administrator::check_timetable_arranged(){ return is_timetable_arranged; }
	void Administrator:: arrangeClassroom(Lecturer& one_lec){
		
	
		for(int i = 0; i <one_lec.parallel_date_vec.size(); ++i){
			
			cout<<"DONE:"<<"("<<one_lec.parallel_date_vec[i].id<<")"<<one_lec.parallel_date_vec[i].name<<" in ";
									
				if(one_lec.get_lec_name() == "ALI"){
					
					if(one_lec.classrooms.size() == 3)
						cout<<one_lec.classrooms[i].get_class_no()<<" at ";
					else
						cout<<one_lec.classrooms[0].get_class_no()<<" at ";
				}
				else
					cout<<one_lec.classrooms[0].get_class_no()<<" at ";

				for(int k = 0; k < one_lec.parallel_date_vec[i].lecture_dates.size(); ++k){
			
					cout<<one_lec.parallel_date_vec[i].lecture_dates[k].day_name<<"_"
					<<one_lec.parallel_date_vec[i].lecture_dates[k].start_class<<"-"
					<<one_lec.parallel_date_vec[i].lecture_dates[k].end_class<<" ";
				}
			cout<<endl;
		}
	}
	/**************************************************************************************/
					/*student class related functions*/
	student:: student(){

		this->name = " ";
		this->surename = " ";
		this->student_no = 0;
		this->level = 0;
		this->credit_right = 0;
		this->current_credit = 0;
		this->in_a_class = 0;//initialy student is not in a class
		this->class_id = 0;
	}
			
 	student:: student(const student& old_student){

		this->name  = old_student.name;
		this->surename = old_student.surename;
		this->student_no = old_student.student_no;
		this->level = old_student.level;
		this->credit_right = old_student.credit_right;
		this->current_credit = old_student.current_credit;
		this->in_a_class = old_student.in_a_class;
		this->class_id = old_student.class_id;

		for (int i = 0; i <old_student.courses_list.size() ; ++i)
			this->courses_list.push_back(old_student.courses_list[i]);
		for (int i = 0; i <old_student.overlap_right.size(); ++i)
			this->overlap_right.push_back(old_student.overlap_right[i]);

	}
	student& student:: operator =(const student& old_student){

		this->name  = old_student.name;
		this->surename = old_student.surename;
		this->student_no = old_student.student_no;
		this->level = old_student.level;
		this->credit_right = old_student.credit_right;
		this->current_credit = old_student.current_credit;
		this->in_a_class = old_student.in_a_class;
		this->class_id = old_student.class_id;
		
		for (int i = 0; i <old_student.courses_list.size() ; ++i)
			this->courses_list.push_back(old_student.courses_list[i]);
		for (int i = 0; i <old_student.overlap_right.size(); ++i)
			this->overlap_right.push_back(old_student.overlap_right[i]);

		return *this;
	}
	student:: ~student(){}

	int student:: get_st_num(){ return this->student_no;}
	int student:: get_st_level(){ return this->level;}
	int student:: get_st_credit_right(){return this->credit_right;}
	int student:: get_st_current_credit(){ return this->current_credit; }
	string student:: get_st_name(){ return this-> name; }
	string student:: get_st_surename(){ return this->surename; }
	int student::get_class_id(){return this->class_id;}
	
	int student:: get_st_in_a_class(){return this->in_a_class;}
	void student::set_st_in_a_class(const int& a){ this->in_a_class = a;}
	void student:: set_class_id (const int& a){this->class_id = a;}
	bool check_same_student(const vector<student>& test_st,const string& st_name,const string& st_surname,const int& st_no,const int& st_level){

		for(int i = 0; i < test_st.size(); ++i){
			
			if(test_st[i].name == st_name and test_st[i].surename == st_surname and test_st[i].student_no == st_no and test_st[i].level== st_level){
			
				return true;
			}
		}
		return false;
	}
	bool check_for_same_id(const vector<student>& st,const int& st_id){//check for same id.

		for (int i = 0; i < st.size(); ++i){
			
			if (st[i].student_no == st_id)
				return true;
		}
		return false;
	}
	bool check_in_other_classroom(vector<student>& st,const int& st_id){//check whether the sutdent is in an other class room

		for (int i = 0; i < st.size(); ++i){

			if(st[i].get_st_num() == st_id){
				if (st[i].get_st_in_a_class() == 1)//if student is in a class
					return true;
				else
					return false;
			}
		}
	}
	bool student:: is_st_in_old_class(vector<Classroom>& classes_vec,const int&class_id){

		for (int i = 0; i < classes_vec.size(); ++i){
			
			if(classes_vec[i].get_class_id() == class_id){
				
				for(int j = 0; j <classes_vec[i].course_list.size(); ++j){
						int k = 0;
						
						while(classes_vec[i].st_ptr[j][k].filled == true){
							if (classes_vec[i].st_ptr[j][k].st_id == student_no)
								return true;
							k++;
						}
				}
				break;
			}
		}
		return false;
	}
	void student::set_student(const string& st_name,const string& st_sur_name,const int& st_number,const int& st_level){

		this->name = st_name;
		this->surename  = st_sur_name;
		this->student_no  = st_number;
		this->level  = st_level;
		this->in_a_class = 0;
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
	/**************************************************************************************/
					/*classroom related functions's definitions*/
	Classroom:: Classroom(){

		id = 0;
		capacity = 0;
		student_inroom = 0;
		c_no =" ";
		st_ptr = nullptr;
	}
	Classroom ::Classroom(const Classroom& old_class){//copy constructor...

		this->id = old_class.id;
		this->c_no = old_class.c_no;
		this->capacity = old_class.capacity;
		this->student_inroom = old_class.student_inroom;		
		
		for(int i = 0; i < old_class.lec_id_list.size(); ++i)
			this->lec_id_list.push_back(old_class.lec_id_list[i]);
		
		for(int i = 0; i < old_class.course_list.size(); ++i)
			this->course_list.push_back(old_class.course_list[i]);
		
		int r_size = this->course_list.size();
		int c_size = this->capacity;

		st_ptr = new struct student_info*[r_size];
		for (int i = 0; i < r_size; ++i){
			st_ptr[i] = new struct student_info[c_size];
		}

		if (old_class.st_ptr == nullptr){
			this->st_ptr = old_class.st_ptr;
		}
		else{

			for(int i = 0; i < r_size; ++i){
				for(int j = 0; j < c_size; ++j){
					
					this->st_ptr[i][j].st_name = old_class.st_ptr[i][j].st_name;
					this->st_ptr[i][j].count_hrs = old_class.st_ptr[i][j].count_hrs;
					this->st_ptr[i][j].st_id = old_class.st_ptr[i][j].st_id;
					this->st_ptr[i][j].st_in_class = old_class.st_ptr[i][j].st_in_class;
					this->st_ptr[i][j].filled = old_class.st_ptr[i][j].filled;
				}
			}
		}
	}
	Classroom& Classroom:: operator =(const Classroom& old_class){


		if ( this == &old_class)
			return * this;
		else{

			this->id = old_class.id;
			this->c_no = old_class.c_no;
			this->capacity = old_class.capacity;
			this->student_inroom = old_class.student_inroom;
			
			for(int i = 0; i < old_class.lec_id_list.size(); ++i)
				this->lec_id_list.push_back(old_class.lec_id_list[i]);

			for(int i = 0; i < old_class.course_list.size(); ++i)
				this->course_list.push_back(old_class.course_list[i]);

			int r_size = this->course_list.size();
			int c_size = this->capacity;

			for (int i = 0; i < r_size; ++i){
				delete[] st_ptr[i];
			}
			delete[] st_ptr;
			
			st_ptr = new struct student_info*[r_size];
			
			for (int i = 0; i < r_size; ++i){
				st_ptr[i] = new struct student_info[c_size];
			}

			for(int i = 0; i < r_size; ++i){
			
				for(int j = 0; j < c_size; ++j){
					
					this->st_ptr[i][j].st_name = old_class.st_ptr[i][j].st_name;
					this->st_ptr[i][j].count_hrs = old_class.st_ptr[i][j].count_hrs;
					this->st_ptr[i][j].st_id = old_class.st_ptr[i][j].st_id;
					this->st_ptr[i][j].st_in_class = old_class.st_ptr[i][j].st_in_class;
					this->st_ptr[i][j].filled = old_class.st_ptr[i][j].filled;
				}
			}

			return *this;
		}	
	}
	
	Classroom:: ~Classroom(){

		int r_size = this->course_list.size();
		for (int i = 0; i < r_size; ++i)
			delete[] st_ptr[i];
		delete[] st_ptr;
	}
	void Classroom:: set_class_id(const int& i){ id =i;}
	void Classroom:: set_class_no(const string& st){ c_no = st;}
	void Classroom:: set_class_capacity(const int& i){ capacity = i;}
	void Classroom:: incerement_student_in_room(const int& i){ student_inroom += i;}

	int Classroom:: get_class_id(){ return id;}
	string Classroom:: get_class_no(){return c_no;}
	int Classroom:: get_class_capacity(){return capacity;}
	int Classroom:: get_class_student_in_room(){return student_inroom;}

	void Classroom::set_dynamic(){

		int r_size = this->course_list.size();
		int c_size = this->capacity;
		st_ptr = new struct student_info*[r_size];
		
		for (int i = 0; i < r_size; ++i){
			st_ptr[i] = new struct student_info[c_size];
		}
		for(int i = 0; i < r_size; ++i){
		
			for(int j = 0; j < c_size; ++j){
				st_ptr[i][j].st_name ='\0';
				st_ptr[i][j].count_hrs = 0;
				st_ptr[i][j].st_id = 0;
				st_ptr[i][j].st_in_class = false;
				st_ptr[i][j].filled = false;
			}
		}
	}

	void Classroom :: enterClassroom(vector<student>& st_vec,const int& s_id,const int& hours_of_week){
		
		string match_week_day;
		string name;
		bool flag = false,inc =true,can_increment = true;
		match_week_day = find_matched_day(hours_of_week);

		for (int i = 0; i < st_vec.size(); ++i){//set st as intered to a  class so that we can indecate when we need it.
			if(st_vec[i].get_st_num() == s_id){
				st_vec[i].set_st_in_a_class(1);
				st_vec[i].set_class_id(this->id);
			}
		}

		if((this->get_class_student_in_room()+1)<=this->get_class_capacity()){
			
			can_increment = true;
			for (int i = 0; i < course_list.size(); ++i){
				for(int j = 0; j < capacity; ++j){
					
					if(st_ptr[i][j].st_id == s_id){
						can_increment = false;
						break;
					}
				}
			}
			for (int i = 0; i < course_list.size() ; ++i){
				
				if(course_list[i].lecture_dates[0].day_name == match_week_day){
					
					for(int j = 0; j < capacity;++j){
						
						if(st_ptr[i][j].st_id == s_id){		
							inc = true;
							for(int k = 0; k < st_ptr[i][j].keep_hours.size(); ++k){
								 if(st_ptr[i][j].keep_hours[k] == hours_of_week)
								 	inc = false;
							}
							if(inc == true)
								st_ptr[i][j].count_hrs += 1;
							flag = true;
							break;
						}
					}
					if(flag == false){					
						
						for (int j = 0; j < capacity ; ++j){
							if(st_ptr[i][j].filled == false){
								
								for (int i = 0; i < st_vec.size(); ++i){
									if (st_vec[i].get_st_num() == s_id){
										st_vec[i].set_st_in_a_class(1);
										name = st_vec[i].get_st_name();
									}
								}
								st_ptr[i][j].st_name = name;
								st_ptr[i][j].st_id = s_id;
								st_ptr[i][j].count_hrs = 1;
								st_ptr[i][j].st_in_class = true;
								st_ptr[i][j].filled = true;
								st_ptr[i][j].keep_hours.push_back(hours_of_week);
								break;
							}
						}
						if(can_increment == true)
							this->incerement_student_in_room(1);
					}
				}
			}
		}
		else{
			cout << "NO CAPACITY!!!"<<endl;
		}
	}
	void Classroom::quitClassroom(){
		
		student_inroom -=1;
	}
	/*************************************************************************************/
				/* some other stand alone and friend functions*/
	bool check_lec_exestence(Lecturer Lec_arr[],const int& index){

		for (int i = 0; i < LECTURERS_QUANTITY; ++i){

			if(Lec_arr[i].personal_id == index){
				return true;
			}
		}

		return false;//looks for the lectures if it exists in the list>>
	}
	bool check_cours_existence(const vector<Cours>& coures_vec,const int& course_id){

		for (int i = 0; i < coures_vec.size(); ++i){
			
			if(coures_vec[i].id == course_id){
				return true;
			}
		}
		return false;
	}
	bool check_class_existence(vector<Classroom>&classes_vec,const int& class_id){

		for (int i = 0; i < classes_vec.size(); ++i){
			
			if (classes_vec[i].get_class_id()== class_id){
				return true;
			}
		}
		return false;
	}
	bool student_exist(const vector<student>& student_vec,int& st_no){//function searches if the student exist in the list or not.
		
		for (int i = 0; i < student_vec.size(); ++i){
			
			if(st_no == student_vec[i].student_no)
				return  true;	
		}
		return false;
	}
	void fill_coures(fstream& cr_cl_f,vector<Cours>& coures_vec){
		
		string coures_title;
		Cours temp_cours;
		cr_cl_f>>coures_title;

		for (int i = 0; i < COURS_QUANTITY; ++i){
		
			cr_cl_f >> temp_cours.id >> temp_cours.name >>temp_cours.code;//course name and id
			cr_cl_f >> temp_cours.credit>>temp_cours.total_hours>>temp_cours.field;//course credit an total hours.
			temp_cours.is_Mandatory = 1;//means coures is mandatory.

			coures_vec.push_back(temp_cours);
		}
	}
	void fill_class(fstream& cr_cl_f,vector<Classroom>& classes_vec){

		string class_title,c_no;
		Classroom temp_clas;
		Classroom operator_temp;
		int id,capacity;

		cr_cl_f >> class_title;
		for (int i = 0; i < CLASS_QUANTITY; ++i){//get info for classroom struct.
		
			cr_cl_f >> id >> c_no >> capacity;

			temp_clas.set_class_id(id);
			temp_clas.set_class_no(c_no);
			temp_clas.set_class_capacity(capacity);

			operator_temp = temp_clas;
			classes_vec.push_back(operator_temp);
		}
	}
	void fill_lectureres(fstream& Lec_file,Lecturer Lec_arr[]){
		
		string lecturer_name,lecturer_surename,lecturer_title;
		char *pointer;
		char lecturer_profession[LEC_LIMIT];
		int j,lec_personal_id,sum =0;
		
		for (j = 0; j < LECTURERS_QUANTITY; ++j){
					
			Lec_file >>lec_personal_id>>lecturer_name>>lecturer_surename>>lecturer_title>>lecturer_profession;
			Lec_arr[j].set_lec(lec_personal_id,lecturer_name,lecturer_surename,lecturer_title);

			pointer  = strtok(lecturer_profession,",");
			while(pointer!=NULL){//tokinizes the rest part
				
				Lec_arr[j].fill_lecturers_professions(pointer);
				++sum;
				pointer = strtok(NULL,",");
			}

			Lec_arr[j].set_prof_count(sum);
			sum = 0;
		}
	}
	void set_last_cours(Lecturer Lec_arr[],Lecturer& last_lecturer){

		bool flag = true;
		int i,j,k;
		string temp_class_name;

		for (i = 0; i < last_lecturer.get_cours_count(); ++i){//itrtea untill the counts of number of coures's of the last lecturer
		
			j = 0;
			while(j < LECTURERS_QUANTITY-1){//iterates untill the last lecturers if required.

				flag = true;
				for(k = 0; k < Lec_arr[i].get_cours_count(); ++k){
				
					if(last_lecturer.parallel_date_vec[i].lecture_dates[0].day_name == Lec_arr[j].parallel_date_vec[k].lecture_dates[0].day_name){
						flag = false;
						break;
					}
				}

				if( true == flag){

					last_lecturer.classrooms.push_back(Lec_arr[j].classrooms[0]);
					Lec_arr[j].classrooms[0].lec_id_list.push_back(last_lecturer.get_lec_personal_id());					
					j = LECTURERS_QUANTITY;
					break;
				}
				j++;
			}

		}
	}
	string generte_day_name(const int& random){

		if(random == 1)
			return("MON");
		else if(random == 2)
			return("TUES");
		else if(random == 3)
			return ("WEDNES");
		else if(random == 4)
			return("TURS");
		else if(random == 5)
			return("FRI");
	}
	void coureses_to_lecturers(Lecturer Lec_arr[],vector<Cours>& coures_vec){

		bool go = true;
		int pid,get_course_code,get_course_credit,get_course_totalhours;
		string get_course_field,get_course_name;


		for (int i = 0; i < coures_vec.size(); ++i){//assign net to the appropriat lecturere.
				
				if(coures_vec[i].field == "NET"){

					for (int j = 0; j < LECTURERS_QUANTITY; ++j){
					 	
					 	go = assignCourses_to_lecturers(coures_vec[i],Lec_arr[j],i);
						
						if(go == 1){
							break;
						}
					}
				}
			}
			for (int i = 0; i < coures_vec.size(); ++i){//assigns the subjects to appropriate lecturers		

				for (int j = 0; j < LECTURERS_QUANTITY; ++j){
			 	
			 		go = assignCourses_to_lecturers(coures_vec[i],Lec_arr[j],i);
					if(go == 1){
						break;
					}
				}
			}
						
			for(int i = 0; i < 3; ++i){

				if(i==0){
					pid = 7; get_course_name = "SOFTWARE"; get_course_code = 312;
					get_course_credit = 3; get_course_totalhours = 3; get_course_field = "MACH";
				}
				else if ( i == 1){
					pid = 7; get_course_name = "HTML"; get_course_code = 255;
					get_course_credit = 4; get_course_totalhours = 2; get_course_field = "MACH";
				}
				else if (i == 2){
					
					pid = 7; get_course_name = "DEEPLEARNING"; get_course_code = 112;
					get_course_credit = 3; get_course_totalhours = 45; get_course_field = "PROG";
				}

				--pid;
				Lec_arr[pid].proposeCourse(coures_vec,get_course_name,get_course_code,get_course_credit,get_course_totalhours,get_course_field);
			}
	}
	void set_timetable(Administrator& Admin,Lecturer Lec_arr[],vector<Cours>& coures_vec){


		for(int i = 0; i < LECTURERS_QUANTITY; ++i){
			Admin.arrangeTimeTable(Lec_arr[i],coures_vec);
		}
		Admin.set_timetable_arranged_fun();//set timetable as arranged.

		for (int i = 0; i < LECTURERS_QUANTITY; ++i){//copies the dates form each lecturess coures date's to the corresponding coures list's dates.					
			Lec_arr[i].set_courese_Dates(coures_vec);
		}
	}
	void arrangeClassroom(Administrator& Admin,Lecturer Lec_arr[],vector<Classroom>& classes_vec,vector<Cours>& coures_vec){

		/*arrange classrooms*/
		for (int i = 0; i < CLASS_QUANTITY; ++i){//arrange coures into classrooms.
					
			Lec_arr[i].classrooms.push_back(classes_vec[i]);
			classes_vec[i].lec_id_list.push_back(Lec_arr[i].get_lec_personal_id());
		}

		for (int i = 0; i < coures_vec.size(); ++i){
			coures_vec[i].is_assigned_to_class = 1;//this indecates that all the courese has been assigned to appropriate classes .
		}
		
		set_last_cours(Lec_arr,Lec_arr[6]);//this function arranges last lecturer's cours.
		for (int i = 0; i < LECTURERS_QUANTITY; ++i)//prints all the coures with their classrooms and related days
			Admin.arrangeClassroom(Lec_arr[i]);

	}
	void fill_class_from_coureses(Lecturer Lec_arr[],vector<Classroom>& c_vec){

		for (int i = 0; i < LECTURERS_QUANTITY-1; ++i){
				
			for (int j = 0; j < Lec_arr[i].parallel_date_vec.size(); ++j){
					c_vec[i].course_list.push_back(Lec_arr[i].parallel_date_vec[j]);
			}
		}
		for (int i = 0; i < Lec_arr[LECTURERS_QUANTITY-1].classrooms.size(); ++i){
			for (int j = 0; j <c_vec.size(); ++j){	
				if(c_vec[j].get_class_no()== Lec_arr[LECTURERS_QUANTITY-1].classrooms[i].get_class_no()){
					c_vec[j].course_list.push_back(Lec_arr[LECTURERS_QUANTITY-1].parallel_date_vec[i]);
				}
			}
		}
	}
	void fill_classes_structs(vector<Classroom>& classes_vec){
		
		for (int i = 0; i < classes_vec.size(); ++i){
			classes_vec[i].set_dynamic();
		}
	}
	void  print_attendece(vector<Classroom>& classes_vec,vector<student>& student_vec,const int& course_id){

		int k = 0;

		for (int i = 0; i < classes_vec.size(); ++i){
		
			for(int j = 0; j < classes_vec[i].course_list.size() ; ++j){
				
				if (classes_vec[i].course_list[j].id == course_id){
					while(classes_vec[i].st_ptr[j][k].filled == true){
						cout<<classes_vec[i].st_ptr[j][k].st_name << " "<< classes_vec[i].st_ptr[j][k].count_hrs;
						k++;
						if (classes_vec[i].st_ptr[j][k].filled == false)
							cout<<" ";
						else
							cout<<" - ";
					}
					break;
				}
			}
		}
	}
	string find_matched_day(const int& hours_of_week){

		if(1 <= hours_of_week and hours_of_week <= 8)
			return"MON"; 
		else if(9 <= hours_of_week and hours_of_week <= 16)
			return"TUES"; 
		else if(17 <= hours_of_week and hours_of_week <= 24)
			return"WEDNES"; 
		else if(25 <= hours_of_week and hours_of_week <= 32)
			return"TURS"; 
		else if(33 <= hours_of_week and hours_of_week <= 40)
			return"FRI";
	}
	int assignCourses_to_lecturers(Cours& coures_vec,Lecturer& Lec_arr,const int& course_index){

		int i,a = 0;

		if(Lec_arr.get_cours_count() >=3){
			
			return 0;
		}
		else{

			for (i = 0; i < Lec_arr.get_prof_cout(); ++i){
				
				if(coures_vec.field == Lec_arr.professions[i] and coures_vec.is_assigned!=1){
					
					Lec_arr.courses_list.push_back(course_index);				
					a = Lec_arr.get_cours_count();
					Lec_arr.set_cours_count(++a);
					coures_vec.is_assigned = 1;
					
					return 1;
				}
			}
		}	
	}
}