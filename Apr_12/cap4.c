#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netpacket/packet.h>
#include<net/ethernet.h>

main()
{
	int pack_socket, n;
	struct sockaddr_ll sa;
	socklen_t sl;
	char buf[2000];
	
	pack_socket=socket(PF_PACKET, SOCK_DGRAM, htons(ETH_P_ALL));
	if(pack_socket<0)
	{
		printf("Failed to oepn packet socket\n");
		exit(0);
	}
	printf("Packet socket successfully opened\n");
	while(1)
	{
		sl=sizeof(struct sockaddr_ll);
		n=recvfrom(pack_socket, buf, 2000, 0, (struct sockaddr *)&sa, &sl);
		printf("Received packet of length %d\n", n);
		printf("Packet Type: %d\n", sa.sll_pkttype);
		printf("Hardware address length: %d\n", sa.sll_halen);
		printf("Protocol: %x\n", ntohs(sa.sll_protocol));
	}
	
	close(pack_socket);
}
