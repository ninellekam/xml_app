
#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>
#include <map>
#include "../inc/company.h"
#include "../inc/xxx.h"

class Command {
    public:
        Company *comp;
    virtual ~Command() {}
    virtual void redo() = 0;
    virtual void undo() = 0;
    void    set_company(Company *c);
};
class Adddep : public Command {
    public:
    std::string name;
    Adddep(std::string n);
    void redo();
    void undo();
};
class Deldep: public Command {
    public:
    std::string name;
    Department dep;
    Deldep(std::string n);
    void redo();
    void undo();
};
class AddWorker : public Command {
    public:
    std::string depn;
    std::string swrk;
    std::string fwrk;
    std::string mwrk;
    std::string func;
    int         salary;
    AddWorker(std::string d,std::string s,
    std::string f,
    std::string m,
    std::string ff, int sal);
    void redo();
    void undo();
};
class DelWorker : public Command {
    public:
    std::string depn;
    std::string swrk;
    std::string fwrk;
    std::string mwrk;
    std::string func;
    int salary;
    DelWorker(std::string d,std::string s);
    void redo();
    void undo();
};

class EditWorker : public Command {
    public :
    std::string dpt;
    std::string swrk;
    std::string func;
    std::string preds;
    std::string predfunc;
    int predsalary;
    int salary;

    EditWorker(std::string d,
    std::string s,
    std::string f,
    int sal);
    void redo();
    void undo(); 
};
class ChangeDepName : public Command {
    public :
    std::string name;
    std::string newname;
    ChangeDepName(std::string name,
    std::string newname);
    void redo();
    void undo(); 
};

#endif