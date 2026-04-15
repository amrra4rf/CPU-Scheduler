
#ifndef    FCFS_H
#define    FCFS_H

#include <iostream>
#include <queue>
#include "../Models/Process.hpp"
#include "../Models/Scheduler.hpp"
using namespace std;

class FCFS : Scheduler{
    private:
        queue<Process> processes;
        float tt_time =0;
        float waiting_time =0;
        int time =0,size =0;

    public:
        
        FCFS(){}

        void addProcess(const Process& p) override{
            /* add the process in the queue*/
            processes.push(p);
            size++;
        }

        int step(){
            /* Get the PID of the process next to execute*/
            return processes.front().getPID();
        }

        bool isFinished() const override{
            /* indecate if the scheduler is finished*/
            return processes.empty();
        }



        // void schedule(){
        //     /* Scheduling using the FCFS */

        //     int time =processes.empty() ? 0 : processes.front().getArrival();

        //     while(!processes.empty()){
        //         cout <<"Process "<< this->step() << " come at time " << time ;
        //         Process process = processes.front();
        //         processes.pop();

        //         if(process.getArrival() > time ){
        //             time = process.getArrival();
        //         }
        //         process.finish( process.getBurst());

        //         time += process.getFinish(); 
        //         cout << " Completed at time " << time << endl;
        //     }
        // }

        int Schdule() override{
            if (!processes.empty()){
                Process p = processes.front();
                processes.pop();
                 cout << "the processes execute : "<<endl;
                while(p.getRemaining()){
                    cout <<p.execute(1)+1 <<" ->";
                }
                if(time < p.getArrival())
                    time += p.getArrival()+p.getBurst();
                else 
                    time += p.getBurst();
                p.finish(time);
                tt_time += p.turnarround();
                waiting_time += p.waiting_time();
                return p.getPID();
            }

        }

        double Average_wait_time() const override{
            if(size >0)
                return waiting_time/size;
            else return -1;

        }
        double Average_turnaround_time()const override{
            if(size >0)
                return tt_time/size;
            else return -1;
        } 
};



#endif