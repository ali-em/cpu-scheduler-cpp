#ifndef PROCESS_H
#define PROCESS_H
#include <vector>
#include "thread.h"
using namespace std;

class Process {
   public:
    Process(vector<int> timeSlices);
    Process();
    void addThread(int timeSlice);
    void setId(int i);
    int getId() { return pid; }
    int numberOfThreads() { return threads.size(); }
    Thread* getThreadById(int i) { return &(threads[i]); }
    void setParentToThreads();
    vector<Thread> threads;

   private:
    int pid;
};
#endif