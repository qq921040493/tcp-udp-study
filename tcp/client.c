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

int main(int argc,char **argv) 
{ 
char recvbuff[100]; //定义要接收的数据缓冲区 
int sockfd; //定义一个socket套接字，用于通讯 
struct sockaddr_in servaddr;//定义网络套接字地址结构 
if(argc != 2){ 
printf("Usage: echo ip地址"); 
exit(0); 
} 
sockfd = socket(AF_INET,SOCK_STREAM,0); //创建一个套接字 
bzero(&servaddr,sizeof(servaddr)); 
servaddr.sin_family = AF_INET; //指定使用的通讯协议族 
servaddr.sin_port = htons(5000);//指定要连接的服务器的端口 
inet_pton(AF_INET, argv[1], &servaddr.sin_addr); 
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)); //连接服务器 
recv(sockfd,recvbuff,sizeof(recvbuff),0); //接收服务器的数据 
printf("%s ",recvbuff); //打印接收到的数据 
close(sockfd); //关闭套接字 
}

