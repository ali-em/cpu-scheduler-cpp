#include "cpu.h"

Cpu::Cpu() {
    numberOfCores = 0;
    numberOfProcesses = 0;
}
void Cpu::addProcess(Process process) {
    processes.push_back(process);
    processes[numberOfProcesses].setId(processes.size());
    for (int i = 0; i <= numberOfProcesses; i++)
        processes[i].setParentToThreads();

    numberOfProcesses++;
    setThreadsToCores(numberOfProcesses);
    logAddProcess(numberOfProcesses);
}
void Cpu::setThreadsToCores(int processId) {
    Process* process = getProcessById(processId);
    Core* bestCore;
    for (int i = 0; i < process->numberOfThreads(); i++) {
        bestCore = getBestCore();
        bestCore->addThread(process->getThreadById(i));
    }
}

Process* Cpu::getProcessById(int id) {
    for (int i = 0; i < processes.size(); i++)
        if (processes[i].getId() == id)
            return &(processes[i]);
    return NULL;
}

Core* Cpu::getBestCore() {
    int min = 0;
    for (int i = 0; i < cores.size(); i++) {
        if (cores[i].getThreadsNumber() < cores[min].getThreadsNumber())
            min = i;
    }
    return &cores[min];
}
void Cpu::addCore() {
    numberOfCores++;
    cores.push_back(Core(numberOfCores));
    logCoreAdd(numberOfCores);
}
void Cpu::logCoreAdd(int id) {
    cout << "Core with core ID = " << id << " successfully added!" << endl;
}
void Cpu::logAddProcess(int id) {
    cout << "Process with pid = " << id << " added!" << endl;
}
void Cpu::showCoresStat() {
    for (int i = 0; i < cores.size(); i++)
        cores[i].showStat();
}
void Cpu::runCores() {
    for (int i = 0; i < cores.size(); i++)
        cores[i].runCore();
}
bool Cpu::isFinished() {
    int tasks = 0;
    for (int i = 0; i < cores.size(); i++)
        if (cores[i].getThreadsNumber())
            return false;
    return true;
}
void Cpu::finishTasks() {
    int i = 1;
    while (!isFinished()) {
        cout << "Time Slice : " << i++ << endl;

        runCores();
    }
}