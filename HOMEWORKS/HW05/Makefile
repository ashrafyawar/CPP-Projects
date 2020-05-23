CXXFLAGS = -std=c++11
hw05: mohammad_ashraf_yawar_161044123.o functions.o
	g++ mohammad_ashraf_yawar_161044123.o functions.o -o hw05
mohammad_ashraf_yawar_161044123.o: mohammad_ashraf_yawar_161044123.cpp headerfile.h
	g++ -c mohammad_ashraf_yawar_161044123.cpp
functions.o: functions.cpp  headerfile.h
	g++ -c functions.cpp
clean:
	rm *.o hw05