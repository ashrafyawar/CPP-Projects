#include "structs_classes.h"
/*function to assing coures to lecturers */
int assignCourses_to_lecturers(Cours& coures_vec,Lecturer& Lec_arr,const int& course_index,const char& one){

	int i,a = 0;

	if(Lec_arr.get_cours_count() >=3){
		
		if(one == 'o'){
			
			cout<<"CAN'T TAKE MORE THAN 3 LECTURES !"<<" ";
			return 0;
		}
		else{
			return 0;
		}
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
/************************************************************************************/
		/*lecturer class's related functions*/
Lecturer::Lecturer(){
	
	personal_id = prof_count = cours_count = 0;
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
		
		cout<<"DONE!"<<endl;
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
		/* some other stand alone and friend functions*/
bool check_lec_exestence(Lecturer Lec_arr[LECTURERS_QUANTITY],const int& index){

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
bool check_class_existence(const vector<Classroom>& classes_vec,const int& class_id){

	for (int i = 0; i < classes_vec.size(); ++i){
		
		if (classes_vec[i].id == class_id){
			return true;
		}
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

	string class_title;
	Classroom temp_clas;
	cr_cl_f >> class_title;
	
	for (int i = 0; i < CLASS_QUANTITY; ++i){//get info for classroom struct.
	
		cr_cl_f >> temp_clas.id >> temp_clas.c_no >>temp_clas.capacity;
		classes_vec.push_back(temp_clas);
		}

}

void fill_lectureres(fstream& Lec_file,Lecturer Lec_arr[LECTURERS_QUANTITY]){
	
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
bool  is_all_assigned(Lecturer Lec_arr[LECTURERS_QUANTITY],int& index){

	for(int i = 0; i < LECTURERS_QUANTITY; ++i){
		
		if (Lec_arr[i].get_cours_count() < 3){

			index = i;
			return false;
		}
	}
	return true;
}
bool is_comma_exist(const string& test_st){

	for (int i = 0; i < test_st.length(); ++i){
		
		if (test_st[i]==','){
			return true;
		}
	}

	return false;
}
bool is_cours_assingned_to_class(const vector<Cours>& coures_vec,const int& course_id){

	for (int i = 0; i < coures_vec.size(); ++i){
		
		if(coures_vec[i].id == course_id){
			
			if(coures_vec[i].is_assigned_to_class == 1){
				return true;
			}

		}
	}
	return false;
}
void set_last_cours(Lecturer Lec_arr[LECTURERS_QUANTITY],Lecturer& last_lecturer){

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
				Lec_arr[j].classrooms[0].student_inroom += 1;
				j = LECTURERS_QUANTITY;
				break;
			}
			j++;
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

void Administrator::arrangeTimeTable(vector<Cours>& coures_vec,const int& course_id,const char& doit){

	int random,limit;
	struct daily_classes temp_date;
	
	for(int i = 0; i < coures_vec.size();++i){

		if(coures_vec[i].id == course_id){

			if(coures_vec[i].is_date_assigned == 1){//checks if the cours already assgined.
				
				cout<<"Assigned Before:"<<"("<<course_id<<")"<<coures_vec[i].name<<" ";
				for (int j = 0; j < coures_vec[i].lecture_dates.size(); ++j){
					cout<<coures_vec[i].lecture_dates[j].day_name<<"_"<<coures_vec[i].lecture_dates[j].start_class<<"-"<<coures_vec[i].lecture_dates[j].end_class<<" ";
				}
				return;
			}
			else{
				
				random = rand()%5+1;
				temp_date.day_name = generte_day_name(random);//returns the day name.
				limit = 17 - coures_vec[i].total_hours;
				random = rand() % (limit - 9 + 1) + 9;			
				
				temp_date.start_class = random;
				temp_date.end_class = random + coures_vec[i].total_hours;
				
				if(doit == 'y'){//if doit is equal to yes which is y in this case then keep coures as assigned to a class.
				
					coures_vec[i].is_date_assigned = 1;
				}
					/*printing the output */
				cout << "DONE:" << "("  << course_id << ")"<< coures_vec[i].name << " ";
				coures_vec[i].lecture_dates.push_back(temp_date); 

				for(int j = 0; j < coures_vec[i].lecture_dates.size(); ++j){
					cout<<coures_vec[i].lecture_dates[j].day_name<<"_"<<coures_vec[i].lecture_dates[j].start_class<<"-"<<coures_vec[i].lecture_dates[j].end_class<<" ";
				}
				cout<<endl;
			}
			break;
		}
	}
	return;
}
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
void Administrator::print_timetable(Lecturer& Lec_arr){//prints the timetable of one lecturer in one call.

	for (int i = 0; i <Lec_arr.parallel_date_vec.size(); ++i){

		cout<<Lec_arr.parallel_date_vec[i].name<<" "<<Lec_arr.parallel_date_vec[i].lecture_dates[0].day_name <<"_";
		cout<<Lec_arr.parallel_date_vec[i].lecture_dates[0].start_class<<"-"<<Lec_arr.parallel_date_vec[i].lecture_dates[0].end_class<<endl;
	}
}
void Administrator:: set_timetable_arranged_fun(){

	this->is_timetable_arranged = 1;
}
int Administrator::check_timetable_arranged(){

	return is_timetable_arranged;
}
void Administrator ::arrangeClassroom(vector<Cours>& coures_vec,vector<Classroom>& classes_vec,const int& course_id,const int& class_id,const char& doit){

	int temp,random;
	string temp_St,temp1_St;
	for(int i = 0; i < coures_vec.size(); ++i){//save the class's id in the corresponding coures
		
		if(coures_vec[i].id == course_id){

			coures_vec[i].classes_ids_vec.push_back(class_id);//save the id of the class inside coure struct vector
			coures_vec[i].is_assigned_to_class = 1;//indecator to that that it has been assigned to a class.
			temp_St = coures_vec[i].lecture_dates[0].day_name;
			break;
		}
	}
	for (int i = 0; i < classes_vec.size(); ++i){
		
		if(classes_vec[i].id == class_id){
			
			if(classes_vec[i].capacity == classes_vec[i].student_inroom){
				
				cout<<"class is full filled!"<<endl;
				return;//if class has reached it's max capacity
			}
			else{

				classes_vec[i].co_id_list.push_back(course_id);//keep the coures id in the class's struct vector
				classes_vec[i].student_inroom +=1;//increment the student in room;
			}
		}
	}
	if(doit == 'y'){//this condition only works in the input of doit is y and used in the arrange timetable command in main function.
		
		temp1_St = temp_St;

		while(temp_St == temp1_St){
		
			random = rand()% 5+1;	
			temp1_St = generte_day_name(random);
		}
	}
	/***************************/
	/*printing the assigned cours to the appropriate class*/
	for (int i = 0; i < coures_vec.size(); ++i){
		
		if(coures_vec[i].id == course_id){

			coures_vec[i].lecture_dates[0].day_name = temp1_St;
			cout<<"DONE:"<<"("<<coures_vec[i].id<<")"<<coures_vec[i].name<<" in "<<class_id<<" at ";
			
			for(int j = 0; j < coures_vec[i].lecture_dates.size(); ++j){
			
				cout<<coures_vec[i].lecture_dates[j].day_name<<"_"<<coures_vec[i].lecture_dates[j].start_class<<"-"<<coures_vec[i].lecture_dates[j].end_class<<" ";
			}
			cout<<endl;
			return;
		}
	}
}
void Administrator:: arrangeClassroom(Lecturer& one_lec){
	
	for(int i = 0; i <one_lec.parallel_date_vec.size(); ++i){
		
		cout<<"DONE:"<<"("<<one_lec.parallel_date_vec[i].id<<")"<<one_lec.parallel_date_vec[i].name<<" in ";
										
			if(one_lec.get_lec_name() == "ALI")
				cout<<one_lec.classrooms[i].c_no<<" at ";	
			else
				cout<<one_lec.classrooms[0].c_no<<" at ";

			for(int k = 0; k < one_lec.parallel_date_vec[i].lecture_dates.size(); ++k){
		
				cout<<one_lec.parallel_date_vec[i].lecture_dates[k].day_name<<"_"
				<<one_lec.parallel_date_vec[i].lecture_dates[k].start_class<<"-"
				<<one_lec.parallel_date_vec[i].lecture_dates[k].end_class<<" ";
			}
		cout<<endl;
	}
}
