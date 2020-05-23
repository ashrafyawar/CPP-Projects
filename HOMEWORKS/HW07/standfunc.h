#ifndef STAND_ALONE
#define STAND_ALONE
#include"headerfile.h"
#include"uni.h"
/*some stand alone functions*/	
	void Libral_University(vector<Persons>&,Employee *em_ptr);
	template<class T>
	Employee* find_besteemp(vector<Persons>&,LibUni<T> *l_uni,LiberalEducation<T> *lib_edu);
	int max_index(int arr[]);

	void Comonist_uni(vector<Persons>&,Employee *emptr[ARR_SIZE]);
	void Capitalist_uni(vector<Persons>&);
	int NewBroker(vector<Persons>&);
	int NewWorker(vector<Persons>&);
	void Start(vector<Persons>& per_vec,BrokerLecturer *LEC_B,BrokerResAssist *RES_B,BrokerSecretary *SEC_B,BrokerOfficer *OF_B,CapUni<int> *Cap_Uni);

	string action_name(const int&);
	void reset_emp(vector<Persons>&,const string&,const string&);
#endif