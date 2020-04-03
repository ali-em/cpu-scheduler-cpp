#ifndef CPU_H
#define CPU_H

#include <deque>
#include <iostream>
#include <vector>
#include "core.h"
#include "process.h"
#include "tool.h"
using namespace std;

class Cpu {
   public:
    Cpu();
    void runCores();
    void finishTasks();
    void addCore();
    void addProcess(Process process);
    void setThreadsToCores(int processId);
    void showCoresStat();
    Process* getProcessById(int id);
    Core* getBestCore();
    void logCoreAdd(int id);
    void logAddProcess(int id);
    bool isFinished();

   private:
    vector<Core> cores;
    vector<Process> processes;
    int numberOfCores;
    int numberOfProcesses;
};

#endif