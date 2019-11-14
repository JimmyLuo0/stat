#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(){
  struct stat things;
  int permissions;
  int fd = stat("program", &things);
  if(fd < 0){
    printf("%d: %s\n", errno, strerror(errno));
  }
  int sizeinbytes = things.st_size;
  float kilo = 1024.0;
  float mega = kilo * 1024.0;
  float giga = mega * 1024.0;
  printf("size of files in bytes: %d %s\n", sizeinbytes, "B");
  printf("size of files in kilobytes: %f %s\n", sizeinbytes/kilo, "KB");
  printf("size of files in megabytes: %f %s\n", sizeinbytes/mega, "MB");
  printf("size of files in gigabytes: %f %s\n", sizeinbytes/giga, "GB");
  printf("permissions of file: %o\n", things.st_mode);
  printf("Last access time: %s", ctime(&things.st_atime));
  
  return 0;
}
