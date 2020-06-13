#include<iostream>
#include<vector>
#include<stack>
int findHistogramArea(const std::vector<int> &arr){
    std::stack<int> st;
    int maxArea = 0, currArea;
    std::vector<int> leftSmall(arr.size(),-1);
    std::vector<int> rightSmall(arr.size(),-1);
    int index = 0;
    while(index<arr.size()){
        if(st.empty()){
            st.push(index);
            ++index;
        }
        else if(arr[index]>=arr[st.top()]){
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
    index = arr.size()-1;
    while(index>=0){
        if(st.empty()){
            st.push(index);
            --index;
        }
        else if(arr[index]>=arr[st.top()]){
            st.push(index);
            --index;
        }
        else{
            leftSmall[st.top()] = index;
            st.pop();
        }
    }
    for(int index = 0;index<arr.size();++index){
        int leftWidth = leftSmall[index]==-1?index:index - leftSmall[index]-1;
        int rightWidth = rightSmall[index]==-1?arr.size() - index - 1: rightSmall[index] - index -1;
        int width = leftWidth + rightWidth +1;
        currArea = width*arr[index];
        maxArea = std::max(currArea,maxArea);
    }
    //std::cout<<maxArea<<std::endl;
    return maxArea;
}
int solve(const std::vector<std::vector<int> >&matx){
    std::vector<int> windowArray(matx[0].size(),0);
    int maxArea = -1;
    int currArea;
    for(int rowIndex = 0;rowIndex<matx.size();++rowIndex){
        for(int colIndex = 0;colIndex<matx[0].size();++colIndex){
            if(matx[rowIndex][colIndex]==0){
                windowArray[colIndex] = 0;
            }
            else{
                 windowArray[colIndex] += matx[rowIndex][colIndex];
            }   
            
        }
        currArea = findHistogramArea(windowArray);
        maxArea = std::max(currArea,maxArea);
    }
    return maxArea;
}
int main(){
    int N,M;
    std::cin>>N>>M;
    std::vector<std::vector<int> > vec(N,std::vector<int>(M,0));
    for(int rowIndex = 0;rowIndex<N;++rowIndex){
        for(int colIndex = 0;colIndex<M;++colIndex){
            std::cin>>vec[rowIndex][colIndex];
        }
    }
    int output = solve(vec);
    std::cout<<output<<std::endl;
    return 0;
}