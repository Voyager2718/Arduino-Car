#include<map>
#include<vector>
#include<string>
#include<memory>
#include<iostream>
#include"Data.h"
#include"DataReceiver.interface.h"

using std::cout;
using std::endl;

class Data{
private:
    std::map<std::string, std::vector<std::shared_ptr<DataReceiver> > > listeners;
    std::map<std::string, std::vector<void(*)(int)> > func_listeners;
    std::map<std::string, int> data;

    std::vector< std::shared_ptr<DataReceiver> > make_vector(std::shared_ptr<DataReceiver> d){
        std::vector< std::shared_ptr<DataReceiver> > v;
        v.push_back(d);
        return v;
    }

    std::vector< void(*)(int) > make_vector(void(*d)(int)){
        std::vector< void(*)(int) > v;
        v.push_back(d);
        return v;
    }
public:
    Data(){

    }
    
    void refresh(){

    }

    void addPin(std::string mode, int pinNumber){
        if(data[mode]){
            cout<<"Duplicated mode, ignored."<<endl;
            return;
        }
        data[mode] = pinNumber;
    }

    void addListener(std::string mode, std::shared_ptr<DataReceiver> listener){
        if(listeners.find(mode) == listeners.end()){
            listeners[mode] = make_vector(listener);
            return;
        }
        listeners[mode] = make_vector(listener);
    }

    void addListener(std::string mode, void(*listener)(int)){
        if(func_listeners.find(mode) == func_listeners.end()){
            func_listeners[mode] = make_vector(listener);
            return;
        }
        func_listeners[mode].push_back(listener);
    }
};