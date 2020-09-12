
#ifndef COMPANY_H
#define COMPANY_H
#include <iostream>
#include <vector>
#include <map>
#include "../inc/department.h"

class Company {

public:
    map<std::string, Department> dpts;
    Company(){};
    ~Company(){};
void    set_comp(const Company &c);
void    go_department(std::string name, Department &d);
void    add_department(std::string name);
void    add_worker(std::string depn,std::string s,
std::string f,
std::string m,
std::string func, int sal);
void    del_worker(std::string depn,std::string s);
void    delete_department(std::string name);
void    edit_worker(std::string dpt, std::string swrk, std::string func, int salary);
void    change_department_name(std::string name, std::string newname);
};

#endif