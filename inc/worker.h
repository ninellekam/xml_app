#pragma once
#ifndef     WORKER_H
#define     WORKER_H
#include    <iostream>
#include    <vector>
using       namespace std;

class Worker
{
public:
    std::string  secondName; // фамилия
    std::string  firstName;
    std::string  middleName; //отчество
    std::string  function;
    int     salary;
    Worker() {function = "none" , salary = 0;}
    ~Worker() {}
    Worker(std::string fn, std::string sn, std::string mn, std::string func, int salary);
    Worker(std::string fn, std::string sn, std::string mn);
    void            print_worker();
    vector<std::string> getName();
    std::string     getFunction();
    unsigned int    getSalary();
    void            setFunction(std::string newFunc);
    void            setSalary(int newSalary);
};

#endif

