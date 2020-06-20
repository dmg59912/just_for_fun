#include<iostream>
#include<string>




char firstNotRepeatingCharacter(std::string s);
int main(void)
{
    const char* sample_char = "jairo";

    std::cout << "First none repeated letter in " << sample_char << " is " << std::endl;
    std::cout << firstNotRepeatingCharacter(sample_char) << std::endl;


	return 0;
}

char firstNotRepeatingCharacter(std::string s)
{
    // check our index of a given character gives us the same value whitch will be 0 then there is only one unique value
    // else it would give us different values since the first index 0 is not equal to the last index 'however many values of that given charecter index'
    for (int i = 0; i < s.length(); ++i)
    {
        if (s.find_first_of(s.at(i) ) == s.find_last_of(s.at(i)))
            return s.at(i);
    }
    return '_';
}






/// this is one way but it might be o(n^2)
/*
char firstNotRepeatingCharacter(std::string s)
{
    char non_repeat;
    // bool seen else not seen
    bool seen = false;
    int index;
    for (int i = 0; i < s.size(); ++i)
    {
        // we set it to false because during out second loop it has the potential to come back to true even if not seen
        // from previous iteration 
        seen = false; 

        for (int j = i + 1; j < s.size(); ++j)
        {
            if (s[i] == s[j])
            {

                s[j] = '_';
                seen = true;
            }
        }

        if (seen == false)
        {
            index = i;
            break;
        }
    }

    return s[index];

}


*/
