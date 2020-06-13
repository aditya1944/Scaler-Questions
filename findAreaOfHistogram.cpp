#include<iostream>
#include<vector>
#include<stack>
int solve(const std::vector<int> &vec){
    int maxArea = 0;
    std::stack<int> st;
    for(int index = 0;index<vec.size();++index){
        if(st.empty()){
            st.push(index);
        }
        else if(vec[index]>=vec[st.top()]){
            st.push(index);
        }
        else{
            //encountered the element less than top of the stack
            int currArea;
            while(!st.empty() && vec[st.top()]>vec[index]){
                //time to calculate area
                int topElementIndex = vec[st.top()];
                st.pop();
                currArea = vec[topElementIndex] * (index-topElementIndex);
                maxArea = std::max(currArea,maxArea);
            }
            st.push(index);
        }
    }
    while(!st.empty()){
        int topElementIndex = st.top();
        st.pop();
        if(st.empty()){
            int currArea = vec[topElementIndex];
            maxArea = std::max(currArea,maxArea);
        }
        else{
            int currArea = vec[topElementIndex] * (topElementIndex - st.top()+1);
            maxArea = std::max(currArea, maxArea);
        }
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