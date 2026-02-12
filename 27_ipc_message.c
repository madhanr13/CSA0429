#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

struct message {
    long msg_type;          // MUST be long
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    // Generate unique key
    key = ftok("progfile", 65);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (fork() == 0) {
        // Child process: receive message
        msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);
        printf("Child received: %s\n", msg.msg_text);
    }
    else {
        // Parent process: send message
        msg.msg_type = 1;
        strcpy(msg.msg_text, "Hello from parent process!");

        msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);
        printf("Parent sent: %s\n", msg.msg_text);

        wait(NULL);

        // Remove message queue
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
