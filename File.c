#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

  if (argc > 1) {
    FILE *fp = fopen(argv[1], "r");
    
    if (!fp) {
      perror("File open failed");
      exit(1);
    }
    
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    
    while ((nread = getline(&line, &len, fp)) != -1) {
      line[strlen(line) - 1] = '\0'; // remove newline
      
      pid_t pid = fork();
      
      if (pid == 0) {
        execlp(line, line, NULL);
        exit(127);
      } else {
        wait(NULL);
      }
    }
    
    free(line);
    fclose(fp);
  }
  
  return 0;
}
