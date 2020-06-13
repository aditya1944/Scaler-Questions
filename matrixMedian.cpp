#include<iostream>
#include<algorithm>
#include<vector>
int customBinary(const std::vector<std::vector<int> >&matx, int num){
    //this function calculates the no. of occurence of num in matx;
    int rows = matx.size();
    int cols = matx[0].size();
    int returnValue = 0;
    //apply binary search
    /*if(num==3){
        std::cout<<cols - (std::upper_bound(matx[0].begin(),matx[0].end(),num)-matx[0].begin());
    }*/
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        returnValue+=(std::upper_bound(matx[rowIndex].begin(),matx[rowIndex].end(),num)-matx[rowIndex].begin());
    }
    //std::cout<<returnValue<<std::endl;
    return returnValue;
}
int solve(const std::vector<std::vector<int> >&matx){
    int returnValue = 0;
    int rows = matx.size();
    int cols = matx[0].size();
    int low = 1, high = 1000000000;
    int desiredNumbersSmaller = ((rows*cols)/2)+1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int countOfNumbersSmallerThanMid = customBinary(matx, mid);
        if(countOfNumbersSmallerThanMid<desiredNumbersSmaller){
            low = mid+1;
        }
        else{
            high = mid-1;
            returnValue = mid;
        }
    }
    return returnValue;
}
int main(){
    int N,M;
    std::cin>>N>>M;
    std::vector<std::vector<int> >matx(N,std::vector<int>(M,0));
    for(int rowIndex = 0;rowIndex<N;++rowIndex){
        for(int colIndex = 0;colIndex<M;++colIndex){
            std::cin>>matx[rowIndex][colIndex];
        }
    }
    int output = solve(matx);
    std::cout<<output<<std::endl;
    return 0;
}