#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

struct Student
{

	std::string imie;
	std::string nazwisko;
	std::string indeks;
	int semestr;

};



std::string imie(std::string im)
{
	std::cout<<"Podaj imie: ";
	std::cin>>im;
	return im;
}

std::string nazwisko(std::string naz)
{
	std::cout<<"Podaj nazwisko: ";
	std::cin>>naz;
	return naz;

}

std::string indeks(std::string in)
{
	std::cout<<"Podaj indeks studenta: ";
	std::cin>>in;
	return in;
}



int semestr(int sm)
{
	std::cout<<"Podaj, na ktorym semestrze jestes: ";
	std::cin>>sm;
	return sm;

}

auto main()-> int

{
	while(true)
	{

	std::string im, naz, in;
	int wybor, sm, wielkosc, usun;
	std::cout<<"######################################\n";
	std::cout<<"1. Dodawanie nowego studenta\n";
	std::cout<<"2. Usuwanie studenta\n";
	std::cout<<"3. Wyswietlanie pelnej tablicy studentow\n";
	std::cout<<"0. Zakoncz program\n"; 
	std::cout<<"Podaj jaka akcje chcesz wykonac: ";
	std::cin>>wybor;
	std::cout<<"######################################\n";
	std::vector<Student>vectorStudent;

	switch(wybor)
	{

	case 1:
		
		
		vectorStudent.push_back(Student());
		vectorStudent.push_back(Student{imie(im),nazwisko(naz),indeks(in),semestr(sm)});
		
		wielkosc=vectorStudent.size();
		std::cout<<"Wielkosc wektora: "<<wielkosc<<"\n";
	
			
		break;
		
	case 2:
		std::cout<<"Podaj, ktorego studenta chcesz usunac\n Pamietaj musisz podac liczbe miedzy zero a numerem ostatniego studenta z listy: ";
		std::cin>>usun;
		vectorStudent.erase(vectorStudent.begin() + usun);
		break;

	case 3:

		for (int i=0; i < vectorStudent.size(); ++i)
		{
			std::cout<<vectorStudent[i].imie<< " "<<vectorStudent[i].nazwisko<<" "<<vectorStudent[i].indeks<<" "<<vectorStudent[i].semestr<<"\n";
		}
			
		break;
	
		
	}
}
		return 0;
}
