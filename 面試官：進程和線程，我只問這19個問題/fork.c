
#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t id = fork();
    if (id < 0) {
        perror("fork\n");
    } else if (id == 0) {  // 子进程
        printf("子进程\n");
    } else {  // 父进程
       printf("父进程\n");
   }
   return 0;
}