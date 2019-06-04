
    #include "PacketFactory.h"
    #include "CG_LOGIN_PAK.h"
	#include "CG_MOVE_PAK.h"
	#include "GC_MOVE_RET_PAK.h"
	

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
            case PACKET_ID::PACKET_ID_CG_LOGIN : m_PacketIdList[nPacketId]++; return std::make_shared<CG_LOGIN_PAK>();
		    case PACKET_ID::PACKET_ID_CG_MOVE : m_PacketIdList[nPacketId]++; return std::make_shared<CG_MOVE_PAK>();
		    case PACKET_ID::PACKET_ID_GC_MOVE_RET : m_PacketIdList[nPacketId]++; return std::make_shared<GC_MOVE_RET_PAK>();
		    
		    default:
			    return nullptr;
		    }
		    return nullptr;
	    }
    }
    