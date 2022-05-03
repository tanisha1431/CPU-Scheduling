#include<stdio.h>
struct Scheduling
{
    int ArrivalTime,WaitingTime,TurnAroundTime,BurstTime;
};

struct Scheduling a[10];
void fcfs()
{
    int n;
    int burst=0,cmpl_T;
    float Average_WT,Average_TT,Total=0;
    printf("Enter number of process\n");
    scanf("%d",&n);
    printf("Enter Arrival time and Burst time of the process\n");
    printf("At BT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].ArrivalTime,&a[i].BurstTime);
    }


    for(int i=0;i<n;i++)
    {
        if(i==0)
            a[i].WaitingTime=a[i].ArrivalTime;
        else
            a[i].WaitingTime=burst-a[i].ArrivalTime;
        burst+=a[i].BurstTime;
        Total+=a[i].WaitingTime;
    }
    Average_WT=Total/n;


    cmpl_T=0;
    Total=0;
    for(int i=0;i<n;i++)
    {
        cmpl_T+=a[i].BurstTime;
        a[i].TurnAroundTime=cmpl_T-a[i].ArrivalTime;
        Total+=a[i].TurnAroundTime;
    }
    Average_TT=Total/n;



    printf("Process ,  Waiting_time ,  TurnA_time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\n",i+1,a[i].WaitingTime,a[i].TurnAroundTime);
    }
    printf("Average waiting time is : %f\n",Average_WT);
    printf("Average turn around time is : %f\n",Average_TT);

}

struct process1
{
    int id,WT,ArrivalTime,BurstTime,TurnAroundTime;
};
struct process1 a1[10];


void swap(int *b,int *c)
{
    int tem;
    tem=*c;
    *c=*b;
    *b=tem;
}

void sjfnp()
{
    int n,check_ar=0;
    int Cmp_time=0;
    float Total_WT=0,Total_TAT=0,Average_WT,Average_TAT;
    printf("Enter the number of process \n");
    scanf("%d",&n);
    printf("Enter the Arrival time and Burst time of the process\n");
    printf("AT BT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a1[i].ArrivalTime,&a1[i].BurstTime);
        a1[i].id=i+1;

        if(i==0)
         check_ar=a1[i].ArrivalTime;

        if(check_ar!=a1[i].ArrivalTime )
         check_ar=1;

    }

    if(check_ar!=0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(a1[j].ArrivalTime>a1[j+1].ArrivalTime)
                {
                      swap(&a1[j].id,&a1[j+1].id);
                      swap(&a1[j].ArrivalTime,&a1[j+1].ArrivalTime);
                      swap(&a1[j].BurstTime,&a1[j+1].BurstTime);
                }
            }
        }
    }


    if(check_ar!=0)
    {
        a1[0].WT=a1[0].ArrivalTime;
        a1[0].TurnAroundTime=a1[0].BurstTime-a1[0].ArrivalTime;
        Cmp_time=a1[0].TurnAroundTime;
        Total_WT=Total_WT+a1[0].WT;
        Total_TAT=Total_TAT+a1[0].TurnAroundTime;
        for(int i=1;i<n;i++)
        {
            int min=a1[i].BurstTime;
            for(int j=i+1;j<n;j++)
            {
                if(min>a1[j].BurstTime && a1[j].ArrivalTime<=Cmp_time)
                {
                      min=a1[j].BurstTime;
                      swap(&a1[i].id,&a1[j].id);
                      swap(&a1[i].ArrivalTime,&a1[j].ArrivalTime);
                      swap(&a1[i].BurstTime,&a1[j].BurstTime);
                }

            }
            a1[i].WT=Cmp_time-a1[i].ArrivalTime;
            Total_WT=Total_WT+a1[i].WT;

            Cmp_time=Cmp_time+a1[i].BurstTime;


            a1[i].TurnAroundTime=Cmp_time-a1[i].ArrivalTime;
            Total_TAT=Total_TAT+a1[i].TurnAroundTime;

        }
    }


    else
    {
        for(int i=0;i<n;i++)
        {
            int min=a1[i].BurstTime;
            for(int j=i+1;j<n;j++)
            {
                if(min>a1[j].BurstTime && a1[j].ArrivalTime<=Cmp_time)
                {
                      min=a1[j].BurstTime;
                      swap(&a1[i].id,&a1[j].id);
                      swap(&a1[i].ArrivalTime,&a1[j].ArrivalTime);
                      swap(&a1[i].BurstTime,&a1[j].BurstTime);
                }

            }
            a1[i].WT=Cmp_time-a1[i].ArrivalTime;


            Cmp_time=Cmp_time+a1[i].BurstTime;


            a1[i].TurnAroundTime=Cmp_time-a1[i].ArrivalTime;
            Total_WT=Total_WT+a1[i].WT;
            Total_TAT=Total_TAT+a1[i].TurnAroundTime;

        }

    }

    Average_WT=Total_WT/n;
    Average_TAT=Total_TAT/n;


    printf("The process are\n");
    printf("ID WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",a1[i].id,a1[i].WT,a1[i].TurnAroundTime);
    }

    printf("Avg waiting time is:- %f\n",Average_WT);
    printf("Avg turn around time is:- %f",Average_TAT);

}
struct process2
{
    int WaitingTime,ArrivalTime,BurstTime,TurnAroundTime;
};

