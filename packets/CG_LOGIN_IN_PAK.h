
    #ifndef  CG_LOGIN_IN_PAK_H_
    #define  CG_LOGIN_IN_PAK_H_

    #include "PBMessage.pb.h"
    #include "Packet.h"

    namespace packets
    {
	    class CG_LOGIN_IN_PAK : public Packet
	    {
	    public:

		    CG_LOGIN_IN_PAK() : Packet(m_PacketData) {}

		    virtual ~CG_LOGIN_IN_PAK() {}

	    public:

    		ProtobufPacket::CG_LOGIN_IN m_PacketData;

	    public:

		    virtual PacketId_t
		    GetPacketId() const { return PACKET_ID::PACKET_ID_CG_LOGIN_IN; }

	    };
    }
    #endif //CG_LOGIN_IN_PAK_H_
    