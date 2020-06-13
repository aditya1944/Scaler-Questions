#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
std::vector<int> solve(std::vector<std::vector<int> > &A){
    std::vector<int> returnValue(A.size());
    std::unordered_map<int, int> frequencyMap;
    std::unordered_map<int, std::stack<int> > orderMap;
    int maxFreq = -1;
    for(int queryIndex = 0;queryIndex<A.size();++queryIndex){
        //do push and pop
        int query = A[queryIndex][0];
        if(query==1){
            //it is push operation
            //1. update frequency of element in frequencyMap
            //2. in orderMap put that element in corresponding frequency
            int num = A[queryIndex][1];
            //incement num frequency
            ++frequencyMap[num];
            int frequency = frequencyMap[num];
            if(frequency>maxFreq){
                maxFreq = frequency;
            }
            orderMap[frequency].push(num);
            returnValue[queryIndex] = -1;
        }
        else if(query==2){
            //it is pop operation
            //pop the element with max frequency
            //and store the poped Element in returnValue
            int maxFreqElement = orderMap[maxFreq].top();
            orderMap[maxFreq].pop();
            --frequencyMap[maxFreqElement];
            if(orderMap[maxFreq].empty()){
                --maxFreq;
            }
            returnValue[queryIndex] = maxFreqElement;
        }
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<std::vector<int> >vec(N,std::vector<int>(2,0));
    for(int index = 0;index<N;++index){
        std::cin>>vec[index][0]>>vec[index][1];
    }
    std::vector<int> output = solve(vec);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}