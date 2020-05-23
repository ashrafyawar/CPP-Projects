
#include "structs_classes.h"
int main(){

	fstream cr_cl_f,Lec_file;
	cr_cl_f.open("courses_classrooms.txt");//txt files
	Lec_file.open("lecturers.txt");//txt files
	
	vector<Cours> coures_vec;//vectors used in program
	vector<Classroom> classes_vec;//vectors used in program
	vector<int> class_id_ar;//vectors used in program

	Administrator Admin;
	srand(time(NULL));
	
	string command,timetable,is_lid,get_course_name,get_course_field;
	Lecturer Lec_arr[LECTURERS_QUANTITY];

	bool test = true,is_lecs_full = false,is_lec_exist = true,is_cours_exits = true,is_f_prof_match = true,is_comma = false,is_class_exist = true;
	bool is_cours_assingned_to_a_class = false,should_continue  = true;
	
	char*pointer;
	char temp_char[TEMPORAR];
	int get_course_code,get_course_credit,get_course_totalhours,pid,go = 0,index,temp,lid,course_id,class_id;
	
	fill_coures(cr_cl_f,coures_vec);//filling desired inputs from the files
	fill_class(cr_cl_f,classes_vec);//filling desired inputs from the files
	fill_lectureres(Lec_file,Lec_arr);//filling desired inputs from the files
	
	for (int i = 0; i < coures_vec.size(); ++i){//assign net to the appropriat lecturere.
		
		if(coures_vec[i].field == "NET"){

			for (int j = 0; j < LECTURERS_QUANTITY; ++j){
			 	
			 	go = assignCourses_to_lecturers(coures_vec[i],Lec_arr[j],i,'a');
				
				if(go == 1){
					break;
				}
			}
		}
	}
	for (int i = 0; i < coures_vec.size(); ++i){//assigns the subjects to appropriate lecturers		

		for (int j = 0; j < LECTURERS_QUANTITY; ++j){
	 	
	 		go = assignCourses_to_lecturers(coures_vec[i],Lec_arr[j],i,'a');
			if(go == 1){
				break;
			}
		}
	}
		/*MENU PART...*/
	while(test){
	
		is_lecs_full = is_all_assigned(Lec_arr,index);//check whether all the lectures has max 3 lectures or not.
		
		cin >> command;

		if (is_lecs_full == false and command == "-propose"){
		
			cout<<"DEAR "<< Lec_arr[index].get_lec_name()<<" SIR! YOU HAVE TO PROPOSE AN ELECTIVE COURSE!"<<endl;

			if(command == "-propose"){
			
				cin>>pid>>get_course_name>>get_course_code>>get_course_credit>>get_course_totalhours>>get_course_field;
				--pid;
				Lec_arr[pid].proposeCourse(coures_vec,get_course_name,get_course_code,get_course_credit,get_course_totalhours,get_course_field);//calling porpose functions
			}
			else{

				cout<<"WRONG INPUT! ENTER (-propose) TO PROPOSE A COURSE!"<<endl;
			}	
		}
		else if(is_lecs_full == true and command == "-assign"){//-assign command executions
			
			getline(cin,is_lid);
			if(is_lid.empty()){
			
				for (int i = 0; i < coures_vec.size(); ++i){//assign net to the appropriat lecturere.
						
					if(coures_vec[i].field == "NET"){

						for (int j = 0; j < LECTURERS_QUANTITY; ++j){ 	
						 	go = assignCourses_to_lecturers(coures_vec[i],Lec_arr[j],i,'a');//assigns 
							if(go == 1){
								break;
							}
						}
					}
				}
				for (int i = 0; i < coures_vec.size(); ++i){//assigns the subjects to appropriate lecturers		

					if(coures_vec[i].is_Mandatory == 1){
						
						for (int j = 0; j < LECTURERS_QUANTITY; ++j){
					 		
					 		go = assignCourses_to_lecturers(coures_vec[i],Lec_arr[j],i,'a');
							if(go == 1){
								break;
							}
						}
					}
				}
				cout<<"DONE!"<<endl;	
			}
			else if(!is_lid.empty()){//if newine after -assign command

				strcpy(temp_char,is_lid.c_str());//parsing parts
				
				pointer = strtok(temp_char," ");//parsing parts
				lid = stoi(pointer);//parsing parts
				pointer = strtok(NULL," ");//parsing parts
				course_id  = stoi(pointer);//parsing parts
					
				is_lec_exist = check_lec_exestence(Lec_arr,lid);//check for lec_exestence in the list
				if(is_lec_exist == false){//condition to no lectures 
				
					cout<<"Error:no lecturer!"<<endl;
				}
				else{

					is_cours_exits = check_cours_existence(coures_vec,course_id);//looks for existence of thee desired cours in the cours vector.
					
					if(is_cours_exits == false){//condition to no coures
						
						cout<<"Error:no Cours!"<<endl;
					}
					else{

						is_f_prof_match = Lec_arr[lid].is_field_professions_match((coures_vec[course_id].field));//checks for matching of the cours field and lectures professions.
						
						if(is_f_prof_match == false){
						
							cout<<"Block:field and profession mismatch"<<endl;
						}
						else{

							if(coures_vec[course_id].is_assigned == 1){

								cout<<"THIS COURS IS ALREADY ASSIGNED! >> "<<coures_vec[course_id].field<<endl;
							}
							else{

								Lec_arr[--lid].assignCourse(coures_vec,course_id);
								cout<<"DONE!"<<endl;
							}
						}
					}
				}
			}
		}
		else if(command == "-assign" and is_lecs_full == false){//if propose not finished yet not allow assign operation to be executed.
			
			cout<<"CAN'T ASSIGN! FIRST FINISH PROPOSING COURSES PLEASE!"<<endl;
		}
		else if(command == "-timetable" and is_lecs_full == true){//timetable execution commands parts
			
			getline(cin,timetable);		
			
			if(timetable.empty()){

				if (Admin.check_timetable_arranged() == 1 ){//if timetable has been arranged then show if not then arrange timetable and show it to the screen.
					
					/*printing the timetable...*/
					
					for(int i = 0;i< LECTURERS_QUANTITY;++i){
						Admin.print_timetable(Lec_arr[i]);
					}
					cout<<"DONE"<<endl;
				}
				else{

					for(int i = 0; i < LECTURERS_QUANTITY; ++i){
						Admin.arrangeTimeTable(Lec_arr[i],coures_vec);
					}

					/*printing the timetable...*/
					for(int i = 0;i< LECTURERS_QUANTITY;++i){
						Admin.print_timetable(Lec_arr[i]);
					}
					
					Admin.set_timetable_arranged_fun();//set timetable as arranged.

					for (int i = 0; i < LECTURERS_QUANTITY; ++i){//copies the dates form each lecturess coures date's to the corresponding coures list's dates.					
						Lec_arr[i].set_courese_Dates(coures_vec);
					}
					cout<<"DONE!"<<endl;
				}
			}
			else{

				course_id = stoi(timetable);
				is_cours_exits = check_cours_existence(coures_vec,course_id);//looks for existence of thee desired cours in the cours vector.
					
				if(is_cours_exits == false){//condition to no coures
					
					cout<<"Error:no Cours!"<<endl;
				}
				else{
				
					Admin.arrangeTimeTable(coures_vec,course_id,'y');
					cout<<endl;
				}
			}
		}
		else if(is_lecs_full ==  false and command == "-timetable"){

			cout<<"CAN'T SET TIMETABLE BEFORE ASSIGNING COURSES!"<<endl;
		}
		else if(command =="-arrangeC" and is_lecs_full == true and (Admin.check_timetable_arranged() == 1)){//execution of arrange part.
			
			getline(cin,command);		
			if(command.empty()){//arrange otomatecally
				
				for (int i = 0; i < CLASS_QUANTITY; ++i){//arrange coures into classrooms.
					
					Lec_arr[i].classrooms.push_back(classes_vec[i]);
					classes_vec[i].lec_id_list.push_back(Lec_arr[i].get_lec_personal_id());
					classes_vec[i].student_inroom = classes_vec[i].student_inroom + 3;
				}

				for (int i = 0; i < coures_vec.size(); ++i){
					coures_vec[i].is_assigned_to_class = 1;//this indecates that all the courese has been assigned to appropriate classes .
				}
				
				set_last_cours(Lec_arr,Lec_arr[6]);//this function arranges last lecturer's cours.
				
				for (int i = 0; i < LECTURERS_QUANTITY; ++i)//prints all the coures with their classrooms and related days
					Admin.arrangeClassroom(Lec_arr[i]);
			}
			else{//not newline for arrangec
				
				is_comma = is_comma_exist(command);//checks for comma exectence of the line if it exest returns ture
				if(is_comma == true){//condition to assginnig morethan one class.
				
					strcpy(temp_char,command.c_str());//converts string to the char array
					pointer = strtok(temp_char," ");
					course_id = stoi(pointer);
					pointer = strtok(NULL,",");

					while(pointer!=NULL){//take all the class ids one by one to the vector.
					
						class_id = stoi(pointer);
						class_id_ar.push_back(class_id);
						pointer = strtok(NULL,",");
					}

					is_cours_exits = check_cours_existence(coures_vec,course_id);//looks for existence of thee desired cours in the cours vector.
					if(is_cours_exits == false){//condition to no coures
						
						cout<<" Error:no Cours!"<<endl;
					}
					else{

						for (int i = 0; i < class_id_ar.size(); ++i){

							is_class_exist = check_class_existence(classes_vec,class_id_ar[i]);//checks for class exestence
						
							if(is_class_exist == false){
								should_continue = false;
							}
						}

						if (should_continue == false){
							cout<<"Error:no class"<<endl;
						}
						else{

							if((Admin.check_timetable_arranged())  == 0){//check for time table arrangement//************************************************************

								cout<<"Error:timetable not arranged yet"<<endl;
							}
							else{
								
								is_cours_assingned_to_a_class = is_cours_assingned_to_class(coures_vec,course_id);//look for the cours if it's assigned laready return true.
								if (is_cours_assingned_to_a_class == true){
							
									cout<<"Block:there is another class assigned"<<endl;	
								}
								else{
								
									for (int i = 0; i <class_id_ar.size(); ++i)
										Admin.arrangeClassroom(coures_vec,classes_vec,course_id,class_id_ar[i],'y');//arrange desired last parameter indecates that i am using it for second condition like there is more than one class the coures to be assigned

								}
							}
						}
					}
				}
				else if(is_comma == false){//only one cours and and class has entered.

					strcpy(temp_char,command.c_str());//convert string type to char arra type.
					
					pointer = strtok(temp_char," ");
					course_id = stoi(pointer);
					
					pointer = strtok(NULL," ");
					class_id = stoi(pointer);
					
					is_cours_exits = check_cours_existence(coures_vec,course_id);//looks for existence of thee desired cours in the cours vector.
					
					if(is_cours_exits == false){//condition to no coures
						
						cout<<" Error:no Cours!"<<endl;
					}
					else{

						is_class_exist = check_class_existence(classes_vec,class_id);//checks for class exestence
						if(is_class_exist == false){
							
							cout<<"Error:no class"<<endl;
						}
						else{
							
							if((Admin.check_timetable_arranged())  == 0){//check for time table arrangement//************************************************************

								cout<<"Error:timetable not arranged yet"<<endl;
							}
							else{

								is_cours_assingned_to_a_class = is_cours_assingned_to_class(coures_vec,course_id);//look for the cours if it's assigned laready return true.
								if (is_cours_assingned_to_a_class == true){
							
									cout<<"Block:there is another class assigned"<<endl;	
								}
								else{
									Admin.arrangeClassroom(coures_vec,classes_vec,course_id,class_id,'n');//arrange desired class 
								}
							}
						}
					}
				}
			}
		}
		else if(command == "-arrangeC" and is_lecs_full == true and (Admin.check_timetable_arranged() == 0)){
			
			cout<<"timetable not arranged yet!"<<endl;
		}
		else if(command == "exit"){
			test = false;
		}
	
	}
	return 0;
}