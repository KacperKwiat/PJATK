#include <iostream>
#include <string>
#include <sstream>
#include "s03-student.h"

using namespace std;

auto main() ->int
{
	auto st = Student{"Kacper","Kwiatkowski","s24533", 1, 3.6};
	cout<<st.to_string()<<std::endl;
	
	return 0;
}
	
