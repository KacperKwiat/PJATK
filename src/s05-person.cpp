#include <iostream>
#include <string>

class Person{
	protected:
	std::string name;
	std::string surname;
	
	public:
	Person(std::string imie, std::string nazwisko): name(imie),surname(nazwisko)
	{}
	
	virtual std::string to_string() const =0;
};

class Mrs :public Person{
	public:
	Mrs(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	auto to_string()const->std::string{
	return "Mrs" + " " + imie + " " + nazwisko; 
	}
};
class Mr :public Person{
	public:
	Mr(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	auto to_string()const->std::string{
	return "Mr" + " " + imie + " " + nazwisko;
	]
	};
class King :public Person{
	public:
	King(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	auto to_string()const->std::string{
	return "King" + " " + imie + " " + nazwisko;
	}
};

class Queen :public Person{
	public:
	Queen(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	auto to_string()const->std::string{
	return "Queen" + " " + imie + " " + nazwisko;
	}
};

auto who_is_it(Person const& osoba) -> std::string{
	return osoba.to_string();
}

auto main()-> int
{
	
	Person *jeden= new Mrs("Julia", "Nowak");
	Person *dwa= new Mr("Adam", "Kowalski");
	Person *trzy=new King("Henryk", "IV");
	Person *cztery=new Queen("Elizabeth", "II");
	std::cout<<who_is_it(*jeden)<<std::endl;
	
	return 0;
}
