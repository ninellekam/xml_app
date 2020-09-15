// class of Commands.Needed to implement (undo) (redo) and commands
// every command action starts from this file
#include "../inc/command.h" 
#include "../inc/xml_codes.h"
#include "../inc/department.h"

void    Command::set_company(Company *c){
        comp = c;
        comp->dpts = c->dpts;
}
Adddep::Adddep(std::string n) {name = n;}
void Adddep::redo() {
        comp->add_department(name);
    }
void Adddep::undo() {
        comp->delete_department(name);
        RemoveDepName(name);
    }

Deldep::Deldep(std::string n) { name = n;}
void Deldep::redo() {
        dep = comp->find_dpt(name);
        comp->delete_department(name);
     //   RemoveDep(name);
    }
void Deldep::undo() {
        SetDep(name , dep);
        comp->set_new_department_before_delete(name, dep);
    }

AddWorker::AddWorker(std::string d,std::string s, std::string f, std::string m, std::string ff, int sal){
    depn = d; 
    swrk = s; 
    fwrk = f; 
    mwrk = m; 
    func = ff; 
    salary = sal;
}
void AddWorker::redo() {
        comp->add_worker(depn,swrk,fwrk,mwrk,func,salary);
    }
void AddWorker::undo() {
       comp->del_worker(depn,swrk);
       RemoveWorker(depn,swrk,fwrk,mwrk);
    }

DelWorker::DelWorker(std::string d,std::string s) {depn = d; swrk = s;}
void DelWorker::redo() {
        fwrk = comp->find_worker(depn,swrk).firstName;
        mwrk = comp->find_worker(depn,swrk).middleName;
        func  = comp->find_worker(depn,swrk).function;
        salary = comp->find_worker(depn,swrk).salary;
        comp->del_worker(depn,swrk);
        RemoveWorker(depn,swrk,fwrk,mwrk);
    }
void DelWorker::undo() {
        auto it = comp->dpts.find(depn);
        comp->add_worker(depn, swrk, 
        fwrk,mwrk,func,salary);
        worker_in_xml(depn, swrk, fwrk, mwrk, func, salary);
    }

EditWorker::EditWorker(std::string d,
    std::string s,
    std::string f,
    std::string m,
    std::string fun,
    int sal) {
        dpt = d;
        swrk = s;
        fwrk = f; 
        mwrk = m;
        preds = swrk;
        predfunc=f; predsalary=sal;
        func = fun; salary = sal; 
}
void    EditWorker::redo() {
        predfunc = comp->find_worker(dpt,swrk).function;
        predsalary = comp->find_worker(dpt,swrk).salary;
        comp->edit_worker(dpt,swrk,func,salary);
        RemoveWorker(dpt,swrk,fwrk,mwrk);
        worker_in_xml(dpt,swrk,fwrk,mwrk,func,salary);
}
void    EditWorker::undo() {
        comp->edit_worker(dpt,preds,predfunc,predsalary);
        RemoveWorker(dpt,swrk,fwrk,mwrk);
        worker_in_xml(dpt,swrk,fwrk,mwrk,predfunc,predsalary);
}


ChangeDepName::ChangeDepName(std::string n,
    std::string nw){
        name = n;
        newname = nw;
    }
void ChangeDepName::redo(){
        comp->change_department_name(name, newname);
        ChangeDepNameXml(name, newname);
}
void ChangeDepName::undo(){
    comp->change_department_name(newname, name);
    ChangeDepNameXml(newname, name);
}