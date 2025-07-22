#include "../headers/rr.h"
#include "../headers/utils.h"
#include <chrono>
#include <queue>
#include <map>
#include <thread>
#include <iostream>     
#include <algorithm>
using namespace std;

void runRR(vector<Process>& processes, int timeQuantum){
 queue<Process> q;
    map<int, int> remainingBurst;

    // Sort by arrival time first
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         { return a.arrivalTime < b.arrivalTime; });

    int currentTime = 0;
    int index = 0;
    vector<Process> completed;

    while (true)
    {
        // Push all processes that have arrived
        while (index < processes.size() && processes[index].arrivalTime <= currentTime)
        {
            q.push(processes[index]);
            remainingBurst[processes[index].pid] = processes[index].burstTime;
            index++;
        }

        if (q.empty())
        {
            if (index < processes.size())
            {
                currentTime = processes[index].arrivalTime;
                continue;
            }
            else
            {
                break;
            }
        }

        Process p = q.front();
        q.pop();

        int execTime = min(timeQuantum, remainingBurst[p.pid]);

        cout << "\nNow executing Process P" << p.pid << " from time " << currentTime
             << " to " << currentTime + execTime << "\nProcessing";

        for (int i = 0; i < 3; ++i)
        {
            cout << ".";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(400));
        }
        cout << endl;

        currentTime += execTime;
        remainingBurst[p.pid] -= execTime;

        while (index < processes.size() && processes[index].arrivalTime <= currentTime)
        {
            q.push(processes[index]);
            remainingBurst[processes[index].pid] = processes[index].burstTime;
            index++;
        }

        if (remainingBurst[p.pid] == 0)
        {
            p.completionTime = currentTime;
            p.turnaroundTime = p.completionTime - p.arrivalTime;
            p.waitingTime = p.turnaroundTime - p.burstTime;
            completed.push_back(p);

            cout << "Process P" << p.pid << " completed at time " << currentTime << endl;
            cout << "---------------------------------------------\n";
        }
        else
        {
            q.push(p); // still has burst left
        }

        this_thread::sleep_for(chrono::milliseconds(600));
    }

    // Sort back by pid for final display
    sort(completed.begin(), completed.end(), [](const Process &a, const Process &b)
         { return a.pid < b.pid; });


  printProcessTable(completed);
printGanttChart(completed);
}