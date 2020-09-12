
#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>
#include <map>
#include "../inc/company.h"

class Command {
    public:
        Company *comp;
    virtual void redo();
    virtual void undo();
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
    DelWorker(std::string d,std::string s);
    void redo();
    void undo();
};

#endif