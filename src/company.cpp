#include "../inc/company.h"

void    Company::add_worker(std::string depn,std::string s,
                                             std::string f,
                                             std::string m,
                                             std::string func, int sal){
    Worker ok(s,f,m,func,sal);
    auto it = dpts.find(depn);
    if (it != dpts.end())
        it->second.addworker(ok);
}
void    Company::go_department(std::string name,Department &d){
    dpts[name] = d;
}
void    Company::set_comp(const Company &c){
    dpts = c.dpts;
}
void    Company::add_department(std::string name) {
    auto it = dpts.find(name);
    if (it == dpts.end())
    {
        cout <<"gg";
        Department  dpt(name);
        dpts[name] = dpt;
    }
    else
        std::logic_error("ERROR : department name:" + name + "already in");
}
void    Company::delete_department(std::string name){
    auto it = dpts.find(name);
    if (it != dpts.end())
        dpts.erase(it);
    else
         std::logic_error("ERROR : department name:" + name + "NOT FOUND");   
}
void    Company::edit_worker(std::string dpt, std::string swrk, std::string func, int salary){
    auto it = dpts.find(dpt);
    if (it != dpts.end())
        it->second.edit_worker(swrk, func, salary);
    else
        std::logic_error("Name:" + swrk + "NOT FOUND");
}
void    Company::change_department_name(std::string name, std::string newname){
    auto it = dpts.find(name);
    if (it != dpts.end())
    {
        auto ok = dpts.find(newname);
        if (ok == dpts.end())
        {
        Department newdep(it->second);
        newdep.change_department(newname);
        dpts[name] = newdep;
        dpts.erase(it);
        }
    }
}
void    Company::del_worker(std::string depn,std::string s){
    auto it = dpts.find(depn);
    if (it != dpts.end())
    {
        it->second.delworker(s);
        dpts.erase(it);
    }
}

