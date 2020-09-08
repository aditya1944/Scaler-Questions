#include<vector>
#include<iostream>
using namespace std;
int findMax(const vector<int> &arr){
    //use kadane algorithm
    int currMax = 0,globalMax = 0;
    for(int index = 0;index<arr.size();++index){
        currMax = max(arr[index], currMax + arr[index]);
        globalMax = max(globalMax, currMax);
    }
    return globalMax;
}
int solve(vector<vector<int> > &A) {
    int ans = 0;
    int cols = A[0].size();
    int rows = A.size();
    for(int i = 0;i<cols;++i){
        vector<int> temp(rows);
        for(int j = i;j<cols;++j){
            for(int rowIndex = 0;rowIndex<rows;++rowIndex){
                temp[rowIndex]+=A[rowIndex][j];
            }
            int currMax = findMax(temp);
            ans = max(ans, currMax);
        }
    }
    return ans;
}
int main(){
    vector<vector<int> > vec = {
        {1,2,-1,-4,-20},
        {-8,-3,4,2,1},
        {3,8,10,1,3},
        {-4,-1,1,7,-6}
    };
    int output = solve(vec);
    cout<<output<<endl;
}