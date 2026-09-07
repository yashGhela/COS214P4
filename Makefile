# complier variable
CXX = g++
#compiler flags variable
CXXFLAGS = -Wall -g -std=c++11

#executable
TARGET = taskforge
#source files
SRCS = main.cpp AssigningState.cpp AuditTrailDecorator.cpp CaseDecorator.cpp ChronologicalIterator.cpp CompletedState.cpp ConfidentialityDecorator.cpp HighPriorityDecorator.cpp HighPriorityIterator.cpp InProgressState.cpp OnHoldState.cpp Phase.cpp Task.cpp TaskOnlyIterator.cpp TaskState.cpp

#build command (compiles the .cpp's and links the .o files)
build:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

#deletes the executable and the linker files
clean:
	rm -f $(TARGET) *.o
