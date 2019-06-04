
    #ifndef  CG_LOGIN_PAK_H_
    #define  CG_LOGIN_PAK_H_

    #include "PBMessage.pb.h"
    #include "Packet.h"

    namespace packets
    {
	    class CG_LOGIN_PAK : public Packet
	    {
	    public:

		    CG_LOGIN_PAK() : Packet(m_PacketData) {}

		    virtual ~CG_LOGIN_PAK() {}

	    public:

    		ProtobufPacket::CG_LOGIN m_PacketData;

	    public:

		    virtual PacketId_t
		    GetPacketId() const { return PACKET_ID::PACKET_ID_CG_LOGIN; }

	    };
    }
    #endif //CG_LOGIN_PAK_H_
    