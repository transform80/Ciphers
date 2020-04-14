#include <bits/stdc++.h>
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include "decry.h"
#define PORT 8080 
using namespace std;
int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "CLIENT ONLINE"; 
    char buffer[1024]={0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT);  
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    send(sock , hello , strlen(hello) , 0 ); 
    printf("CONNECTION WITH SERVER MADE\n"); 
 	string key,pt;
	key="133457799BBCDFF1";
	keyGenerate(key);
    valread = read( sock ,buffer,1024); 
    cout<<"RECIEVED CIPHER TEXT  "<<binToHex(buffer)<<endl;
    string dd=decrypt(binToHex(buffer),buffer); 
	//cout<<"DECRYPTED MESSAGE IN BINARY: "<<dd<<endl;
	cout<<"DECRYPTED MESSAGE IN HEX: "<<binToHex(dd)<<endl;
    return 0; 
}