#include <iostream>
#include <string>

class Person{
	protected:
	std::string name;
	std::string surname;
	
	public:
	Person(std::string imie, std::string nazwisko): name(imie),surname(nazwisko){}
	
	virtual std::string to_string() const = 0;
};

class Mrs : public Person{
	public:
	Mrs(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	auto to_string() const -> std::string{
		return "Mrs " + name + " " + surname;
	}
};
class Mr : public Person{
	public:
	Mr(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	auto to_string() const -> std::string{
		return "Mr " + name + " " + surname;
	}
};
class King : public Person{
	public:
	King(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	auto to_string()const->std::string{
		return "King " + name + " " + surname;
	}
};

class Queen : public Person{
	public:
	Queen(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	auto to_string()const->std::string{
		return "Queen "+ name + " " + surname;
	}
};

auto who_is_it(Person const& osoba) -> std::string{
	return osoba.to_string();
}
class Greeting{
	public:
	virtual std::string greet(Person const& osoba)const = 0;
};
class Hello :public Greeting
{
	auto greet(Person& osoba)const->std::string{
		return "Hello "+ osoba.to_string();
	}
};

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
	Greeting* hello=new Hello();
	std::cout<<hello->greet(*jeden)<<std::endl;
	return 0;
}
