#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Item{
    std::string payload;
};

struct ActionIsNumber{
    bool action(const Item& item){
        return std::count_if(std::begin(item.payload),std::end(item.payload),[](char c){
            if((c>='0')&&(c<='9')) return true;
            return false;
        }) == item.payload.size();
    };
};

struct ActionB{
    int action(const Item& item){
        return atoi(item.payload.c_str());
    };
};

struct ActionC{
    int action(int val){
        return val*val;
    };
};

struct ActionD{
    std::string action(int val){
        return std::to_string(val);
    };
};

struct Controller{
    std::string process(const Item & item){
        if(ActionIsNumber().action(item)){
            return ActionD().action(ActionC().action(ActionB().action(item)));
        } else throw std::logic_error("not a number");
    }
};

auto main() -> int {

    Item i{"12"};

    // process string
    std::cout << "Result:" << Controller().process(i) << std::endl;
    return 1;
}