#include <iostream>
#include <cstdlib>
#include <ctime> 

int main ()
{
int liczba, proba;
std::cout << "Hej pomyslalem sobie o liczbie miedzy 1 do 100" << "\n";
std::srand(time(NULL));
liczba = rand() % 100+1;;
while (proba!=liczba)
{
std::cout << "Zgadnij jaka to liczba: " << "\n";
std::cin>> proba;
if (proba==liczba)
{
std::cout << "Brawo wygrales!!!"<< "\n";
}
else if  (proba<liczba)
{
std::cout << "Za malo" << "\n";
}
else if (proba>liczba)
{
std::cout << "Za duzo" << "\n";
}
}
return 0;
}
