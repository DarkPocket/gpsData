#ifndef RECORD_H
#define RECORD_H

#include <iostream>
using namespace std;



enum Type {FIXED, VARIABLE};
class Record
{

        int sizes; //数据大小
        char* buffer; //数据
        Type   t;   //记录类型
        //函数分开写报错
        Record( );

        Record(int a, char *q ) //构造函数
        {

                if ((a > 0) && (a < 1024))
                {

                        buffer = new char [a];
                        *buffer = *q;
                }
                sizes = 1024;


        };
        Record(const Record& in ) //拷贝构造函数
        {
                sizes = in.sizes;
                buffer = new char [in.sizes];
                *buffer = *in.buffer;
                t = in.t;

        }
        Record& operator=(const Record& in)//赋值函数
        {
                sizes = in.sizes;
                //  buffer =new char [in.sizes];
                *buffer = *in.buffer;
                t = in.t;

        };
        ~Record()//析构函数
        {
                delete buffer ;
        }
        virtual int Get(char*, int offset, int n);  // do nothing
        virtual int Put(char*, int offset, int n) ;    // do nothing
};
//Get 和 Put 均返回读入和写数据的字节数目，出错则 -1
class FixedRecord   : public Record
//size = 1024/2048/4096
{
        virtual int Get(char*, int offset, int n);        //memcpy
        virtual int Put(char*, int offset, int n) ;        //memcpy
};
class VariableRecord   : public Record
{
        virtual int Get(char*, int offset, int n) ;      //memcpy
        virtual int Put(char*, int offset, int n) ;     //memcpy
};
//注意：  对于变长记录，  如果  offset +n  超过现有长度，需要重新分配

#endif // RECORD_H
