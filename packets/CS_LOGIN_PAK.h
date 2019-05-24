
    #ifndef  CS_LOGIN_PAK_H_
    #define  CS_LOGIN_PAK_H_

    #include "PBMessage.pb.h"
    #include "Packet.h"

    namespace packets
    {
	    class CS_LOGIN_PAK : public Packet
	    {
	    public:

		    CS_LOGIN_PAK() : Packet(m_PacketData) {}

		    virtual ~CS_LOGIN_PAK() {}

	    public:

    		ProtobufPacket::CS_LOGIN m_PacketData;

	    public:

		    virtual PacketId_t
		    GetPacketId() const { return PACKET_ID::PACKET_ID_CS_LOGIN; }

	    };
    }
    #endif //CS_LOGIN_PAK_H_
    