
    #ifndef  CG_MOVE_PAK_H_
    #define  CG_MOVE_PAK_H_

    #include "PBMessage.pb.h"
    #include "Packet.h"

    namespace packets
    {
	    class CG_MOVE_PAK : public Packet
	    {
	    public:

		    CG_MOVE_PAK() : Packet(m_PacketData) {}

		    virtual ~CG_MOVE_PAK() {}

	    public:

    		ProtobufPacket::CG_MOVE m_PacketData;

	    public:

		    virtual PacketId_t
		    GetPacketId() const { return PACKET_ID::PACKET_ID_CG_MOVE; }

	    };
    }
    #endif //CG_MOVE_PAK_H_
    