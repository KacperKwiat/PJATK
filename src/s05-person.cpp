#include <iostream>
#include <string>
#include "Person.h"

auto main()-> int
{
	
	Person* jeden= new Mrs("Julia", "Nowak");
	Person* dwa= new Mr("Adam", "Kowalski");
	Person* trzy=new King("Henryk", "IV");
	Person* cztery=new Queen("Elizabeth", "II");
	std::cout<<who_is_it(*jeden)<<std::endl;
	std::cout<<who_is_it(*dwa)<<std::endl;
	std::cout<<who_is_it(*trzy)<<std::endl;
	std::cout<<who_is_it(*cztery)<<std::endl;
	Greeting* hello = new Hello();
	Greeting* good = new Good_evening();
	Greeting* farewell = new Farewell();
	std::cout << hello->greetings(*jeden) << "\n";
	std::cout << good->greetings(*dwa) << "\n";
	std::cout << farewell->greetings(*trzy) << "\n";
	std::cout << farewell->greetings(*cztery) << "\n";
	delete jeden;
	
	return 0;
}
