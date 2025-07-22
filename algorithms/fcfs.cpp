#include "../headers/fcfs.h"
#include "../headers/utils.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>
using namespace std;

void runFCFS(vector<Process> &processes)
{
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         { return a.arrivalTime < b.arrivalTime; });

    int currentTime = 0;

    for (auto &p : processes)
    {
        if (currentTime < p.arrivalTime)
            if (currentTime < p.arrivalTime)
                currentTime = p.arrivalTime;

        cout << "\nNow executing Process P" << p.pid << " at time " << currentTime << endl;

        cout << "Processing";
        for (int i = 0; i < 3; ++i)
        {
            cout << ".";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(400));
        }
        cout << endl;

        currentTime += p.burstTime;
        p.completionTime = currentTime;

        cout << "Process P" << p.pid << " finished at time " << currentTime << "\n"
             << endl;
        cout << "-----------------------------------------\n";

        this_thread::sleep_for(chrono::milliseconds(800));
        p.arrivalTime = max(currentTime, p.arrivalTime);
        p.completionTime = p.arrivalTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;

        currentTime = p.completionTime;
    }

    printProcessTable(processes);
    printGanttChart(processes);
}
