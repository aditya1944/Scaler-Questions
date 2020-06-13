#include<vector>
#include<algorithm>
int helper(int *preOrder, int* inOrder,int *postOrder,int len){
    if(len==0){
        return 1;
    }
    else if(len==1){
        //check if the first character are same
        if(preOrder[0]==inOrder[0]==postOrder[0]){
            return 1;
        }
        return 0;
    }
    int currNum = preOrder[0];
    int currIndex = -1;
    for(int index = 0;index<len;++index){
        if(preOrder[index]==currNum){
            currIndex = currNum;
            break;
        }
    }
    if(currIndex==-1){
        return 0; 
    }
    //move to left subtree
    helper(preOrder+1,inOrder,postOrder,currIndex);

    //move to right subtree
    helper(preOrder+currIndex+1, inOrder+currIndex+1, postOrder+currIndex,len-currIndex-1);
}
int solve(std::vector<int> &preOrder, std::vector<int> &inOrder, std::vector<int> &postOrder){
    //convert them in arrays
    if(preOrder.size()!=inOrder.size() || preOrder.size()!=postOrder.size()){
        return 0;
    }
    if(preOrder[0]!=postOrder[postOrder.size()-1]){
        return 0;
    }
    int size = preOrder.size();
    int *preArray = new int[size];
    int *postArray = new int[size];
    int *inArray = new int[size];
    for(int index = 0;index<preOrder.size();++index){
        preArray[index] = preOrder[index];
        postArray[index] = postOrder[index];
        inArray[index] = inOrder[index];
    }
    int returnValue = helper(preArray, inArray, postArray,preOrder.size());
    return returnValue;
}