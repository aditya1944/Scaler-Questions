#include<iostream>
#include<vector>
#include<climits>
std::vector<int> solve(std::vector<int> &arr, int K){
    int left = 0, right = -1, maxWindowLength = INT_MIN, currentWindowLength = 0,finalLeft, finalRight,zeroInRange = 0;
    /*if(arr[0]==0){
        ++currZeroesinRange;
    }*/
    /*if(arr[0]==0){
        ++currZeroesinRange = 1;
    }*/
    //std::cout<<currentWindowLength;
    while(right+1<arr.size()){	
        if(zeroInRange<=K){
            ++right;
            if(arr[right]==0){
                ++zeroInRange;
            }
            //++right;
        }
        if(zeroInRange>K){
            if(arr[left]==0){
                --zeroInRange;
            }
            ++left;
        }
        currentWindowLength = right-left+1;
        //std::cout<<currentWindowLength;
        if(currentWindowLength>maxWindowLength){
            maxWindowLength = currentWindowLength;
            finalLeft = left;
            finalRight = right;
        }
    }
    std::vector<int> returnValue;
    for(int index = finalLeft;index<=finalRight;++index){
        if(index!=arr.size())
            returnValue.push_back(index);
    }
    return returnValue;
}
int main(){
    int N,K;
    std::cin>>N>>K;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<int> output = solve(vec,K);
    for(int& x: output){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    return 0;
}