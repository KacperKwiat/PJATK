#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::string Battelfield[11][11];
std::string ship_place[10];
int column_position;
int first_letter;
int letter;
std::string placment;
std::string row;
int row_position;
char shooting_position[30];
int tab_size;
int row_shot;
int column_shot;
std::string user_row;
int count_z=0;

std::string position[30];

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
	if(64<first_letter && first_letter<75){
		 system("continue");
	 }else{
		 std::cout<<"Prosze uruchomic program ponownie tym razem wprowadzajac wszytkie pole uzywajac wielkich liter oraz pamietaj o przedziale od A do J"<<std::endl;
		 exit(1);
	 }
	/* row= ship.at(1);
	 row_position= std::atoi(row.c_str());
	 row_position=row_position+1;	
	 if(row_position>9 || row_position<0){
		 std::cout<<"Po literze oznaczajacej kolumne prosze wpisac cyfre wiersza od 0 do 9\n";
	 }else{
		 system("conitinue");
	 }*/
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
				 std::cout<<"Zle rozlozenie statku: "<<ship<<std::endl;
				 showBattelfield();
				 exit(1);
				 
			 }
			 Battelfield[row_position+i][column_position]="x";
		 }
	 }else{
		 for(int i=0;i<ship_size;i++){
			 			 if(Battelfield[row_position][column_position+i]!=" "){
				 std::cout<<"Zle rozlozenie statku: "<<ship<<std::endl;
				 showBattelfield();
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
					showBattelfield();
					exit(1);
				}
			}
		}		
	 }else{
		 for(int j=0;j<ship_size+1;j++){
			 for(int k=0; k<2;k++){
				if(Battelfield[row_position-1][column_position+j]=="x" || Battelfield[row_position+1][column_position+j]=="x" || Battelfield[row_position][column_position+ship_size]=="x" || Battelfield[row_position-1][column_position-1]=="x" || Battelfield[row_position-1][column_position+k]=="x"){
							 std::cout<<"Sprawdz rozstawienie swoich statkow pamietaj ze musi byc co najmniej jedna kratka odstepu pomiedzy nimi. Przeszkadzajacy statek jest na pozycji: "<<ship<<std::endl;
							 showBattelfield();
							 exit(1);
						 }
					 }
				 }
			}  
		 
 }
 
 bool user_uppercase(std::vector<std::string>vec)
 {

	for(auto s: vec){
		first_letter=s.front();
		if(64<first_letter && first_letter<75){
			return true;
			 system("continue");
		 }else if(first_letter==0){
			 return true;
			 system("continue");
		 }else if(64>first_letter || first_letter>75){
			 std::cout<<"Podane dane sa bledne prosze je zmienic "<<std::endl;
			 return false;
			 break;
			 
		 }
	 }
	exit(0);
 
 }
 void shots(std::vector<std::string>vec)
 {
	
	 for(auto x: vec){
		 column_shot=x.front();
		 user_row=x.at(1);
		 row_shot=std::atoi(user_row.c_str());
		 column_shot=column_shot-64;
		 row_shot=row_shot+1;
		 if(Battelfield[row_shot][column_shot]==" "){
			 Battelfield[row_shot][column_shot]="P";
		 }else if(Battelfield[row_shot][column_shot]=="x"){
			 Battelfield[row_shot][column_shot]="T";
			 count_z=count_z+1;
		 }else if(Battelfield[row_shot][column_shot]=="T" || Battelfield[row_shot][column_shot]=="P" || Battelfield[row_shot][column_shot]=="Z"){
			 Battelfield[row_shot][column_shot]="D";
			
		 }else if(column_shot<0){
			 break;
		 }
	 }
	
 }
 void aircraft_status(std::string ship)
 {
	 column_position = ship.front();
	 row= ship.at(1);
	 row_position= std::atoi(row.c_str());
	 column_position = column_position-64;
	 row_position=row_position+1;	
	 placment=ship.back();
	if(placment=="v"){
		 if(Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="T"&& Battelfield[row_position+3][column_position]=="T" || Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="T"&& Battelfield[row_position+3][column_position]=="T" || Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="D" && Battelfield[row_position+2][column_position]=="T"&& Battelfield[row_position+3][column_position]=="T" || Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="D"&& Battelfield[row_position+3][column_position]=="T" || Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="T"&& Battelfield[row_position+3][column_position]=="D"|| Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="D"&& Battelfield[row_position+3][column_position]=="D" || Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="D" && Battelfield[row_position+2][column_position]=="T"&& Battelfield[row_position+3][column_position]=="D" || Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="T"&& Battelfield[row_position+3][column_position]=="D" || Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="D" && Battelfield[row_position+2][column_position]=="D"&& Battelfield[row_position+3][column_position]=="T" || Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="D"&& Battelfield[row_position+3][column_position]=="T"|| Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="D" && Battelfield[row_position+2][column_position]=="T"&& Battelfield[row_position+3][column_position]=="T"||Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="D" && Battelfield[row_position+2][column_position]=="D"&& Battelfield[row_position+3][column_position]=="D"||Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="D" && Battelfield[row_position+2][column_position]=="T"&& Battelfield[row_position+3][column_position]=="D" || Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="D"&& Battelfield[row_position+3][column_position]=="D"|| Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="D" && Battelfield[row_position+2][column_position]=="D"&& Battelfield[row_position+3][column_position]=="T"){
			 for(int i=0;i<4;i++){
				 Battelfield[row_position+i][column_position]="Z";
			 }
		 }
	 }else{
		 if(Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="T"&& Battelfield[row_position][column_position+3]=="T" || Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="T"&& Battelfield[row_position][column_position+3]=="T" || Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="D" && Battelfield[row_position][column_position+2]=="T"&& Battelfield[row_position][column_position+3]=="T" || Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="D"&& Battelfield[row_position][column_position+3]=="T" || Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="T"&& Battelfield[row_position][column_position+2]=="D"|| Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="D"&& Battelfield[row_position][column_position+3]=="D" || Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="D" && Battelfield[row_position][column_position+2]=="T"&& Battelfield[row_position][column_position+3]=="D" || Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="T"&& Battelfield[row_position][column_position+3]=="D" || Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="D" && Battelfield[row_position][column_position+2]=="D"&& Battelfield[row_position][column_position+3]=="T" || Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="D"&& Battelfield[row_position][column_position+3]=="T"|| Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="D" && Battelfield[row_position][column_position+2]=="T"&& Battelfield[row_position][column_position+3]=="T"||Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="D" && Battelfield[row_position][column_position+2]=="D"&& Battelfield[row_position][column_position+3]=="D"||Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="D" && Battelfield[row_position][column_position+2]=="T"&& Battelfield[row_position][column_position+3]=="D" || Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="D"&& Battelfield[row_position][column_position+3]=="D"|| Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="D" && Battelfield[row_position][column_position+2]=="D"&& Battelfield[row_position][column_position+3]=="T"){
			 for(int i=0;i<4;i++){
				 Battelfield[row_position][column_position+i]="Z";
			 }
		 }
	 }
				 
 }
 
 void submarine_status(std::string ship)
 {
	 column_position = ship.front();
	 row= ship.at(1);
	 row_position= std::atoi(row.c_str());
	 column_position = column_position-64;
	 row_position=row_position+1;	
	 placment=ship.back();
	 if(placment=="v"){
		 if(Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="T"|| Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="T"||Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="D" && Battelfield[row_position+2][column_position]=="T"||Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="D"||Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="D" && Battelfield[row_position+2][column_position]=="T"||Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="T" && Battelfield[row_position+2][column_position]=="D"||Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="D" && Battelfield[row_position+2][column_position]=="D"){
			 for(int i=0;i<3;i++){
				 Battelfield[row_position+i][column_position]="Z";
			 }
		 }
	 }else{
		 if(Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="T"||Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="T"||Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="D" && Battelfield[row_position][column_position+2]=="T"||Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="D"||Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="D" && Battelfield[row_position][column_position+2]=="T"||Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="T" && Battelfield[row_position][column_position+2]=="D"||Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="D" && Battelfield[row_position][column_position+2]=="D"){
			 for(int i=0;i<3;i++){
				 Battelfield[row_position][column_position+i]="Z";
			 }
		 }
	 }
 }
 
 void cruiser_status(std::string ship)
 {
	 column_position = ship.front();
	 row= ship.at(1);
	 row_position= std::atoi(row.c_str());
	 column_position = column_position-64;
	 row_position=row_position+1;	
	 placment=ship.back();
	 if(placment=="v"){
		 if(Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="T"||Battelfield[row_position][column_position]=="D" && Battelfield[row_position+1][column_position]=="T"||Battelfield[row_position][column_position]=="T" && Battelfield[row_position+1][column_position]=="D"){
			 for(int i=0;i<2;i++){
				 Battelfield[row_position+i][column_position]="Z";
			 }
		 }
	 }else{
		 if(Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="T"||Battelfield[row_position][column_position]=="D" && Battelfield[row_position][column_position+1]=="T"||Battelfield[row_position][column_position]=="T" && Battelfield[row_position][column_position+1]=="D"){
			 for(int i=0;i<2;i++){
				 Battelfield[row_position][column_position+i]="Z";
			 }
		 }
	 } 
 }
 
 void destroyer_status(std::string destroyer)
 {
	 column_position = destroyer.front();
	 row= destroyer.at(1);
	 row_position= std::atoi(row.c_str());
	 column_position = column_position-64;
	 row_position=row_position+1;
	 if(Battelfield[row_position][column_position]=="T"){
		 Battelfield[row_position][column_position]="Z";	
	 } 
 }

