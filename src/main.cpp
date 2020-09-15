#include    <iostream>
#include    "../inc/tinyxml2.h"
#include    "../inc/goprocess.h"
#include    "../inc/xml_codes.h"
using namespace tinyxml2;


Gopro process;
int fxml()
{
    XMLDocument xmlDoc;

    XMLError eResult = xmlDoc.LoadFile("txt.xml");

    if (eResult != XML_SUCCESS) return -1;

    XMLNode * root = xmlDoc.FirstChildElement("departments");
    if (root == nullptr) return -1;

    for (XMLElement *department = root->FirstChildElement(); department!=nullptr; department=department->NextSiblingElement())
    {    
        Department dp;
        dp.depName = department->Attribute("name") ; 
        process.adddprtmnt(dp.depName);

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
            process.addwrkr(dp.depName,wrk.secondName,
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
        std::getline(std::cin,com);
    if (com == "LOAD")
    //----------------------load file ---------------------------------- 
        fxml();
    else if (com == "ADD WRK")
    {
        std::cout << "Department:"<<std::endl;
        std::getline(std::cin,dep);
        process.adddprtmnt(dep);
        std::cout << "Surname:"<<std::endl;
        std::getline(std::cin,sn);
        std::cout << "Firstname:"<<std::endl;
        std::getline(std::cin,fn);
        std::cout << "Middlename:"<<std::endl;
        std::getline(std::cin,mn);
        std::cout << "Function:"<<std::endl;
        std::getline(std::cin,func);
        std::cout << "Salary:"<<std::endl;
        std::string sal;
        std::getline(std::cin,sal);
        salary = std::atoi(sal.c_str());
        fxml();
        process.addwrkr(dep,sn,fn,mn,func,salary);
        worker_in_xml(dep,sn,fn,mn,func,salary);
    cout <<"---------------------- A D D   W R K -------------------------" << endl;
    }
    else if (com == "ADD DEP")
    {
        fxml();
        std::cout << "Department:" << std::endl;
        getline(std::cin,dep);
        process.adddprtmnt(dep);
        dprmnt_in_xml(dep);
        cout <<"-------------------A D D  D E P ---------------------------" << endl;
    }
    else if (com == "EDIT")
    {
        fxml();
        std::cout << "Department: ";
        std::getline(std::cin,dep);
        std::cout << "Surname: ";
        std::getline(std::cin,sn);
        std::cout << "Firstname:"<<std::endl;
        std::getline(std::cin,fn);
        std::cout << "Middlename:"<<std::endl;
        std::getline(std::cin,mn);
        std::cout << "New Function: ";
        std::getline(std::cin,func);
        std::cout << "New Salary: ";
        std::string sal;
        std::getline(std::cin,sal);
        salary = std::atoi(sal.c_str());
        process.editwrkr(dep,sn,fn,mn,func,salary);
        cout << "---------------------- E D I T  W O R K E R  ------------------------" << endl;
    }
    else if (com == "CHANGE DEP NAME"){
        fxml();
        std::cout << "Department: ";
        std::getline(std::cin,dep);
        std::cout << "Newname: ";
        std::getline(std::cin,sn); 
        process.chngdprtmntname(dep, sn);
       cout << "---------------------- C H A N G E   D E P   N A M E ------------------------" << endl;
    }
    else if (com =="DEL WRK"){
        fxml();
        std::cout << "Department: ";
        std::getline(std::cin,dep);
        std::cout << "Surname:"<<std::endl;
        std::getline(std::cin,sn);
        std::cout << "Firstname:"<<std::endl;
        std::getline(std::cin,fn);
        std::cout << "Middlename:"<<std::endl;
        std::getline(std::cin,mn);
        process.delwrkr(dep, sn);
        cout << "----------------------D E L  W R K ------------------------" << endl;
    }
    else if (com == "DEL DEP")
    {
        fxml();
        std::cout << "Department:" << std::endl;
        std::getline(std::cin,dep);
        process.deldprtmnt(dep);
        cout << "----------------------D E L  D E P ------------------------" << endl;
    }
    else if (com == "PRINT")
    {
        process.print_gopro();
    }
    else {
    if (com == "UNDO"){
        process.UNDO();
        cout <<"--------------------- U N D O ----------------------" << endl;
    }
        else if (com == "REDO"){
            process.REDO();
         cout <<"--------------------- R E D O ----------------------" << endl;
        }
    }
}
}
