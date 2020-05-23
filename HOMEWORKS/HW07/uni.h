#ifndef UNI_H
#define UNI_H
#include<string>
using namespace std;
template<class T>
	class University{//university class
	
		public:
			/*i made these functions inline cause it dosn't work in any other ways to be implemented*/
			virtual T get_cont() = 0;
			virtual void set_uni_cont(T a) = 0;
			virtual string get_uni_name() = 0;
			virtual void set_uni_name(const string& st) = 0;
			virtual string get_uni_type() = 0;
			virtual void set_uni_type(string& uni_t)= 0;
			virtual string contribute(T element) = 0;		
		private:	
			T cont;
			string uni_name;
			string uni_type;
	};
#endif