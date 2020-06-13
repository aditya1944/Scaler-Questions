#include<iostream>
#include<queue>
struct Node{
    int row,col,step;
};
int knight(int A, int B, int C, int D,int E, int F){
    if(C==E && D==F){
        return 0;
    }
    // knight goes in 8 directions
    //1. currRow - 2, currCol - 1;
    //2. currRow - 1, currCol - 2; 
    //3. currRow + 1, currCol - 2;
    //4. currRow + 2, currCol - 1;
    //5. currRow + 2, currCol + 1;
    //6. currRow + 1, currCol + 2;
    //7. currRow - 1, currCol + 2;
    //8. currRow - 2, currCol + 1;
    const int rows = A-1,cols = B-1,initialRow = C-1,initialCol = D-1,finalRow = E-1,finalCol = F-1;
    std::queue<Node> q;
    Node node;node.row = initialRow;node.col = initialCol; node.step = -1;
    q.push(node);
    std::vector<std::vector<bool> > visited(A,std::vector<bool>(B, false));
    while(!q.empty()){
        Node currNode = q.front();
        int currRow = currNode.row,currCol = currNode.col,currStep = currNode.step;
        q.pop();
        //1st move
        if((currRow-2>=0 && currCol-1 >=0) && !visited[currRow-2][currCol-1]){
            node.row = currRow-2;node.col = currCol-1;node.step = currStep+1;
            if(node.row==finalRow && node.col==finalCol){
                return node.step+1;
            }
            q.push(node);
            visited[currRow-2][currCol-1] = true;
        }
        //2nd move
        if(currRow-1>=0 && currCol-2>=0 && !visited[currRow-1][currCol-2]){
            node.row = currRow-1;node.col = currCol-2;node.step = currStep+1;
            if(node.row==finalRow && node.col==finalCol){
                return node.step+1;
            }
            q.push(node);
            visited[currRow-1][currCol-2] = true;
        }
        //3rd move
        if(currRow+1<A && currCol-2>=0 && !visited[currRow+1][currCol-2]){
            node.row = currRow+1;node.col = currCol-2;node.step = currStep+1;
            if(node.row==finalRow && node.col==finalCol){
                return node.step+1;
            }
            q.push(node);
            visited[currRow+1][currCol-2] = true;
        }
        //4th move
        if(currRow+2<A && currCol-2>=0 && !visited[currRow+1][currCol-2]){
            node.row = currRow+1;node.col = currCol-2;node.step = currStep+1;
            if(node.row==finalRow && node.col==finalCol){
                return node.step+1;
            }
            q.push(node);
            visited[currRow+1][currCol-2] = true;
        }
        //5th move
        if(currRow+1<A && currCol+1<B && !visited[currRow+1][currCol+1]){
            node.row = currRow+1;node.col = currCol+1;node.step = currStep+1;
            if(node.row==finalRow && node.col==finalCol){
                return node.step+1;
            }
            q.push(node);
            visited[currRow+1][currCol+1] = true;
        }
        //6th move
        if(currRow+1<A && currCol+2<B && !visited[currRow+1][currCol+2]){
            node.row = currRow+1;node.col = currCol+2;node.step = currStep+1;
            if(node.row==finalRow && node.col==finalCol){
                return node.step+1;
            }
            q.push(node);
            visited[currRow+1][currCol+2] = true;
        }
        //7th move
        if(currRow-1>=0 && currCol+2<B && !visited[currRow-1][currCol+2]){
            node.row = currRow-1;node.col = currCol+2;node.step = currStep+1;
            if(node.row==finalRow && node.col==finalCol){
                return node.step+1;
            }
            q.push(node);
            visited[currRow-1][currCol+2] = true;
        }
        //8th move
        if(currRow-2>=0 && currCol+1<B && !visited[currRow-2][currCol+1]){
            node.row = currRow-2;node.col = currCol+1;node.step = currStep+1;
            if(node.row==finalRow && node.col==finalCol){
                return node.step+1;
            }
            q.push(node);
            visited[currRow-2][currCol+1] = true;
        }
    }   
    return -1;
}
int main(){
    return 0;
}