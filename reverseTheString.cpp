#include<iostream>
#include<string>
void trim(std::string &str){
    //remove leading spaces
    int index = 0;
    while(index<str.size() && str[index]==' '){
        ++index;
    }
    //std::cout<<index<<std::endl;
    str = str.substr(index);
    //std::cout<<str;
    index = str.size()-1;
    while(index>=0 && str[index]==' '){
        str.pop_back();
        --index;
    }
    //std::cout<<index<<std::endl;
}
std::string solve(std::string &input){
    std::string returnValue = "";
    trim(input);
    //std::cout<<input<<std::endl;
    int index = input.size()-1;
    while(1){
        int j = index;
        while(j-1>=0 && input[j-1]!=' '){//moving j to start of word
            --j;
        }
        
        //from j+1 to index;
        for(int k = j;k<=index;++k){
            returnValue+=input[k];
        }
        
        std::cout<<"j: "<<j<<std::endl;
        while(j-1>=0 && input[j-1]==' '){//moving j to another word
            --j;
        }
        --j;
        if(j<0){
            break;
        }
        returnValue+=' ';
        index = j;
    }
    return returnValue;
}
int main(){
    std::string str;
    std::getline(std::cin,str);
    std::string output = solve(str);
    std::cout<<output.size()<<std::endl;
    //std::cout<<output<<std::endl;
    return 0;
}