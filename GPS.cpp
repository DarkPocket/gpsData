#include "GPS.h"



//自定义排序函数
/*
bool  GPS::SortBytime ( const GPS &v1, const GPS &v2)//注意：本函数的参数的类型一定要与vector中元素的类型一致
{

        return v1.t < v2.t;//升序排列
}*/

//注意：本函数的参数的类型一定要与vector中元素的类型一致

bool  GPS::SortBySmallTime (   GPS &v1,    GPS &v2)
{
        //从小到大
        return v1.t < v2.t;//升序排列
}

bool  GPS:: SortByBigTime (  GPS &v1,  GPS &v2)
{
        //从大到小
        return v2.t < v1.t ;//降序排列
}

bool  GPS:: SortByObj(   GPS &v1,  GPS &v2)
{

        if (v1.obj_id == v2.obj_id)
        {
                return v1.t < v2.t;//升序排列
        }

        return v1.obj_id < v2.obj_id;
}


void GPS ::setTime(string timestr)
{
        t.setTime(timestr);
}
void GPS ::show(  )
{
        t.showTime();

        cout << "  " << x << ", " << y;
        cout << " " << obj_id << endl;
}
void GPS ::show( int n )
{

        t.showTime(n);

        cout << "  " << x << ", " << y;
        cout << " " << obj_id << endl;
}


void GPS :: setObjId( string  id )
{
        if (!id.empty())
        {
                obj_id = id;
        }
}

string GPS ::getObj( )
{
        return obj_id;
}

Time GPS ::getTime( )
{
        return t;
}
void GPS ::setx(  float X )
{
        x = X;
}
void GPS ::sety(  float Y )
{
        y = Y;
}
string GPS ::translateString(string str)
{
        //"4/1/2014 0:11:00",40.769,-73.9549,"B02512"
        //转化  4/1/2014 0:11:00   40.769 -73.9549 B02512
        string buf1 = "";
        string buf2 = "";

        int i, j = 0;
        char strs[arraySize] = {0};

        strcpy(strs , str.c_str() );
        char bufstr[arraySize] = {0};

        for (i = 0; i < str.size(); i++)
        {

                if ((strs[i] == ',') || (  strs[i] == '\"'))
                {
                        bufstr[j++] = ' ' ;
                        //i++;
                }
                else
                {
                        bufstr[j++] = strs[i] ;
                }
        }


        //     cout << " bufstrstrs  " <<  bufstr << endl;
        // 4/1/2014 0:11:00 40.769 -73.9549 B02512

        char buf[6][arraySize] = {0};
        double a, b;


        sscanf(bufstr, "%s%s%s%s%s", buf[0], buf[1], buf[2],  buf[3], buf[4]);
        /*   for (i = 0; i < 5; i++)
           {
                   printf("%d  = %s \n", i, buf[i]);
           }
        */
        strcat( buf[0], " ");
        strcat( buf[0], buf[1]);

        string times = buf[0];
        a = atof(buf[2] );
        b = atof(buf[3] );

        string id = buf[4];

        obj_id = id;
        x = a;
        y = b;
        t.setTime(times);

        /*
        gpsbuf.setObjId( id);
        gpsbuf.setx( a);
        gpsbuf.sety(b);
        gpsbuf.setTime(times);*/
        return buf1;
}

string GPS ::toString( )
{
        char temp[arraySize ] = {0};

        sprintf(temp, " %0.4f %0.4f %s", x, y, obj_id.c_str());

        string buf =   t.toString();
        buf += temp ; // = month + " " + day + " " + year + " " + h + " " + m + " " + s;
        return buf;


}
