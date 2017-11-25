#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date
{
    public:
        enum Month {january = 1, february, march, april, may, june, july, august, september, october, november, december};

        Date();
        ~Date();
        Date(int y, Month m, int d);
        Date(int y, int m, int d);
        Date(const Date& other);
        Date operator=(const Date& other);
        bool operator<(const Date& other);
        friend bool operator>(const Date& lhs, const Date& rhs);
        Date operator++(int);

        int getDaysInMonth();
        bool isLeapYear();
        void incrementDay();
        void incrementMonth();
        void incrementYear();

        int getDay();
        void setDay(int d);

        Month getMonth();
        void setMonth(Month m);

        int getYear();
        void setYear(int y);

        string toString();
        void print();

    private:
        int day;
        Month month;
        int year;
};

#endif // DATE_H
