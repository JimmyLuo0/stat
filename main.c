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
  if(sizeinbytes < kilo)
  	printf("size of file: %d %s\n", sizeinbytes, "B");
  if(sizeinbytes >= kilo)
    printf("size of file: %f %s\n", sizeinbytes/kilo, "KB");
  if(sizeinbytes >= mega)
    printf("size of file: %f %s\n", sizeinbytes/mega, "MB");
  if(sizeinbytes >= giga)
    printf("size of files: %f %s\n", sizeinbytes/giga, "GB");
 
  printf("permissions of file: %o\n", things.st_mode);

  printf("Last access time: %s", ctime(&things.st_atime));
  
  return 0;
}
