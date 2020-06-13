#include<iostream>
#include<vector>
#include<stack>
int solve(std::vector<int> &vec){
    int returnValue =-1;
    std::stack<int> st;
    std::vector<int> rightSmall(vec.size(), -1);
    std::vector<int> leftSmall(vec.size(), -1);
    int index = 0;
    while(index<vec.size()){
        if(st.empty()){
            st.push(index);
            ++index;
        }
        else if(vec[index]>=vec[st.top()]){
            st.push(index);
            ++index;
        }
        else{
            rightSmall[st.top()] = index;
            st.pop();
        }
    }
    while(!st.empty()){
        st.pop();
    }
    index = vec.size()-1;
    while(index>=0){
        if(st.empty()){
            st.push(index);--index;
        }
        else if(vec[index]>=vec[st.top()]){
            st.push(index);
            --index;
        }
        else{
            leftSmall[st.top()] = index;
            st.pop();
        }
    }
    //now calculate area
    int currentArea;
    for(int index = 0;index<vec.size();++index){
        int leftWidth = leftSmall[index]==-1?index:index - leftSmall[index]-1;
        int rightWidth = rightSmall[index]==-1?vec.size()-index-1:rightSmall[index] - index-1;
        int width = leftWidth + rightWidth  + 1;
        currentArea = width * vec[index];
        //std::cout<<"leftArea : "<<leftWidth<<"rightWidth : "<<rightWidth<<" "<<currentArea<<std::endl;
        returnValue = std::max(returnValue,currentArea);
    }
    /*for(int &x: leftSmall){
        std::cout<<x<<" ";
    }*/
    return returnValue;
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