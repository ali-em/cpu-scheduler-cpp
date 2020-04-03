#include "thread.h"
#include "process.h"
using namespace std;

Thread::Thread(int timeSlice) {
    timeSliceNumber = timeSlice;
}
int Thread::getParentId() {
    return parent->getId();
}
void Thread::showInfo() {
    cout << "Process ID : " << getParentId() << " - Thread ID : " << getId() << endl;
}