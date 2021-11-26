#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

struct Student
{

private:
	std::string imie;
	std::string nazwisko;
	std::string indeks;
	int semestr;

public:

Student(std::string im, std::string naz, std::string in, int sm)

{
	imie=im;
	nazwisko=naz;
	indeks=in;
	semestr=sm;
} 

void pokaz()

{
std::cout<<imie<<" "<<nazwisko<<" "<<indeks<<" "<<semestr<<"\n";
}

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

	std::string im, naz, in;
	int i, wybor, sm, wielkosc;
	std::cout<<"1. Dodawanie nowego studenta\n";
	std::cout<<"2. Usuwanie studenta\n";
	std::cout<<"3. Wyswietlanie pelnej tablicy studentow\n";
	std::cout<<"0. Zakoncz program\n"; 
	std::cout<<"Podaj jaka akcje chcesz wykonac: ";
	std::cin>>wybor;
	std::vector<Student>vectorStudent;

	switch(wybor)

	{

	case 1:

		vectorStudent.push_back(Student{imie(im),nazwisko(naz),indeks(in),semestr(sm)});
		wielkosc=vectorStudent.size();
		std::cout<<"Wielkosc wektora: "<<wielkosc<<"\n";
		break;

		/* case 3:

		i=0;
		for (i; i < vectorStudent.size(); ++i)
		{
		std::cout<<vectorStudent[i];
		}
		break;
		*/ 
	}
		return 0;

}
