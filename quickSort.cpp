#include<iostream>
#include<vector>

int partition(std::vector<int> &vec, int left, int right){
    int pivot = vec[right];
    int i,j;
    i = j = left;
    while(j<=right-1){
        if(vec[j]<=pivot){
            std::swap(vec[i],vec[j]);
            ++i;
        }
        ++j;
    }
    std::swap(vec[i],vec[right]);
    return i;
}
void helper(std::vector<int> &vec,int left, int right){
    if(left>=right){
        return;
    }
    int partitionIndex = partition(vec,left,right);
    helper(vec,left,partitionIndex-1);
    helper(vec,partitionIndex+1,right);
}
void quickSort(std::vector<int> &vec){
    int left = 0,right = vec.size()-1;
    helper(vec,left,right);
}
int main(){
    std::vector<int> vec = {9,8,7,6,5,4,3,2,1,0};
    quickSort(vec);
    for(const int &num: vec){
        std::cout<<num<<" ";
    }
    return 0;
}