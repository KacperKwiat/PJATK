#ifndef time
#define time

#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>

struct Time{
	private:
	int godzina;
	int minuta;
	int sekunda;
	enum class TimeofDay
	{
		rano,
		dzien,
		wieczor,
		noc,
	};
	public:
	Time()=default;
	Time(int g, int m, int s){
		godzina=g;
		minuta=m;
		sekunda=s;
	}
	~Time()
	{
	}

	auto const to_string() -> std::string
	{
		auto result = std::ostringstream{};
		if(godzina<10)
		{
			result << "0"<<godzina<<"::";	
		}else{
			result <<godzina<<"::";
		}
		if(minuta<10)
		{
			result << "0"<<minuta<<"::";	
		}else{
			result <<minuta<<"::";
		}
		if(sekunda<10)
		{
			result << "0"<<sekunda<<"";	
		}else{
			
			result <<sekunda;
		}
		return result.str(); 
	}
	void nextHour()
	{

		if(godzina==23)
		{
			godzina=0;
		}else{
			godzina++;
			}
	}
	void nextMinute()
	{

		if(minuta==59)
		{
			minuta=0;
			nextHour();
		}else{
			minuta++;
		}
	}
		void nextSecond()
		{

			if(sekunda==59)
			{
				sekunda=0;
				nextMinute();
			}else{
				sekunda++;
			}
		}

    std::string string_dwa(TimeofDay pora){
       switch(pora)
       {
		   case TimeofDay::rano:
		   return "rano";
		   case TimeofDay::dzien:
		   return "dzien";
		   case TimeofDay::wieczor:
		   return "wieczor";
		   case TimeofDay::noc:
		   return "noc";
		   default:		   
		   break;
	   }
        exit(0);
    }
      TimeofDay timeday()
    {
		if(godzina<=11&&godzina>=6){
			return TimeofDay::rano;
			}else if(godzina>11 && godzina<=18){
				return TimeofDay::dzien;
			}else if(godzina>18 && godzina<=22){
				return TimeofDay::wieczor;
			}else{
			return TimeofDay::noc;
		}
	}
	auto count_seconds() const -> uint64_t
	{
			uint64_t wynik;
			wynik=godzina*3600+minuta*60+sekunda;
			return wynik;
	}
	auto count_minutes() const -> uint64_t
	{
			uint64_t wynik;
			wynik=godzina*60+minuta;
			return wynik;
	}
	auto time_to_midnight()const -> Time
	{
		Time dopolnocy;
		if(sekunda==0)
		{
			dopolnocy.sekunda=sekunda;
			dopolnocy.minuta=60-minuta;
		}else{
			dopolnocy.minuta=59-minuta;
			dopolnocy.sekunda=60-sekunda;
		}
		if(minuta==0)
		{
			dopolnocy.minuta=minuta;
			dopolnocy.godzina=24-godzina;
			
		}else{
			dopolnocy.godzina=23-godzina;
			dopolnocy.minuta=60-minuta;
		}

		return dopolnocy;
	}
	Time operator+(const Time& other)const
	{
		Time dodaj;
		if(godzina+other.godzina>=24){
			dodaj.godzina=godzina+other.godzina-24;
			
		}else{
			dodaj.godzina=godzina+other.godzina;
		}
		if(minuta+other.minuta>=60){
			dodaj.minuta=minuta+other.minuta-60;
		}else{
			dodaj.minuta=minuta+other.minuta;		
			}
		if(sekunda+other.sekunda>=60){
			dodaj.sekunda=sekunda+other.sekunda-60;		
			}else{
			dodaj.sekunda=sekunda+other.sekunda;		
		}
		return dodaj;
	}
  	Time operator-(const Time& other)const
	{
		Time odejmij;
		if(godzina-other.godzina<0){
			odejmij.godzina=24+(godzina-other.godzina);
		}else if(godzina-other.godzina==0){
			odejmij.godzina=0;
		}	
		else if(godzina-other.godzina>0){
			odejmij.godzina=godzina-other.godzina;
		}
		if(minuta-other.minuta<=0){
			odejmij.minuta=60+(minuta-other.minuta);
			odejmij.godzina--;
		}else{
			odejmij.minuta=minuta-other.minuta;		
			}
		if(sekunda-other.sekunda<=0){
			odejmij.sekunda=60-(sekunda+other.sekunda);	
			odejmij.minuta--;	
			}else{
			odejmij.sekunda=sekunda-other.sekunda;		
		}
		return odejmij;
	}
	auto operator== ( Time const& other) const -> bool
	{
		return (godzina==other.godzina && minuta==other.minuta && sekunda==other.sekunda);
	}
		auto operator!= ( Time const& other) const -> bool
	{
		return !(*this==other);
	}
	auto operator< (Time const& other) const -> bool
	{
		if(godzina<other.godzina){
			return true;
		}else if(godzina>other.godzina){
			return false;
		}else if(godzina==other.godzina && minuta<other.minuta){
			return true;
		}else if(godzina==other.godzina && minuta>other.minuta){
			return false;
		}else if(godzina==other.godzina && minuta==other.minuta && sekunda<other.sekunda){
			return true;
		}else if(godzina==other.godzina && minuta==other.minuta && sekunda>other.sekunda){
			return false;
		}else if(godzina==other.godzina && minuta==other.minuta && sekunda==other.sekunda){
			return false;
		}
		exit(0);
	}
	auto operator> (Time const& other) const -> bool
	{
		if(godzina<other.godzina){
			return false;
		}else if(godzina>other.godzina){
			return true;
		}else if(godzina==other.godzina && minuta<other.minuta){
			return false;
		}else if(godzina==other.godzina && minuta>other.minuta){
			return true;
		}else if(godzina==other.godzina && minuta==other.minuta && sekunda<other.sekunda){
			return false;
		}else if(godzina==other.godzina && minuta==other.minuta && sekunda>other.sekunda){
			return true;
		}else if(godzina==other.godzina && minuta==other.minuta && sekunda==other.sekunda){
			return false;
		}
		exit(0);
	}


};
#endif 
