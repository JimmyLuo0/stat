#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(){
  struct stat things;
  int fd = stat("main.c", &things);
  if(fd < 0){
    printf("%d: %s\n", errno, strerror(errno));
  }
  return 0;
}
