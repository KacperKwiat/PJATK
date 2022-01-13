#include <iostream>
#include <iostream>
#include <unistd.h>
#include "Item.h"

int main(){
    
	Creature Terminator("T-800", 100);
	Item* bron = new Weapon();
	Item* potka= new Potion();
	Item* maczeta = new Sword();
	Item* siekierka = new Axe();
	Item* luk = new Bow();
	Item* potka_zycia = new Hp_Potion();
	do{
	luk->use_on(Terminator);
	Terminator.get_hp();
	Terminator.check_hp();
	sleep(1);
	maczeta->use_on(Terminator);
	Terminator.get_hp();
	Terminator.check_hp();
	sleep(1);
	potka_zycia->use_on(Terminator);
	Terminator.get_hp();
	Terminator.check_hp();
	sleep(1);
	siekierka->use_on(Terminator);
	Terminator.get_hp();
	Terminator.check_hp();
	sleep(1);
	potka_zycia->use_on(Terminator);
	Terminator.check_hp();
	sleep(1);
	}while(Terminator.zycie>0);
	return 0;
}
