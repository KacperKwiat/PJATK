#ifndef student //nazwa nie musi byc taka sama jak plik
#define student

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Student
{
	private:
	string imie;
	string nazwisko;
	string indeks;
	int semestr;
	float srednia;
	public:
	Student(std::string im, std::string naz, std::string in, int sm, float sr)
	{
		imie=im;
		nazwisko=naz;
		indeks=in;
		semestr=sm;
		srednia=sr;

	}	
		auto const to_string() -> std::string
	{
		auto result = std::ostringstream{};
		result << imie << " " <<nazwisko << " ("<<indeks<<") semestr: " << semestr << " srednia: "<< srednia;
		return result.str();    
    }
};
#endif
