#include "../inc/worker.h"


Worker::Worker(std::string sn, std::string fn, std::string mn){
    firstName = fn;
    secondName = sn;
    middleName = mn;
}
void                    Worker::print_worker() {
    std::cout << "\tSecondName: " << secondName << endl;
    std::cout << "\tFirstName: " << firstName << endl;
    std::cout << "\tMiddleName: " << middleName << endl;
    std::cout << "\tFunction: " << function << endl;
    std::cout << "\tSalary: " << to_string(salary) << endl;
}
Worker::Worker(std::string sn, std::string fn, std::string mn, std::string func, int sal) {
    firstName = fn;
    secondName = sn;
    middleName = mn;
    function = func;
    salary = sal;
}
/*vector <std::string>     Worker::getName() {
    vector<std::string> ok;
    ok.push_back(secondName); // 0
    ok.push_back(firstName); // 1
    ok.push_back(middleName);// 2
    return  ok;
}*/
unsigned int            Worker::getSalary(){

    return salary;
}
void                    Worker::setFunction(std::string newFunc){
    function = newFunc;
}
void                    Worker::setSalary(int newSalary){
    salary = newSalary;
}
std::string             Worker::getFunction(){
    return function;
}
