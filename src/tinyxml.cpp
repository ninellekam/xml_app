#include <iostream>
#include "../inc/tinyxml2.h"
using namespace std;
using namespace tinyxml2;
#include "../inc/gopro.h"
#include "../inc/xxx.h"

Gopro ok;
int fxml()
{
    XMLDocument xmlDoc;

    XMLError eResult = xmlDoc.LoadFile("tst.xml");

    if (eResult != XML_SUCCESS) return -1;

    XMLNode * root = xmlDoc.FirstChildElement("departments");
    if (root == nullptr) return -1;

    for (XMLElement *department = root->FirstChildElement(); department!=nullptr; department=department->NextSiblingElement())
    {    
        Department dp;
        dp.depName = department->Attribute("name") ; 
        ok.adddprtmnt(dp.depName);

        XMLNode * employments = department->FirstChildElement("employments");
        Worker wrk;
        
        for (XMLNode *employment = employments->FirstChildElement();employment!=nullptr;employment=employment->NextSiblingElement())
        {        
            for (XMLElement* element = employment->FirstChildElement() ; element != nullptr ; element = element->NextSiblingElement())
            {
                if ( element == employment->FirstChildElement("surname") )
                    wrk.secondName =  element->GetText() ;
                else if (element == employment->FirstChildElement("name") )
                    wrk.firstName =  element->GetText() ;
                else if (element == employment->FirstChildElement("middleName") )
                    wrk.middleName =  element->GetText() ;
                else if (element == employment->FirstChildElement("function") )
                    wrk.function =  element->GetText() ;
                else if (element == employment->FirstChildElement("salary") )
                    wrk.salary =  atoi(element->GetText()) ;
            }
            dp.addworker(wrk);
            ok.addwrkr(dp.depName,wrk.secondName,
            wrk.firstName,
            wrk.middleName,wrk.function,wrk.salary);
        }
    }
    return 0;
}
int main()
{
    //---------------go  process----------------------------------------
    std::string com;
    std::string dep;
    std::string sn;
    std::string fn; std::string mn;std::string func; int salary;
    Company comp;
    com = "go";
    while (com !="EXIT") {
        getline(std::cin,com);
    if (com == "LOAD")
    //----------------------load file ---------------------------------- 
    fxml();
    else if (com == "ADD")
    {
    std::cout << "Department:"<<std::endl;
    getline(std::cin,dep);
    ok.adddprtmnt(dep);
        std::cout << "Surname:"<<std::endl;
    getline(std::cin,sn);
        std::cout << "Firstname:"<<std::endl;
    getline(std::cin,fn);
        std::cout << "Middlename:"<<std::endl;
    getline(std::cin,mn);
        std::cout << "Function:"<<std::endl;
    getline(std::cin,func);
        std::cout << "Salary:"<<std::endl;
    int salary;
    std::string sal;
    getline(std::cin,sal);
    salary = std::atoi(sal.c_str());
   // in_xml(dep,sn,fn,mn,func,salary);
    fxml();
    ok.addwrkr(dep,sn,fn,mn,func,salary);
   // ok.print_gopro();
    cout <<"------------------------------------------------------" << endl;
    cout <<"------------------------------------------------------" << endl;
    }
    else if (com == "EDIT")
    {
        fxml();
                std::cout << "Department: ";
                getline(std::cin,dep);
                std::cout << "Surname: ";
                getline(std::cin,sn);
                std::cout << "New Function: ";
                getline(std::cin,func);
                std::cout << "New Salary: ";
                std::string sal;
                getline(std::cin,sal);
                salary = std::atoi(sal.c_str());
        ok.editwrkr(dep,sn,func,salary);
        ok.print_gopro();
    }
    else if (com == "CHANGE"){
        fxml();
        ok.print_gopro();
                std::cout << "Name Department: ";
                getline(std::cin,dep);
                std::cout << "Newname: ";
                getline(std::cin,sn);
        ok.chngdprtmntname(dep,sn);
        //ok.print_gopro();
    }
    else if (com =="DELW"){
        fxml();
        std::cout << "Department: ";
                getline(std::cin,dep);
        std::cout << "Surname:"<<std::endl;
            getline(std::cin,sn);
        ok.delwrkr(dep, sn);
    }
    else if (com == "UNDO"){
        ok.UNDO();
        cout <<"---------------------UUUUU NNN DDDD OOOO----------------------" << endl;
        ok.print_gopro();
    }
}
}
