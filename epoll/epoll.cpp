#include <iostream>
#include <sys/epoll.h>
#include <unistd.h>

int main() {

    int epfd,nfds;
    epfd = epoll_create(1);

    struct epoll_event ev{},events[5];
    ev.data.fd = STDIN_FILENO;
    ev.events |= EPOLLIN;
    ev.events |= EPOLLET;
    // default is LT

    epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    for (; ;) {
        nfds = epoll_wait(epfd,events,5,-1);

        for (int i = 0; i < nfds; ++i) {
            if(events[i].data.fd == STDIN_FILENO) {
                printf("welcome to epoll's world!\n");
            }
        }

    }
#pragma clang diagnostic pop
}