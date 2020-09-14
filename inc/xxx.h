#include    <iostream>
#include    "../inc/tinyxml2.h"
#include    "../inc/tinydelxml.h"
#include    "../inc/tinystr.h"
using       namespace std;
using       namespace tinyxml2;

int     worker_in_xml(std::string dn, std::string s,std::string f,std::string m,std::string ff, int sal);
void    dprmnt_in_xml(std::string dn);
int     Removedep(std::string dn);