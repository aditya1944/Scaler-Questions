#include<iostream>
#include<stack>
#include<vector>
int solve(const std::vector<int> &A){
    std::vector<int> B(A.size());
    int BIndex = 0;
    std::stack<int> C;
    for(int index = 0;index<A.size();++index){
        if(C.empty()){
            C.push(A[index]);
        }
        else{
            if(A[index]>=C.top()){
                C.push(A[index]);
            }
            else{
                while(C.size()>0 && C.top()<A[index]){
                    int val = C.top();
                    C.pop();
                    B[BIndex++] = val;
                }
                C.push(A[index]);
            }
        }
    }
    while(!C.empty()){
        B[BIndex++] = C.top();
        C.pop();
    }
    for(int index = 0;index<B.size()-1;++index){
        if(A[index]>A[index+1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    int output = solve(vec);
    std::cout<<output<<std::endl;
    return 0;
}