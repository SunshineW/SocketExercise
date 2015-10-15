#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<linux/in.h>
#include<errno.h>

#define PORT 8888

int main(int argc, char **argv)
{
	int s;
	struct sockaddr_in server_addr;
	int err;
	
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
	{
		printf("Socket error!\n");
		return -1;
	}
	
	
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
	server_addr.sin_port = htons(PORT);
	

	err = connect(s, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
	if (err < 0)
	{
		printf("connect error!\n");
		return;
	}
	process_conn_client(s);
	close(s);
}