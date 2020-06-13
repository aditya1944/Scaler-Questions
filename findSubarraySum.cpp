#include<iostream>
#include<vector>
std::vector<int> solve(std::vector<int> &vec, int K){
    int lowPtr = 0;
    int highPtr = 1;
    int currSum = vec[lowPtr] + vec[highPtr];
    while(highPtr<vec.size() && lowPtr<=highPtr){
        if(currSum==K){
            break;
        }
        else if(currSum<K){
            ++highPtr;
            currSum+=vec[highPtr];
        }
        else{
            ++lowPtr;
            currSum-=vec[lowPtr-1];
        }
    }
    if(currSum!=K){
        std::vector<int> returnValue(1);
        returnValue[0] = -1;
        return returnValue;
    }
    //std::cout<<"lowPtr : "<<lowPtr<<"highPtr :"<<highPtr<<std::endl;
    std::vector<int> returnValue(vec.begin()+lowPtr, vec.begin()+highPtr+1);
    return returnValue;
}
int main(){
    int N,K;
    std::cin>>N;
    std::vector<int> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    std::cin>>K;
    std::vector<int> output = solve(arr, K);
    for(int x:output){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    return 0;
}