#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "SHIP.h"

auto main(int argc, char* argv[])->int
{

	if(argc!=11){
		std::cout<<"Podano bledne dane uruchom program ponownie pamietaj aby wpisac dokladnie 10 pol na ktorych chcesz umiescic swoje statki\n";
		exit(0);
	}
	
	//fulling array with empty strings
	
	 for(int i=0; i<11;i++){
			for(int j=0;j<11;j++){
				Battelfield[i][j]=" ";
		 }
	 }
	
	//assining position of the ship
	
	 auto const aircraft= std::string{argv[1]};//statek 4 masztowe
	 auto const submarine1= std::string{argv[2]};//statki 3 masztowe
	 auto const submarine2= std::string{argv[3]};
	 auto const cruiser1= std::string{argv[4]};//statki 2 masztowe
	 auto const cruiser2= std::string{argv[5]};
	 auto const cruiser3= std::string{argv[6]};
	 auto const destroyer1= std::string{argv[7]};//statki 1 masztowe
	 auto const destroyer2= std::string{argv[8]};
	 auto const destroyer3= std::string{argv[9]};
	 auto const destroyer4= std::string{argv[10]};
	 
	 //checking the correction of given positions
	 
	 check_uppercase(aircraft);
	 check_uppercase(submarine1);
	 check_uppercase(submarine2);
	 check_uppercase(cruiser1);
	 check_uppercase(cruiser2);
	 check_uppercase(cruiser3);
	 check_uppercase(destroyer1);
	 check_uppercase(destroyer2);
	 check_uppercase(destroyer3);
	 check_uppercase(destroyer4);
	 
	 //setting the Battelfield
	 
	 Battelfield[0][0]="-";
	 Battelfield[1][0]="0";
	 Battelfield[2][0]="1";
	 Battelfield[3][0]="2";
	 Battelfield[4][0]="3";
	 Battelfield[5][0]="4";
	 Battelfield[6][0]="5";
	 Battelfield[7][0]="6";
	 Battelfield[8][0]="7";
	 Battelfield[9][0]="8";
	 Battelfield[10][0]="9";
	 
	 Battelfield[0][1]="A";
	 Battelfield[0][2]="B";
	 Battelfield[0][3]="C";
	 Battelfield[0][4]="D";
	 Battelfield[0][5]="E";
	 Battelfield[0][6]="F";
	 Battelfield[0][7]="G";
	 Battelfield[0][8]="H";
	 Battelfield[0][9]="I";
	 Battelfield[0][10]="J";

	//setting position of aircraft
	set_ships(aircraft,4);
	 
	//setting position of submarine1
	set_ships(submarine1,3);
	
	//setting position of submarine2
	set_ships(submarine2,3);
	
	//setting position of crusier1
	set_ships(cruiser1,2);
	
	//setting position of crusier2
	set_ships(cruiser2,2);
	
	//setting position of crusier3
	set_ships(cruiser3,2);
	
	//setting position of destroyer1
	set_ships(destroyer1,1);
	
	//setting position of destroyer2
	set_ships(destroyer2,1);
	
	//setting position of destroyer3
	set_ships(destroyer3,1);
	
	//setting position of destroyer4
	set_ships(destroyer4,1);
	
	bool prawda;
	do{
	int vSize=0;
	std::vector<std::string>shooting;
	std::cout<<"Prosze teraz podac pozycje, ktore maja zostac odsloniete(program przyjmnie maksymalnie 10 pol):\n";
	std::cin.getline(shooting_position,30);
	std::string position[30];
	for(int i=0;i<31;i++){
		position[i]=std::string{shooting_position[i]};
	}
	
	for(int i=0;i<31;i){
		std::string x;
		x=position[i]+position[i+1];
		shooting.push_back(x);
		i=i+3;
	}
	vector_size(shooting);
	shooting.shrink_to_fit();
	for(std::string x: shooting){ 
		prawda=user_uppercase(x);	
		if(prawda==true){
			shots(x);
			aircraft_status(aircraft);
			submarine_status(submarine1);
			submarine_status(submarine2);
			cruiser_status(cruiser1);
			cruiser_status(cruiser2);
			cruiser_status(cruiser3);
			destroyer_status(destroyer1);
			destroyer_status(destroyer2);
			destroyer_status(destroyer3);
			destroyer_status(destroyer4);
			SHOW_RESULT(x);
		}		
	}
	
	shooting.clear();
	shooting.shrink_to_fit();
	std::fill(std::begin(shooting_position), std::end(shooting_position),' ');
	std::fill(std::begin(position), std::end(position)," ");
	//showBattelfield();
	}while(count_z!=20);
	std::cout<<"Brawo wszytkie statki zostaly zatopione!!!\n!!!!!!!Wygrales te rozgrywke!!!!!!\n";
	exit(0);
}
