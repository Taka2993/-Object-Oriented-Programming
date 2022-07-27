#include <iostream>
#include <string>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

vector<string> member()
{
    string input;
    int found ;
    vector<string> col;

    printf("Enter stop to quit.\n\n");

    do
    {
        printf("Enter a new string: ");
        getline(cin, input);
        found = input.find("stop");
        if (found == -1)
        {
            col.push_back(input);
        }


    } while (found == -1);

    return col;
}


int main()
{
    int position ;
    int i ;
    int length ;
    int total_capacity = 0;
    vector<string> result;

    result = member();

    printf("\nStrings you entered:\n");
    position = 0;
    length = result[0].size();
    i = 0;

    for (auto re : result)
    {
        cout << re << endl;
        if (result[i].size() > length)
        {
            position = i;
            length = result[position].size();
        }
        total_capacity += result[i].capacity();
        i++;
    }

    cout << "\nNumber of strings               =  "<< result.size() << endl;

    cout << "Longest string                  =  "<< result[position] << endl;
    cout << "Length of the longest string    =  "<< length << endl;

    cout << "Capacity of vector              =  "<< total_capacity << endl;


    return 0;
}