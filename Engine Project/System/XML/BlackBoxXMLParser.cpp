#include "BlackBoxXMLParser.h"

#include "tinyxml2.h"
#include "../Log.h"
#include "../../Actors/Actor.h"

namespace BlackBoxEngine
{
    ActorXMLParser::ActorXMLParser(const char* fileName)
    {
        m_pXmlDoc = new tinyxml2::XMLDocument;
        int error = m_pXmlDoc->LoadFile(fileName);
        if ( error != tinyxml2::XML_SUCCESS)
            BB_LOG(LogType::kFailure, "Couldnt load ActorXML file : ", fileName , " - " , m_pXmlDoc->ErrorName() );
        m_pRootElement = m_pXmlDoc->FirstChildElement();
        m_pComponentElement = m_pRootElement->FirstChildElement(kComponentElement);
    }

    ActorXMLParser::~ActorXMLParser()
    {
        if(m_pXmlDoc)
            delete m_pXmlDoc;
    }

    tinyxml2::XMLElement* ActorXMLParser::NextComponent()
    {
        if (!m_pComponentElement)
            return m_pComponentElement;
        auto returnElement = m_pComponentElement;
        m_pComponentElement = m_pComponentElement->NextSiblingElement(kComponentElement);
        return returnElement;
    }

    bool ActorXMLParser::SaveActor(const std::unique_ptr<Actor>& pActor,
                                   const char* pActorName,
                                   std::filesystem::path filePath)
    {
        tinyxml2::XMLDocument saveDoc;
        auto* pRootElement = saveDoc.NewElement(pActorName);
        saveDoc.InsertFirstChild(pRootElement);

        for (auto& [id, pComponet] : pActor->m_componentMap)
        {
            XMLElementParser componetParser(pRootElement->InsertNewChildElement(kComponentElement));
            componetParser.GetTinyXML()->SetAttribute(kComponentAttribute, pComponet->Name());
            pComponet->Save(componetParser);
        }
        
        if (filePath.empty())
        {
            filePath = std::filesystem::path(kActorFilePath) / pActorName;
            filePath.replace_extension(".xml");
        }

        if constexpr ( kPrintSavedActors )
            saveDoc.Print();
        
        int errCode = saveDoc.SaveFile( filePath.string().c_str() );
        if ( errCode == tinyxml2::XML_SUCCESS )
        {
            BB_LOG(LogType::kMessage, "Actor saved name:", pActorName, " - saved to :", filePath );
            return true;
        }
        BB_LOG(LogType::kError, "Failed to save actor file , errorcode : " , errCode , "  " , saveDoc.ErrorStr() );
        return false;
    }

    XMLElementParser::XMLElementParser(tinyxml2::XMLElement* pElement)
        : m_pRootElement(pElement)
    {

    }

    const char* XMLElementParser::GetComponentName() const
    {
        return m_pRootElement->FirstAttribute()->Value();
    }

    XMLElementParser XMLElementParser::GetChildElement(const char* pName) const
    {
        return XMLElementParser(m_pRootElement->FirstChildElement(pName));
    }

    void XMLElementParser::GetChildVariable(const char* pName, const char** savedVariable) const
    {
        XMLElementParser child = GetChildElement(pName);
        if (!child)
        {
            BB_LOG(LogType::kError, '\"', pName, '\"', " not found");
            return;
        }
        *savedVariable = child->GetText();
    }

    void XMLElementParser::GetChildVariable(const char* pName, int* savedVariable) const
    {
        XMLElementParser child = GetChildElement(pName);
        if(!child)
        {
            BB_LOG(LogType::kError, '\"', pName, '\"', " not found");
            return;
        }
        if (child->QueryIntText(savedVariable) != tinyxml2::XML_SUCCESS)
        {
            BB_LOG(LogType::kError, "Int variable not found , \"", pName, '\"');
            *savedVariable = 0;
        }
    }

    void XMLElementParser::GetChildVariable(const char* pName, unsigned* savedVariable) const
    {
        XMLElementParser child = GetChildElement(pName);
        if (!child)
        {
            BB_LOG(LogType::kError, '\"', pName, '\"', " not found");
            return;
        }
        if (child->QueryUnsignedText(savedVariable) != tinyxml2::XML_SUCCESS)
        {
            BB_LOG(LogType::kError, "u-Int variable not found , \"", pName, '\"');
            *savedVariable = 0;
        }
    }

