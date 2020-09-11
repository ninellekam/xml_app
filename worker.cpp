#include "worker.h"

Worker::Worker(std::string fn, std::string sn, std::string mn){
    firstName = fn;
    secondName = sn;
    middleName = mn;
}
void                    Worker::print_worker() {
    std::cout << "\tSecondName:" << secondName << endl;
    std::cout << "\tFirstName:" << firstName << endl;
    std::cout << "\tMiddleName:" << middleName << endl;
    std::cout << "\tFunction:" << function << endl;
    std::cout << "\tSalary:" << salary << endl;
}
Worker::Worker(std::string fn, std::string sn, std::string mn, std::string func, int salary) {
    firstName = fn;
    secondName = sn;
    middleName = mn;
    function = func;
    salary = salary;
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
