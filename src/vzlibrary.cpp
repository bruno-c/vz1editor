#include "vzlibrary.h"
#include <wx/file.h>
#include <wx/xml/xml.h>

VZLibrary::VZLibrary(const wxString &sFilename) :
    m_sFilename(sFilename),
    m_bDirty(false)
{
    Load(sFilename);
}

VZLibrary::~VZLibrary()
{
    Close();
}


void VZLibrary::ClearData()
{
    for(vector<vzLibEntry*>::iterator it = m_vEntries.begin(); it != m_vEntries.end(); ++it)
        delete(*it);
    m_vEntries.clear();
}

bool VZLibrary::Load(const wxString &sFilename)
{
    //!@todo Use filename as parameter
    wxXmlDocument xmlDoc;
    if(!wxFileExists(sFilename) || !xmlDoc.Load(sFilename))
        return false;
    Close();
    wxXmlNode* pNode = xmlDoc.GetRoot()->GetChildren();
    while(pNode)
    {
        vzLibEntry* pEntry = new vzLibEntry;
        pEntry->type = pNode->GetName();
        pEntry->name = pNode->GetAttribute(wxT("name"), wxT("New Voice"));
        pEntry->description = pNode->GetAttribute(wxT("description"), wxEmptyString);
        pEntry->group = pNode->GetAttribute(wxT("group"), wxEmptyString);
        pEntry->filename = pNode->GetAttribute(wxT("filename"), wxString::Format(wxT("%s.syx"), pEntry->name.c_str()));
        m_vEntries.push_back(pEntry);
        pNode = pNode->GetNext();
    }
    m_sFilename = sFilename;
    m_bDirty = false;
    return true;
}

bool VZLibrary::Save()
{
    //!@todo Use filename as parameter
    wxXmlDocument xmlDoc;
    wxXmlNode* pNode = new wxXmlNode(NULL, wxXML_ELEMENT_NODE, wxT("vzlibrary"));
    xmlDoc.SetRoot(pNode);
    //iterate in reverse because we are adding each node to the root so it ends up at start of document
    for(vector<vzLibEntry*>::reverse_iterator it = m_vEntries.rbegin(); it != m_vEntries.rend(); ++it)
    {
        vzLibEntry* pEntry = *it;
        pNode = new wxXmlNode(xmlDoc.GetRoot(), wxXML_ELEMENT_NODE, pEntry->type);
        pNode->AddAttribute(wxT("name"), pEntry->name);
        pNode->AddAttribute(wxT("group"), pEntry->group);
        pNode->AddAttribute(wxT("description"), pEntry->description);
        pNode->AddAttribute(wxT("filename"), pEntry->filename);
    }
    m_bDirty = xmlDoc.Save(m_sFilename);
    return m_bDirty;
}

void VZLibrary::Close()
{
   if(m_bDirty)
    {
        if(wxMessageBox(wxT("Save changes to library?"), wxT("Unsaved changes"), wxYES_NO|wxCENTRE) == wxYES)
            Save();
    }
    ClearData();
}

bool VZLibrary::AddEntry(const wxString &sName, const wxString &sFilename, const wxString &sDescription, const wxString &sGroup, const wxString &sType)
{
    vzLibEntry* pEntry = new vzLibEntry;
    pEntry->type = sType;
    pEntry->description = sDescription;
    pEntry->group = sGroup;
    m_vEntries.push_back(pEntry);
    m_bDirty = true;
    return true;
}

bool VZLibrary::RemoveEntry(wxString sFilename)
{
    for(vector<vzLibEntry*>::iterator it = m_vEntries.begin(); it != m_vEntries.end(); ++it)
        if(sFilename.IsSameAs((*it)->filename))
        {
            delete(*it);
            m_vEntries.erase(it);
            m_bDirty = true;
            return true;
        }
    return false;
}

