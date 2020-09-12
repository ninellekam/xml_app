#ifndef GOPRO_H
#define GOPRO_H
#include "../inc/command.h"
class Gopro {

public:
    vector <Command *> Do_Com; // redo
    vector <Command *> No_Com; // undo
    Command *c;
    Company com;
    void    adddprtmnt(std::string name);
    void    addwrkr(std::string depn,std::string s,
                                    std::string f,
                                    std::string m,
                                    std::string func, int sal);
void    delwrkr(std::string depn,std::string s);
void    deldprtmnt(std::string name);
};

//void    editwrkr(std::string dpt, std::string swrk, std::string func, int salary);
//void    change_dprtmnt_name(std::string name, std::string newname);
#endif