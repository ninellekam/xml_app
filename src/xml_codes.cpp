#include "../inc/xml_codes.h"

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
    if (fl == 1)
        break;
    if  (depname == dn)
    {
        fl = 1;
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
    XMLNode * dep = xmlDoc.NewElement("department");
   // XMLNode * empl = xmlDoc.FirstChildElement("employments");
    department->SetAttribute("name",dn.c_str());
    root->LinkEndChild(department);
    root->LinkEndChild(dep);
    xmlDoc.SaveFile("txt.xml");
}


int    RemoveDep(std::string dn){
    TiXmlDocument doc("txt.xml");
    int fl = 0;
    if(!doc.LoadFile()) 
        return -1;  
    TiXmlNode *dep = doc.FirstChildElement("departments");
    for (TiXmlElement *d = dep->FirstChildElement(); d!= nullptr ; d = d->NextSiblingElement())
    {
        if (fl == 1)
            break;
        if (dn == d->Attribute("name"))
        {
            d->RemoveAttribute("name");
            fl = 1;
            TiXmlNode * employments = d->FirstChildElement("employments");
            for (TiXmlNode *employment = employments->FirstChildElement();employment!=nullptr; employment=employment->NextSiblingElement())
            {
                for (TiXmlElement* element = employment->FirstChildElement() ; element != nullptr ; element = element->NextSiblingElement())
                {
                    employment->RemoveChild(element);
                }
                employments->RemoveChild(employment);
            }
            d->RemoveChild(employments);
            dep->RemoveChild(d);
        }
    }
    doc.SaveFile("txt.xml");
    return (0);
}
int    RemoveWorker(std::string dn,std::string s,std::string f,std::string m){
    TiXmlDocument doc("txt.xml");
    int fl = 0;
    if(!doc.LoadFile()) 
        return -1;  
    TiXmlNode *dep = doc.FirstChildElement("departments");
    for (TiXmlElement *d = dep->FirstChildElement(); d!= nullptr ; d = d->NextSiblingElement())
    {
        cout << "HERE";
        if (fl == 1)
            break;
        if (dn == d->Attribute("name"))
        {
            cout << " dep name : " << dn ;
            TiXmlNode * employments = d->FirstChildElement("employments");
            for (TiXmlNode *employment = employments->FirstChildElement();employment!=nullptr; employment=employment->NextSiblingElement())
            {
                for (TiXmlElement* element = employment->FirstChildElement() ; element != nullptr ; element = element->NextSiblingElement())
                {
                    if (element->GetText() == s)
                        employment->RemoveChild(element);
                    else if (element->GetText() == f)
                        employment->RemoveChild(element);
                    else if (element->GetText() == m)
                    {
                        employment->RemoveChild(element);
                        fl = 1;
                    }
                }
                if (fl == 1)
                {
                    employments->RemoveChild(employment);
                    break;
                }
            }
        }
    }
    doc.SaveFile("txt.xml");
    return (0);
}

int     ChangeDepNameXml(std::string dn, std::string newdn){
     TiXmlDocument doc("txt.xml");
    int fl = 0;
    if(!doc.LoadFile()) 
        return -1;  
    TiXmlNode *dep = doc.FirstChildElement("departments");
    for (TiXmlElement *d = dep->FirstChildElement(); d!= nullptr ; d = d->NextSiblingElement())
    {
        if (fl == 1)
            break;
        if (dn == d->Attribute("name"))
        {
            d->TiXmlElement::SetAttribute("name",newdn.c_str());
            fl = 1;
        }
    }
    doc.SaveFile("txt.xml");
    return (0);
}

int    RemoveDepName(std::string dn){
    TiXmlDocument doc("txt.xml");
    int fl = 0;
    if(!doc.LoadFile()) 
        return -1;  
    TiXmlNode *dep = doc.FirstChildElement("departments");
    for (TiXmlElement *d = dep->FirstChildElement(); d!= nullptr ; d = d->NextSiblingElement())
    {
        if (fl == 1)
        {
            dep->RemoveChild(d);
            break;
        }
        if (dn == d->Attribute("name"))
        {
            cout << " find ";
            dep->RemoveChild(d);
            fl = 1;
        }
    }
    doc.SaveFile("txt.xml");
    return (0);
}


int     SetDep(std::string depname , Department &dep) {

    for (auto it = dep.workers.begin() ; it != dep.workers.end() ; it++ )
    {
        worker_in_xml(depname, it->second.secondName , it->second.firstName , it->second.middleName,
        it->second.function, it->second.salary);
    }
    return (0);
}

