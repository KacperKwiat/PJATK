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
	int nextHour()
	{

		if(godzina==23)
		{
			godzina=0;
		}else{
			godzina++;
			}
			return godzina;
	}
	int nextMinute()
	{

		if(minuta==59)
		{
			minuta=0;
			nextHour();
		}else{
			minuta++;
		}
		return minuta;
	}
		int nextSecond()
		{

			if(sekunda==59)
			{
				sekunda=0;
				nextMinute();
			}else{
				sekunda++;
			}
			return sekunda;
		}
	
};
auto main()-> int
{
	auto czas = Time{23,59,59};

	czas.nextSecond();
	std::cout<<czas.to_string()<<std::endl;
	return 0;
}
