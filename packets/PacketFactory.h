
    #ifndef SIXDAY_PACKET_FACTORY_H_
	#define SIXDAY_PACKET_FACTORY_H_

	#include "Packet.h"
	#include <memory>
	#include <vector>

	namespace packets
	{
		class PackeFactory
		{

		public:

			void
			Init();

			PacketPtr
			CreatePacket(PacketId_t nPacketId);

		private:

			std::vector<uint32_t> m_PacketIdList;

		};

		extern PackeFactory gPacketFactory;
	}


	#endif
    