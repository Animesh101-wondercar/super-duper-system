#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int cid, cbs,cbyte,addsize;
	char cstr[100];int sstr[100];

	struct sockaddr_in cadd, receiver;
	
	cid = socket(AF_INET, SOCK_DGRAM, 0);
		
	if(cid==-1)
	{
		printf("\n No socket for server application is not created successfully.");
		exit(0);
	}
	printf("\n A Socket for server application is created sussessflly.");
	
	cadd.sin_family=AF_INET;
	cadd.sin_port=htons(1026);
	cadd.sin_addr.s_addr=htonl(INADDR_ANY);


	memset(&(cadd.sin_zero), '\0', 8);


	cbs=bind(cid, (struct sockaddr *) &cadd,sizeof(cadd));

	if (cbs==-1)
	{
		printf("\nBinding Failure - Client Side");
		exit(0);
	}
	printf("\nBinding Successful - Client Side");
	
		
	receiver.sin_family=AF_INET;
	receiver.sin_port=htons(1025);
	receiver.sin_addr.s_addr=htonl(INADDR_ANY);
	
	memset(&(receiver.sin_zero),'\0',8);

	printf("Enter your name : ");
	for(int i=0;i<8;i++)
	scanf("%c",&cstr[i]);

	cbyte=sendto(cid,cstr,sizeof(cstr),0,(struct sockaddr*)&receiver, sizeof(receiver));
	if(cbyte==-1){
	printf("\n From client side - No message sent");
	exit(0);
	}
	
	cstr[cbyte]='\0';
	printf("Client send : %s",cstr);
	printf("\n %d bytes sent ",cbyte);
	
	
	addsize=sizeof(receiver);
	cbyte=recvfrom(cid,cstr,100,0,(struct sockaddr*)&receiver,&addsize);
	if(cbyte==-1){
		printf("\n In client side - No message received");
		exit(0);
	}
	cstr[cbyte]='\0';
	printf("\n %d bytes received",cbyte);
	
	
	close(cid);
	return 0;
}
