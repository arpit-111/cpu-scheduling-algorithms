#include <iostream>
#include<iomanip>
#include<string.h>
using namespace std;
struct process{
    int id;
    int at,bt;
    int st,ct,tat,wt,rt;
    //int rem_bt;
};
int main(){
    int n;
    cout<<"enter no of processes=";
    cin>>n;
    int rem_bt[n];
    int is_completed[n];
    struct process p[n];
    
    for(int i=0;i<n;i++){
        cout<<"enter at of process"<<""<<i+1<<"=";
        cin>>p[i].at;
        cout<<"enter bt of process"<<""<<i+1<<"=";
        cin>>p[i].bt;
        p[i].id=i+1;
        rem_bt[i]=p[i].bt;
        is_completed[i]=0;
    }
    
    int current_time=0;
    int prev=0;
    int completed=0;
    while(completed!=n){
        int idx=-1;
        int min=100000;
        for(int i=0;i<n;i++){
            if(p[i].at<=current_time && is_completed[i]==0){
                if(rem_bt[i]<min){
                    idx=i;
                    min=rem_bt[i];
                }
                if(rem_bt[i]==min){
                    if(p[i].at<p[idx].at){
                        idx=i;
                        min=rem_bt[i];
                    }
                }
            }
        }
        
        cout<<idx;
    
        
        if(idx!=-1){
            if(rem_bt[idx]==p[idx].bt){
                p[idx].st=current_time;
                current_time++;
                rem_bt[idx]--;
                prev=current_time;
            }
            else{
                current_time++;
                rem_bt[idx]--;
                prev=current_time;
            }
            if(rem_bt[idx]==0){
                p[idx].ct=current_time;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;
                p[idx].rt=p[idx].st-p[idx].at;
                completed++;
                is_completed[idx]=1;
            }
        }
        else{
            current_time++;
        }
    }
    cout<<endl<<"id\t"<<"at\t"<<"bt\t"<<"st\t"<<"ct\t"<<"tat\t"<<"wt\t"<<"rt\t";
    for(int i=0;i<n;i++){
        cout<<endl<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t";
    }
}