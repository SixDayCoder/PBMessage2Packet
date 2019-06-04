
    #ifndef  SIXDAY_PACKETDEFINE_H_
    #define  SIXDAY_PACKETDEFINE_H_

    #include <stdint.h>
    #if defined (PLATFORM_WINDOWS)
    #include <WinSock2.h>
    #include <WS2tcpip.h>
    #elif defined (PLATFORM_LINUX)
    #include <sys/epoll.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <fcntl.h>
    #include <unistd.h>
    #endif

    typedef uint16_t PacketId_t;
    #define PACKET_HEADER_LEN_SIZE   (sizeof(uint32_t))
    #define PACKET_HEADER_ID_SIZE    (sizeof(PacketId_t))
    #define PACKET_HEADER_TOTAL_SIZE (PACKET_HEADER_LEN_SIZE + PACKET_HEADER_ID_SIZE)

    namespace packets
    {
	    enum PACKET_ID
	    {
		    PACKET_ID_NONE = 0,
		    PACKET_ID_CG_LOGIN = 1,
		    PACKET_ID_CG_MOVE = 2,
		    PACKET_ID_GC_MOVE_RET = 3,
		    PACKET_ID_MAX,
	    };

	    enum PACKET_EXECUTE_RET_CODE
	    {
		    PACKET_EXECUTE_RET_CODE_ERROR    = 0,
		    PACKET_EXECUTE_RET_CODE_CONTINUE = 1,
	    };
    }

    #endif // SIXDAY_PACKETDEFINE_H_
    