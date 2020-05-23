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



int main(int argc,char *argv[]) 
{

int listensock,connsock; //定义两个socket套接字，一个用于监听，一个用于通讯 
struct sockaddr_in servaddr; //定义网络套接字地址结构 
const char buff[] = "Hello! Welcome here! "; //定义要发送的数据缓冲区； 
listensock = socket(AF_INET,SOCK_STREAM,0); //创建一个套接字，用于监听 
bzero(&servaddr,sizeof(servaddr)); //地址结构清零 
servaddr.sin_family = AF_INET; //指定使用的通讯协议族 
servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //指定接受任何连接，因为服务器不知道谁会要求连接 
servaddr.sin_port = htons(5000); //指定监听的端口 
bind(listensock,(struct sockaddr*)&servaddr,sizeof(servaddr)); //给套接口邦定地址 
listen(listensock,1024); //开始监听

connsock = accept(listensock,(struct sockaddr*)NULL, NULL); //建立通讯的套接字，accept函数，等待客户端程序使用connect函数的连接

send(connsock,buff,sizeof(buff), 0); //向客户端发送数据 
close(connsock); //关闭通讯套接字 
close(listensock); //关闭监听套接字 
}
