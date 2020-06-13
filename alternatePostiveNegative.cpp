#include<iostream>
#include<vector>
#include<algorithm>
void rightRotate(std::vector<int> &A,int left, int right){
    if(right==A.size()){
        //no need to do anything
        return;
    }
    int temp = A[right];
    int index = right;
    while(index-1>=left){
        A[index] = A[index-1];
        --index;
    }
    A[left] = temp;
}
std::vector<int> solve(std::vector<int> &A){
    for(int index = 0;index<A.size();++index){
        if(index%2!=0){
            //index for non negative number
            if(A[index]<0){
                int j = index+1;
                while(j<A.size() && A[j]<0){
                    //find the nonNegative Number
                    ++j;
                }
                //index j has the non negative number
                rightRotate(A,index,j);
            }
        }
        else{
            //index for negative number
            if(A[index]>=0){
                int j = index+1;
                while(j<A.size() && A[j]>=0){
                    //find the nonNegative Number
                    ++j;
                }
                //index j has the non negative number
                rightRotate(A,index,j);
            }
        }
    }
    return A;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<int> output = solve(vec);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}