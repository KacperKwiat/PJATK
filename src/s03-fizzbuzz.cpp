#include <iostream>
#include <unistd.h>
int liczba;
int main()
{
std::cout << "Podaj swoja liczbe: ";
std::cin >> liczba;
for (liczba; liczba>=1; liczba--)
{
sleep(0.920);
if(liczba % 3 == 0 && liczba % 5 == 0)
{
std::cout<< "FizzBuzz " <<liczba<< "\n";
}else if(liczba % 3 ==0 && liczba % 5 != 0)
{
std::cout<<"Fizz "<<liczba<<"\n";
}else if(liczba % 5 ==0 && liczba  % 3 !=0)
{
std::cout<<"Buzz "<<liczba<< "\n";
}else if (liczba % 3!= 0 && liczba % 5 !=0)
{
std::cout<<liczba<<"\n";
}
}
return 0;
}
