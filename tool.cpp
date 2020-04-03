#include "tool.h"
using namespace std;

void runApp(Cpu &cpu) {
    vector<string> commands;

    string cmd;
    while (getline(cin, cmd)) {
        commands = split(cmd, " ");
        handleCommand(cpu, commands);
    }
}
void handleCommand(Cpu &cpu, vector<string> command) {
    string mainCommand = command[0];

    if (mainCommand == "add_core")
        cpu.addCore();
    else if (mainCommand == "add_process")
        addProcess(&cpu, command);
    else if (mainCommand == "show_cores_stat")
        cpu.showCoresStat();
    else if (mainCommand == "run_cores")
        cpu.runCores();
    else if (mainCommand == "finish_tasks")
        cpu.finishTasks();
}
void addProcess(Cpu *cpu, vector<string> command) {
    int numberOfThreads = stoi(command[1]);
    Process process;
    for (int i = 2; i < command.size(); i++)
        process.addThread(stoi(command[i]));
    cpu->addProcess(process);
}
bool isIncluded(string sentence, char character) {
    for (int i = 0; i < sentence.size(); i++)
        if (sentence[i] == character)
            return true;

    return false;
}
vector<string> split(string input, string delimiters) {
    int arrayNum = 0;
    vector<string> result;
    result.push_back("");
    for (int i = 0; i < input.size(); i++) {
        if (!isIncluded(delimiters, input[i]))
            result[arrayNum] += input[i];
        else {
            if (result[arrayNum] == "")
                continue;
            arrayNum++;
            result.push_back("");
        }
    }
    return result;
}