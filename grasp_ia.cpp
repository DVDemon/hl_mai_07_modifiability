#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Item
{
    size_t count;
    size_t price;
};

struct Basket
{
    std::vector<Item> items;
};

auto main() -> int
{
    Basket basket;
    basket.items.push_back({3, 5});
    basket.items.push_back({2, 13});

    size_t total_price{0};
    std::for_each(std::begin(basket.items), std::end(basket.items), [&total_price](const Item &i)
                  { total_price += i.count * i.price; });

    std::cout << "Total basket card:" << total_price << std::endl;

    return 1;
}