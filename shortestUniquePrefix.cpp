#include<iostream>
#include<vector>
#include<unordered_map>
class TrieNode{
    public:
        std::unordered_map<char, TrieNode*> hash;
        int count = 0;
        bool isEnd = false;
};
void insertTrie(const std::string &str, TrieNode* head){
    TrieNode* temp = head;
    for(int index = 0;index<str.length();++index){
        if(temp->hash.find(str[index])!=temp->hash.end()){
            ++(temp->count);
        }
        else{
            temp->hash[str[index]] = new TrieNode();
        }
        temp = temp->hash[str[index]];
    }
    temp->isEnd = true;
}
std::string findPrefix(TrieNode* head,const std::string &str){
    TrieNode* temp = head;
    std::string returnValue;
    int index = 0;
    while(temp->count>1){
        temp = temp->hash[str[index]];
        returnValue.push_back(str[index]);
        ++index;
    }
    return returnValue;
}
std::vector<std::string> solve(std::vector<std::string> &vec){
    TrieNode* head = new TrieNode();
    for(int index = 0;index<vec.size();++index){
        insertTrie(vec[index],head);
    }
    std::vector<std::string> returnValue(vec.size());
    for(int index = 0;index<vec.size();++index){
        //reach either count = 1 or reach end
        returnValue[index] = findPrefix(head, vec[index]);
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<std::string> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<std::string> output = solve(vec);
    for(auto& str:output){
        std::cout<<str<<" ";
    }
    return 0;
}