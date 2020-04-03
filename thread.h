#ifndef THREAD_H
#define THREAD_H
#include <iostream>
class Process;
using namespace std;

class Thread {
   public:
    Thread(int timeSlice);
    int getParentId();
    int getId() { return id; }
    int getTimeSliceNumber() { return timeSliceNumber; }
    void decreaseTimeSlice() { timeSliceNumber--; }
    void showInfo();
    void showTimeSlots() { cout << "Number of time slots : " << timeSliceNumber << endl; }
    void setParentProcess(Process* process) { parent = process; }
    void setId(int i) { id = i; }

   private:
    int id;
    int timeSliceNumber;
    Process* parent;
};

#endif