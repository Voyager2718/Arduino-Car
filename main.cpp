#include"Data.h"
#include<map>
#include<vector>
#include<string>
#include<iostream>

using std::cout;
using std::endl;

std::vector<int> make_vector(){
    std::vector<int> v;
    return v;
}

int main(){
    std::map< std::string, std::vector<int> > map;
    map["a"] = make_vector();
    map["a"].push_back(10);
    cout<<map["a"][0]<<endl;
    return 0;
}