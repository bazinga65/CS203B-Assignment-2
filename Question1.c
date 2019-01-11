#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int n=10000000,t=1000;
int arr[10000000],cnt[10000000];

void distribute(int arr[], int n){
	
	int i;
	
	for(i=0;i<n;i++){	//uniform random distribution
		arr[i]=rand()%n;
	}
	
	return;
}

int max(int arr[],int n){	//maximum load on any server
	
	int i,cnt[n],max=0;
	
	for(i=0;i<n;i++){
		cnt[i]=0;
	}
	
	for(i=0;i<n;i++){
		cnt[arr[i]]++;
		if(cnt[arr[i]]>max){
			max=cnt[arr[i]];
		}
	}
	
	return max;
}

int main()
{
	srand(time(0));
	
	int i,j;
	
	for(i=0;i<n;i++){ //initiate
		cnt[i]=0;
	}
	
	for(j=1;j<=t;j++){
		distribute(arr,n); //each client gives its job to a server
		cnt[max(arr,n)]++; //counting the times cnt[i] is the random variable

	}
	
	for(i=0;i<50;i++){
		printf("%d %.4f\n",i,(cnt[i]/1.0)/t);	//probability output
	}
	
	
	return 0;
}
