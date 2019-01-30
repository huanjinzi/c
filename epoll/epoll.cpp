#include <iostream>
#include <sys/epoll.h>
#include <unistd.h>

int main() {

    int epfd,nfds;

    
    /* 
    Creates an epoll instance.  Returns an fd for the new instance.
    The "size" parameter is a hint specifying the number of file
    descriptors to be associated with the new instance.  The fd
    returned by epoll_create() should be closed with close(). 
    */

    /*
    创建一个epoll对象，返回指向这个对象的epfd。指定这个对象可以监控多少个fd，这里是只能监听一个.
    */
    epfd = epoll_create(1);

    struct epoll_event ev{},events[5];
    ev.data.fd = STDIN_FILENO;
    ev.events |= EPOLLIN;
    ev.events |= EPOLLET;
    // default is LT

    /* 
    Manipulate an epoll instance "epfd". Returns 0 in case of success,
    -1 in case of error ( the "errno" variable will contain the
    specific error code ) The "op" parameter is one of the EPOLL_CTL_*
    constants defined above. The "fd" parameter is the target of the
    operation. The "event" parameter describes which events the caller
    is interested in and any associated user data.
    */
    /*
    将STDIN_FILENO这个fd关联到epfd指向的epoll对象，ev表示STDIN_FILENO的触发条件
    */
    epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev);


    for (; ;) {
        /* 
        Wait for events on an epoll instance "epfd". Returns the number of
        triggered events returned in "events" buffer. Or -1 in case of
        error with the "errno" variable set to the specific error code. The
        "events" parameter is a buffer that will contain triggered
        events. The "maxevents" is the maximum number of events to be
        returned ( usually size of "events" ). The "timeout" parameter
        specifies the maximum wait time in milliseconds (-1 == infinite).

        This function is a cancellation point and therefore not marked with
        __THROW.  
        */

        /* nfds 表示触发的事件数量，events 是触发事件的buffer，5 表示buffer的大小，-1表示不超时 */
        nfds = epoll_wait(epfd,events,5,-1);

        for (int i = 0; i < nfds; ++i) {
            if(events[i].data.fd == STDIN_FILENO) {
                printf("welcome to epoll's world!\n");
            }
        }

    }

    /*释放epfd指向的epoll对象*/
    epfd.close();
}