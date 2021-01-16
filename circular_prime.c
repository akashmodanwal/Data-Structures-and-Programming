#include<stdio.h>
#include<math.h>

int flag;

void isprime(long int n){
	int i;
	flag=1;
    for (i = 2; i <= n / 2; ++i){
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
}
int circular_prime(long int n){
	isprime(n);
	if(flag==1){
	
	int digits =0,i;
	int t=n;
	while(t>0){
		digits++;
		t=t/10;
	}
	int pow_ten=pow(10,digits-1);
	for(i=0;i<digits-1;i++){
		int first_digit=n/pow_ten;
		long int new_number=((n*10)+first_digit)-(first_digit*pow_ten*10);
		n=new_number;
		isprime(n);
		if(flag==0){
			return 0;
		}
		
	}

}
}
//driver funtion
int main(){
	long int n;
	scanf("%li",&n);
	if(n<=0){
		printf("-1");
	}
	else if(n==1){
		printf("0");
	}
	else{
	
	circular_prime(n);		
	if(flag==0){
		printf("0");
	}
	else{
		printf("1");
	}
}
}
