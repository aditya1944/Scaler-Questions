#include<iostream>
#include<vector>
bool isPossible(const std::vector<int> &positions, int noOfCows, const int &distance){
    bool returnValue = false;
    //place 1st cow at index 0;
    --noOfCows;
    int lastIndex = 0;
    for(int index = 1;index<positions.size();++index){
        if(positions[index]- positions[lastIndex]>=distance){
            //place the cow at this index
            lastIndex = index;
            --noOfCows;
        }
        if(noOfCows==0){
            returnValue = true;
            break;
        }
    }
    return returnValue;
}
int solve(const std::vector<int> &positions,const int &noOfCows){
    int low = 0,high = positions[positions.size()-1] - positions[0];
    int returnValue;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(positions,noOfCows,mid)){
            low = mid+1;
            returnValue = mid;
        }
        else{
            high = mid-1;
        }
    }
    return returnValue;
}
int main(){
    int N,noOfCows;
    std::cin>>N;
    std::vector<int> positions(N,0);
    for(int index = 0;index<N;++index){
        std::cin>>positions[index];
    }
    std::cin>>noOfCows;
    int output = solve(positions, noOfCows);
    std::cout<<output<<std::endl;
    return 0;
}