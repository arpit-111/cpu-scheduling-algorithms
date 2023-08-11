#include<iostream>
#include <algorithm>
#include<iomanip>
#include<string.h>

using namespace std;
struct process{
    int id;
    int at;
    int bt;
    int st,ct,rt,tat,wt;
};
int main(){
    int n;
    struct process p[100];
    float avg_tat,avg_wt,avg_rt,cpu_utilisation;
    int total_tat=0,total_wt=0,total_rt=0;
    int total_idle_time=0;
    float throughput,total_bt;
    cout<<"no of processes=";
    cin>>n;
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        cout<<"enter at of process"<<i+1<<"=";
        cin>>p[i].at;
        cout<<"enter bt of process"<<i+1<<"=";
        cin>>p[i].bt;
    }
    
    int completed=0;
    int is_completed[n];
    memset(is_completed,0,sizeof(is_completed));
    int prev=0;//store previous process ct
    int current_time=0;
    //find process with min bt
    while(completed!=n){
        int idx=-1;//index
        int min=100000;
        for(int i=0;i<n;i++){
            if(p[i].at<=current_time && is_completed[i]==0){
                if(p[i].bt<min){
                    min=p[i].bt;
                    idx=i;
                }
                if(p[i].bt==min){
                    if(p[idx].at>p[i].at){
                        min=p[i].bt;
                        idx=i;
                    }
                }    
            }
        }
        //if process is found
        if(idx!=-1){
            p[idx].st=current_time;
            p[idx].ct=p[idx].st+p[idx].bt;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
            p[idx].rt=p[idx].st-p[idx].at;
            total_tat+=p[idx].tat;
            total_rt+=p[idx].rt;
            total_wt+=p[idx].wt;
            total_bt+=p[idx].bt;
            total_idle_time+=p[idx].st-prev;
            is_completed[idx]=1;
            completed++;
            current_time=p[idx].ct;
            prev=current_time;
        }
        else{
             current_time++;
        }
    }
    avg_rt=(float)total_rt/n;
    avg_tat=(float)total_tat/n;
    avg_wt=(float)total_wt/n;
    cpu_utilisation=(total_bt/prev)*100;
    throughput=(float)n/prev;
    cout<<endl;
    cout<<"p_id\t"<<"at\t"<<"bt\t"<<"ct\t"<<"tat\t"<<"wt\t"<<"rt\t"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<endl;
    }
    cout<<"avg_tat="<<avg_tat;
    cout<<endl<<"avg_rt="<<avg_rt;
    cout<<endl<<"avg_wt="<<avg_wt;
    cout<<endl<<"cpu_uti="<<cpu_utilisation;
    cout<<endl<<"throughput="<<throughput;
}