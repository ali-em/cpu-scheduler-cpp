#ifndef TOOL_H
#define TOOL_H
#include <iostream>
#include <string>
#include <vector>
#include "cpu.h"
#include "thread.h"
using namespace std;
class Cpu;
vector<string> getInput();
void runApp(Cpu &cpu);
void addProcess(Cpu *cpu, vector<string> command);
void handleCommand(Cpu &cpu, vector<string> command);
vector<string> split(string input, string delimiters);
bool isIncluded(string sentence, char character);
string trim(string str);
#endif