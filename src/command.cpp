#include "../inc/command.h" 

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
    }

Deldep::Deldep(std::string n) { name = n;}
void Deldep::redo() {
        comp->delete_department(name);
    }
void Deldep::undo() {
         comp->add_department(name);
    }

AddWorker::AddWorker(std::string d,std::string s,
    std::string f,
    std::string m,
    std::string ff, int sal) {depn = d ; swrk = s; 
    fwrk = f; 
    mwrk = m; func = ff; salary = sal;}
void AddWorker::redo() {
        comp->add_worker(depn,swrk,fwrk,mwrk,func,salary);
    }
void AddWorker::undo() {
       comp->del_worker(depn,swrk);
    }

DelWorker::DelWorker(std::string d,std::string s) {depn = d; swrk = s;}
void DelWorker::redo() {
        comp->del_worker(depn,swrk);
    }
void DelWorker::undo() {
        auto it = comp->dpts.find(depn);
        comp->add_worker(depn, swrk, 
        it->second.workers[swrk].firstName,
        it->second.workers[swrk].middleName,
        it->second.workers[swrk].function,
        it->second.workers[swrk].salary);
    }

EditWorker::EditWorker(std::string d,
    std::string s,
    std::string f,
    int sal) {
        dpt = d; swrk = s;
        preds = swrk;
        predfunc=f; predsalary=sal;
     
        comp->find_worker(dpt,swrk);
        cout << "predfunc " << predfunc << endl;
        predsalary = comp->find_worker(d,s).salary;
        func = f; salary = sal; 
    }
void    EditWorker::redo() {
    cout <<"d";
        comp->edit_worker(dpt,swrk,func,salary);
    }
void    EditWorker::undo() {
        comp->edit_worker(dpt,preds,predfunc,predsalary);
    }