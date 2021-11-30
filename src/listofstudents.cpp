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
	Student(std::string imie, std::string nazwisko, std::string indeks, int semestr): imie(imie), nazwisko(nazwisko), indeks(indeks), semestr(semestr){}
	std::string get_imie(){return this->imie;}
	std::string get_nazwisko(){return this->nazwisko;}
	std::string get_indeks(){return this->indeks;}
	int get_semestr(){return this->semestr;}
	void pokaz()
	{
		std::cout<<imie<<" "<<nazwisko<<" "<<indeks<<" "<<semestr<<"\n";
	}
};
void lista(std::vector<Student*> vectorStudent)
{
	int i=0;
	for( Student* student : vectorStudent)
	{					
	std::cout << i << " ";
	student->pokaz();
	i++;
	}
}


std::string imie()
{
	std::string imie;
	std::cout<<"Podaj imie: ";
	std::cin>>imie;
	return imie;
}

std::string nazwisko()
{
	std::string nazwisko;
	std::cout<<"Podaj nazwisko: ";
	std::cin>>nazwisko;
	return nazwisko;

}

std::string indeks()
{
	std::string indeks;
	std::cout<<"Podaj indeks studenta: ";
	std::cin>>indeks;
	return indeks;
}



int semestr()
{
	int semestr;
	std::cout<<"Podaj, na ktorym semestrze jestes: ";
	std::cin>>semestr;
	return semestr;

}

auto main()-> int

{
	std::vector<Student*>vectorStudent;
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

	switch(wybor)
	{

	case 1:
		
		
		vectorStudent.push_back(new Student{imie(),nazwisko(),indeks(),semestr()});
		
		wielkosc=vectorStudent.size();
		std::cout<<"Wielkosc wektora: "<<wielkosc<<"\n";
			
		break;
		
	case 2:
		std::cout<<"Podaj, ktorego studenta chcesz usunac: ";
		std::cin>>usun;
		vectorStudent.erase(vectorStudent.begin() + (usun-1));
		std::cout<<"Student nr: "<<usun<<" zostal usuniety\n";
		break;

	case 3:
		lista(vectorStudent);
		break;
	case 0:
		exit(1);
		break;
		
	}
}
		return 0;
}
