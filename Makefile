NAME = ft_main
SRC = src/main.cpp src/tinyxml2.cpp src/tinyxmlerror.cpp src/xml_codes.cpp src/command.cpp src/tinyxmlparser.cpp src/goprocess.cpp src/company.cpp src/department.cpp src/worker.cpp src/tinydelxml.cpp src/tinystr.cpp 

.PHONY: clean fclean

all:
	g++ -o $(NAME) $(SRC) -std=c++11

clean:
	/bin/rm -f *.o *.h.gch
fclean: clean
	/bin/rm -f $(NAME)
