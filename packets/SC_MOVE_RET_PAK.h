
    #ifndef  SC_MOVE_RET_PAK_H_
    #define  SC_MOVE_RET_PAK_H_

    #include "PBMessage.pb.h"
    #include "Packet.h"

    namespace packets
    {
	    class SC_MOVE_RET_PAK : public Packet
	    {
	    public:

		    SC_MOVE_RET_PAK() : Packet(m_PacketData) {}

		    virtual ~SC_MOVE_RET_PAK() {}

	    public:

    		ProtobufPacket::SC_MOVE_RET m_PacketData;

	    public:

		    virtual PacketId_t
		    GetPacketId() const { return PACKET_ID::PACKET_ID_SC_MOVE_RET; }

	    };
    }
    #endif //SC_MOVE_RET_PAK_H_
    