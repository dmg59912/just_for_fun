#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

//    simple lamda sample

/*void for_each(const std::vector<int>&, void(*func)(int)); /// second parameter tells what the lamda function needs to be 
int main(void)
{
	std::vector<int> values = { 1,5,4,2,3 };
	//we will use a lamda fuction to prin to values
	//for_each(values, [](int values) {std::cout << "Value: " << values << std::endl; });

	//  or we can use the follwing 
	auto lamda = [](int values) {std::cout << "Value: " << values << std::endl; };

	for_each(values,lamda);
	return 0;
}

void for_each(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}

*/
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------


int main(void)
{
	std::vector<int> values = { 1,5,4,2,3 };
	auto it = std::find_if(values.begin(), values.end(), [](int values) { return values > 3; });

	std::cout << *it << std::endl;


	
	return 0;
}
