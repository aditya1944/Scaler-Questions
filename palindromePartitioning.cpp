#include<iostream>
#include<vector>
#include<climits>
int solve(const std::string &str){
    using namespace std;{
        const int rows = str.length(),cols = str.length();
        vector<vector<int> > dp(rows,vector<int>(cols,0));
        vector<vector<int> >cut(rows,vector<int>(cols,0));
        //base case
        //1. every one length string is palindrome of length 1;
        for(int index=0;index<rows;++index){
            dp[index][index] = 1;
        }
        for(int length = 2;length<=str.length();++length){
            for(int start = 0;start<=str.length()-length;++start){
                //abcd
                //0123
                //length = 4
                int end = length + start-1;
                //now fill dp[start][end]
                if(length==2){
                    dp[start][end] = (str[start]==str[end]);
                } 
                else{
                    dp[start][end] = (str[start]==str[end]&&dp[start+1][end-1]);
                }
                //two conditions
                //if the string is palindrome no cut is required
                if(dp[start][end]==1){
                    //string from start index upto end index is palindrome
                    cut[start][end] = 0;
                }
                else{
                    //string from start index upto end Index is not a palindrome
                    //abbaba
                    //012345
                    //start = 0 end = 5
                    //
                    cut[start][end] = INT_MAX;
                    for(int k = start;k<end;++k){
                        cut[start][end] = std::min(cut[start][end],1 + cut[start][k] + cut[k+1][end]);
                    }
                }
            }
        }
        /*for(int rowIndex = 0;rowIndex<rows;++rowIndex){
            for(int colIndex = 0;colIndex<cols;++colIndex){
                cout<<dp[rowIndex][colIndex]<<" ";
            }
            cout<<endl;
        }*/
        return cut[0][cols-1];
    }
    
}
int main(){
    using namespace std;{
        std::string str;
        std::cin>>str;
        int output = solve(str);
        std::cout<<output<<std::endl;
    }
    return 0;
}