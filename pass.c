#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void p(char*a){perror(a);exit(1);}
int main(int a, char**b){int d;struct sockaddr_in e;struct sockaddr_in f;char h[1];char *k;size_t l;
socklen_t i=sizeof(e);unsigned short j=4400;FILE *m=fopen("pass.bin","rb");if(m){fseek(m,0,SEEK_END);
l=ftell(m);fseek(m,0,SEEK_SET);k=malloc(l);if(k){fread(k,1,l,m);}else{p("Malloc");}fclose(m);}else{
p("Open");}int c=socket(AF_INET,SOCK_STREAM,0);if(c<0)p("Socket");setsockopt(c,SOL_SOCKET,SO_REUSEADDR,
(const void*)&d,sizeof(int));bzero((char*)&e,sizeof(e));e.sin_family=AF_INET;
e.sin_addr.s_addr=htonl(INADDR_ANY);e.sin_port=htons(j);if(bind(c,(struct sockaddr*)&e,i)<0)p("Bind");
if(listen(c,8)<0)p("Listen");while(42){int g=accept(c,(struct sockaddr*)&f,&i);if(g<0)p("Accept");
read(g,h,1);write(g,k,l);close(g);}close(c);return 0;}