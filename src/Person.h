#ifndef task1
#define task1
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
class Greeting
{
	public:
	virtual std::string greetings(Person const& osoba) = 0;
};

class Hello : public Greeting{
	std::string greetings(Person const& osoba){
		return "Hello " + osoba.to_string();
	}
};

class Good_evening : public Greeting{
	std::string greetings(Person const& osoba){
		return  "Good evening " + osoba.to_string();
	}
};

class Farewell : public Greeting{
	std::string greetings(Person const& osoba){
		return "Farewell " + osoba.to_string();
	}
};

#endif
