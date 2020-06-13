#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<ios>
struct Node{
    int val;
    int val2;
};
std::vector<std::string> tokenise(const std::string& str);
int main(){
    std::vector<int> arr = {2,6,9,9,0,12,34,34,9,2,7,7};
    std::vector<Node> nodeLst = {{1,2},{1,9},{2,-1},{1,3}};
    /*std::sort(arr.begin(),arr.end(),[](const int&a, const int&b)-> bool{
        return a>b;
    });*/
    /*
    
    std::vector<Node>::iterator last;

    last = std::unique(nodeLst.begin(),nodeLst.end(),[](const Node&n1,const Node&n2)->bool{
        if(n1.val==n2.val){
            return true;
        }
        return false;
    });

    nodeLst.resize(std::distance(nodeLst.begin(),last));

    for(auto &val: nodeLst){
        std::cout<<val.val<<" "<<val.val2<<std::endl;
    }*/


    /*int a = 99;
    auto x = [a](int b, int c){
        return a + b + c;
    };
    std::cout<<x(1,2);*/

    /*std::sort(arr.begin(),arr.end(),[](int &a, int &b)->bool{
        return a>b;
    });
    for(int val: arr){
        std::cout<<val<<" ";
    }*/

    /*std::fstream f;//create and write on files

    f.open("a.txt", std::ios::app | std::ios::in);//opened the file with following flags
    //out for writing the file
    //in for reading the file
    //app for appending the file
    std::string str = "";//declare the string
    std::getline(std::cin,str);//get the value from user
    f<<str;
    f >> str;
    std::cout<<str<<std::endl;
    f.close();*/

    //read from csv file and store in 2d vector

    std::fstream file;//declare file datatype

    file.open("a.txt",std::ios::in);
    std::vector<std::string> lines;
    while(file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            lines.push_back(line);
        }
        file.close();
    }
    /*for(auto line: lines){
        std::cout<<line<<std::endl;
    }*/
    std::vector<std::vector<std::string> > dictionary(lines.size());
    
    //lines has all the lines
    int index = 0;
    while(index<lines.size()){
        //std::cout<<index<<std::endl;
        dictionary[index] = tokenise(lines[index]);
        ++index;
    }
    //dictionary has all words
    std::sort(dictionary.begin(),dictionary.end(),[](const std::vector<std::string> &v1, const std::vector<std::string> &v2){
        return v1[0]<v2[0];
    });

    for(auto line: dictionary){
        for(auto word: line){
            std::cout<<word<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
std::vector<std::string> tokenise(const std::string &str){
    std::vector<std::string> tokens;
    int first = 0;
    //std::cout<<"aditya";
    while(first<str.size()){
        int second = str.find_first_of(',',first);
        //first has index of start of token
        //second has index of end of token + 1;
        if(second==std::string::npos){
            second = str.size();
        }
        std::string token = str.substr(first, second-first);
        //axaxax,asas,csdcs,cscds
        //0123456
        tokens.push_back(token);
        first = second + 1;
    }
    return tokens;
} 