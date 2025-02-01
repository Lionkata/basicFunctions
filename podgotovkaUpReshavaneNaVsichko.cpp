#include <iostream>
using namespace std;

void factorial(int num)
{
    
    for (int i = 1; i <= num; i++)
    {
       cout <<  (num *= i);
    }
}

int main() 
{
    int number = 6;
   factorial(number);
}
