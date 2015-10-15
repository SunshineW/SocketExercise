all:client.out server.out

client.out:tcp_process.o tcp_client.o
	gcc -o client.out tcp_process.o tcp_client.o
	
server.out:tcp_process.o tcp_server.o
	gcc -o server.out tcp_process.o tcp_server.o
	
clean:
	rm -f *.out *.o
