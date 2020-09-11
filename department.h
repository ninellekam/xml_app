#pragma once
#ifndef DEFINE_H
#define DEFINE_H
#include <iostream>
#include <vector>
#include <map>
#include "worker.h"

using namespace std;

class Department
{
public:
    std::string depName;
    int countWorkers;
    int avgSalary;
    map<std::string, Worker> workers; // workers[kamkia] = ob;


    Department() {}
    Department(std::string dn) {depName = dn;}
    Department(std::string dn, Worker wrkrs){
        depName = dn;
        std::string tcn = wrkrs.secondName;
        workers[tcn] = wrkrs;
    }
    std::string   getName();
    int     getCountWorkers();
    int     getavgSalary();
    void    delworker( std::string sn);
    void    addworker(Worker wrkr);
    void    edit_worker(std::string swrk, std::string func, int salary);
    void    changeWorker(std::string for_change_secname, vector<std::string> name, std::string func, int salary);
    void    setName(std::string newName);
    void    print_department();
    void    change_department( std::string newname);
};

std::string   Department::getName(){
    return depName;
}
int     Department::getCountWorkers() {
      return countWorkers;
  }
int     Department::getavgSalary() {
    return avgSalary;
}
void    Department::delworker( std::string sn) {
        auto it = workers.find(sn);
        if ( it == workers.end())
            std::logic_error ("SecondName" + sn + "NOT FOUND ");
        else
            workers.erase(it);
}
void    Department::changeWorker(std::string for_change_secname, vector<std::string> name, std::string func, int salary) {
        auto it = workers.find(for_change_secname) ;
        if (it == workers.end())
            std::logic_error("SecondName" + for_change_secname + "for change NOT FOUND");
        else
        {
            it->second.secondName = name[0];
            it->second.firstName = name[1];
            it->second.middleName = name[2];
            it->second.salary = salary;
            it->second.function = func;
        }
        
}
void    Department::edit_worker(std::string swrk, std::string func, int salary){
    auto it = workers.find(swrk);
    if (it != workers.end())
    {
        workers[swrk].function = func;
        workers[swrk].salary = salary;
    }
    else
        std::logic_error("Name:" + swrk + "NOT FOUND");
}
void    Department::setName(std::string newName){
            depName = newName;
    }
void    Department::addworker(Worker wrkr){
        workers[wrkr.secondName] = wrkr;
    }
void    Department::print_department(){
    for (auto it = workers.begin() ; it!= workers.end() ; it++)
    {
          cout<<"Department:" << depName << endl;
          it->second.print_worker();
    }
}
void    Department::change_department(std::string newname){
        depName = newname;
}
#endif