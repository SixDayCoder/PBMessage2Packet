
    #ifndef  GC_MOVE_RET_PAK_H_
    #define  GC_MOVE_RET_PAK_H_

    #include "PBMessage.pb.h"
    #include "Packet.h"

    namespace packets
    {
	    class GC_MOVE_RET_PAK : public Packet
	    {
	    public:

		    GC_MOVE_RET_PAK() : Packet(m_PacketData) {}

		    virtual ~GC_MOVE_RET_PAK() {}

	    public:

    		ProtobufPacket::GC_MOVE_RET m_PacketData;

	    public:

		    virtual PacketId_t
		    GetPacketId() const { return PACKET_ID::PACKET_ID_GC_MOVE_RET; }

	    };
    }
    #endif //GC_MOVE_RET_PAK_H_
    