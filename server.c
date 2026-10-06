#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PORT 8181

int main() {
  int s, c; // s: socket | c: client
  socklen_t addrlen; // unsigned int 
  
  addrlen = 0;
  
  struct sockaddr_in srv, cli;
  char buf[512];
  char *data;
  
  memset(&srv, 0 , sizeof(srv));
  memset(&cli, 0, sizeof(cli));
  
  s = socket(AF_INET, SOCK_STREAM, 0);
  
  if (s < 0) {
    printf("socket()\n");
    return -1;
  }
  
  srv.sin_family = AF_INET;
  srv.sin_addr.s_addr = 0;
  srv.sin_port = htons(PORT);
  
  if (bind(s, (struct sockaddr *)&srv, sizeof(srv))) {
    printf("Bind()\n");
    close(s);
    return -1;
  }
  
  if (listen(s, 5)) {
    printf("listen()\n");
    close(s);
    return -1;
  }
  printf("Listenning on 0.0.0.0:%d\n", PORT);
  
  // netsat 0.0.0.0:8181
  
  c = accept(s, (struct sockaddr *)&srv, &addrlen);
  if (c < 0) {
    printf("accept()\n");
    close(s);
    return -1;
  }
  
  printf("Client Connected Successfully\n");
  read(c, buf, 511);
  data = "httpd v1.0\n";
  write(c, data, strlen(data));
  
  close(c);
  close(s);
  
  return 0;
}

