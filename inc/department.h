
#ifndef DEFINE_H
#define DEFINE_H
#include <iostream>
#include <vector>
#include <map>
#include "../inc/worker.h"

using namespace std;

class Department
{
public:
    std::string depName;
    int countWorkers;
    int avgSalary;
    map<std::string, Worker> workers; // workers[kamkia] = ob;


    Department() {}
    Department(std::string dn);
    Department(std::string dn, Worker wrkrs);
    std::string     getName();
    int             getCountWorkers();
    int             getavgSalary();
    void            delworker( std::string sn);
    void            addworker(Worker wrkr);
    void            edit_worker(std::string swrk, std::string func, int salary);
    void            changeWorker(std::string for_change_secname, vector<std::string> name, std::string func, int salary);
    void            setName(std::string newName);
    void            print_department();
    void            change_department( std::string newname);
};

#endif