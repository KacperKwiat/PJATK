#include <iostream>
#include <string>
#include <sstream>

struct Time{
	int godzina;
	int minuta;
	int sekunda;
	enum class TimeofDay
	{
		morning,
		afternoon,
		evening,
		night,
	};
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
		   case TimeofDay::morning:
		   return "mornig";
		   case TimeofDay::afternoon:
		   return "afternoon";
		   case TimeofDay::evening:
		   return "evening";
		   case TimeofDay::night:
		   return "night";
		   default:
		   break;
	   }
        
    }
    TimeofDay timeday()
    {
		if(godzina<11&&godzina>6){
			return TimeofDay::morning;
			}else if(godzina>11 && godzina<18){
				return TimeofDay::afternoon;
			}else if(godzina>18 && godzina<22){
				return TimeofDay::evening;
			}else if(godzina>22 && godzina<6){
			return TimeofDay::night;
		}
		exit(1);
	};
};
	

auto main()-> int
{
	auto czas = Time{23,59,59};
	czas.nextSecond();
	std::cout<<czas.to_string()<<std::endl;
	//#######################################################
	auto time= Time{12,45,34};
	time.timeday();
	std::cout<<time<<std::endl;
	
	
	
	return 0;
}
