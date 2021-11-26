#include <iostream>

struct obiekty
{
    std::string ufo;
    std::string samolot;

    void show(){
        std::cout << this << "\n";
    }

};

auto main()-> int{

    auto obiektylatajace = obiekty();
    obiektylatajace.show();
    std::cout << &obiektylatajace << "\n";
    return 0;

}
