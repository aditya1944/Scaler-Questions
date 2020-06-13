#include<iostream>
#include<vector>
#include<algorithm>
//using namespace std;
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int left = 0,right = matrix.size()-1;
    int row;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(target==matrix[mid][0]){
            return true;
        }
        else if(target<matrix[mid][0]){
            left = mid + 1;
            row = mid;
        } 
        else if(target>matrix[mid][0]){
            right = mid-1;
        }
    }

    bool returnValue = std::binary_search(matrix[row].begin(),matrix[row].end(),target);

    return returnValue;
}
int main(){
    return 0;
}