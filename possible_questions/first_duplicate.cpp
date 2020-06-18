#include<iostream>
#include<vector>


/* Given an array a that contains only numbers in the range from 1 to a.length, find the first duplicate number for which 
the second occurrence has the minimal index. In other words, if there are more than 1 duplicated numbers, return the number
for which the second occurrence has a smaller index than the second occurrence of the other number does. If there are no such 
elements, return -1


For a = [2, 1, 3, 5, 3, 2], the output should be firstDuplicate(a) = 3.

There are 2 duplicates: numbers 2 and 3. The second occurrence of 3 has a smaller index than the second occurrence of 2 does, so the answer is 3.

For a = [2, 2], the output should be firstDuplicate(a) = 2;

For a = [2, 4, 3, 5, 1], the output should be firstDuplicate(a) = -1.


Guaranteed constraints:
1 ≤ a.length ≤ 105,
1 ≤ a[i] ≤ a.length.
meaning that it cannnot be less than 1 or greater than the lenght of the array

*/   


int firstDuplicate(std::vector<int> a);

int main(void)
{
    std::vector<int> sample = { 2,1,3,5,3,2 };
    std::vector<int> sample2 = { 2,4,3,5,1 };

    std::cout << "First duplicate for our sample vector " << std::endl;
    for (int i = 0; i < sample.size(); ++i)
        std::cout << sample[i] << "  ";

    std::cout << std::endl;
    std::cout << "is ";

    std::cout << firstDuplicate(sample) << std::endl;

    std::cout << "\nAnother sample is " << std::endl;
    for (int i = 0; i < sample2.size(); ++i)
        std::cout << sample2[i] << "  ";

    std::cout << std::endl;
    std::cout << "is "; 
    std::cout << firstDuplicate(sample2) << std::endl;
    std::cout << "is -1 because it does not have a duplicate in the array " << std::endl;

}



// we are trying to map by the index of the value to the array index setting to -1 if seen again the idexed will be map tp -1 and boom, we hit repeatin value

int firstDuplicate(std::vector<int> a)
{
    for (int i = 0; i < a.size(); ++i)
    {
     if (a[abs(a[i]) - 1] < 0)
           return abs(a[i]); // look out our index -1, if already negative then we will return that value since it was already mapped from a previous element
     else
           a[abs(a[i]) - 1] = -a[abs(a[i]) - 1]; // everytime we see an elemente we are looking the array of the value minus 1 and making it negative
    }

    return -1;

}
