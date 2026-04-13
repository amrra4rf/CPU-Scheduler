
#ifndef    FCFS_H
#define    FCFS_H

#include <iostream>
#include <queue>
#include "../Models/Process.hpp"
#include "../Models/Scheduler.hpp"
using namespace std;

class FCFS{
    private:
        queue<Process> processes;

    public:
        
        FCFS(){}

        void addProcess(const Process& p){
            /* add the process in the queue*/
            processes.push(p);
            cout<< "The Process "<< p.getPID() <<" Added ";
        }

        int step(){
            /* Get the PID of the process next to execute*/
            return processes.front().getPID();
        }

        bool isFinished(){
            /* indecate if the scheduler is finished*/
            return processes.empty();
        }



        void schedule(){
            /* Scheduling using the FCFS */

            int time =processes.empty() ? 0 : processes.front().getArrival();

            while(!processes.empty()){
                cout <<"Process "<< this->step() << " come at time " << time ;
                Process process = processes.front();
                processes.pop();

                if(process.getArrival() > time ){
                    time = process.getArrival();
                }
                process.finish( process.getBurst());

                time += process.getFinish(); 
                cout << " Completed at time " << time << endl;
            }
        }

        
};


int main (){
    Process p1 = Process(1, 1, 5);
    Process p2 = Process(2, 2, 3);
    Process p3 = Process(3, 3, 4);
    Process p4 = Process(4, 13, 7);


    FCFS s = FCFS();
    s.addProcess(p1);
    s.addProcess(p2);
    s.addProcess(p3);
    s.addProcess(p4);

    cout << "the PID next to execute is "<<s.step()<<endl;
    s.schedule();



}

#endif