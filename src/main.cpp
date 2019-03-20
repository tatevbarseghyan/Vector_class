#include "vector.hpp"
#include <iostream>
int main()
{
    Vector <int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    std::cout << "Call push_back for 10 item :" <<std::endl;
    v.print();
    std::cout << " Call pop_back :" <<std::endl;
    v.pop_back();
    std::cout << v;
    v.insert(9,9);
    std::cout << "Call insert :" <<std::endl;
    std::cout << v;
    std::cout << "Get_size :" << std::endl;
    std::cout << v.get_size() << std::endl;
    v.insert(5,0);
    std::cout << "Call insert :" << std::endl;
    std::cout << v;
}
