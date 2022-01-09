#include <iostream>
#include <string>
#include <sstream>
std::string Battelfield[11][11];
std::string ship_place[10];
int column_position;
int first_letter;
std::string placment;
std::string row;
int row_position;
int sunk_ships;
const int MAX=100;
char shooting_position[30];
std::string get_position[30];

void showBattelfield()
{
		 for(int i=0; i<11;i++){
			 std::cout<<"\n";
			for(int j=0;j<11;j++){
				std::cout<<"\t";
				std::cout<<Battelfield[i][j]<<" ";
		 }
			std::cout<<std::endl;
	 }
	 
}

void check_uppercase(std::string ship)
{
	first_letter=ship.front();
	if(64<first_letter && first_letter<91){
		 system("continue");
	 }else{
		 std::cout<<"Prosze uruchomic program ponownie tym razem wprowadzajac wszytkie pole uzywajac wielkich liter"<<std::endl;
		 exit(1);
	 }
 }
 
 void set_ships(std::string ship, int ship_size)
 {
	 column_position = ship.front();
	 row= ship.at(1);
	 row_position= std::atoi(row.c_str());
	 column_position = column_position-64;
	 row_position=row_position+1;	
	 placment=ship.back();
	 if(placment=="v"){
		 for(int i=0;i<ship_size;i++){		 
			 if(Battelfield[row_position+i][column_position]!=" "){
				 std::cout<<"Zle rozlozenie statku: "<<ship<<" wychodzi poza obszar rozgrywki"<<std::endl;
				 show();
				 exit(1);
				 
			 }
			 Battelfield[row_position+i][column_position]="x";
		 }
	 }else{
		 for(int i=0;i<ship_size;i++){
			 			 if(Battelfield[row_position][column_position+i]!=" "){
				 std::cout<<"Zle rozlozenie statku: "<<ship<<" wychodzi poza obszar rozgrywki"<<std::endl;
				 show();
				 exit(1);
				 
			 }
			 Battelfield[row_position][column_position+i]="x";
		 }
	 }
	 
	 //to check if every ship has a one hash gap bettwen them
	 if(placment=="v"){
		for(int j=0; j<ship_size+1;j++){
			for(int k=0; k<2;k++){
				if(Battelfield[row_position+j][column_position+1]=="x" || Battelfield[row_position+j][column_position-1]=="x" || Battelfield[row_position+ship_size][column_position]=="x" || Battelfield[row_position-1][column_position+k]=="x" || Battelfield[row_position-1][column_position-1]=="x"){
					std::cout<<"Sprawdz rozstawienie swoich statkow pamietaj ze musi byc co najmniej jedna kratka odstepu pomiedzy nimi. Przeszkadzajacy statek jest na pozycji: "<<ship<<std::endl;
					show();
					exit(1);
				}
			}
		}		
	 }else{
		 for(int j=0;j<ship_size+1;j++){
			 for(int k=0; k<2;k++){
				if(Battelfield[row_position-1][column_position+j]=="x" || Battelfield[row_position+1][column_position+j]=="x" || Battelfield[row_position][column_position+ship_size]=="x" || Battelfield[row_position-1][column_position-1]=="x" || Battelfield[row_position-1][column_position+k]=="x"){
							 std::cout<<"Sprawdz rozstawienie swoich statkow pamietaj ze musi byc co najmniej jedna kratka odstepu pomiedzy nimi. Przeszkadzajacy statek jest na pozycji: "<<ship<<std::endl;
							 show();
							 exit(1);
						 }
					 }
				 }
			}  
		 
 }
 
 void user_uppercase(std::string tab[],int size_tab)
 {
	
	for(int i=0;i<size_tab;i++){
		first_letter=tab[i].front();
		if(64<first_letter && first_letter<91){
			 system("continue");
		 }else{
			 std::cout<<"Prosze ponownie wprowadzic swoje pola: "<<std::endl;
			 break;
		 }
	}
 
 }

	 

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
	
	std::cout<<"Prosze teraz podac pozycje, ktore maja zostac odsloniete(program przyjmnie maksymalnie 10 pol):\n";
	std::cin.getline(shooting_position,30);
	std::string position(shooting_position);
	for(int i=0;i<30;i++){	
		get_position[i]=position[i];
	}
	
	for(int j=0;j<30;j){
		get_position[j]=get_position[j]+get_position[j+1];
		j=j+3;
	}
	user_uppercase(get_position,30);


	//showBattelfeild();
	return 0;
}