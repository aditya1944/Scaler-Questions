#include<iostream>
#include<vector>
int main(){
    std::vector<int> arr = {1,1,0};
    int bitMask = 0;
    for(int index = 0;index<arr.size();++index){
        if(arr[index]){
            bitMask = bitMask | (1<<index);
        }
        
    }
    std::cout<<bitMask;
    return 0;
}