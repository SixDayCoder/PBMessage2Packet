#include "PacketUtils.h"
#include "CG_LOGIN_IN_PAK.h"
#include <string>

namespace packets
{

	packets::PacketPtr
	PacketUtils::CreatePacket(PacketId_t nPacketId)
	{
		switch (nPacketId)
		{
		case PACKET_ID::PACKET_ID_LOGIN_IN:
			return std::make_shared<CG_LOGIN_IN_PAK>();
		default: return nullptr;
		}
	}

	void 
	PacketUtils::SendPacket(int fd, Packet& rPacket)
	{
		if (fd < 0) { return; }
		char bytes[1024] = { 0 };
		uint32_t nbytes = 0;
		if (Packet2ByteStream(rPacket, bytes, &nbytes)) {
			send(fd, bytes, nbytes, 0);
		}	
	}

	bool PacketUtils::Packet2ByteStream(const packets::Packet& rPacket, char* outbytes, uint32_t* nbytes)
	{
		if (outbytes == nullptr) {
			return false;
		}
		char szHeader[PACKET_HEADER_TOTAL_SIZE] = { 0 };
		uint32_t nPacketLen = htonl(rPacket.Getpacketsize());
		uint16_t nPacketId = htons(rPacket.GetPacketId());
		*nbytes = rPacket.Getpacketsize() + PACKET_HEADER_TOTAL_SIZE;
		memcpy(szHeader, &nPacketLen, PACKET_HEADER_LEN_SIZE);
		memcpy(szHeader + PACKET_HEADER_LEN_SIZE, &nPacketId, PACKET_HEADER_ID_SIZE);
		memcpy(outbytes, szHeader, PACKET_HEADER_TOTAL_SIZE);
		return rPacket.m_PacketData.SerializeToArray(outbytes + PACKET_HEADER_TOTAL_SIZE, 1024);
	}

	packets::PacketPtr
	PacketUtils::ByteStream2Packet(const char* szData, uint32_t nDataLen)
	{
		//validate datelen
		char szHeader[PACKET_HEADER_TOTAL_SIZE] = { 0 };
		if (nDataLen < PACKET_HEADER_TOTAL_SIZE) {
			return nullptr;
		}

		//parse packet header
		memcpy(szHeader, szData, PACKET_HEADER_TOTAL_SIZE);
		uint32_t nPacketLen = 0;
		memcpy(&nPacketLen, szHeader, PACKET_HEADER_LEN_SIZE);
		nPacketLen = ntohl(nPacketLen);
		uint16_t nPacketId = 0;
		memcpy(&nPacketId, szHeader + PACKET_HEADER_LEN_SIZE, PACKET_HEADER_ID_SIZE);
		nPacketId = ntohs(nPacketId);

		//validate packetid and remain data length
		if (nPacketId <= PACKET_ID::PACKET_ID_NONE || nPacketId >= PACKET_ID::PACKET_ID_MAX) {
			return nullptr;
		}
		if (nDataLen < PACKET_HEADER_TOTAL_SIZE + nPacketLen) {
			return nullptr;
		}
		//create packet
		PacketPtr pPacket = CreatePacket(nPacketId);
		if (pPacket == nullptr) {
			return nullptr;
		}
		if (!pPacket->m_PacketData.ParseFromArray(szData + PACKET_HEADER_TOTAL_SIZE, nPacketLen)) {
			return nullptr;
		}
		return pPacket;
	}
}