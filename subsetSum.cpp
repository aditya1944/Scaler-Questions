#include<iostream>
#include<vector>
bool solve(const std::vector<int> &vec, int sum){
    //when sum is 0 do not take any element 
    if(sum==0){
        return true;
    }
    //when there are no elements in vec and sum you want is not zero 
    if(vec.size()==0){
        return false;
    }
    //using bottom up approach
    //make a dp array 
    //sum is in column
    //array elements are in row(basically they are indices)
    std::vector<std::vector<bool> > dp(2,std::vector<bool>(sum+1));
    //base cases if sum is 0
    for(int rowIndex = 0;rowIndex<2;++rowIndex){
        //for sum = 0 do not take any element that is why output is true 
        dp[rowIndex][0] = true;
    }
    //filling the first row
    for(int colIndex = 1;colIndex<=sum;++colIndex){
        dp[0][colIndex] = false;
        if(colIndex==vec[0]){
            dp[0][colIndex] = true;
        }
    }
    int flag = 1;
    //now here comes the dp filling part
    for(int rowIndex = 1;rowIndex<vec.size();++rowIndex){
        for(int colIndex = 1;colIndex<=sum;++colIndex){
            //first let we do not take the current element
            dp[flag][colIndex] = dp[flag^1][colIndex];
            if(colIndex-vec[rowIndex]>=0)
                dp[flag][colIndex] = dp[flag^1][colIndex - vec[rowIndex]] || dp[flag][colIndex];
            //std::cout<<dp[flag][colIndex]<<" ";
        }
        //std::cout<<std::endl;
        
        flag = flag^1;
    }
    bool returnValue = dp[flag^1][sum];
    return returnValue;
}
int main(){
    int N,K;
    std::cin>>N;
    std::vector<int> input(N);
    for(int index = 0;index<N;++index){
        std::cin>>input[index];
    }
    std::cin>>K;
    bool output = solve(input,K);
    if(output){
        std::cout<<"Yes"<<std::endl;
    }
    else{
        std::cout<<"No"<<std::endl;
    }
    return 0;
}