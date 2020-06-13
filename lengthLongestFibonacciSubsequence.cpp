#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
int findLength(int a, int b,std::unordered_set<int> &hash){
    int length = 2;
    while(hash.find(a+b)!=hash.end()){
        int next = a + b;
        a = b;
        b = next;
        ++length;
    }

    return length;
}
int solve(const std::vector<int> &vec){
    std::unordered_set<int> hash;
    for(int index = 0;index<vec.size();++index){
        hash.insert(vec[index]);
    }
    //start from last
    int maxLength = INT_MIN;
    for(int i = 0;i<vec.size()-1;++i){
        for(int j = i+1;j<vec.size();++j){
            int a = vec[i],b = vec[j];
            int currLength = findLength(a,b,hash);
            maxLength = std::max(maxLength,currLength);
        }
    }
    if(maxLength>2){
        return maxLength;
    }
    return 0;
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