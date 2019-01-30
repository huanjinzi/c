#include <iostream>
#include <unistd.h>
#include <cstring>
#include <wait.h>

#define SUCCESS 0

using namespace std;
int main() {
    int fds[2];

    // fds[0] read
    // fds[1] write
    if(pipe(fds) != SUCCESS){
        cout << "create pipe fail.";
        exit(1);
    }
    // pipe create success.

    // if PARENT process is dead,the CHILD process is also dead.
    pid_t pid = fork();

    if(pid == 0) {

        sleep(2);

        // close read endpoint.
        close(fds[0]);

        const char* msg = "hello,dad.\n";
        int count = 3;
        while (count--){
            cout << "child writing..." << endl;
            sleep(1);
            write(fds[1], msg, strlen(msg));

        }
        close(fds[1]);
        cout << "child i am dying." << endl;
        exit(0);

    } else {

        sleep(2);
        close(fds[1]);
        char buf[1024];

        while (1) {
            cout << "parent reading..." << endl;
            sleep(1);
            auto size = read(fds[0], buf, 1024);

            if (size > 0) {
                buf[size] = '\0';
                cout << "parent child say:" << buf << endl;
            } else if (size ==0 ) {
                cout << "parent pipe read end!" << endl;
                break;
            } else {
                cout << "parent pipe read error!" << endl;
                exit(1);
            }
        }

        close(fds[0]);

        int status = 0;
        pid_t pid_ = waitpid(pid, &status, 0);

        if (pid == pid_) {
            cout << "parent child dies." << endl;
        }
        cout << "parent i am dying." << endl;
        return 0;
    }
}