struct process2 a2[10];

void sjfp()
{
    int n,temp[10];
    int count=0,t=0,short_P;
    float total_WT=0, total_TAT=0,Average_WT,Average_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time of the process\n");
    printf("AT WT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a2[i].ArrivalTime,&a2[i].BurstTime);


        temp[i]=a2[i].BurstTime;
    }


    a2[9].BurstTime=10000;

    for(t=0;count!=n;t++)
    {
        short_P=9;
        for(int i=0;i<n;i++)
        {
            if(a2[i].BurstTime<a2[short_P].BurstTime && (a2[i].ArrivalTime<=t && a2[i].BurstTime>0))
            {
                short_P=i;
            }

        }

        a2[short_P].BurstTime=a2[short_P].BurstTime-1;


        if(a2[short_P].BurstTime==0)
        {

            count++;
            a2[short_P].WaitingTime=t+1-a2[short_P].ArrivalTime-temp[short_P];
            a2[short_P].TurnAroundTime=t+1-a2[short_P].ArrivalTime;


            total_WT=total_WT+a2[short_P].WaitingTime;
            total_TAT=total_TAT+a2[short_P].TurnAroundTime;
        }



    }
    Average_WT=total_WT/n;
    Average_TAT=total_TAT/n;


    printf("Id WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",i+1,a2[i].WaitingTime,a2[i].TurnAroundTime);
    }
    printf("Avg waiting time of the process is %f\n",Average_WT);
    printf("Avg turn around time of the process %f\n",Average_TAT);

}
struct process3
{
    int id,ArrivalTime,BurstTime,WaitingTime,TurnAroundTime;
};

struct process3 a3[10];

int queue[100];
int front=-1;
int rear=-1;


void insert(int n)
{
    if(front==-1)
     front=0;
    rear=rear+1;
    queue[rear]=n;
}


int delete()
{
    int n;
    n=queue[front];
    front=front+1;
    return n;
}
void rr()
{
    int n,TQ,p,TIME=0;
    int temp[10],exist[10]={0};
    float total_wt=0,total_tat=0,Average_WT,Average_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time of the process\n");
    printf("AT BT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a3[i].ArrivalTime,&a3[i].BurstTime);
        a3[i].id=i;
        temp[i]=a3[i].BurstTime;
    }
    printf("Enter the time quantum\n");
    scanf("%d",&TQ);

    insert(0);
    exist[0]=1;

    while(front<=rear)
    {
        p=delete();
        if(a3[p].BurstTime>=TQ)
        {
            a3[p].BurstTime=a3[p].BurstTime-TQ;
            TIME=TIME+TQ;
        }
        else
        {
            TIME=TIME+a3[p].BurstTime;
            a3[p].BurstTime=0;
        }



        for(int i=0;i<n;i++)
        {
            if(exist[i]==0 && a3[i].ArrivalTime<=TIME)
            {
                insert(i);
                exist[i]=1;
            }
        }

        if(a3[p].BurstTime==0)
        {
            a3[p].TurnAroundTime=TIME-a3[p].ArrivalTime;
            a3[p].WaitingTime=a3[p].TurnAroundTime-temp[p];
            total_tat=total_tat+a3[p].TurnAroundTime;
            total_wt=total_wt+a3[p].WaitingTime;
        }
        else
        {
            insert(p);
        }
    }

    Average_TAT=total_tat/n;
    Average_WT=total_wt/n;


    printf("ID WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d  %d  %d\n",a3[i].id,a3[i].WaitingTime,a3[i].TurnAroundTime);
    }
    printf("Average waiting time of the processes is : %f\n",Average_WT);
    printf("Average turn around time of the processes is : %f\n",Average_TAT);

}

int main()
{
    int c;
    printf("Enter your choice: \n1) First come first served \n 2) Shortest job first(non pre-emptive) \n 3)Shortest job first preemptive \n 4)Round robin\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        fcfs();
        break;
    case 2:
        sjfnp();
        break;
    case 3:
        sjfp();
        break;
    case 4:
        rr();
        break;
    }


}
