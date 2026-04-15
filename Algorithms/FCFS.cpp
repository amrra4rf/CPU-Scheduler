
#ifndef    FCFS_H
#define    FCFS_H

#include <iostream>
#include <queue>
#include "../Models/Process.hpp"
#include "../Models/Scheduler.hpp"
using namespace std;

class FCFS : public Scheduler{
    private:
        queue<Process> processes;
        float turnaround =0;
        float waiting_time =0;
        int size =0;

    public:
        
        FCFS(){}

        void addProcess(const Process& p) override{
            /* add the process in the queue*/
            processes.push(p);
            size ++;
            // cout<< "The Process "<< p.getPID() <<" Added " <<endl;
        }

        int step() const override {
            /* Get the PID of the process next to execute*/
            return processes.front().getPID();
        }

        bool isFinished() const override {
            /* indecate if the scheduler is finished*/
            return processes.empty();
        }



        int Schdule() override{
            /* Scheduling using the FCFS */

            int time =processes.empty() ? 0 : processes.front().getArrival();

            while(!processes.empty()){
                cout <<"Process "<< this->step() << " start at time " << time ;
                Process process = processes.front();
                processes.pop();

                if(process.getArrival() > time ){
                    time = process.getArrival();
                }
                process.finish( process.getBurst()+time );

                time = process.getFinish(); 
                cout << " Completed at time " << time << endl;

                turnaround += process.turnarround();
                cout << "the turnaround is " << turnaround<<endl;
                waiting_time += process.waiting_time();
                cout << "the waiting is " << waiting_time <<endl;

            }
            return time;
        }

        double Average_wait_time()const{
            if(size>0)
                return waiting_time/size;
        }

        virtual double Average_turnaround_time()const {
            if(size>0)
                return turnaround/size;
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
    s.Schdule();

    cout << "The Average waiting time " << s.Average_wait_time()<<endl;
    cout << "The Average turnaround time " << s.Average_turnaround_time()<<endl;




}

#endif
