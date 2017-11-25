#include <iostream>

#include "Date.h"

using namespace std;

void testDate();

int main()
{
    Date date = Date(1995, 3, 38);
    Date d2 = Date(1995, 12, 1);

    if(date < d2)
        cout << "True";
    else
        cout << "False";

    cout << endl;
    testDate();


}

void testDate()
{
    Date date (1995, 12, 15);

    while(date.getMonth() != Date::may)
    {
        date.print();
        cout << endl;
        date++;
    }
}
