
#ifndef    FCFS_HPP
#define    FCFS_HPP

#include <iostream>
#include <queue>
#include "../Models/Process.hpp"
#include "../Models/Scheduler.hpp"
using namespace std;

class FCFS : public Scheduler{
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

        int step()const override{
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
            // If no processes are ready, the CPU is idle
            if (processes.empty()){
                time++;
                return -1; 
            }

            // Get a REFERENCE to the front process so we can edit it directly
            Process& p = processes.front();

            // Record start time on its very first tick
            p.start_p(time);

            // Execute for exactly 1 second
            p.execute(1);
            int current_pid = p.getPID();

            // Check if it finished on this exact tick
            if(p.getRemaining() == 0){
                p.finish(time + 1);
                
                // Add its final stats to the running totals
                tt_time += p.turnarround();
                waiting_time += p.waiting_time();
                
                // Remove it from the queue so the next process can run
                processes.pop();
            }

            // Move internal clock forward
            time++;
            return current_pid;
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