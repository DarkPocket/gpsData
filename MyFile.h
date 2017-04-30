#ifndef MYFILE_H
#define MYFILE_H


#include<vector>
#include<algorithm>

#include<functional>
#include<iterator>

#include <fstream>
#include <iostream>

#include "GPS.h"
#include "Record.h"

class MyFile
{
        const int recordNum = 200000;
        string name; //文件名称
        int recordno; //包含记录的个数,  设定上限 10 万
        int* recorded; //记录标识
        int* offset; //每个记录在文件里的起始位置

        //  int fileId;
public:
        vector<GPS> myGpsData;

        MyFile ();

        void   File(string in); //创建文件，初始化记录个数
        int WriteRecord(Record*);//向文件添加一个记录，以二进制形式将记录写入文件
        //调整记录个数、初始位置，返回写入记录的大小，失败则为-1
        int ReadRecord(int recordid);//从文件读取记录
        //返回读入记录的大小，失败则-1

        string  translateString(GPS &gpsbuf, string str);
        string getName();
        string setName(string names);
void setRecordno(int num);
        void sortDataBytime(  vector<GPS> &myGpsData);
        //将vector中的数据 按时间大小排序
        void sortDataByObj(   vector<GPS> &myGpsData );

        void  outputDataToFile( vector<GPS> &myGpsDatas, string  fileName );

        int  scanObj( string objList[]);
        int getObjlongestTime(  string objList[] , int k);

        void lookObj(  string objList[] , int k);
};
//文件头部{记录个数,  记录标识数组、偏移量数组} //磁盘上存储形式
#endif // MYFILE_H
