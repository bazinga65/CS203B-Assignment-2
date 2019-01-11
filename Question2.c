#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int n=1200000;
int ppl[1200000];

void tell(int ppl[], int a, int n){	// a tells a random person but not to self
	
	int r=rand()%n;
	
	while(r==a){
		r=rand()%n;
	}
	if(ppl[r]==0){
	ppl[r]=2;
	}
	
	return;
}

int check(int ppl[], int n){	//checks whether the whole town knows the news or not
	
	int i;
	
	for(i=0;i<n;i++){
		if(ppl[i]==2){
			ppl[i]=1;
		}
	}
	
	for(i=0;i<n;i++){
		if(ppl[i]==0){
			return 0;
	}
	}
	
	return 1;
}

int days(int n){	//outputs value of days for an experiment
    
    int days=0,i;
    
    for(i=0;i<n;i++){
		ppl[i]=0;
	}

	ppl[0]=1;
	
	while(check(ppl,n)==0){	//check at the start of every day
		for(i=0;i<n;i++){
			if(ppl[i]==1){
				tell(ppl,i,n);
			}
		}
		days++;
	
	}
	return days;
}

int main()
{	
	srand(time(0));
	
	int i;
	int tcases=1000;
	
	for(i=1;i<=tcases;i++){
	printf("%d\n",days(n));	//experiment performed 'tcases' times and we get sample space of X, we calculated the distribution separately using MS Excel
	}
	
	return 0;
}