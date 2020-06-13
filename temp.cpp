#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
int helper(int painters, int maxLength, std::vector<int> &C, int &returnValue){
    int painterRequired = 0;
    int index = 0;
    for(int index = 0;index<C.size();){
        int currLengthPainted = 0;
        while(index<C.size()){
            if(currLengthPainted+C[index]>maxLength){
                break;
            }
            currLengthPainted += C[index];
            ++index;
        }
        if(returnValue<currLengthPainted){
            returnValue = currLengthPainted;
        }
        ++painterRequired;
    }
    if(painterRequired>painters){
        return 1;
    }
    return 2;
}
int solve(int A, int B, std::vector<int> &C){
    int left = INT_MIN;
    int right = 0;
    for(int index = 0;index<C.size();++index){
        left = std::max(left, C[index]);
        right = right + C[index];
    }
    if(A>=C.size()){
        return left*B;
    }
    int returnValue = right;
    while(left<=right){
        //std::cout<<left<<" "<<right;
        int mid = left + (right - left)/2;
        int temp = 1;
        if(helper(A, mid, C, temp)==1){
            //if helper returns 1 current mid is not enough increase the mid
            left = mid+1;
        }
        else{
            //if helper returns 2 current mid is enough decrease the mid
            right = mid-1;
            returnValue = std::min(returnValue, temp);
        }
    }
    return returnValue*B;
}
int main(){
    int noOfPainters, unitTime, noOfBoards;
    std::cin>>noOfPainters>>unitTime>>noOfBoards;
    std::vector<int> boards(noOfBoards,0);
    for(int index = 0;index<noOfBoards;++index){
        std::cin>>boards[index];
    }
    int output = solve(noOfPainters, unitTime, boards);
    std::cout<<output<<std::endl;
    return 0;
}