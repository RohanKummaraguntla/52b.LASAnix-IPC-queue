#ifndef SIGINFO_H
#define SIGINFO_H

struct sigevent {
    int sigev_notify;               
    int sigev_signo;             
    union {
        int sival_int;       
        void* sival_ptr;        
    } sigev_value;
};

#endif 
