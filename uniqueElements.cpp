#include<iostream>
#include<unordered_map>
#include<vector>
int find(std::unordered_map<int, int> &mp,int number){
    while(1){
        ++number;
        if(mp.find(number)==mp.end()){
            return number;
        }
    }
}
int solve(std::vector<int> &vec){
    std::unordered_map<int,int> mp;
    for(int index = 0;index<vec.size();++index){
        ++mp[vec[index]];
    }
    //stored the frequency
    int output = 0;
    for(int index = 0;index<vec.size();++index){
        int currVal = vec[index];
        if(mp[currVal]>1){
            //find the next min Number which is not in map
            int minNumber = find(mp, currVal);
            output+=(minNumber-currVal);
            --mp[currVal];
            mp[minNumber] = 1;
        }
    }
    return output;
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