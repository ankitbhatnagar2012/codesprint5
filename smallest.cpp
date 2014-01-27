#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<math.h>
#define MAX 35000

using namespace std;

typedef unsigned long long int uint64;

uint64 db[MAX+5];

void preprocess(){

	// build a set of MAX number of integers with 9's & 0's only
	uint64 num, itr, toStart;
	uint64 currentExponent = 1;
	uint64 indexWrite = 0;
	uint64 indexRead = 0;

	while(indexWrite < MAX){
		
		toStart = 9 * currentExponent;
		db[indexWrite] = toStart;
		indexWrite++;
		
		for(itr=0; itr<indexRead; itr++){
			if(indexWrite < MAX){
				num = toStart + db[itr];
				db[indexWrite] = num;
				indexWrite++;	
			} else break;
			
		}

		currentExponent = currentExponent * 10;
		indexRead = indexWrite;

	}

}

uint64 findSmallestMultiple(int n){

	int flag = 0;
	uint64 itr;
	for(itr=0;itr<MAX;itr++){

		if(db[itr] % (uint64)n == 0){
			
			printf("%llu\n",db[itr]);
			flag = 1;
			break;
			
		}

	}
	if(flag == 0){
		printf("beyond!\n");
	}

}

int main(){
	int cases,n;
	preprocess();
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&n);
		findSmallestMultiple(n);
	}
	return 0;
}