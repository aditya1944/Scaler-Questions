#include<iostream>
int rangeBitwiseAnd(int m ,int n){
    //find common prefix of both of these numbers
    //that will suffice
    int count = 0;
    while(m!=n){
        m = m>>1;
        n = n>>1;
        ++count;
    }
    m = m<<count;
    return m;
}