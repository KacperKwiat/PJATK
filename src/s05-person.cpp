#include <iostream>
#include <string>

class Person{
	
	std::string imie;
	std::string nazwisko;
	
	public:
	Person(std::string im, std::string naz): imie(im),nazwisko(naz)
	{}
	
	virtual std::string to_string() const =0;
};

class Mrs :public Person{
	public:
	Mrs(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	virtual std::string to_string(){
	return "Mrs" + " " +imie+ " " +nazwisko; 
	}
};
class Mr :public Person{
	public:
	Mr(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	return "Mr" + " " +imie+ " " +nazwisko;
	}
};
class King :public Person{
	public:
	King(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	return "King" + " " +imie+ " " +nazwisko;
	}
};
class Queen :public Person{
	public:
	Queen(std::string imie, std::string nazwisko) :Person(imie, nazwisko)
	{}
	virtual std::string to_string(){
	return "Queen" + " " +imie+ " " +nazwisko;
	}
};

auto who_is_it(Person const& osoba) -> std::string{
	return osoba.to_string();
}

auto main()-> int
{
	
	Person *jeden= new Mrs{"Julia", "Nowak"};
	Person *dwa= new Mr{"Adam", "Kowalski"};
	Person *trzy=new King{"Henryk", "IV"};
	Person *cztery=new Queen{"Elizabeth", "II"};
	std::cout<<who_is_it(*jeden)<<std::endl;
	
	return 0;
}
