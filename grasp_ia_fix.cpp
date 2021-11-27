#include <iostream>
#include <string>
#include <numeric>
#include <vector>

class Item{
    private:
        size_t count;
        size_t price;
    public:
        Item(size_t c,size_t p) : count(c),price(p){}
        operator int(){
            return count*price;
        }
};

class Basket{
    private:
        std::vector<Item> items;
    public:
         void add(const Item& i){
            items.push_back(i);
         }
         size_t total_price(){
             return std::accumulate(std::begin(items),std::end(items),0);
        }
};

auto main() -> int {
    Basket basket;  
    basket.add({3,5});
    basket.add({2,13});

    std::cout << "Total basket card:" << basket.total_price() << std::endl;

    return 1;
}