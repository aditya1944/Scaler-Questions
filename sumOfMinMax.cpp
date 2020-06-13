#include<iostream>
#include<vector>
#include<deque>
#define mod 1000000007
int solve(std::vector<int> &vec, int K){
    //K is subarray size;
    std::deque<int> maxDequeue, minDequeue;//store indices
    long long returnValue = 0;
    int startIndex = 0;
    int endWindow = 0;
    bool isFirst = true;
    while(startIndex<=vec.size()-K){
        if(!maxDequeue.empty() && maxDequeue.front()<startIndex){
            maxDequeue.pop_front();
        }
        if(!minDequeue.empty() && minDequeue.front()<startIndex){
            minDequeue.pop_front();
        }
        if(isFirst){
            for(int j = 0;j<K;++j){
                int currNum = vec[j];
                while(!maxDequeue.empty()&&vec[maxDequeue.back()]<=currNum){
                    maxDequeue.pop_back();
                }
                while(!minDequeue.empty() && vec[minDequeue.back()]>=currNum){
                    minDequeue.pop_back();
                }
                maxDequeue.push_back(j);
                minDequeue.push_back(j);
            }
            isFirst = false;
        }
        else{
            int j = startIndex + K-1;
            int currNum = vec[j];
            while(!maxDequeue.empty()&&vec[maxDequeue.back()]<=currNum){
                maxDequeue.pop_back();
            }
            while(!minDequeue.empty() && vec[minDequeue.back()]>=currNum){
                minDequeue.pop_back();
            }
            maxDequeue.push_back(j);
            minDequeue.push_back(j);
        }
        int currWindowMinIndex = minDequeue.front();
        int currWindowMaxIndex = maxDequeue.front();
        //std::cout<<vec[currWindowMinIndex]<<" "<<vec[currWindowMaxIndex]<<std::endl;
        long long sum = ((long long)vec[currWindowMaxIndex] + (long long)vec[currWindowMinIndex] + mod)%mod;
        returnValue = (returnValue + sum)%mod;
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
    int output = solve(vec,K);
    std::cout<<output<<std::endl;
    return 0;
}