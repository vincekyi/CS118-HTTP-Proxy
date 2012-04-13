//PROXY
#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "utilities.h"

using namespace std;

void dostuff(int newsockfd, int portno, struct in_addr *sin_addr);

int main(int argc, char *argv[])
{
    // Variable declaration
    int sockfd, newsockfd, portno, pid;
    socklen_t clilen;
    
    struct sockaddr_in serv_addr, cli_addr;
    

    // Usage check
    if (argc < 2) {
        error("ERROR, no port provided\n");
    }

    // Open socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
       	error("ERROR opening socket");
       	return 0;
    }
    portno = atoi(argv[1]);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind to socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR on binding");
	}

    // listen/accept (blocking call)
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    // Server Infinite Loop
    while (1) {
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if(getsockname(newsockfd, (struct sockaddr *)&serv_addr, &clilen) == -1){
        	error("ERROR getsockname");
		}

		if (newsockfd < 0){
        	error("ERROR on accept");
		}
			
		pid = fork();
		
		if (pid < 0){
			error("ERROR on fork");
		}
		if (pid == 0) {
			close(sockfd);
			dostuff(newsockfd, portno, &serv_addr.sin_addr);
			exit(0);
		}
		else close(newsockfd);
	}
	close(sockfd);
	return 0;
}

void dostuff(int newsockfd, int portno, struct in_addr *sin_addr) {
	
    // Read from socket
   char buffer[BUFFERSIZE];
   int n;
   bzero(buffer,256);
   n=read(newsockfd, buffer, BUFFERSIZE-1);
   if(n<0)
	   error("ERROR on read");
   string temp(buffer);
   cout<<"Received message: "<<temp<<endl;
   
   //write a confirmation message
   char message[]="Thanks for the message";
   write(newsockfd, message, strlen(message));
}

