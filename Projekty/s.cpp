#include <iostream>
#include <string>
std::string get_position[30];
int tab_size;
int first_letter;
int z=0;
char shooting_position[30];
int main()
{
do{

std::cout<<"Prosze teraz podac pozycje, ktore maja zostac odsloniete(program przyjmnie maksymalnie 10 pol):\n";
	
std::cin.getline(shooting_position,30);
std::string position(shooting_position);
	for(int i=0;i<30;i++){	
		get_position[i]=position[i];

	}
		for(int j=0;j<30;j){
				for(int i=0;i<11;i++){
				get_position[i]=get_position[j]+get_position[j+1];
				j=j+3;
			}
		}
			for(int i=0;i<31;i++){
		first_letter=get_position[i].front();
		if(64<first_letter && first_letter<91 || 96<first_letter && first_letter<123){
			system("continue");
		}else{
			tab_size=i;
			break;
		}
	}
	for(int i=0;i<tab_size;++i){
		std::cout<<get_position[i]<<"\n";
	}
z=z+1;
}while(z!=5);
return 0;
}







