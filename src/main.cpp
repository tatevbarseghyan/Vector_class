#include "vector.hpp"
#include <iostream>

int main()
{
    vector <int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    vector <int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(2*i);
    }
    std::cout << "Print vector v            : ";
    std::cout << v;
    std::cout << "Print other vector v1     : ";
    std::cout << v1;
    v1 = v;;
    std::cout << "Print vector v1 using v1=v : ";
    std::cout << v1;
    v.pop_back();
    std::cout << "Pop_back  : ";
    std::cout << v;
    v.insert(9,9);
    std::cout <<"Insert item : ";
    std::cout << v;
    v[3] = 5;
    std::cout <<"Change item : ";
    std::cout << v;
    std::cout << "Vector size is : " << v.get_size() << std::endl;
    v.insert(5,0);
    std::cout <<"Isert item: ";
    std::cout << v;
    v.remove(5);
    std::cout <<"Remove item  : ";
    std::cout << v;
    v.remove(19);
    std::cout << "End element is : " << v.end_element() <<std::endl;
    for (int i =0; i < 10; ++i) {
        v.pop_back();
    }
    v.pop_back();
    std::cout << v;
}

