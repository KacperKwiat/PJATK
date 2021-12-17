#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
#include "s03-Time.h"

auto main()-> int
{
	auto czas = Time{23,59,59};
	czas.nextSecond();
	std::cout<<czas.to_string()<<std::endl;
	//#######################################################
	std::cout<<czas.string_dwa(czas.timeday())<<std::endl;
	//#######################################################
	std::cout<<"Od polnocy minelo "<<czas.count_seconds()<<" sekund\n";
	std::cout<<"Od polnocy minelo "<<czas.count_minutes()<<" minut\n";	
	std::cout<<"Do polnocy "<<czas.time_to_midnight().to_string()<<"\n";
	//#######################################################
	auto czas2 = Time{4,2,5};
	Time wynik=czas+czas2;
	std::cout<<wynik.to_string()<<std::endl;
	Time wynik2=czas-czas2;
	std::cout<<wynik2.to_string()<<std::endl;
	bool rownosc = wynik==wynik2;
	std::cout<<"Jesli jest 1 to "<<czas.to_string()<<" i " <<czas2.to_string()<<" sa rowne: "<<rownosc<<std::endl;
	bool nierownosc= czas!=czas2;
	std::cout<<"Jesli jest 1 to "<<czas.to_string()<<" i " <<czas2.to_string()<<" sa rozne: "<< nierownosc<<std::endl;
	bool mniejszosc= czas<czas2;
	std::cout<<"Jesli jest 1 to "<<czas.to_string()<<" jest mniejsze: "<<mniejszosc<<std::endl;
	bool wiekszosc= czas>czas2;
	std::cout<<"Jesli jest 1 to "<<czas.to_string()<<" jest wiekszy: "<<wiekszosc<<std::endl;
	return 0;
}
