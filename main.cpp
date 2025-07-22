#include <iostream>
#include <vector>
#include <limits>
#include "headers/process.h"
#include "headers/scheduler.h"
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes:";
    cin >> n;

    vector<Process> processes(n);

    // taking input for processes
    cout << "Enter the details of each process:\n";

    for (int i = 0; i < n; ++i)
    {
        processes[i].pid = i + 1;
        cout << "\nProcess " << processes[i].pid << ":\n";
        cout << "Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Burst Time: ";
        cin >> processes[i].burstTime;
        cout << "Priority (lower number means higher priority): ";
        cin >> processes[i].priority;
    }

    // algorithm choice
    int choice;
    cout << "\nChoose the scheduling algorithm:\n";
    cout << "1. First-Come, First-Served (FCFS)\n";
    cout << "2. Shortest Job First (SJF)\n";
    cout << "3. Round Robin (RR) with Time Quantum - 4\n";
    cout << "4. Priority Scheduling\n";

    cout << "Enter your choice (1-4): ";
    while (!(cin >> choice) || choice < 1 || choice > 4)
    {
        cout << "Invalid choice! Please choose a valid option (1-4): ";
        cin.clear();                                       
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    switch (choice)
    {
    case 1:
        cout << "\nRunning First-Come, First-Served (FCFS) scheduling...\n";
        runFCFS(processes);
        break;

    case 2:
        cout << "\nRunning Shortest Job First (SJF) scheduling...\n";
        runSJF(processes);
        break;

    case 3:
        cout << "\nRunning Round Robin (RR) scheduling with Time Quantum - 4...\n";
        runRR(processes, 4); // Assuming time quantum is 4
        break;

    case 4:
        cout << "\nRunning Priority Scheduling...\n";
      runPriority(processes);
        break;

    default:
        cout << "Invalid choice!\n";
    }



    return 0;
}