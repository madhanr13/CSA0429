#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>   // FIXED

struct msg_buffer {
    long msg_type;            // MUST be long
    char msg_text[100];
};

int main() {
    struct msg_buffer message;
    key_t key;
    int msgid;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (fork() == 0) {
        // Child process: receive message
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);  // FIXED
        printf("Child received: %s\n", message.msg_text);
    } 
    else {
        // Parent process: send message
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from parent!");

        msgsnd(msgid, &message, sizeof(message.msg_text), 0);     // FIXED
        printf("Parent sent: %s\n", message.msg_text);

        wait(NULL);
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
