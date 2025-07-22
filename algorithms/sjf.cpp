#include "../headers/sjf.h"
#include "../headers/utils.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>
using namespace std;

void runSJF(vector<Process> &processes)
{

    int n = processes.size();
    int currentTime = 0;
    int completed = 0;
    vector<bool> isDone(n, false);

    while (completed < n)
    {
        // Filter: eligible & not done
        int idx = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (!isDone[i] && processes[i].arrivalTime <= currentTime)
            {
                if (processes[i].burstTime < minBurst)
                {
                    minBurst = processes[i].burstTime;
                    idx = i;
                }
                else if (processes[i].burstTime == minBurst &&
                         processes[i].arrivalTime < processes[idx].arrivalTime)
                {
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            currentTime++;
            continue;
        }

        Process &p = processes[idx];

        cout << "\nNow executing Process P" << p.pid << " at time " << currentTime << endl;
        cout << "Processing";
        for (int i = 0; i < 3; ++i)
        {
            cout << ".";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(400));
        }
        cout << endl;

        p.completionTime = currentTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;

        currentTime = p.completionTime;
        isDone[idx] = true;
        completed++;

        cout << "Process P" << p.pid << " finished at time " << p.completionTime << "\n"
             << "-----------------------------------------\n";
        this_thread::sleep_for(chrono::milliseconds(800));
    }

    printProcessTable(processes);
    printGanttChart(processes);
}