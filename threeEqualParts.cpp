#include<vector>
#include<iostream>
#include<algorithm>
std::vector<int> threeEqualParts(std::vector<int>& A) {
        int noOfOnes =  0;
        std::vector<int> vec{-1,-1};
        for(int index = 0;index<A.size();++index){
            noOfOnes+=A[index];
        }
        if(noOfOnes%3!=0){
            //cout<<noOfOnes;
            return vec;
        }
        int lastZeroes = 0;
        int index = A.size()-1;
        while(index>=0 && A[index]==0){
            ++lastZeroes;
            --index;
        }
        //cout<<lastZeroes;
        if(lastZeroes==A.size()){
            //all numbers are 0
            vec[0] = 0;
            vec[1] = A.size()-1;
            return vec;
        }
        int T = noOfOnes/3,t = 0;
        //determine first Interval;
        //[i1, j1], [i2, j2], [i3, j3];
        //upto first interval no. of ones should be T
        //we have to return j1 and i3
        //[], 
        int i1, j1, i2,j2,i3,j3;
        for(int index = 0;index<A.size();++index){
            if(A[index]==1){
                t+=1;
                if(t==1){
                    i1 = index;
                }
                if(t==T){
                    j1 = index;
                }
                if(t==T+1){
                    i2 = index;
                }
                if(t==2*T){
                    j2 = index;
                }
                if(t==2*T+1){
                    i3 = index;
                }
                if(t==3*T){
                    j3 = index;
                }
            }
        }
        if(!std::equal(A.begin()+i1, A.begin()+j1,A.begin()+i2, A.begin()+j2) || !(std::equal(A.begin()+i1, A.begin()+j1,A.begin()+i3, A.begin()+j3))){
            return vec;
        }
        //compare no. of zeroes
        int noOfZeroesBetweenFirstAndSecond = i2-j1-1;
        int noOfZeroesBetweenThirdAndSecond = i3-j2-1;
        if(noOfZeroesBetweenFirstAndSecond!=lastZeroes || noOfZeroesBetweenThirdAndSecond!=lastZeroes){
            return vec;
        }
        vec[0] = j1 + lastZeroes;
        vec[1] = j2 + lastZeroes+1;
        return vec;
    }