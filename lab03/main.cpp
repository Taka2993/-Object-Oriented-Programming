
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>


using namespace std;

vector <double> numbers;



int main()
{
    printf("Enter number: ");
    double input = 0;

    do
    {
        cin >> input;

        if (input < 0)
        {
            break;
        }
        else
        {
            printf("Enter number: ");
            numbers.push_back(input);
        }
    }

    while (input >= 0);


    for (int i = 0;i < numbers.size(); ++i)
    {
        sort(numbers.begin(), numbers.end());
        cout << fixed;
        cout << setprecision(3) << numbers[i]<< endl ;
    }



    return 0;
}