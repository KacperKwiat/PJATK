#include <iostream>
#include <string>
#include <vector>
#include <cmath>
std::vector<std::string> create_vector(int const argc, char* argv[])
{
    std::vector <std::string> vector_to_create;

    for (int i = 0; i < argc; i++) {
        vector_to_create.push_back(std::string(argv[i]));
    }
    return vector_to_create;
}
int wybor;
float jedynka, dwojka, wynik1, wynik2;
int wykladnik, podstawa, potegowanie=1;
int main(int argc, char*argv[]) 
{
	auto main_vector = create_vector(argc, argv);
	int num1;
	int num2;
	std::cout<<"Wybier numer działania, które chcesz wykonać."<<"\n";
	std::cout<<"1. Dodawanie (+)"<<"\n";
	std::cout<<"2. Reszta z dzielenie (%)"<<"\n";
	std::cout<<"3. Dzielenie liczb całkowitych (//)"<<"\n";
	std::cout<<"4. Mnozenie  (*)"<<"\n";
	std::cout<<"5. Dzielenie (/)"<<"\n";
	std::cout<<"6. Potegowanie  (**)"<<"\n";
	std::cout<<"7. Pierwiastkowanie kwadratowe (sqrt)"<<"\n";
	std::cout<<"Twoj wybor: ";
	std::cin>>wybor;
	
    num1 = std::stoi(argv[1]);
    
    num2 = std::stoi(argv[2]);

    for (int i = 1; i < argc-1; i = i + 1) 
    {

        switch (wybor)
        {
            case 1:
                std::cout<< (num1+num2)<<"\n";
                break;
            case 2:
                std::cout<< (num1%num2)<<"\n";
                break;
            case 3:
				std::cout<< (num1/num2)<<"\n";
                break;
            case 4:
                std::cout<< (num1*num2)<<"\n";
                break;
            case 5:
				jedynka=num1;
				dwojka=num2;
				std::cout<<(jedynka/dwojka)<<"\n";
				break;
			case 6:
				wykladnik=num2;
				podstawa=num1;
				for(int i=0; i<wykladnik; i++)
				{
					potegowanie*=podstawa;
				}
				std::cout<<potegowanie<<"\n";
				break;
			case 7:
				jedynka=num1;
				dwojka=num2;
				wynik1=sqrt(jedynka);
				wynik2=sqrt(dwojka);
				std::cout<<"Pierwiastek pierwszej liczby to: "<<wynik1<<"\n"<<"Pierwiastek drugiej liczby to: " <<wynik2<<"\n";
			
            default:
                break;
        }
    }
    return (0);
}
		
