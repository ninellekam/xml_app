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
    std::string sn; std::string func; int salary;
    Company comp;
    com = "go";
    while (com !="EXIT") {
        getline(std::cin,com);
        fxml();  
        ok.editwrkr("syprog", "Васильев", "ddd", 221);
//     if (com == "LOAD")
//     //----------------------load file ---------------------------------- 
//         fxml();
//     else if (com == "ADD")
//     {
//     std::cout << "Department:"<<std::endl;
//     std::string dep;
//     std::cin >> dep ;
//     ok.adddprtmnt(dep);
//         std::cout << "Surname:"<<std::endl;
//         std::string sn;
//         std::cin >> sn ;
//     std::cout << "Firstname:"<<std::endl;
//         std::string fn;
//         std::cin >> fn ;
//     std::cout << "Middlename:"<<std::endl;
//         std::string mn;
//         std::cin >> mn ;
//     std::cout << "Function:"<<std::endl;
//         std::string func;
//         std::cin >> func ;
//     std::cout << "Salary:"<<std::endl;
//     int salary;
//     std::cin >> salary ;
//    // in_xml(dep,sn,fn,mn,func,salary);
//     fxml();
//     ok.addwrkr(dep,sn,fn,mn,func,salary);
//    // ok.print_gopro();
//     cout <<"------------------------------------------------------" << endl;
//     cout <<"------------------------------------------------------" << endl;
//     }
//     else if (com == "EDIT")
//     {
//         fxml();
//                         std::cout << "Department: ";
//                         cin >> dep;
//                         std::cout << "Surname: ";
//                         cin>>sn;
//                         std::cout << "Function: ";
//                         cin >> func;
//                         std::cout << "Salary: ";
//                         cin >> salary;
//         ok.editwrkr(dep,sn,func,salary);
//      //   ok.print_gopro();
//     }
    // else if (com == "UNDO")
    // {
     ok.UNDO();
     cout <<"---------------------UUUUU NNN DDDD OOOO----------------------" << endl;
    ok.print_gopro();
   // }
}
}
