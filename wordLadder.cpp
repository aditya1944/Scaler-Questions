#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    std::unordered_set<std::string> hash(wordList.begin(),wordList.end());
    if(hash.find(endWord)==hash.end()){
        return 0;
    }
    std::queue<std::string> q;
    std::vector<char> alphabets(26);
    for(char c='a';c<='z';++c){
        alphabets[c - 'a'] = c;
    }
    q.push(beginWord);
    int steps = 1;
    while(!q.empty()){
        int levelSize = q.size();
        for(int i = 0;i<levelSize;++i){
            std::string topStr = q.front();
            q.pop();
            std::string temp = topStr;
            for(int index = 0;index<topStr.size();++index){
                temp = topStr;
                char originalIndex = topStr[index];
                for(char &ch: alphabets){
                    if(ch==originalIndex){
                        continue;
                    }
                    temp[index] = ch;
                    if(temp==endWord){
                        return steps+1;
                    }
                    if(hash.find(temp)!=hash.end()){
                        q.push(temp);
                        hash.erase(temp);
                    }
                }
            }
        }
        ++steps;
    }
    return 0;
}
int main(){
    std::string a,b;
    int N;
    std::cin>>a>>b>>N;
    std::vector<std::string> lst(N);
    for(int index = 0;index<N;++index){
        std::cin>>lst[index];
    }
    std::cout<<ladderLength(a,b,lst);
    return 0;
}