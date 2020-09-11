#pragma once
#ifndef GOPRO_H
#define GOPRO_H
#include "command.h"
class Gopro {

public:
    vector <Command *> Do_Com; // redo
    vector <Command *> No_Com; // undo
void    adddprtmnt(std::string name){
    Command *com;
    Adddep add(name);
    com = &add;
    com->redo();
    Do_Com.push_back(com);
}
void    addwrkr(std::string depn,std::string s,
std::string f,
std::string m,
std::string func, int sal){
    Command *com;
    AddWorker add(depn,s,f,m,func,sal);
    com = &add;
    com->redo();
    Do_Com.push_back(com);
}

void    delwrkr(std::string depn,std::string s){
    Command *com;
    DelWorker add(depn,s);
    com = &add;
    com->redo();
    Do_Com.push_back(com);
}
void    deldprtmnt(std::string name)
{
    Command *com;
    Deldep add(name);
    com = &add;
    com->redo();
    Do_Com.push_back(com);
}
//void    editwrkr(std::string dpt, std::string swrk, std::string func, int salary);
//void    change_dprtmnt_name(std::string name, std::string newname);
};

#endif