#include "../inc/department.h"

Department::Department(std::string dn) { 
    depName = dn; 
    countWorkers = 0; 
    avgSalary = 0;
}

Department::Department(std::string dn, Worker wrkrs){
    depName = dn;
    std::string tcn = wrkrs.secondName;
    workers[tcn] = wrkrs;
    countWorkers = 0; avgSalary =0;
}
int     Department::getCountWorkers() {
      return countWorkers;
}
int     Department::getavgSalary() {
    if (countWorkers != 0)
        return avgSalary/countWorkers;
    else
        return avgSalary;   
}
void    Department::delworker( std::string sn) {
        auto it = workers.find(sn);
        if ( it == workers.end())
            std::logic_error ("SecondName" + sn + "NOT FOUND ");
        else
            workers.erase(it);
        --countWorkers;
        avgSalary = avgSalary - it->second.salary;
}
void    Department::changeWorker(std::string for_change_secname, vector<std::string> name, std::string func, int salary) {
        auto it = workers.find(for_change_secname) ;
        if (it == workers.end())
            std::logic_error("SecondName" + for_change_secname + "for change NOT FOUND");
        else
        {
            avgSalary = avgSalary - it->second.salary;
            it->second.secondName = name[0];
            it->second.firstName = name[1];
            it->second.middleName = name[2];
            it->second.salary = salary;
            it->second.function = func;
        }
        avgSalary = avgSalary + salary;
        
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
        workers[wrkr.secondName].salary = wrkr.salary;
        workers[wrkr.secondName].middleName = wrkr.middleName;
        countWorkers++;
        avgSalary = avgSalary + wrkr.salary;
    }
void    Department::print_department(){
    std::cout<< "\vDepartment:" << depName << std::endl;
    std::cout << "Сount of workers: " << getCountWorkers() << std::endl;
    std::cout << "Avg Salary: " << getavgSalary() << std::endl;
    int c = 0;
    for (auto it = workers.begin() ; it!= workers.end() ; it++)
    {
        if (c%2 == 0)
        {
            std::cout << "\tSecondName: " << it->second.secondName << endl;
            std::cout << "\tFirstName: " << it->second.firstName << endl;
            std::cout << "\tMiddleName: " << it->second.middleName << endl;
            std::cout << "\tFunction: " << it->second.function << endl;
            std::cout << "\tSalary: " << to_string(it->second.salary) << endl;
        }
        else
            {
            std::cout << "SecondName: " << it->second.secondName << endl;
            std::cout << "FirstName: " << it->second.firstName << endl;
            std::cout << "MiddleName: " << it->second.middleName << endl;
            std::cout << "Function: " << it->second.function << endl;
            std::cout << "Salary: " << to_string(it->second.salary) << endl;
        }
        c++;
    }
}
void    Department::change_department(std::string newname){
        depName = newname;
}