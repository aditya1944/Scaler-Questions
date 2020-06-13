#include<iostream>
#include<vector>
//find minimumSwaps to sort an array
void helper(std::vector<int> &vec, int index, int &noOfNodes, bool &zeroFlag){
    if(vec[index]<0){
        //++noOfNodes;
        return;
    }
    if(vec[index]==0 && zeroFlag==true){
        return;
    }
    ++noOfNodes;
    if(vec[index]==0){
        zeroFlag = true;
    }
    int nextIndex = vec[index];
    vec[index] = vec[index]*-1;
    helper(vec,nextIndex,noOfNodes,zeroFlag);
}
int solve(std::vector<int> &vec){
    //find no. of nodes in cycles
    //subtract 1 from each and add in returnValue;
    int returnValue = 0;
    bool zeroFlag = false;
    for(int index = 0;index<vec.size();++index){
        if(vec[index]>=0){
            int noOfNodes = 0;
            //vec[index]*=-1;
            helper(vec,index,noOfNodes,zeroFlag);
            //std::cout<<noOfNodes<<" ";
            if(noOfNodes>0)
                returnValue+=(noOfNodes-1);
        }
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    int output = solve(arr);
    std::cout<<output<<std::endl;
    return 0;
}