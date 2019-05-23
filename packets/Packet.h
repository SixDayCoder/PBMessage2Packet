#ifndef SIXDAY_PACKET_H_
#define SIXDAY_PACKET_H_

#include "PacketDefine.h"
#include "google/protobuf/message.h"
#include  <memory>

namespace packets
{
	class Packet
	{
	public:

		google::protobuf::Message& m_PacketData;

	public:

		explicit Packet(google::protobuf::Message& rPacketData) : m_PacketData(rPacketData) {}

		virtual ~Packet() {}

	public:

		uint32_t 
		Getpacketsize() const { return m_PacketData.ByteSize(); } 

	public:
	
		//virtual PACKET_EXECUTE_RET_CODE 
		//Execute() = 0;

		virtual PacketId_t 
		GetPacketId() const = 0;

	};
	using PacketPtr = std::shared_ptr<Packet>;
}

#endif