


#ifndef DATAMANAGEMENT_H
#define   DATAMANAGEMENT_H




#include <cstdlib>
#include "MyFile.h"

#include<sstream>

//using namespace std;

class Database
{
        const int fileNum = 50;
        string name;
        int fileno;    //设定上限 50
        MyFile * gps_file; //管理数据文件
        string* des; //文件作用


public:
        static int databaseID ;
        Database(string in);
        Database(const Database& in);//拷贝构造函数，完成数据库复制
        //数据库、文件名称加后缀“2”，同时需对文件进行复制
        void Print();//输出文件名及作用
        int  AddFile(string name); //添加文件
        int GetFile(string name, MyFile*); //获取文件
        int CloseFile(string name); //关闭文件
        ~Database();



     string intToString(int n);
     int stringToInt(string str);
        int fun2( );
        int fun3();
        int fun4();
        int fun5();
};
//数据库对应文件  Trajectory
//文件头{数据库名称、文件个数、文件名称、文件作用} //磁盘上存储形式









#endif // DATAMANAGEMENT_H
