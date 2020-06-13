#include<iostream>
#include<vector>
void rightRotate(std::vector<int> &vec, int left, int right){
    int val1 = vec[right];
    int index = right;
    while(index>left){
        vec[index] = vec[index-1];
        --index;
    }
    vec[index] = val1;
}
//1 2 3 4 5
//5 1 2 3 4
std::vector<int> solve(std::vector<int> &input){
    for(int index = 0;index<input.size();++index){
        int currVal = input[index];
        if(index%2==0){
            if(currVal>0){
                //find the nearest negative integer
                int nearestPlace = -1;
                for(int j = index+1;j<input.size();++j){
                    if(input[j]<0){
                        nearestPlace = j;
                        break;
                    }
                }
                //std::cout<<index<<" "<<nearestPlace<<std::endl;
                if(nearestPlace!=-1){
                    rightRotate(input, index, nearestPlace);
                }
            }
        }
        else{
            //this should be in even index
            if(currVal<0){
                //find the nearest negative integer
                int nearestPlace = -1;
                for(int j = index+1;j<input.size();++j){
                    if(input[j]>0){
                        nearestPlace = j;
                        break;
                    }
                }
                if(nearestPlace!=-1){
                    rightRotate(input, index, nearestPlace);
                }
            }
        }
        
    }
    return input;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<int> output = solve(vec);
    for(int &x: output){
        std::cout<<x<<" ";
    }

    return 0;
}