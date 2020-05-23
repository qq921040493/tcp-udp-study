#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/time.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<dirent.h>
#include<signal.h>
#include<sys/socket.h>
#include<netinet/in.h>

char *hostname = "127.0.0.1"; //这个特殊的ip表示本的计算机 
void main() 
{ 
int sinlen; 
int port = 8080; 
char message[256]; 
int sockfd; 
struct sockaddr_in sin; 
struct hostent *server_host_name; // hostent结构有着机器的名字等信息 
server_host_name = gethostbyname("127.0.0.1"); // 这个函数用来得到“127.0.0.1”的主机名字，也就是本机的名字
bzero(&sin,sizeof(sin)); 
sin.sin_family = AF_INET; 
sin.sin_addr.s_addr = htonl(INADDR_ANY); 
sin.sin_port = htons(port); 
sockfd = socket(PF_INET,SOCK_DGRAM,0); //这里也不一样 
bind(sockfd,(struct sockaddr *)&sin,sizeof(sin)); 
while(1){
sinlen = sizeof(sin); 
recvfrom(sockfd,message,256,0, (struct sockaddr *)&sin,&sinlen);// 它是接受数据的函数 
printf("\nData come from server:\n%s\n",message);
if(strncmp(message,"over",4) ==0)break;
} 
close(sockfd); 
}

