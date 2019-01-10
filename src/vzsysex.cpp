#include "vzsysex.h"
#include <cstring>

static const unsigned int VZ_PAYLOAD_START = 7;

vzsysex::vzsysex(unsigned int nPayloadSize) :
    m_nPayloadSize(nPayloadSize)
{
    m_pSysEx = new wxByte[GetSize()];
    Validate(true);
    m_bModified = false;
}

vzsysex::vzsysex(wxByte* pData, unsigned int nPayloadSize) :
    m_nPayloadSize(nPayloadSize)
{
    m_pSysEx = new wxByte[GetSize()];
    SetSysEx(pData);
}

vzsysex::~vzsysex()
{
    if(m_pSysEx)
        delete [] m_pSysEx;
    m_pSysEx = 0;
}

wxByte vzsysex::GetValue(unsigned int nOffset, wxByte nMask)
{
    //!@todo Validate this works
    wxByte nValue = GetByteFromSysex(nOffset);
    nValue &= nMask;
    wxByte nShift = 0;
    for(nShift = 0; nShift < 8; ++nShift)
        if(nMask & (1 << nShift))
            break;
    return nValue >> nShift;
}

void vzsysex::SetValue(unsigned int nOffset, wxByte nMask, wxByte nValue)
{
    //!@todo Validate this works
    wxByte nShift = 0;
    for(nShift = 0; nShift < 8; ++nShift)
        if(nMask & (1 << nShift))
            break;
    PutByteToSysex(nOffset, ((nValue << nShift) & nMask) | (GetByteFromSysex(nOffset) & ~nMask));
}

bool vzsysex::IsModified()
{
    return m_bModified;
}

void vzsysex::GetSysEx(wxByte* pData)
{
    memcpy(pData, m_pSysEx, m_nPayloadSize);
}

wxByte* vzsysex::GetSysEx()
{
    return m_pSysEx;
}

bool vzsysex::SetSysEx(wxByte* pData)
{
    memcpy(m_pSysEx, pData, GetSize());
    m_bModified = Validate(true);
    return m_bModified;
}

bool vzsysex::ValidateByte(wxByte* pByte, wxByte nByte, bool bFix)
{
    bool bInvalid = (nByte != *pByte);
    if(bFix)
        *pByte = nByte;
    return bInvalid;
}

bool vzsysex::Validate(bool bFix)
{
    m_bModified = false;
    m_bModified |= ValidateByte(m_pSysEx, 0xF0, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 1, 0x44, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 2, 0x03, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 3, 0x00, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 4, 0x70, bFix); //!@todo Allow different MIDI channel [0xF0 - 0xFF]
    m_bModified |= ValidateByte(m_pSysEx + 5, 0x00, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 6, 0x40, bFix); //!@todo Allow different tone locations [0x40 - 0x44]
    m_bModified |= ValidateByte(m_pSysEx + m_nPayloadSize + 7, Checksum(m_pSysEx + 7, m_nPayloadSize), bFix);
    m_bModified |= ValidateByte(m_pSysEx + m_nPayloadSize + 8, 0xF7, bFix); //!@todo Allow different tone locations [0x40 - 0x44]
    return m_bModified;
}

wxByte vzsysex::Checksum(wxByte* pData, unsigned int nSize, wxByte nChecksum)
{
    wxByte nSum = nChecksum;
    for(unsigned int nIndex = 0; nIndex < nSize; nIndex+=2)
        nSum += DecodeByte(pData + nIndex);
    return (0 - nSum) & 0x7F;
}


wxByte vzsysex::DecodeByte(wxByte* pCursor)
{
    return (*(pCursor) << 4) | (*(pCursor + 1));
}

void vzsysex::EncodeByte(wxByte* pCursor, wxByte nValue)
{
    *pCursor = (nValue & 0xF0) >> 4;
    *(pCursor + 1) = nValue & 0x0F;
}

wxByte vzsysex::GetByteFromSysex(unsigned int nOffset)
{
    if(nOffset >= m_nPayloadSize / 2)
            return 0;

    return DecodeByte(m_pSysEx + VZ_PAYLOAD_START + nOffset * 2);
}

bool vzsysex::PutByteToSysex(unsigned int nOffset, wxByte nValue)
{
    if(nOffset >= m_nPayloadSize / 2)
        return false;
    EncodeByte(m_pSysEx + VZ_PAYLOAD_START + nOffset * 2, nValue);
    return true;
}

unsigned int vzsysex::GetSize()
{
    return VZ_HEADER_SIZE + m_nPayloadSize + 2; //Sysex header, payload, checksum + sysex end
}