#include<stdio.h>
#include<conio.h>
int main(){
	printf("\t\t\tCPU SCHEDULER\n");
	printf("**Note Higher Priority Number will be Executed First**\n");
	int quantum,n,i,p[10],a[10],j,temp,pid[10],b[10],na[10],np[10],time=0,total=0,status[10],cur=0,next,npr,ext=0,slot=0,comp[10],tat[10],wt[10],fb[10],last[10],no[10];
	printf("ENTER QUANTUM TIME :- \n");
	scanf("%d",&quantum);
	printf("ENTER NO OF PROCESS :- \n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("ENTER ARRIVAL TIME FOR P[%d] :-\n",i+1);
		pid[i] = i+1;
		status[i] = 0;
		scanf("%d",&a[i]);
		printf("ENTER BURST TIME OF P[%d] :-\n",i+1);
		scanf("%d",&b[i]);
		fb[i] = b[i];
		printf("ENTER PRIORITY OF P[%d] :-\n",i+1);
		scanf("%d",&p[i]);	
	}
	printf("\n\n\t\tYOU HAVE ENTERED\n\n");
	printf(" PROCESS ID \t ARRIVAL TIME \t BURST TIME \t PRIORITY \n");
	for(i=0;i<n;i++){
	printf("P[%d] \t\t %d \t\t %d \t\t %d\n",pid[i],a[i],b[i],p[i]);
	}
	
	

        for (i = 0; i < n; ++i) 
        {
            for (j = i + 1; j < n; ++j)
            {
                if (a[i]>a[j]) 
                {
                    temp =  a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    temp =  p[i];
                    p[i] = p[j];
                    p[j] = temp;
                    temp =  pid[i];
                    pid[i] = pid[j];
                    pid[j] = temp; 
                    temp =  b[i];
                    b[i] = b[j];
                    b[j] = temp; 
                    temp =  fb[i];
                    fb[i] = fb[j];
                    fb[j] = temp;
                }else if(a[i]==a[j]){
                	if(p[i]<p[j]){
                		temp =  a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    temp =  p[i];
                    p[i] = p[j];
                    p[j] = temp;
                    temp =  pid[i];
                    pid[i] = pid[j];
                    pid[j] = temp; 
                    temp =  b[i];
                    b[i] = b[j];
                    b[j] = temp;
					temp =  fb[i];
                    fb[i] = fb[j];
                    fb[j] = temp;	
					}
				}
 
            }
 
        }
	
	printf("\n\n\t\tMODIFIED ACCORDING TO PRIORITY\n\n");
		printf(" PROCESS ID \t ARRIVAL TIME \t BURST TIME \t PRIORITY \n");
	for(i=0;i<n;i++){
	printf("P[%d] \t\t %d \t\t %d \t\t %d\n",pid[i],a[i],b[i],p[i]);
	}
	
	for(i=0;i<n;i++){
		if(b[i]%quantum==0){
			slot = slot+b[i]/quantum;
		}else{
			slot = slot+(b[i]/quantum)+1;
		}
	}
	for(i=0;i<slot;i++){
		printf("\nRunning p[%d]\n",pid[cur]);
		if(b[cur]<quantum){
			ext = b[cur];
		}else{
			ext = quantum;
		}
		b[cur] = b[cur]-ext;
		printf("Executed From %d to %d\n",time,time+ext);
		printf("Remaining Burst is %d\n",b[cur]);
		printf("--------------------------\n");
		if(b[cur]<=0){
			p[cur]=-100;
			
			
		}
		time = time+ext;
		if(b[cur]<=0){
			comp[cur]=time;
			last[cur]=time-ext;
		}
		for(j=0;j<n;j++){
			if(a[j]<=time && p[j]>p[cur] && b[j]>0){
				cur = j;
			}
		}
	}
	printf("\n\n\t Turn Around Times\n");
	for(i=0;i<n;i++){
		tat[i] = comp[i]-a[i];
		printf("Turn Around Time of P[%d] is %d\n",pid[i],tat[i]);	
	}
	printf("\n\n \t Waiting Times\n\n");
	for(i=0;i<n;i++){
		int x = comp[i]-(a[i]+fb[i]);
		printf("Waiting Time of P[%d] is %d \n",pid[i],x);
	}
	
}