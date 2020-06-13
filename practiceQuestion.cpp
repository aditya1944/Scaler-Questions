#include<iostream>
#include<vector>
void updateLeft(std::vector<int> &vec,int &left, int right){
    while(vec[left]!=0){
        ++left;
    }
    //at this left it is 0
    ++left;
}
std::vector<int> solve(std::vector<int> &vec, int M){
    int left = 0, right = -1;
    int currentLength, maxLength = -1, maxLeft, maxRight,currCount = 0;
    while(right+1<vec.size()){
        if(currCount<M){
            if(vec[right+1]==0){
                ++currCount;
            }
            ++right;
        }
        else if(currCount==M){
            if(vec[right+1]==1){
                ++right;
            }
            else{
                //time to update left and currCount
                updateLeft(vec,left, right);
                --currCount;
            }
        }
        currentLength = right - left + 1;
        //std::cout<<"left : "<<left<<"right :"<<right<<std::endl;
        if(currentLength>maxLength){
            maxLeft = left;
            maxRight = right;
            maxLength = currentLength;
        }
    }
    std::vector<int> returnValue(maxLength);
    for(int num = maxLeft;num<=maxRight;++num){
        returnValue[num - maxLeft] = num;
    }
    return returnValue;
}
int main(){
    int N,M;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>M;
    std::vector<int> output = solve(vec,M);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}