#include "../inc/xxx.h"

int worker_in_xml(std::string dn, std::string s,std::string f,std::string m,std::string ff,
int sal)
{
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile("txt.xml");
    if (eResult != XML_SUCCESS) 
        return   -1;
    cout << "gggg";
    XMLNode * root = xmlDoc.FirstChildElement("departments");
    if (root == nullptr) return -1;

    int fl = 0;

for (XMLElement *department = root->FirstChildElement(); department!=nullptr; department=department->NextSiblingElement())
{  
    std::string depname;
    depname = department->Attribute("name");
    cout << depname ;
    if (fl == 1)
        break;
    if  (depname == dn)
    {
        fl = 1;
        cout << " ok " ;
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
if (fl == 0 ) // ----------------------no dp in ------------------------------
{
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
}

xmlDoc.SaveFile("txt.xml");
    return (0);
}

void dprmnt_in_xml(std::string dn){
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile("txt.xml");
    XMLNode * root = xmlDoc.FirstChildElement("departments");
    XMLElement *department = xmlDoc.NewElement("department");
    department->SetAttribute("name",dn.c_str());
    root->LinkEndChild(department);
    xmlDoc.SaveFile("txt.xml");
}

