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

int port = 5500;
void main()
{
int sockfd; 
int count = 0;
int flag;
char buf[80];
struct sockaddr_in address; 
sockfd = socket(AF_INET, SOCK_DGRAM, 0); //看到不同的地方了吗？
memset(&address, 0, sizeof(address));
address.sin_family = AF_INET; 
address.sin_addr.s_addr = inet_addr("127.0.0.1");
address.sin_port = htons(port); 
flag = 1; 
do{
sprintf(buf,"Packet %d\n", count);
if(count > 30){ 
sprintf(buf,"over\n"); 
flag = 0; 
} 
sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&address, sizeof(address)); // 发现了吗使用的函数不一样,它也是发送数据 
count++; 
}while (flag); 
} 

