#ifndef DATA_H
#define DATA_H

#include<string>
#include<map>
#include<vector>
#include<string>
#include"DataReceiver.interface.h"

class Data{
private:
    std::map<std::string, std::vector<std::shared_ptr<DataReceiver> > > listeners;
    std::map<std::string, std::vector<void(*)(int)> > func_listeners;
    std::map<std::string, int> data;

    std::vector< std::shared_ptr<DataReceiver> > make_vector(std::shared_ptr<DataReceiver>);
    std::vector< void(*)(int) > make_vector(void(*)(int));
public:
    Data();
    void refresh();
    void addPin(std::string, int);
    void addListener(std::string, std::shared_ptr<DataReceiver>);
    void addListener(std::string, void(*)(int));
};

#endif