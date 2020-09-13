#include "../inc/xxx.h"

int if_dprtmnt_in_xml(std::string dn, std::string s,std::string f,std::string m,std::string ff,
int sal)
{
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile("tst.xml");
    if (eResult != XML_SUCCESS) return -1;
                XMLNode * root = xmlDoc.FirstChildElement("departments");
if (root == nullptr) return -1;

XMLElement *department = root->FirstChildElement("department");
for (XMLElement *department = root->FirstChildElement(); department!=nullptr; department=department->NextSiblingElement())
{  
    std::string depname;
    depname = department->Attribute("name");
    if  (depname == dn)
    {

        XMLElement *employments = department->FirstChildElement("employments");
        XMLElement *employmentElement = xmlDoc.NewElement("employment");
        XMLElement *element = xmlDoc.NewElement("surname");
        XMLText *elementText = xmlDoc.NewText(s.c_str());

        element->LinkEndChild(elementText); 
        employmentElement->LinkEndChild(element); 
        employments->LinkEndChild(employmentElement); 

        element = xmlDoc.NewElement("name");
        elementText = xmlDoc.NewText(f.c_str());
        element->LinkEndChild(elementText); 
        employmentElement->LinkEndChild(element); 
        employments->LinkEndChild(employmentElement);

        element = xmlDoc.NewElement("middlename");
        elementText = xmlDoc.NewText(m.c_str());
        element->LinkEndChild(elementText); 
        employmentElement->LinkEndChild(element); 
        employments->LinkEndChild(employmentElement);

        element = xmlDoc.NewElement("function");
        elementText = xmlDoc.NewText(ff.c_str());
        element->LinkEndChild(elementText); 
        employmentElement->LinkEndChild(element);  
        employments->LinkEndChild(employmentElement);

        element = xmlDoc.NewElement("salary");
        elementText = xmlDoc.NewText(to_string(sal).c_str());
        element->LinkEndChild(elementText); 
        employmentElement->LinkEndChild(element); 
        employments->LinkEndChild(employmentElement);
    }
}

xmlDoc.SaveFile("txt.xml");
    return (0);
}

int if_dprtmnt_no_in_xml(std::string dn, std::string s,std::string f,std::string m,std::string ff,
int sal) {

    XMLDocument xmlDoc;
xmlDoc.LoadFile("tst.xml");
// if (eResult != XML_SUCCESS) return -1;

XMLNode * root = xmlDoc.FirstChildElement("departments");
if (root == nullptr) return -1;

XMLElement *department = xmlDoc.NewElement("department");
department->SetAttribute("name",dn.c_str());
root->LinkEndChild(department);
XMLElement *employments = xmlDoc.NewElement("employments");
department->LinkEndChild(employments);

XMLElement *employmentElement = xmlDoc.NewElement("employment");
XMLElement *element = xmlDoc.NewElement("surname");
XMLText *elementText = xmlDoc.NewText(s.c_str());

element->LinkEndChild(elementText); 
employmentElement->LinkEndChild(element); 
employments->LinkEndChild(employmentElement); 

element = xmlDoc.NewElement("name");
elementText = xmlDoc.NewText(f.c_str());
element->LinkEndChild(elementText); 
employmentElement->LinkEndChild(element); 
employments->LinkEndChild(employmentElement);

element = xmlDoc.NewElement("middlename");
elementText = xmlDoc.NewText(m.c_str());
element->LinkEndChild(elementText); 
employmentElement->LinkEndChild(element); 
employments->LinkEndChild(employmentElement);

element = xmlDoc.NewElement("function");
elementText = xmlDoc.NewText(ff.c_str());
element->LinkEndChild(elementText); 
employmentElement->LinkEndChild(element);  
employments->LinkEndChild(employmentElement);

element = xmlDoc.NewElement("salary");
elementText = xmlDoc.NewText(to_string(sal).c_str());
element->LinkEndChild(elementText); 
employmentElement->LinkEndChild(element); 
employments->LinkEndChild(employmentElement);

xmlDoc.SaveFile("SavedData.xml");
    return 0;
}

