#include <iostream>
#include <unistd.h>
int liczbapiw;
int main()
{
std::cout<<"Podaj liczbe piw: ";
std::cin>>liczbapiw;
for(liczbapiw; liczbapiw>=0; liczbapiw--)
{
std::cout<< liczbapiw << " bottels of beer on the wall, " <<
liczbapiw << " bottels of beer. Take one down pass it around, "<<"\n";
sleep(1);
if(liczbapiw == 0)
{
std::cout<< "No more bottels  of beer on the wall no more bottels of beer. Go to the store and buy some more, 99 bottels of beer..."<<"\n";

}
}

return 0;
} 
