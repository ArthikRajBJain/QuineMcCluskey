final: QuineMcCluskey.o functions.o UnitTest.o
	g++ -o QuineMcCluskey QuineMcCluskey.o functions.o
	g++ -o UnitTest UnitTest.o functions.o

functions.o: functions.cpp functions.h
	g++ -c functions.cpp -o functions.o

QuineMcCluskey.o: QuineMcCluskey.cpp functions.o
	g++ -c QuineMcCluskey.cpp -o QuineMcCluskey.o

UnitTest.o: UnitTest.cpp functions.o
	g++ -c UnitTest.cpp -o UnitTest.o

clean:
	rm *.o QuineMcCluskey UnitTest
