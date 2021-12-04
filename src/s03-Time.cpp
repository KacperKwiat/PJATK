#include <iostream>
#include <string>
#include <sstream>

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
	Time(int g, int m, int s){
		godzina=g;
		minuta=m;
		sekunda=s;
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
  
};

auto main()-> int
{
	auto czas = Time{23,59,59};
	czas.nextSecond();
	std::cout<<czas.to_string()<<std::endl;
	//#######################################################
	std::cout<<czas.string_dwa(czas.timeday())<<std::endl;
	//#######################################################
	
	
	return 0;
}
