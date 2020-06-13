#include<iostream>
#include<vector>
#include<climits>
#define mod 10000003
int findPaintersRequired(std::vector<int> &boards, int permissibleUnitToPaint, long long &minimumTime){
    int paintersRequired = 0;
    for(int index = 0;index<boards.size();){
        int currBoardUnitPainted = 0;
        while(index<boards.size()){
            if(currBoardUnitPainted + boards[index]>permissibleUnitToPaint){
                break;
            }
            currBoardUnitPainted+=boards[index];
            ++index;
        }
        if(minimumTime<currBoardUnitPainted){
            minimumTime = currBoardUnitPainted;
        }
        ++paintersRequired;
    }
    //std::cout<<paintersRequired<<std::endl;
    return paintersRequired;
}
int solve(int noOfPainters, int unitTime, std::vector<int> &boards){
    //find answer space
    int low = INT_MIN,high = 0;
    long long returnValue;
    for(int index = 0;index<boards.size();++index){
        low = std::max(low, boards[index]);
        high += boards[index];
    }
    if(noOfPainters>=boards.size()){
        return ((low%mod) * (unitTime%mod))%mod;
    }
    while(low<=high){
        long long mid = low + (high-low)/2;
        long long minimumTime = 1;
        int paintersRequired = findPaintersRequired(boards, mid, minimumTime);
        //std::cout<<"low: "<<low<<"mid: "<<mid<<"high: "<<high<<"minimum Time: "<<minimumTime<<"painter required: "<<paintersRequired<<std::endl;
        if(paintersRequired>noOfPainters){
            low = mid+1;
        }
        else{
            high = mid-1;
            if(minimumTime<returnValue)
                returnValue = minimumTime;
        }
    }
    returnValue = ((returnValue%mod) * (unitTime%mod))%mod;
    return returnValue;
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