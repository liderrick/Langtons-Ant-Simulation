#Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++0x

#Project executable output file
PROJ = project1

#Object files
OBJS = main.o Ant.o Board.o menu.o randomFunctions.o

#Source files
SRCS = main.cpp Ant.cpp Board.cpp menu.cpp randomFunctions.cpp

#Header files
HEADERS = Ant.hpp Board.hpp menu.hpp randomFunctions.hpp

#Compile project executable from object files
${PROJ}: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${PROJ}

#Compile object files from source files
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

#Remove project executable and object files
clean:
	rm ${PROJ} ${OBJS}

#Citation:
#Format of this makefile based off of: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4