void vector_size(std::vector<std::string>vec)
{
	 int vSize=0;
	 int count_place=0;
	 for(auto s: vec){
		
		first_letter=s.front();
		if(64<first_letter && first_letter<91 || 96<first_letter && first_letter<123){
			count_place=count_place+1;
			system("continue");
		}else{
			vSize=vSize+1;
		}
	 }
		vSize=vSize+count_place;
		vec.erase(vec.begin()+count_place, vec.begin()+vSize);
		
	
}

void SHOW_RESULT(std::vector<std::string>vec)
 {
	
	 for(auto x: vec){
		 column_shot=x.front();
		 if(column_shot==0){
			 break;
		 }else{
			 user_row=x.at(1);
			 row_shot=std::atoi(user_row.c_str());
			 column_shot=column_shot-64;
			 row_shot=row_shot+1;
			 std::cout<<Battelfield[row_shot][column_shot]<<" ";
		 }
	 }
	std::cout<<"\n";
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
	
	//user_uppercase(shooting);
	//if(user_uppercase(shooting)==true){
		shots(shooting);
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
		SHOW_RESULT(shooting);
	//}
	/*for(auto s: shooting){
		std::cout<<s<<"\n";
	}*/
	std::fill(std::begin(shooting_position), std::end(shooting_position),' ');
	std::fill(std::begin(position), std::end(position)," ");
	shooting.clear();
	//showBattelfield();
	}while(count_z!=20);
	std::cout<<"\aBrawo wszytkie statki zostaly zatopione!!!\n!!!!!!!Wygrales te rozgrywke!!!!!!\n";
	exit(0);
	
	
}
