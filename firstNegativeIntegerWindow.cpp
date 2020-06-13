#include<iostream>
#include<queue>
#include<vector>
std::vector<int> solve(const std::vector<int> &vec, int K){
    std::queue<int> q;
    std::vector<int> returnValue(vec.size() - K+1);
    int startIndex = 0;
    bool isFirst = true;
    while(startIndex<=vec.size()-K){
        if(!q.empty() && q.front()<startIndex){
            q.pop();
        }
        if(isFirst){
            for(int j = startIndex;j<K + startIndex;++j){
                if(vec[j]<0){
                    q.push(j);
                }
            }
            isFirst = false;
        }
        else{
            int j = startIndex + K-1;
            if(vec[j]<0){
                q.push(j);
            }
        }
        if(q.empty()){
            returnValue[startIndex] = 0;
        }
        else{
            returnValue[startIndex] = vec[q.front()];
        }
        ++startIndex;
    }
    return returnValue;
}
int main(){
    int N,K;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>K;
    std::vector<int> output = solve(vec, K);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}