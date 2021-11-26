
#include <iostream>

struct Student
{
	private:
	std::string imie;
	std::string nazwisko;
	public:
	Student(std::string im, std::string naz)
	{
		imie=im;
		nazwisko=naz;

	}	
	~Student()
	{
		std::cout<<"DESTRUCTION!!!!!\n";
		std::cout<<imie<<"\n";
		std::cout<<nazwisko<<"\n";

		
	}
	
	
};
int main()
{
	auto student = Student("Kacper", "Kwiatkowski");
	
	
	return 0;
}

