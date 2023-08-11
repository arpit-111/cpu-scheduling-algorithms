#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
struct process{
    int id,at,bt,pr;
    int st,ct,tat,wt,rt,rem_bt;
};
int main(){
    int n;
    cout<<"enter no of processes=";
    cin>>n;
    int is_completed[n];
    process p[100];
    for(int i=0;i<n;i++){
        cout<<"enter at of process"<<""<<i+1<<"=";
        cin>>p[i].at;
        cout<<"enter bt of process"<<""<<i+1<<"=";
        cin>>p[i].bt;
        cout<<"enter pr of process"<<""<<i+1<<"=";
        cin>>p[i].pr;
        p[i].rem_bt=p[i].bt;
        p[i].id=i+1;
        is_completed[i]=0;
    }
    int completed=0;
    int current_time=0;
    int prev=0;

    while(completed!=n){
        int idx=-1;
        int max=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=current_time && is_completed[i]==0){
                if(p[i].pr>max){
                    idx=i;
                    max=p[i].pr;
                }
                if(p[i].pr==max){
                    if(p[i].at<p[idx].at){
                        idx=i;
                        max=p[i].pr;
                    }
                }
            }
        }
        if(idx!=-1){
            if(p[idx].rem_bt==p[idx].bt){
                p[idx].st=current_time;

            }
            current_time++;
            p[idx].rem_bt--;
            prev=current_time;
            if(p[idx].rem_bt==0){
                p[idx].ct=current_time;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;
                p[idx].rt=p[idx].st-p[idx].at;
                is_completed[idx]=1;
                completed++;
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