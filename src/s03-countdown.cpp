#include <iostream>
#include <string> 
#include <cstdlib>
#include <unistd.h>

auto main (int argc, char* argv[])-> int 
{
if (argc <=1)
{
std::cout << "Brak argumentu";
return 1;
}
auto number = std::stoi(argv[1]);
int temp = number;
if (number>0)
{
for (auto i =0; i<= number ; i++)
{
std::cout << number << "\n";
sleep(1);
number--;
}
}
else
{
for (auto i = 0; i>=1; i++)
{
std::cout << number << "\n";
sleep(1);
number++;
}
}
return 0;
}
