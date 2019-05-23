#ifndef SIXDAY_PACKET_UTILS_H_
#define SIXDAY_PACKET_UTILS_H_

#include "Packet.h"

namespace packets
{
	class PacketUtils
	{
	public:

		static PacketPtr
		CreatePacket(PacketId_t nPacketId);

		static void
		SendPacket(int fd, packets::Packet& rPacket);

		static bool
		Packet2ByteStream(const packets::Packet& rPacket, char* outbytes, uint32_t* nbytes);

		static PacketPtr
		ByteStream2Packet(const char* szData, uint32_t nDataLen);
	};
}


#endif // 
