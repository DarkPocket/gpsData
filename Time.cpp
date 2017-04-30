#include "Time.h"




Time ::Time()
{

        year = month = day = 0;
        h = m = s = 0;
}
Time :: Time(const  Time& other)
{
        year = other.year;
        month = other.month;
        day = other.day;
        h = other.h;
        m = other.m;
        s = other.s;

}
void Time ::setTime(string timestr)
{
        //timestr  4/11/2014 0:11:00
        //
        int startpos = 0, endpos = 0;
        string buf ;

        endpos = timestr.find('/', startpos);
        buf = timestr.substr(startpos, endpos - startpos) ;
        //   cout << "buf time " << buf << endl;
        month = atoi( buf.c_str());


        startpos = endpos   + 1;
        endpos = timestr.find('/', startpos);
        buf = timestr.substr(startpos, endpos - startpos) ;
        //   cout << "buf time " << buf << endl;
        day = atoi( buf.c_str());

        startpos = endpos   + 1;
        endpos = timestr.find(' ', startpos);
        buf = timestr.substr(startpos, endpos - startpos) ;
        //     cout << "buf time " << buf << endl;
        year = atoi( buf.c_str());

        startpos = endpos   + 1;
        endpos = timestr.find(':', startpos);
        buf = timestr.substr(startpos, endpos - startpos) ;
        //     cout << "buf time " << buf << endl;
        h = atoi( buf.c_str());

        startpos = endpos   + 1;
        endpos = timestr.find(':', startpos);
        buf = timestr.substr(startpos, endpos - startpos) ;
        //     cout << "buf time " << buf << endl;
        m = atoi( buf.c_str());

        startpos = endpos   + 1;
        endpos = timestr.find(' ', startpos);
        buf = timestr.substr(startpos, endpos - startpos) ;
        //     cout << "buf time " << buf << endl;
        s = atoi( buf.c_str());

        /*
        startpos=timestr.find('/', startpos);
         cout << "startpos " << startpos << endl;
        startpos=timestr.find('/', startpos+1);
         cout << "startpos " << startpos << endl;
        */

        //  cout << " month  " << month << endl;


}

bool Time ::operator ==(    Time  t2)
{
        if ( (year == t2.year) && (month == t2.month ) && (day == t2.day))
        {

        }
        else
        {
                return false;
        }

        if ( (h == t2.h) && (m == t2.m) && (s == t2.s) )
        {

        }
        else
        {
                return false;
        }



        return true;
}



bool Time ::operator <(  Time  t2)
{

        if (year < t2.year)
        {
                return true;
        }
        else
        {
                if (year > t2.year)
                {
                        return false;
                }
        }

        if (month < t2.month)
        {
                return true;
        }
        else
        {
                if (month > t2.month)
                {
                        return false;
                }
        }

        if (day < t2.day)
        {
                return true;
        }
        else
        {
                if (day > t2.day)
                {
                        return false;
                }
        }

        if (h < t2.h)
        {
                return true;
        }
        else
        {
                if (h > t2.h)
                {
                        return false;
                }
        }

        if (m < t2.m)
        {
                return true;
        }
        else
        {
                if (m > t2.m)
                {
                        return false;
                }
        }
        if (s < t2.s)
        {
                return true;
        }
        else
        {
                if (s > t2.s)
                {
                        return false;
                }
        }

        /*
        if (d1.m < d2.month)
        {
                return true;
        }*/

}

void Time ::showTime(  )
{
        cout << " " << month << " " << day << " " << year ;
        cout << " " <<  h << ": " << m << ": " << s ;

        //    cout << endl ;


}
void Time ::showTime(int n  )
{
        cout << " " << month << " " << day << " " << year ;
        cout << " " <<  h << ": " << m << ": " << s ;
        if (n > 0)
        {
                cout << endl ;
        }
        else
        {

        }
}
void  Time ::copyTime(Time& copy , const  Time& other)
{
        copy = other;
}

string Time ::toString( )
{
        char temp[arraySize ] = {0};

        sprintf(temp, "%d/%d/%d %d:%d:%d", month, day, year, h, m, s);
        string buf = temp ; // = month + " " + day + " " + year + " " + h + " " + m + " " + s;
        return buf;
}

long int   Time :: get_Difference_between_times(  Time t1, Time  t2)
{


        long int  secs = 0;
        if (t1 < t2)
        {

        }
        else
        {
                Time temp;
                temp = t1;
                t1 = t2;
                t2 = temp;
        }

        int y, m, d, hour, mins, sec;

        y = t1.year;
        m = t1. month;
        d = t1.day;
        hour = t1.h;
        mins = t1.m;
        sec = t1.s;
        do
        {

                if (    (y == t2.year) && (m == t2.month) && (d == t2. day) && ( hour == t2.h)  && ( mins == t2.m ) && ( sec == t2.s ) )
                {
                        break ;
                }

                sec++;

                if (sec >= 60)
                {
                        mins++;
                        sec = 0;
                }
                if (mins >= 60)
                {

                        hour++;
                        mins = 0;
                }
                if (hour >= 24)
                {

                        d++;
                        hour = 0;
                }

                if (d >  look_Days_of_leap_years(y, m))
                {
                        d = d -  look_Days_of_leap_years(y, m);
                        m++;
                }
                if (m > 12)
                {
                        m = m - 12;
                        y++;
                }
                secs++;




        }
        while ( 1 );




        return secs;

}
int Time ::look_Days_of_leap_years(int year, int month)
{
        int Fer = 0;

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
                Fer = 1;

        }
        else
        {
                Fer = 0;
        }

        int days[ 13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        days[2] += Fer;

        return days[month] ;

}


Time ::~Time()
{


}
