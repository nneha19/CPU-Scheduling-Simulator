#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"
#include "../headers/fcfs.h"
#include "../headers/priority.h"
#include "../headers/sjf.h"
using namespace std;

//algorithm function declarations
void runFCFS(vector<Process>& processes);
void runPriority(vector<Process>& processes);
void runSJF(vector<Process>& processes);
void runRR(vector<Process>& processes, int timeQuantum);

#endif 