//
// Created by mbataglia on 01/05/17.
//

#ifndef TP3_COMMONTHREAD_H
#define TP3_COMMONTHREAD_H

#include <thread>

class Thread {
private:
    std::thread thread;

public:
    Thread() {}

    void start();

    void join();

    virtual void run() = 0;
    virtual ~Thread() {}

    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;

    Thread(Thread&& other);

    Thread& operator=(Thread&& other);
};


#endif //TP3_COMMONTHREAD_H
