#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<math.h>

#define MOD 1000000007LL
#define MAX 2000005

using namespace std;

typedef unsigned long long int uint64;
typedef unsigned long int uint32;

uint64 n,m; // global rows | columns 	

uint64 fact[MAX];
uint64 ifact[MAX];

uint64 inverse(uint64 a){ // computes ( a^MOD-2 ) % MOD using exponentiation by repeated squaring
	
	uint64 result = 1;
	uint64 exp = MOD-2;
 
	while (exp){
		if (exp%2)
			result = (result*a)%MOD;
		exp /= 2;
		a = (a*a)%MOD;
	}
 
	return result;
}

void preprocess(){

	fact[0] = ifact[0] = 1;
	uint64 i;
	for(i=1;i<=MAX;i++){

		fact[i] = (i*fact[i-1])%MOD;
		ifact[i] = inverse(fact[i]); // (fact[i]^MOD-2)%MOD

	}
}

uint64 choose(uint64 a, uint64 b){

	return (((fact[a]*ifact[b])%MOD)*ifact[a-b])%MOD;

}

int main(){
	int cases;
	uint64 result,a,b;
	preprocess();
	scanf("%d",&cases);
	while(cases--){
		scanf("%llu %llu",&a,&b);
		printf("%llu\n",choose(a+b-2, a-1));
	}
	return 0;
}