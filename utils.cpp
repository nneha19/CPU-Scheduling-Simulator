#include "headers/utils.h"
#include <iostream>
using namespace std;

void printProcessTable(const vector<Process> &processes)
{
    cout << "\nProcess Table:\n";
    cout << "PID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";
    for (const auto &p : processes)
    {
        cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t" << p.priority
             << "\t\t" << p.completionTime << "\t\t" << p.turnaroundTime << "\t\t" << p.waitingTime << "\n";
    }
}

void printGanttChart(const vector<Process> &processes)
{
    cout << "\nGantt Chart:\n";
    for (const auto &p : processes)
    {
        cout << "| P" << p.pid << " ";
    }
    cout << "|\n0";
    for (const auto &p : processes)
    {
        cout << "   " << p.completionTime;
    }
    cout << "\n";
}