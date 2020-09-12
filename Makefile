HEADER = inc/command.h inc/tinyxml2.h inc/gopro.h inc/company.h inc/department.h inc/worker.h
OPTION = -c -I $(HEADER)
all:
	g++ $(OPTION) src/tinyxml.cpp src/tinyxml2.cpp src/command.cpp src/gopro.cpp src/company.cpp src/department.cpp src/worker.cpp   -std=c++11
