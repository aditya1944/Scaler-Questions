#include<iostream>
#include<vector>
#include<unordered_map>
class TrieNode{
    public:
        char ch;
        std::unordered_map<char, TrieNode*> hash;
        bool isEnd;
        TrieNode(char _ch){
            ch = _ch;
            isEnd = false;
        }
};
//this function will return 1 if it found a prefix number else it will return 0
int check(TrieNode* head, const std::string& str){
    TrieNode* node = head;
    for(int index = 0;index<str.size();++index){
        char ch = str[index];
        if(node->isEnd){
            //there exists a string in a trie which is prefix of the current string
            return 1;
        }
        if(node->hash.find(ch)==node->hash.end()){
            //trieNode do not have current character
            node->hash[ch] = new TrieNode(ch);
        }
        node = node->hash[ch];
        if(index==str.size()-1){
            //we are at last index
            if(node->hash.size()>0){
                //then there exists some longer string
                return 1;
            }
            node->isEnd = true;
        }
    }
    return 0;
}
int solve(std::vector<std::string> &A){
    TrieNode* head = new TrieNode(' ');
    for(int index = 0;index<A.size();++index){
        if(check(head,A[index])==1){
            return 0;
        }
    }
    return 1;
}
int main(){
    std::vector<std::string> vec = {"1234","2342","567"};
    std::cout<<solve(vec);
    return 0 ;
}