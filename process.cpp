#include "process.h"
#include "thread.h"
#define NOT_SET -1
using namespace std;

Process::Process(vector<int> timeSlices) {
    pid = NOT_SET;
    for (int i = 0; i < timeSlices.size(); i++)
        threads.push_back(Thread(timeSlices[i]));
}
Process::Process() {
    pid = NOT_SET;
}
void Process::addThread(int timeSlice) {
    threads.push_back(Thread(timeSlice));
}
void Process::setId(int i) {
    pid = i;
}
void Process::setParentToThreads() {
    for (int i = 0; i < threads.size(); i++) {
        threads[i].setParentProcess(this);
        threads[i].setId(i + 1);
    }
}
