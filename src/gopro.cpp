#include "../inc/gopro.h"

void    Gopro::adddprtmnt(std::string name){
    cout << "ok";
    c = new Adddep(name);
    c->set_company(&com);
    c->redo();
    Do_Com.push_back(c);
}
void    Gopro::addwrkr(std::string depn,std::string s,
std::string f,
std::string m,
std::string func, int sal){
    Command *com;
    AddWorker add(depn,s,f,m,func,sal);
    com = &add;
    com->redo();
    Do_Com.push_back(com);
}

void    Gopro::delwrkr(std::string depn,std::string s){
    Command *com;
    DelWorker add(depn,s);
    com = &add;
    com->redo();
    Do_Com.push_back(com);
}
void    Gopro::deldprtmnt(std::string name)
{
    Command *com;
    Deldep add(name);
    com = &add;
    com->redo();
    Do_Com.push_back(com);
}