    void XMLElementParser::GetChildVariable(const char* pName, int64_t* savedVariable) const
    {
        XMLElementParser child = GetChildElement(pName);
        if (!child)
        {
            BB_LOG(LogType::kError, '\"', pName, '\"', " not found");
            return;
        }
        if (child->QueryInt64Text(savedVariable) != tinyxml2::XML_SUCCESS)
        {
            BB_LOG(LogType::kError, "int64 variable not found , \"", pName, '\"');
            *savedVariable = 0;
        }
    }

    void XMLElementParser::GetChildVariable(const char* pName, uint64_t* savedVariable) const
    {
        XMLElementParser child = GetChildElement(pName);
        if (!child)
        {
            BB_LOG(LogType::kError, '\"', pName, '\"', " not found");
            return;
        }
        if (child->QueryUnsigned64Text(savedVariable) != tinyxml2::XML_SUCCESS)
        {
            BB_LOG(LogType::kError, "u-Int64 variable not found , \"", pName, '\"');
            *savedVariable = 0;
        }
    }

    void XMLElementParser::GetChildVariable(const char* pName, bool* savedVariable) const
    {
        XMLElementParser child = GetChildElement(pName);
        if (!child)
        {
            BB_LOG(LogType::kError, '\"', pName, '\"', " not found");
            return;
        }
        if (child->QueryBoolText(savedVariable) != tinyxml2::XML_SUCCESS)
        {
            BB_LOG(LogType::kError, "bool variable not found , \"", pName, '\"');
            *savedVariable = 0;
        }
    }

    void XMLElementParser::GetChildVariable(const char* pName, double* savedVariable) const
    {
        XMLElementParser child = GetChildElement(pName);
        if (!child)
        {
            BB_LOG(LogType::kError, '\"', pName, '\"', " not found");
            return;
        }
        if (child->QueryDoubleText(savedVariable) != tinyxml2::XML_SUCCESS)
        {
            BB_LOG(LogType::kError, "Double variable not found , \"", pName, '\"');
            *savedVariable = 0;
        }
    }

    void XMLElementParser::GetChildVariable(const char* pName, float* savedVariable) const
    {
        XMLElementParser child = GetChildElement(pName);
        if (!child)
        {
            BB_LOG(LogType::kError, '\"', pName, '\"', " not found");
            return;
        }
        if (child->QueryFloatText(savedVariable) != tinyxml2::XML_SUCCESS)
        {
            BB_LOG(LogType::kError, "Float variable not found , \"", pName, '\"');
            *savedVariable = 0;
        }
    }

    void XMLElementParser::ClearChildElements()
    {
        if (m_pRootElement->ChildElementCount() > 0) // ensure the parser is empty.
            m_pRootElement->DeleteChildren();
    }

    XMLElementParser XMLElementParser::InsertNewChild(const char* pName)
    {
        return XMLElementParser(m_pRootElement->InsertNewChildElement(pName));
    }

    void XMLElementParser::NewChildVariable(const char* pName, const char* savedVariable)
    {
        m_pRootElement->InsertNewChildElement(pName)->SetText(savedVariable);
    }

    void XMLElementParser::NewChildVariable(const char* pName, int savedVariable)
    {
        m_pRootElement->InsertNewChildElement(pName)->SetText(savedVariable);
    }

    void XMLElementParser::NewChildVariable(const char* pName, unsigned savedVariable)
    {
        m_pRootElement->InsertNewChildElement(pName)->SetText(savedVariable);
    }

    void XMLElementParser::NewChildVariable(const char* pName, int64_t savedVariable)
    {
        m_pRootElement->InsertNewChildElement(pName)->SetText(savedVariable);
    }

    void XMLElementParser::NewChildVariable(const char* pName, uint64_t savedVariable)
    {
        m_pRootElement->InsertNewChildElement(pName)->SetText(savedVariable);
    }

    void XMLElementParser::NewChildVariable(const char* pName, bool savedVariable)
    {
        m_pRootElement->InsertNewChildElement(pName)->SetText(savedVariable);
    }

    void XMLElementParser::NewChildVariable(const char* pName, double savedVariable)
    {
        m_pRootElement->InsertNewChildElement(pName)->SetText(savedVariable);
    }

    void XMLElementParser::NewChildVariable(const char* pName, float savedVariable)
    {
        m_pRootElement->InsertNewChildElement(pName)->SetText(savedVariable);
    }


}