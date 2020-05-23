CXXFLAGS = -std=c++11
hw07: mohammad_ashraf_yawar_161044123.o functions.o standfunc.cpp
	g++ mohammad_ashraf_yawar_161044123.o functions.o  standfunc.o -o hw07
mohammad_ashraf_yawar_161044123.o: mohammad_ashraf_yawar_161044123.cpp headerfile.h uni.h standfunc.h
	g++ -c mohammad_ashraf_yawar_161044123.cpp
functions.o: functions.cpp  headerfile.h uni.h standfunc.h
	g++ -c functions.cpp
standfunc.o: standfunc.cpp headerfile.h uni.h
clean:
	rm *.o hw07