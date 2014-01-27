#include<iostream>
#include<cstdio>
#include<cstdlib>

long long int fib[100]; // array of all fibonacci's
int index = 2; // global iterator

void preprocess(){
	
	long long int first = 0, next = 1, sum;
	
	fib[0] = first;
	fib[1] = next;

	do{
		sum = first + next;
		fib[index] = sum;
		index++;

		first = next;
		next = sum; 
	} while(sum <= 10000000000);

	return;
}

int isFibonacci(long long int num){

	for(int i=0;i<index-1;i++){
		if(fib[i] == num){
			return 1;
		}
	}
	return 0;

}

int main(){
	preprocess();
	long int cases;
	long long int num;
	scanf("%ld",&cases);
	while(cases--){
		scanf("%lld",&num);
		if(isFibonacci(num)){
			printf("IsFibo\n");
		} else {
			printf("IsNotFibo\n");
		}
	}
	return 0;
}