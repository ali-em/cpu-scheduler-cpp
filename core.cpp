#include "core.h"

Core::Core(int id) {
    coreID = id;
}
void Core::showCoreID() {
    cout << "Core number : " << coreID << endl;
}
void Core::showStat() {
    showCoreID();
    for (auto thread : threads) {
        thread->showInfo();
        thread->showTimeSlots();
    }
}

void Core::logRun() {
    showCoreID();
    threads[FIRST_THREAD]->showInfo();
}
void Core::runCore() {
    if (threads.size() == 0)
        return;
    logRun();
    threads[FIRST_THREAD]->decreaseTimeSlice();
    if (threads[FIRST_THREAD]->getTimeSliceNumber() != 0)
        threads.push_back(threads[FIRST_THREAD]);
    threads.pop_front();
}