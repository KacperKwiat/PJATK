
#include <iostream>
#include <string>

auto main()-> int
{
std::string password = "student";
auto line = std::string{};

do 
{
std::getline(std::cin, line);

if(line == password){
std::cout << "ok!";
}else{
std::cout << "zle haslo  ";
}
}while(line != password);

return 0;
}
