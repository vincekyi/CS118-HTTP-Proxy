//CLIENT

#include <iostream>
#include <unistd.h>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include "utilities.h"

using namespace std;


int main(int argc, char *argv[])
{
	//set up variables
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    
    //Handle error: if you did not provide the correct number of args
    if (argc < 3) {
       error("ERROR, Did not provide correct arguments");
    }
    //store the port number
    portno = atoi(argv[2]);
    
    //create a socket and check for errors
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
        
    //get the host name and check for errors    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("ERROR, no such host");
    }
    
    //initialize the sockaddr_in variables
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    //connect to the provided host and port
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    
    //User input message
    cout<<"Please enter the message: ";
    string message;
    getline(cin, message);
    char cMessage[BUFFERSIZE];
    StrToChar(message, cMessage);
    
    //send the message to server
    n = write(sockfd, cMessage, strlen(cMessage));
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    
    //read in the response and output it
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    string temp(buffer);
    cout<<"Response from server: "<<temp<<endl;
    close(sockfd);
    return 0;
}
