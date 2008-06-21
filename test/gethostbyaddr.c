#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//gcc -fPIC  -g -O2 -Wall -I. -o gethostbyaddr gethostbyaddr.c -lc
int main() {
  struct in_addr bar;
  struct hostent *foo;
  inet_aton("64.4.33.7",&bar);
  foo=gethostbyaddr(&bar,4,AF_INET);
  if (foo) {
    int i;
    for (i=0; foo->h_addr_list[i]; ++i)
      printf("%s -> %s\n",foo->h_name,inet_ntoa(*(struct in_addr*)foo->h_addr_list[i]));
    for (i=0; foo->h_aliases[i]; ++i)
      printf("  also known as %s\n",foo->h_aliases[i]);
  }
  return 0;
}
