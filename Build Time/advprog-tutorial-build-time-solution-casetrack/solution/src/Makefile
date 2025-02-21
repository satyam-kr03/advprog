CXX = g++ 
CXXFLAGS = -std=c++17 -Wall -g

caseTrack: caseTrack.o helper.o
	$(CXX) -o caseTrack caseTrack.o helper.o $(CXXFLAGS)

caseTrack.o: caseTrack.cpp helper.h
	$(CXX) -c -o caseTrack.o caseTrack.cpp $(CXXFLAGS)

helper.o: helper.cpp helper.h
	$(CXX) -c -o helper.o helper.cpp $(CXXFLAGS)

clean:
	rm caseTrack caseTrack.o helper.o
