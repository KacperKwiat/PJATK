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
 
 bool user_uppercase(std::string s)
 {
		first_letter=s.front();
		if(64<first_letter && first_letter<75){
			return true;
			system("continue");	
		}else if(first_letter==0){
			system("continue"); 
		}else{
			std::cout<<"Podano bledne dane\n";
			return false;
		}
		return false;
}



 void shots(std::string x)
 {
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
			system("continue");
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

void SHOW_RESULT(std::string s)
 {
	
	 
		 column_shot=s.front();
		 if(column_shot==0){
			 system("continue");
		 }else{
			 user_row=s.at(1);
			 row_shot=std::atoi(user_row.c_str());
			 column_shot=column_shot-64;
			 row_shot=row_shot+1;
			 std::cout<<Battelfield[row_shot][column_shot]<<" ";
		 }
	 
	std::cout<<"\n";
 }
