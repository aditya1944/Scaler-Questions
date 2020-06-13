#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
class Trie{
    public:
        bool isEnd = false;
        std::unordered_map<char, Trie*> hashMap;
};
void insert(Trie* head,const std::string & str){
    Trie* temp = head;
    for(int index = 0;index<str.length();++index){
        if(temp->hashMap.find(str[index])==temp->hashMap.end()){
            temp->hashMap[str[index]] = new Trie();
        }
        temp = temp->hashMap[str[index]];
    }
}
bool find(Trie* head,std::string str,const std::unordered_set<std::string> &hash){
    //with only one modification
    bool isFound = true;
    Trie* temp = head;
    for(int index = 0;index<str.length() && temp;++index){
        //see what is there in the current node
        for(auto val: temp->hashMap){
            if(val.first==str[index]){
                continue;
            }
            char ch = val.first;     
            //modify the string at index = index with ch;
            std::string tempStr = str;
            tempStr[index] = ch;
            if(hash.find(tempStr)!=hash.end()){
                return true;
            }    
        }
        temp = temp->hashMap[str[index]];
    }
    isFound = false;
    return isFound;
}
std::string solve(std::vector<std::string> &A,std::vector<std::string> &B){
    Trie *head = new Trie();
    std::string returnValue;
    std::unordered_set<std::string> hash;
    for(int index = 0;index<A.size();++index){
        insert(head, A[index]);
        hash.insert(A[index]);
    }
    for(int index = 0;index<B.size();++index){
        if(find(head, B[index],hash)){
            returnValue.push_back('1');
        }
        else{
            returnValue.push_back('0');
        }
    }
    return returnValue;
}
int main(){
    int n1,n2;
    std::cin>>n1;
    std::vector<std::string> A(n1);
    for(int index = 0;index<n1;++index){
        std::cin>>A[index];
    }
    std::cin>>n2;
    std::vector<std::string> B(n2);
    for(int index = 0;index<n2;++index){
        std::cin>>B[index];
    }
    std::string output = solve(A,B);
    std::cout<<output<<std::endl;
    return 0;
}