#include<stdlib.h>
#include <stdbool.h>
#include<stdio.h>
#include<string.h>
int current_process=0;
struct fixed{
	int pri,burst,arrival,waiting,turn;
	char id[5];
}fix[10];

bool arrival_time(int curr,int in,int curr_in){
	int i=curr_in;
	for(;i<=in;i++){
		if(curr==fix[i].arrival)
			return true;
		else
			return false;
	}
}


bool compare_priority(int a,int b){// case 1,2,3,0
	int temp=fix[a].pri;
	int i=0;
	int flag=0;
	for(;i<=b;i++){
		if(temp>fix[i].pri){
		current_process=i;
		temp=fix[i].pri;
		}	
		else
		flag=1;;
	}
	if(flag==0)
		return true;
	else
		return false;
}

void deleteprocess(int a, int b){
	int i=b;
	for(;i<=a-1;i++){
		fix[i]=fix[i+1];
	}
}

void prioritycheck(int a,int b){//del 0 and 2,1,3
	int i=0;
	int priority=fix[i].pri;
	for(;i<=a-1;i++){
		if(priority>fix[i].pri && b>=fix[i].arrival){
			priority=fix[i].pri;
			current_process=i;
		}
		else
		current_process=i;
	}
}

struct round{
	int arrival,waiting,turn,burst;
	char id[5];
}rou[10];

void findavgTime(int n,int quantum){
	int wt[l],tat[l],total_wt=0,total_tat=0;
}

void main(){
	struct fixed temp;
	int i=0,j=0,k=0,l=0;//l is used for round robin index
	int lim,flag1=0,flag2=0,avg_wait,current_time=0,curr_in,comparing_index,count=0,quant=1;
	
	printf("\t\t\t\t\t\tThis is a simulation for fixed priority and round robin algorithm\n");
	printf("\n Enter total number of process for fixed priority queue:- \n");
	scanf("%d",&lim);
	
	for(i=0;i<lim;i++){
		printf("Enter the process id:-");
		fflush(stdin);
		gets(fix[i].id);
		printf("\nEnter the process arrival time:- ");
		fflush(stdin);
		scanf("%d",&fix[i].arrival);
		printf("\nEnter the process's burst time it should be multiple of 2:- ");
		fflush(stdin);
		scanf("%d",&fix[i].burst);
		printf("\nenter the process's priority:- ");
		fflush(stdin);
		scanf("%d",&fix[i].pri);
	}
	
	for(i=0;i<lim-1;i++){   			//for sorting arrival time for fixed priority queue
		for(j=0;j<lim-1;j++){
			if(fix[j].arrival>fix[j+1].arrival){
				temp=fix[j+1];
				fix[j+1]=fix[j];
				fix[j]=temp;
			}
		}
	}
	for(i=0;i<lim;i++){
		printf("%d\n",fix[i].arrival);
	}
	flag1=lim;
	while(flag1!=0){
		count=0;
		k=0;//
		comparing_index=j;
		curr_in=j;
		int tb;
		int tmb=fix[j].burst;//temporary burst time for loop
		tb=tmb;//temp burst time for decreasing burst time
		for(k=0;k<=tmb;k++){
			tb--;
			current_time++;
			if(arrival_time(current_time,(comparing_index+1),curr_in)){
				comparing_index=comparing_index+1;
				if(compare_priority(j,comparing_index)){
					//if(tb!=0)
					rou[l].burst=tb;
					rou[l].arrival=fix[j].arrival;
					strcpy(rou[l].id,fix[j].id);
					deleteprocess(flag1,j);
					l++;
					comparing_index--;
					current_process--;
					count=1;//it is indicating that a process is deleted from the queue
					break;//bacause current process is move to round robin queue
				}
			}
			
		}
		if(count==0){
			deleteprocess(flag1,j);//
			prioritycheck((flag1-1),current_time);
			j=current_process;	
		}
		else{
			j=current_process;
		}
		flag1--;
	}
	for(i=0;i<l;i++){
		printf("%c",rou[i].arrival);
		printf("\n");
	}
	findavgTime(l,quant);
	
}

