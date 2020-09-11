#pragma once
#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>
#include <map>
#include "company.h"

class Command {
    public:
        Company *comp;
    virtual void redo();
    virtual void undo();
};
class Adddep : public Command {
    public:
    std::string name;
    Adddep(std::string n) {name = n;}
    void redo() {
        comp->add_department(name);
    }
    void undo() {
        comp->delete_department(name);
    }
};
class Deldep: public Command {
    public:
    std::string name;
    Deldep(std::string n) { name = n;}
    void redo() {
        comp->delete_department(name);
    }
    void undo() {
         comp->add_department(name);
    }
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
    std::string ff, int sal) {depn = d ; swrk = s; 
    fwrk = s; 
    mwrk = m; func = ff; salary = sal;}
    void redo() {
        comp->add_worker(depn,swrk,fwrk,mwrk,func,salary);
    }
    void undo() {
       comp->del_worker(depn,swrk);
    }
};
class DelWorker : public Command {
    public:
    std::string depn;
    std::string swrk;
    DelWorker(std::string d,std::string s) {depn = d; swrk = s;}
    void redo() {
        comp->del_worker(depn,swrk);
    }
    void undo() {
        auto it = comp->dpts.find(depn);
        comp->add_worker(depn, swrk, 
        it->second.workers[swrk].firstName,
        it->second.workers[swrk].middleName,
        it->second.workers[swrk].function,
        it->second.workers[swrk].salary);
    }
};

#endif