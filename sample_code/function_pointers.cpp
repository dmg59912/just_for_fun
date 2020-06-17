#include<iostream>
#include<vector>

// function pointerts is basically we a re assigning  a funtion to a variable 
void hello_world( int a);


//sample 
/*int main(void)
{
	
	//auto function = hello_world;
	//or we can do the following, it means the same thing 
	//void(*function)() = hello_world;

	//prefer way for some is instead of auto use typdef

	typedef void(*hello_world_function )(int);// int is a parameter 
	 
	hello_world_function function = hello_world;

	function(8);


	return 0;
}


void hello_world( int a )
{
	std::cout << "Hello world! Value " << a << std::endl;
}

*/
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

//real senario for why we might use funtion pointers 

void print_values(int value);
void for_each(const std::vector<int>&, void(*func)(int) );
int main(void)
{
	std::vector<int> values = { 1,5,4,2,3 };
	for_each(values,print_values);
	return 0;
 }

void for_each(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}

void print_values(int value)
{
	std::cout << "Value " << value << std::endl;
}