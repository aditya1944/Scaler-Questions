#include<iostream>
#include<vector>
#include<unordered_map>
class TrieNode{
    public:
        char ch;
        int count;
        std::unordered_map<char, TrieNode*> hashMap;
        TrieNode(char _ch){
            ch = _ch;
            count = 1;
        }
        TrieNode(){
            count = 0;
        }
        
};
void insert(TrieNode* node,const std::string& str){
    ++(node->count);
    for(int index = 0;index<str.length();++index){
        char ch = str[index];
        if(node->hashMap.find(ch)==node->hashMap.end()){
            //the node do not have link to ch
            node->hashMap[ch] = new TrieNode(ch);
            node = node->hashMap[ch];
        }
        else{
            node = node->hashMap[ch];
            ++(node->count);
        }
    }
}
int search(TrieNode* trie, const std::string& str){
    int returnValue = 0;
    for(int index = 0;index<str.length();++index){
        char ch = str[index];
        if(trie->hashMap.find(ch)==trie->hashMap.end()){
            return 0;
        }
        trie = trie->hashMap[ch];
    }
    returnValue = trie->count;
    return returnValue;
}
std::vector<int> solve(std::vector<int> &A, std::vector<std::string> &B){
    TrieNode *trie = new TrieNode();
    std::vector<int> returnValue;
    for(int index = 0;index<A.size();++index){
        if(A[index]==0){
            //insert in trie
            insert(trie,B[index]);
        }
        else{
            //search in Trie
            int count = search(trie, B[index]);
            returnValue.push_back(count);
        }
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> A(N);
    std::vector<std::string> B(N);
    for(int index = 0;index<N;++index){
        std::cin>>A[index];
    }
    for(int index = 0;index<N;++index){
        std::cin>>B[index];
    }
    auto returnValue = solve(A,B);
    for(const int& val: returnValue){
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    return 0;
}