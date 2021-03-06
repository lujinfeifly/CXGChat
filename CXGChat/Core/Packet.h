#ifndef __PACKET_H_
#define __PACKET_H_

#include "RefCount.h"

typedef unsigned char PACKET_TYPE;

#pragma pack(push, 1)

struct PACKET_HADER
{
	int     packetSize;
    char    packetAction;
    char    packetType;
    short   packetBackup;
    
    PACKET_HADER()
    {
        packetSize = 0;
        packetAction = '\0';
        packetType = '\0';
        packetBackup = 0;
    }
};

#pragma pack(pop)

// CPacket
class CPacket
	: public CRefCount
{
public:
    
	static CPacket* CreateFromPayload(char* pPayload, int nPayload);
	static CPacket* CreateFromTotal(char* pTotal, long nTotal);

    
    int  GetPacketType() const;
	long GetPacketSize() const;
	long GetPayloadSize() const;
	long GetTotalSize() const;
    
    char*   GetTotal() const;
    char*   GetPayload() const;
    
    void    SetPacketType(int ptType);
    void    SetPacketAction(int ptAction);

protected:
    
	CPacket();
	virtual ~CPacket();
    
	bool InitPayload(char* pPayload, int nPayload);
	bool InitTotal(char* pTotal, long nTotal);

private:
    
	PACKET_HADER*    m_pHeader;
    
	char*            m_pTotal;
    char*            m_pPayload;
    
	long             m_nTotal;
	int              m_nPayload;
};

#endif
