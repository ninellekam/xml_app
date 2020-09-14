#include    <iostream>
#include    "../inc/tinyxml2.h"
#include    "../inc/tinydelxml.h"
#include    "../inc/tinystr.h"
#include    "../inc/department.h"
using       namespace std;
using       namespace tinyxml2;

int     worker_in_xml(std::string dn, std::string s,std::string f,std::string m,std::string ff, int sal);
void    dprmnt_in_xml(std::string dn);
int     RemoveDep(std::string dn);
int     RemoveWorker(std::string dn,std::string s,std::string f,std::string m);
int     ChangeDepNameXml(std::string dn, std::string newdn);
int     RemoveDepName(std::string dn);
int     SetDep(std::string depname , Department &dep);