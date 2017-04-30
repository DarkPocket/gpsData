#ifndef GPS_H
#define GPS_H


#include<cstring>

#include "Time.h"

class GPS
{
        Time t;
        float x, y;
        string obj_id; //或者  string   int
public:
        string translateString(string str)  ;//
        string toString( );
        void setObjId( string  id );
        string getObj( );
        Time getTime( );
        void setx(  float x );
        void sety(  float y );
        void setTime(string timestr);
        void show(  );
        void show( int n )  ;   //  n>0 换行
        //    static      bool SortBytime ( const GPS &v1, const GPS &v2);

        static      bool SortBySmallTime (    GPS &v1,    GPS &v2);
        //从小到大
        static      bool SortByBigTime (  GPS &v1,  GPS &v2);
        //从大到小

        //对象排序
        static bool SortByObj(   GPS &v1,  GPS &v2);
        //  friend bool SortBytime ( const GPS &v1, const GPS &v2);
};
#endif // GPS_H
