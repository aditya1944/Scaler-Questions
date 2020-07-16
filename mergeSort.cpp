#include<vector>
#include<iostream>
void merge(std::vector<int> &vec, int left, int right){
    int mid = left + (right - left)/2;
    int leftPtr = left,rightPtr = mid+1;
    std::vector<int> temp;
    while(leftPtr<=mid && rightPtr<=right){
        if(vec[leftPtr]<=vec[rightPtr]){
            temp.push_back(vec[leftPtr]);
            ++leftPtr;
        }
        else{
            temp.push_back(vec[rightPtr]);
            ++rightPtr;
        }
    }
    while(leftPtr<=mid){
        temp.push_back(vec[leftPtr]);
        ++leftPtr;
    }
    while(rightPtr<=right){
        temp.push_back(vec[rightPtr]);
        ++rightPtr;
    }
    for(int index = left;index<=right;++index){
        vec[index] = temp[index-left];
    }
}
void helper(std::vector<int> &vec, int left, int right){
    if(left>=right){
        return;
    }
    int mid = left + (right - left)/2;
    helper(vec,left,mid);
    helper(vec,mid+1,right);
    merge(vec,left,right);
}
void mergeSort(std::vector<int> &vec){
    int left = 0,right = vec.size()-1;
    helper(vec,left,right);
}
int main(){
    std::vector<int> vec = {9,8,7,6,5,4,3,2,1,0};
    mergeSort(vec);
    for(const int& num:vec){
        std::cout<<num<<" ";
    }
    return 0;
}