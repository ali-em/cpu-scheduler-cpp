#ifndef CORE_H
#define CORE_H
#include <deque>
#include <iostream>
#include "thread.h"
#define FIRST_THREAD 0
using namespace std;

class Core {
   public:
    Core(int id);
    void runCore();
    void addThread(Thread* thread) { threads.push_back(thread); }
    int getThreadsNumber() { return threads.size(); }
    void showStat();
    void logRun();
    void showCoreID();

   private:
    int coreID;
    deque<Thread*> threads;
};

#endif