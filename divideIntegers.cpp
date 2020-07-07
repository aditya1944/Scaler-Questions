#include<iostream>
#include<climits>
int divide(int A, int B){
    if(A==INT_MIN && B==-1){
        return INT_MAX;
    }
    if(A==INT_MIN && B==1){
        return INT_MIN;
    }
    long returnValue = 0;
    int sign = 1;
    if(A<0 && B<0){
        //both are negative
        sign = 1;
    }
    else if(A< 0 || B< 0 ){
        sign = -1;
    }
    long dividend = abs((long)A);
    long divisor = abs((long)B);
    if(divisor==1){
        return dividend * sign;
    }
    //A/B
    //cout<<dividend<<" "<<divisor; 
    while(dividend>=divisor){
        long x = 0;
        long temp = divisor;
        while((temp<<1)<=dividend){
            temp = temp<<1;
            ++x;
        }
        returnValue+=(1<<x);
        dividend-=temp;
    }
    return returnValue *sign;
}