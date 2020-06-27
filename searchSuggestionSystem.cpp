#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
//this question provided a limit of just showing 3 suggestion. Hence all suggestion is not required. 
class Node{
    public:
        char ch;
        std::unordered_map<char, Node*> hash;
        bool isEnd;
};
void insert(Node *head,const std::string &str){
    for(int index = 0;index<str.length();++index){
        if(head->hash.find(str[index])!=head->hash.end()){
            //str[index];
            head = head->hash[str[index]];
        }
        else{
            //create a new Node;
            Node *node = new Node();
            node->ch = str[index];
            head->hash[str[index]] = node;
            head = node;
        }
        if(index==str.length()-1){
            head->isEnd = true;
        }
    }
}
void dfs(Node *node, std::vector<std::string> &returnValue, std::string &currString){
    currString.push_back(node->ch);
    if(node->isEnd){
        returnValue.push_back(currString);
    }
    for(auto neighbour: node->hash){
        dfs(neighbour.second,returnValue,currString);
    }
    currString.pop_back();
}
std::vector<std::string> find(Node* node,const std::string &prefix){
    std::vector<std::string> returnValue;
    for(int index = 0;index<prefix.size();++index){
        if(node->hash[prefix[index]]==NULL){
            return returnValue;
        }
        else{
            node = node->hash[prefix[index]];
        }
    }
    std::string currString = prefix.substr(0,prefix.length()-1);
    dfs(node,returnValue,currString);
    std::sort(returnValue.begin(),returnValue.end());
    returnValue.resize(3);
    return returnValue;
}
void clearMemory(Node *node){
    if(!node){
        return;
    }
    for(auto neighbour: node->hash){
        clearMemory(neighbour.second);
    }
    delete(node);
}
std::vector<std::vector<std::string> >suggestedProducts(std::vector<std::string>& products, std::string searchWord){        
    //first create trie of all products
    Node *node  = new Node();
    for(int index = 0;index<products.size();++index){
        insert(node,products[index]);
    }
    //trie construction completed

    std::vector<std::vector<std::string> > returnValue(searchWord.size());
    for(int index = 0;index<searchWord.size();++index){
        std::string substr = searchWord.substr(0,index+1);
        //find strings in trie which has prefix as substr
        returnValue[index] = find(node,substr);
        if(returnValue[index].size()==0){
            break;
        }
    }
    //clear the memory
    clearMemory(node);
    return returnValue;
}