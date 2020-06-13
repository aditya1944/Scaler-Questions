#include<iostream>
#include<math.h>
int solve(int A, int B, int C) {
    //find d such that d>=B && d<=C A^d is maximum
    long long output = 0;
    int power = 0;
    for(int bitIndex = 0;bitIndex<32;++bitIndex){
        int bit = (A>>bitIndex) & 1;
        if(bit==1){
            // ans bit would be 0;
            ++power;
        }
        else{
            //ans bit would be 1;
            long long temp = output;
            temp = output + pow(2, power);
            if(temp>C){
                //thats it. current output is max;
                break;
            }
            else{
                output = temp;
            }
            ++power;
        }
    }
    output = output^A;
    return output;
}
int main(){
    int A,B,C;
    std::cin>>A>>B>>C;
    int output = solve(A,B,C);
    std::cout<<output<<std::endl;
    return 0;
}