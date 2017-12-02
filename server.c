#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  int in_sock;
  struct sockaddr_in addr;
  struct sockaddr_in client;
  int len;
  int out_sock;

  in_sock = socket(AF_INET, SOCK_STREAM, 0);

  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  bind(in_sock, (struct sockaddr *) &addr, sizeof(addr));

  listen(in_sock, 5);

  len = sizeof(client);
  out_sock = accept(in_sock, (__SOCKADDR_ARG) &client, &len);

  char *msg = "Hello World";
  write(out_sock, msg, strlen(msg));
  close(out_sock);

  close(in_sock);

  return 0;
}
