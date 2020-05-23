
#include "structs_classes.h"
//this program simply fills the incompleted lecturer's cubject rights othomatecally and then links the required implementaions like making timetable and arranging
//class rooms and so on and then promts to user to enter to a list of students and then the entered students can enter to a classroom and choise a subject and quit from a classroom and so on.
using namespace all_classes;
int main(){

	fstream cr_cl_f,Lec_file;
	cr_cl_f.open("courses_classrooms.txt");//txt files
	Lec_file.open("lecturers.txt");//txt files
	
	vector<Cours> coures_vec;//vectors used in program
	vector<Classroom> classes_vec;//vectors used in program
	vector<int> class_id_ar;//vectors used in program
	vector<student> student_vec;
	student temp_obj;

	bool go_on = true,is_class_exist = true,is_st_exist = true,check = true,same_id = true;
	bool result =true,in_other_class = true,in_old_class = true,in_a_class = false,go = true;
	int student_id = 0,classroom_id = 0,course_id = 0,hour_of_week = 0,get_student_no = 0,get_level = 0;
	string get_name,get_surename;

	Administrator Admin;
	srand(time(NULL));

	string command,timetable,is_lid,get_course_name,get_course_field;
    Lecturer Lec_arr[LECTURERS_QUANTITY];

	fill_coures(cr_cl_f,coures_vec);//filling desired inputs from the files
	fill_class(cr_cl_f,classes_vec);//filling desired inputs from the files
	fill_lectureres(Lec_file,Lec_arr);//filling desired inputs from the files
	cout<<"------------------TIMETABLE-------------------"<<endl;
	coureses_to_lecturers(Lec_arr,coures_vec);//set courses to lectures
	set_timetable(Admin,Lec_arr,coures_vec);//set timetable to courses
	arrangeClassroom(Admin,Lec_arr,classes_vec,coures_vec);//arrange classrooms
	fill_class_from_coureses(Lec_arr,classes_vec);
	fill_classes_structs(classes_vec);
	cout<<"--------------------MENU----------------------"<<endl;

	while(go_on){//main manu or interface of the program to be executed.

		cout<<"(input)>";
		cin>>command;
		
		if(command == "-ns"){//condition for first input string

			cin >> get_name >>get_surename>>get_student_no>>get_level;//get input form user.
			check = check_same_student(student_vec,get_name,get_surename,get_student_no,get_level);//check for duplicate students. 
			same_id =  check_for_same_id(student_vec,get_student_no);//check for duplicate id 
			
			if (check==true)
				cout << "DUPLICATE STUDENT!"<<endl;
			else if(same_id==true)
				cout <<"DUPLICATE ID !"<<endl;

			else if(result == true){//this block of else statment check for capacity of classes and then if there is space in classes registers the name of that student there.
						
				temp_obj.set_student(get_name,get_surename,get_student_no,get_level);//temprarly object used to manipulation.
				student_vec.push_back(temp_obj);//assigning temp obj to the corresponding vector class index.
				cout<<"DONE!"<<endl;
			}
		}
		else if(command == "-enter"){
			
			cin>>student_id>>classroom_id>>hour_of_week;
			is_class_exist = check_class_existence( classes_vec,classroom_id);//checks class existence
			is_st_exist = student_exist(student_vec,student_id);//checks for existing of a student in the list after registration.

			if(!is_class_exist)
				cout<<"ERRORE: no class!"<<endl;
			else if(!is_st_exist)
				cout<<"ERRORE: no student!"<<endl;
			else{
				
				in_other_class = check_in_other_classroom(student_vec,student_id);//checks if in other class such a student exist.
				for (int i = 0; i < student_vec.size(); ++i){
					if(student_vec[i].get_st_num() == student_id){
						in_old_class = student_vec[i].is_st_in_old_class(classes_vec,classroom_id);//if student is already exist.
						break;
					}
				}

				if(in_other_class == true and in_old_class == false){
					cout<<"BLOCK: the student is at an other Classroom!"<<endl;
				}
				else{

					cout<<"(output)>";
					for (int i = 0; i < classes_vec.size(); ++i){

						if(classes_vec[i].get_class_id() == classroom_id){
							classes_vec[i].enterClassroom(student_vec,student_id,hour_of_week);//calling enroll function.
							break;	
						}
					}
					for (int i = 0; i < classes_vec.size(); ++i){
						if(classes_vec[i].get_class_id() == classroom_id){
							cout<< "student in room: "<<classes_vec[i].get_class_student_in_room()<<endl;
							break;
						}
					}
				}
			}		
		}
		else if(command == "-quit"){
			
			cin>>student_id;
			is_st_exist = student_exist(student_vec,student_id);//checks for existing of a student in the list after registration.
			
			if(!is_st_exist){
				cout<<"ERRORE: no student!"<<endl;
			}
			else{

				for (int i = 0; i < student_vec.size(); ++i){
					if(student_vec[i].get_st_num() == student_id){
						if(student_vec[i].get_st_in_a_class() == 1)
							in_a_class = true;
						else
							in_a_class = false;
					}
				}
				if (in_a_class == false)
					cout<<"BLOCK: she/he is not in any classroom"<<endl;
				else{
					
					cout<<"(output)>";
					for (int i = 0; i < student_vec.size(); ++i){
						if(student_vec[i].get_st_num() == student_id){
							
							for(int j = 0; j < classes_vec.size(); ++j){
								if(student_vec[i].get_class_id() == classes_vec[j].get_class_id()){
									
									classes_vec[j].quitClassroom();//calling quit classroom func
									student_vec[i].set_st_in_a_class(0);//indecator to particular student that means student is not in any class at the moment
									cout<< "student in room: "<<classes_vec[j].get_class_student_in_room()<<endl;
									break;
								}
							}
						}
					}
				}
			}
		}
		else if(command == "-attendance"){
			
			cin>>course_id;
			cout<<"(output)>";
			print_attendece(classes_vec,student_vec,course_id);//prints the attendance for the particular subject
			cout<<endl;
		}
		else if(command == "exit"){ 
			
			go_on = false;
			cout<< endl;
		}
		else{
		 	cout<<"WRONG INPUT!"<<endl;
		}
	}

	cr_cl_f.close();//closing the used files.
	Lec_file.close();//closing the used files.
	return 0;
}