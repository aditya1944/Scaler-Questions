#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
class Node{
    bool operator==(const Node& node) const{
        if(this->sum==node.sum){
            return true;
        }
        return false;
    }
    public:
        int i1;
        int i2;
        int sum;
        
};
class HashFunction{
    public:
        long long operator()(const Node& node) const{
            long long hash = (long long)node.i1 + (long long)node.i2*2;
            return hash;
        }
};
std::vector<int> solve(std::vector<int> &arr){
    std::vector<int> returnValue;
    std::unordered_map<int , std::pair<int, int> > hashMap;
    for(int i = 0;i < arr.size();++i){
        for(int j = i+1; j<arr.size();++j){
            int sum = arr[i] + arr[j];
            if(hashMap.find(sum)==hashMap.end()){
                //the sum do not exists in map;
                hashMap.insert(std::make_pair(sum, std::make_pair(i,j)));
            }
            else{
                //the sum already exists in map
                auto val = (hashMap.find(sum));
                int i1 = val->second.first,i2 = val->second.second;
                //check the condition
                //now i is c1 and j is d1
                if(i1<i && (j!=i2) && (i2!=i)){
                    std::vector<int> temp(4);
                    temp[0] = i1;
                    temp[1] = i2;
                    temp[2] = i;
                    temp[3] = j;
                    //check in returnValue
                    if(returnValue.empty()){
                        returnValue = temp;
                    }
                    else{
                        //compare temp with returnValue
                        //if temp is lexicographically smaller than returnValue
                        //temp is ans;
                        for(int index = 0;index<3;++index){
                            if(temp[index]>returnValue[index]){
                                break;
                            }
                            else if(temp[index]==returnValue[index]){
                                continue;
                            }   
                            else{
                                returnValue = temp;
                            }
                        }
                    }
                }
            }

        }
    }
    return returnValue;
    //3 4 7 1 2 9 8
    //0 1 2 3 4 5 6
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<int> output = solve(vec);
    for(int &x: output){
        std::cout<<x<<" "; 
    }
    return 0;
}