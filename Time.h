#ifndef TIME_H
#define TIME_H


#include <iostream>
#include <cstdlib>
#include<cstdio>

using namespace std;

const int arraySize = 100;

class Time
{
        int year, month, day;
        int h, m, s;
public:
        //构造函数、拷贝构造函数、复制函数
        //运算符重载  operator <

        Time();
        virtual ~Time();
        Time(const  Time& other);
        // Time& operator<(const DataManagement& other);
        // bool operator <(const Time& d1,)
        bool operator <(    Time  t2) ;
        bool operator ==(    Time  t2) ;


        //        bool operator <( const   Time  t2) ;

        void   copyTime(Time& copy , const  Time& other);
        void setTime(string timestr);
        void showTime( int n );  //  n>0 换行
        void showTime(  );
        string toString( );

        static        int  look_Days_of_leap_years(int year, int month) ;
        static     long int   get_Difference_between_times(  Time t1, Time  t2) ;

};

#endif // TIME_H
