#include "../inc/department.h"

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