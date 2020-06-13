#include<iostream>
int solve(std::string A) {
    if(A.size()<=3){
        int num = std::stoi(A);
        if(num%8==0){
            return 1;
        }
        return 0;
    }
    else{
        std::string str = "";
        str+=A[A.size()-3];
        str+=A[A.size()-2];
        str+=A[A.size()-1];
        int num = stoi(str);
        if(num%8==0){
            return 1;
        }
        return 0;
    }
}