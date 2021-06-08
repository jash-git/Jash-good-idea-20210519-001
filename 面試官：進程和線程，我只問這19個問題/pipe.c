#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {
    int _pipe[2];
    int ret = pipe(_pipe);
    if (ret < 0) {
        perror("pipe\n");
    }
    pid_t id = fork();
    if (id < 0) {
        perror("fork\n");
    } else if (id == 0) {  // 子进程
        close(_pipe[1]);
        int j = 0;
        char _mesg[100];
        while (j < 100) {
            memset(_mesg, '\0', sizeof(_mesg));
            read(_pipe[0], _mesg, sizeof(_mesg));
            printf("%s\n", _mesg);
            j++;
        }
    } else {  // 父进程
        close(_pipe[0]);
        int i = 0;
        char *mesg = NULL;
        while (i < 100) {
            mesg = "父进程来写消息了";
            write(_pipe[1], mesg, strlen(mesg) + 1);
            sleep(1);
            ++i;
        }
    }
    return 0;

}