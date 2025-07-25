# CPUSched++ - CPU Scheduling Simulator (C++)

A console-based C++ project that simulates key **CPU scheduling algorithms**:  
- FCFS (First-Come, First-Served)  
- SJF (Shortest Job First)  
- Round Robin (with Time Quantum 4)  
- Priority Scheduling  

Built from scratch using core C++ concepts like **vectors, sorting, conditionals**, and **process struct modeling**, this tool visualizes execution order, timing metrics, and Gantt charts — mimicking how a real CPU scheduler functions.
<img width="1048" height="609" alt="image" src="https://github.com/user-attachments/assets/3e11a047-75ee-4ab2-a6b4-d6868406a2de" />


<br/>

## 🛠️ Features

- ⏳ **Interactive input** for process details
- 📊 Gantt chart-like visual display
- 🧮 Calculates: Completion Time, Turnaround Time, Waiting Time
- 🔁 Round Robin with fixed time quantum (4 units)
- 📋 Priority support (lower number = higher priority)

<br/>

## 🚀 Algorithms Implemented

### 1. First-Come, First-Served (FCFS)
**Logic:** Sort processes by arrival time and execute one after another.

```cpp
sort(processes.begin(), processes.end(), compareByArrivalTime);
```
Example:

| PID | Arrival | Burst |
|-----|---------|-------|
| 1   | 0       | 4     |
| 2   | 1       | 3     |

🕐 Gantt Chart: `| P1 (0–4) | P2 (4–7) |`

<br/>

### 2. Shortest Job First (Non-Preemptive)
**Logic:**  At each time, pick the process with the smallest burst that has arrived.

```cpp
if (p.arrivalTime <= currentTime && p.burstTime < minBurst)
```
<br/>

### 3. Round Robin (Time Quantum = 4)
**Logic:**  Use a queue; each process gets 4 units in turn until done.
```cpp
queue<Process> q;
remainingBurst[p.pid] = p.burstTime;
```
<br/>

### 4. Priority Scheduling
**Logic:**  Execute by priority, resolve ties using arrival time.
```cpp
sort(processes.begin(), processes.end(), [](a, b) {
    return a.priority < b.priority || (a.priority == b.priority && a.arrivalTime < b.arrivalTime);
});
```
<br/>

## 📸 Sample Output
```cpp
Now executing Process P2 at time 0
Processing...
Process P2 finished at time 3
-----------------------------------------
```

🕐 Final Table:

| PID | Arrival | Burst | Arrival | Burst | Burst |
|-----|---------|-------| --------|-------|-------|
| 1   | 0       | 4     |  4      | 4     | 0     |

<br/>

## 🔧 How to Run
```cpp
g++ main.cpp -o CPUSchedPlusPlus
./CPUSchedPlusPlus
```
Or compile all **.cpp** files together, depending on your setup.

<br/>

## 📁 File Structure
```
├── main.cpp
├── scheduler.cpp
├── utils.cpp
├── headers/
│   ├── process.h
│   ├── fcfs.h
│   ├── sjf.h
│   ├── rr.h
│   ├── priority.h
│   ├── scheduler.h
│   └── utils.h
├── algorithms/
│   ├── fcfs.cpp
│   ├── sjf.cpp
│   ├── rr.cpp
│   └── priority.cpp
└── README.md
```

<br/>

## 🧠 Why This Project?
As part of core Computer Science learning, this project strengthens understanding of:
- OS scheduling theory
- Time management of processes
- Simulation of real CPU-like behaviour
- C++ data structures and logic building

<br/>

## 🏁 Future Improvements
- Add Preemptive SJF or Multilevel Queues
- Export table as CSV
- GUI-based interface (maybe in Qt or web)

<br/>

## 👩‍💻 Author
**Neha Ghariyal**  
📫 [GitHub](https://github.com/nneha19) | 📧 [nehaghariyal19@gmail.com](mailto:nehaghariyal19@gmail.com)
