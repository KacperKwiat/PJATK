#ifndef andriod
#define android
#include <iostream>
#include <iostream>
#include <unistd.h>
class Creature
{
	public:
	std::string nazwa;
	int zycie;
	Creature(std::string name, int hp) : nazwa(name), zycie(hp){}
	
	void get_hp()
	{
        std::cout<<nazwa<<": "<<zycie<<"HP \n";
	}
	void check_hp()
	{
		if(zycie<0){
			std::cout<<"Android zostal powstrzymany"<<"\n";
			exit(0);
		}
	}
};

class Item
{
	public:
	virtual void use_on(Creature& character) = 0;
	virtual int strength() const = 0;
};


class Weapon : public Item
{
	public:
	void use_on(Creature& character){
	character.zycie = character.zycie - strength();
	}
	int strength() const{
	return 10;
	}
    
};
class Sword : public Weapon
{
	void use_on(Creature& character){
	character.zycie = character.zycie - strength();
	std::cout<<"Uzyto maczety \n";
	}
	int strength() const{
	return 35;
	}
};
class Axe : public Weapon
{
	void use_on(Creature& character){
		character.zycie = character.zycie - strength();
	std::cout<<"Uzyto siekierki \n";
	 }
	int strength() const{
	return 20;
	}
};
class Bow : public Weapon
{
	void use_on(Creature& character){
	character.zycie = character.zycie - strength();
	std::cout<<"Uzyto luku \n";
	}
	int strength() const{
	return 5;
	}
};

class Potion : public Item
{
	public:
	void use_on(Creature& character){
        character.zycie = character.zycie + strength();
	}
	int strength() const{
	return 10;
	}
};
class Hp_Potion : public Potion
{
	public:
	int used_potion = 0;
	void use_on(Creature& character){
		if(used_potion < 3){
			std::cout<<"Uzyto potki na hp \n";
			character.zycie = character.zycie + strength();
			this->used_potion += 1;
		}
		else{
			std::cout<<"!!!!!!Danger!!!!!Danger!!!!!Danger!!!!!!\n";
			std::cout << "Zuzyto wszytkie potki \n";
			sleep(3);
		}
   	}
	int strength() const{
	return 15;
	}
};
#endif
