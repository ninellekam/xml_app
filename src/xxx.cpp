#include "../inc/xxx.h"

int in_xml(std::string dn, std::string s,std::string f,std::string m,std::string ff,
int sal)
{
    XMLDocument xmlDoc;
    XMLError eResult ;
  //  XMLError eResult = xmlDoc.LoadFile("tst.xml");
    if (eResult != XML_SUCCESS) return -1;
                XMLNode * pRoot = xmlDoc.NewElement("departments");
                xmlDoc.InsertFirstChild(pRoot);

                XMLElement * pElement = xmlDoc.NewElement("department");
                xmlDoc.InsertEndChild(pElement);
                pElement->SetAttribute("name", dn.c_str());

                XMLNode * empls = xmlDoc.NewElement("employments");
                xmlDoc.InsertEndChild(empls);
                
                XMLNode * empl = xmlDoc.NewElement("employment");
                xmlDoc.InsertEndChild(empl);
                //---------------------------surname--------------------
                        XMLElement * pNew = xmlDoc.NewElement("surname");
                        pNew->SetText(s.c_str());
                        empl->InsertEndChild(pNew);
                //----------------------------name-------------------------
                        pNew = xmlDoc.NewElement("name");
                        pNew->SetText(f.c_str());
                        empl->InsertEndChild(pNew);
                //----------------------middlename--------------------------
                        pNew = xmlDoc.NewElement("middlename");
                        pNew->SetText(m.c_str());
                        empl->InsertEndChild(pNew);
                //----------------function----------------------
                        pNew = xmlDoc.NewElement("function");
                        pNew->SetText(ff.c_str());
                        empl->InsertEndChild(pNew);
                //----------------salary------------------------------
                        pNew = xmlDoc.NewElement("salary");
                        pNew->SetText(sal);
                        empl->InsertEndChild(pNew);

            eResult = xmlDoc.SaveFile("SavedData.xml");
    return (0);
}

int un_xml(std::string dn, std::string s,std::string f,std::string m,std::string ff,
int sal) {
    XMLDocument xmlDoc;

    XMLError eResult = xmlDoc.LoadFile("tst.xml");

    if (eResult != XML_SUCCESS) return -1;

    XMLNode * root = xmlDoc.FirstChildElement("departments");
    if (root == nullptr) return -1;


    for (XMLElement *department = root->FirstChildElement(); department!=nullptr; department=department->NextSiblingElement())
    {    
        string depName;
        depName = department->Attribute("name"); 

        XMLNode * empls = department->FirstChildElement("employments");
                for (XMLNode *empl = empls->FirstChildElement();empl!=nullptr;empl=empl->NextSiblingElement())
                {        
                    if (dn == depName)
                    {
                    for (XMLElement* elem = empl->FirstChildElement() ; elem != nullptr ; elem = elem->NextSiblingElement())
                    {
                        if ( elem == empl->FirstChildElement("surname") )
                            {
                                XMLElement * pNew = xmlDoc.NewElement("surname");
                                pNew->SetText(s.c_str());
                                empl->InsertEndChild(pNew);
                            }
                        else if (elem == empl->FirstChildElement("name") )
                        {
                            XMLElement * pNew = xmlDoc.NewElement("name");
                            pNew->SetText(f.c_str());
                            empl->InsertEndChild(pNew);
                        }
                         else if (elem == empl->FirstChildElement("middlename") )
                        {
                            XMLElement * pNew = xmlDoc.NewElement("middlename");
                            pNew->SetText(m.c_str());
                            empl->InsertEndChild(pNew);
                         }
                        else if (elem == empl->FirstChildElement("function") )
                        {
                            XMLElement * pNew = xmlDoc.NewElement("function");
                            pNew->SetText(ff.c_str());
                            empl->InsertEndChild(pNew);
                        }
                        else if (elem == empl->FirstChildElement("salary") )
                        {
                            XMLElement * pNew = xmlDoc.NewElement("salary");
                            pNew->SetText(sal);
                            empl->InsertEndChild(pNew);
                        }    
                    }
                } 
            }
    }
    return 0;
}

