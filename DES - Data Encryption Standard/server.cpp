#include <unistd.h> 
#include <bits/stdc++.h>
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include "encry.h"
#define PORT 8080 
using namespace std;
int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
 	string key,pt;
	key="133457799BBCDFF1";
	keyGenerate(key);
	pt="0123456789ABCCEF";
	if(pt.length()%16!=0)
    {
		int i=pt.length()%16;
		while(i--)
        {
			pt+='\0';
		}
	}
	string ee=encrypt(pt);
    const char* hello =ee.c_str();
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    valread = read( new_socket , buffer, 1024); 
    cout<<buffer<<endl; 
    //cout<<"PLAIN TEXT IN BINARY: "<<hexToBin(pt)<<endl;
    cout<<"PLAIN TEXT IN HEX: "<<pt<<endl;
    //cout<<"CIPHER TEXT IN BINARY: "<<ee<<endl;
    cout<<"CIPHER TEXT IN HEX: "<<binToHex(ee)<<endl;
    int y=send(new_socket ,hello,strlen(hello) , 0 ); 
    cout<<"CIPHER TEXT SENT"<<endl; 
    return 0; 
}