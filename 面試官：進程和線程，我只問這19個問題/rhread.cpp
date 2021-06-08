
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

#define BUFFER_SIZ 20

typedef struct {
    long int msg_type;
    char text[BUFFER_SIZ];
} MsgWrapper;

void Receive() {
    MsgWrapper data;
    long int msgtype = 2;
    int msgid = msgget((key_t)1024, 0666 | IPC_CREAT);
    if (msgid == -1) {
        cout << "msgget error \n";
        return;
    }
    while (true) {
        if (msgrcv(msgid, (void *)&data, BUFFER_SIZ, msgtype, 0) == -1) {
            cout << "error " << errno << endl;
        }
        cout << "read data " << data.text << endl;
        if (strlen(data.text) > 6) {  // 发送超过6个字符的数据，结束
            break;
        }
    }
    if (msgctl(msgid, IPC_RMID, 0) == -1) {
        cout << "msgctl error \n";
    }
    cout << "Receive ok \n";
}

void Send() {
    MsgWrapper data;
    long int msgtype = 2;
    int msgid = msgget((key_t)1024, 0666 | IPC_CREAT);
    if (msgid == -1) {
        cout << "msgget error \n";
        return;
    }
    data.msg_type = msgtype;
    for (int i = 0; i < 10; ++i) {
        memset(data.text, 0, BUFFER_SIZ);
        char a = 'a' + i;
        memset(data.text, a, 1);
        if (msgsnd(msgid, (void *)&data, BUFFER_SIZ, 0) == -1) {
            cout << "msgsnd error \n";
            return;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    memcpy(data.text, "1234567", 7);
    if (msgsnd(msgid, (void *)&data, BUFFER_SIZ, 0) == -1) {
        cout << "msgsnd error \n";
        return;
    }
}

int main() {
    std::thread r(Receive);
    r.detach();
    std::thread s(Send);
    s.detach();
    std::this_thread::sleep_for(std::chrono::seconds(20));
    return 0;
}
/*
输出：root@iZuf64idor3ej648ciairaZ:~# ./a.out
read data a
read data b
read data c
read data d
read data e
read data f
read data g
read data h
read data i
read data j
read data 1234567
Receive ok
*/
