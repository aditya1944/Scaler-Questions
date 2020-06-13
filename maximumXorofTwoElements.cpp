#include<iostream>
#include<vector>
#include<climits>
class Trie{
    public:
        Trie* left = NULL;//it means 0
        Trie* right = NULL;// it means 1
};
void insert(Trie* root, int num){
    Trie* temp = root;
    int bitIndex = 0;
    while(bitIndex<32){
        int bit = (num>>bitIndex) & 1;
        if(bit){
            temp->right = new Trie();
            temp = temp->right;
        }
        else{
            temp->left  = new Trie();
            temp = temp->left;
        }
        ++bitIndex;
    }
}
int findXOR(int num, Trie* root){
    int xorValue = 0;
    int multiplier = 1;
    int bitIndex = 0;
    Trie *temp = root;
    while(bitIndex<32){
        int bit = (num>>bitIndex)&1;
        if(bit==1){
            if(temp->left){
                temp = temp->left;
                xorValue+=multiplier;
            }
            else{
                temp = temp->right;
            }
        }
        else{
            if(temp->right){
                temp = temp->right;
                xorValue+=multiplier;
            }
            else{
                temp = temp->left;
            }
        }
        multiplier*=2;
        ++bitIndex;
    }
    return xorValue;
}
int solve(std::vector<int> &A){
    //insert all binary value in tries;
    Trie *root = new Trie();
    for(int index = 0;index<A.size();++index){
        insert(root,A[index]);
    }
    int maxXor = INT_MIN;
    for(int index = 0;index<A.size();++index){
        int currXOR = findXOR(A[index],root);
        maxXor = std::max(currXOR, maxXor);   
    }
    return maxXor;
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