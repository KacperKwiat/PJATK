#include <iostream>
#include <string>
#include <sstream>

struct Time{
	private:
	int godzina;
	int minuta;
	int sekunda;
	public:
	Time(int g, int m, int s){
	godzina=g;
	minuta=m;
	sekunda=s;
	}
	
	auto const to_string() -> std::string
	{
		auto result = std::ostringstream{};
		result << godzina<<"::"<<minuta<<"::"<<sekunda<<"\n";
		return result.str(); 
	}
	nextHour();
	{
		if(godzina==23)
		{
			godzina=0;
		}else{
			godzina++;
			}
	}
	nextMinute();
	{
		if(sekunda==59)
		{
			minuta=0;
		}else{
			minuta++;
		}
	}
		nextSecond();
		{
			if(sekunda==59)
			{
				sekunda=0;
			}else{
				sekunda++;
			}
		}
	
};
auto main()-> int
{
	auto czas = Time{23,59,59};
	std::cout<<czas.to_string()<<std::endl;
	return 0;
}
