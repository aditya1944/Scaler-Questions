#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>
struct Node{
    int index;
    int countGoodWords;
};
bool compare(const Node &n1,const Node &n2){
    if(n1.countGoodWords==n2.countGoodWords){
        return n1.index<n2.index;
    }
    return n1.countGoodWords>n2.countGoodWords;
}
std::vector<int> solve(std::string A, std::vector<std::string> &B){
    std::unordered_set<std::string> hash;
    //first all good words in hash
    int first = 0;
    while(first<A.size()){
        int second = A.find_first_of('_',first);
        if(second==std::string::npos){
            second = A.size();
            hash.insert(A.substr(first, second-first));
            break;
        }
        else{
            hash.insert(A.substr(first, second - first));
        }
        first = second+1;
    }
    //now hash has all good words
    std::vector<Node> arr(B.size());
    std::vector<int> resultArr(B.size());
    for(int index = 0;index<B.size();++index){
        std::string currString = B[index];
        //find count of good words in currString
        int count = 0;
        int first = 0;
        while(first<currString.size()){
            int second = currString.find_first_of('_',first);
            if(second==std::string::npos){
                second = currString.size();
            }
            std::string word = currString.substr(first,second-first);
            if(hash.find(word)!=hash.end()){
                //current word is good word 
                ++count;
            }
            first = second + 1;
        }
        Node node;
        node.countGoodWords = count;
        node.index = index;
        //std::cout<<count<<std::endl;
        arr[index] = node;
    }
    std::sort(arr.begin(),arr.end(),compare);
    for(int index = 0;index<B.size();++index){
        resultArr[index] = arr[index].index;
    }
    return resultArr;
}
int main(){
    std::string str;
    std::cin>>str;
    int N;
    std::cin>>N;
    std::vector<std::string> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<int> output = solve(str,vec);
    for(auto x: output){
        std::cout<<x<<" ";
    }
    return 0;
}