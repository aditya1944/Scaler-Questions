#include<iostream>
#include<vector>
//make a maxHeap
void heapify(std::vector<int> &vec,int right){
    for(int index = right;index>0;--index){
        int parentIndex = (index-1)/2;
        if(vec[parentIndex]<vec[index]){
            std::swap(vec[parentIndex],vec[index]);
        }
    }
}
void heapSort(std::vector<int> &vec){
    int right = vec.size()-1;
    while(right>0){
        heapify(vec,right);
        std::swap(vec[0],vec[right]);
        --right;
    }
}
int main(){
    std::vector<int> vec  = {8,9,0,6,5,4,8,1,2};
    heapSort(vec);
    for(auto &val : vec){
        std::cout<<val<<" ";
    }
}