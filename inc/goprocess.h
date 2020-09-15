#ifndef     GOPROCESS_H
#define     GOPROCESS_H
#include    "../inc/command.h"
class Gopro {

public:
    vector <Command *> Do_Com; // redo
    vector <Command *> No_Com; // undo
    Command *c;
    Company com;
    void    adddprtmnt(std::string name);
    void    fadddprtmnt(std::string name);

    void    addwrkr(std::string depn,std::string s,
                                    std::string f,
                                    std::string m,
                                    std::string func, int sal);
    void    faddwrkr(std::string depn,std::string s,
                                    std::string f,
                                    std::string m,
                                    std::string func, int sal);

                                    
void    delwrkr(std::string depn,std::string s);
void    deldprtmnt(std::string name);
void    editwrkr(std::string d,
    std::string s,
    std::string f,
    std::string m,
    std::string func,
    int sal);
void    chngdprtmntname(std::string name, std::string newname);
Gopro&  operator =(Gopro &other);
void    UNDO();
void    REDO();
void    print_gopro();
};

#endif