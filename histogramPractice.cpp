#include<iostream>
#include<vector>
#include<stack>
int solve(const std::vector<int> &histogram){
    if(histogram.size()==0){
        return 0;
    }
    if(histogram.size()==1){
        return histogram[0];
    }
    std::stack<int> st;
    int maxArea = 0;
    for(int index = 0;index<histogram.size();++index){
        if(st.empty()){
            st.push(index);
        }
        else if(vec[st.top()]>vec[index]){
            int currArea;
            while(!st.empty() && vec[st.top()]>vec[index]){
                int topElementIndex = st.top();
                st.pop();
                currArea = vec[topElementIndex] * (index - topElementIndex);
            }
            maxArea = std::max(currArea,maxArea);
        }
        else{
            st.push(index);
        }
    }
    while(!st.empty()){
        
    }
    return maxArea;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    int maxArea = solve(vec);
    std::cout<<maxArea<<std::endl;
    return 0;
}