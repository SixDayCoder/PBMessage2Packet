
    #include "PacketFactory.h"
    #include "CS_LOGIN_PAK.h"
	#include "CS_MOVE_PAK.h"
	#include "SC_MOVE_RET_PAK.h"
	

    namespace packets
    {

	    PackeFactory gPacketFactory;

	    void
	    PackeFactory::Init()
	    {
		    m_PacketIdList.reserve(PACKET_ID::PACKET_ID_MAX);
		    for (int i = 0; i < PACKET_ID::PACKET_ID_MAX; ++i) {
    			m_PacketIdList.push_back(0);
		    }
	    }

	    packets::PacketPtr
	    PackeFactory::CreatePacket(PacketId_t nPacketId)
	    {
		    if (nPacketId <= PACKET_ID::PACKET_ID_NONE || nPacketId >= PACKET_ID::PACKET_ID_MAX) {
			    return nullptr;
		    }
		    switch (nPacketId)
		    {
            case PACKET_ID::PACKET_ID_CS_LOGIN : m_PacketIdList[nPacketId]++; return std::make_shared<CS_LOGIN_PAK>();
		    case PACKET_ID::PACKET_ID_CS_MOVE : m_PacketIdList[nPacketId]++; return std::make_shared<CS_MOVE_PAK>();
		    case PACKET_ID::PACKET_ID_SC_MOVE_RET : m_PacketIdList[nPacketId]++; return std::make_shared<SC_MOVE_RET_PAK>();
		    
		    default:
			    return nullptr;
		    }
		    return nullptr;
	    }
    }
    