
    #ifndef  CS_MOVE_PAK_H_
    #define  CS_MOVE_PAK_H_

    #include "PBMessage.pb.h"
    #include "Packet.h"

    namespace packets
    {
	    class CS_MOVE_PAK : public Packet
	    {
	    public:

		    CS_MOVE_PAK() : Packet(m_PacketData) {}

		    virtual ~CS_MOVE_PAK() {}

	    public:

    		ProtobufPacket::CS_MOVE m_PacketData;

	    public:

		    virtual PacketId_t
		    GetPacketId() const { return PACKET_ID::PACKET_ID_CS_MOVE; }

	    };
    }
    #endif //CS_MOVE_PAK_H_
    