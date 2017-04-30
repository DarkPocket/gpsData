#include "DataManagement.h"



int Database::databaseID = 0 ;

Database:: Database(string in)
{
        fileno = 0;
        name = in;

        databaseID++;

        gps_file = new MyFile[fileNum];



        des = new string[fileNum] ;

}
Database::  Database(const Database& in)
{
        //拷贝构造函数，完成数据库复制

        //数据库、文件名称加后缀“2”，同时需对文件进行复制
        string namebuf ;
        cout << "拷贝构造函数  " << in.name << endl;


        gps_file = new MyFile[fileNum];
        des = new string[fileNum] ;

        databaseID++;
        std::string IDstr;
        IDstr =  intToString(databaseID);




        string databuf;
        ifstream fileRead;
        ofstream fileWrite;

        fileRead.open( in.name + ".txt", ios::in );

        if (!  fileRead.is_open())
        {
                cout << "Error opening file write" <<  in.name ;
                system("pause");
                exit (1);
        }

        namebuf =  in.name + intToString( databaseID) + ".txt" ;

        fileWrite.open(  namebuf , ios::out );
        if (!  fileWrite.is_open())
        {
                cout << "Error opening file write" << namebuf;
                system("pause");
                exit (1);
        }
        // system("pause");
        fileRead >> databuf;
        fileWrite << databuf << endl;

        name = databuf;
        // cout <<  " databuf  " << databuf << endl;

        fileRead >> databuf;
        fileWrite << databuf << endl;
        fileno = atoi(databuf.c_str());

        cout <<  " fileno  " << fileno << endl;
        int i = 0;
        for (i = 1; i <= fileno; ++i)
        {
                fileRead >> databuf;
                gps_file[i ].setName( databuf)   ;
                cout <<  databuf << endl;

                fileWrite << databuf + intToString( databaseID) << endl;
        }

        for (  i = 1; i <= fileno; ++i)
        {
                fileRead >> databuf;
                des[i ]  = databuf;
                // << endl;
                cout <<  databuf << endl;
                fileWrite << databuf  << endl;
        }

        fileRead.close();
        fileWrite.close();
        // fileRead.close();
        /*    string namebuf;
            int n = 1;

            for (i = 1; i <= fileno; ++i)
            {
                    for (n = 1; n <= fileNum; ++n)
                    {
                            namebuf =    "record" + intToString(n);
                            if (namebuf == gps_file[i ].getName())
                            {
                                    break ;
                            }
                    }
            }
        */

        //     ofstream fileWrite;
        i = 1;
        //复制record文件

        namebuf =  gps_file[i ].getName()   +  ".txt";

        fileRead.open( namebuf, ios::in );
        if (!  fileRead.is_open())
        {
                cout << "Error opening file write" << namebuf;
                exit (1);
        }
        namebuf = gps_file[i ].getName() + intToString( databaseID) + ".txt" ;

        fileWrite.open(  namebuf , ios::out );
        if (!  fileWrite.is_open())
        {
                cout << "Error opening file write" << namebuf;
                exit (1);
        }

        fileRead >> databuf ;
        gps_file[i].setRecordno(stringToInt(databuf) ) ;
        fileWrite << databuf;

        char buffer[128] = {0};
        int   recorded[ 128];
        int     offset[128] ;

        int j = 0;
        while (!fileRead.eof())
        {
                // fileRead >> databuf ;

                //      fileRead.getline(buffer, 100);

                //  fileRead  >> recorded[ j] >>    >> offset[j]  ;
                fileRead  >> recorded[ j] ;
                fileRead >> offset[j]  ;

                fileWrite << recorded[ j] << " " << offset[j]  << endl;

                /*
                            databuf=buffer ;
                            fileWrite << databuf << endl;
                            strcpy(buffer,"");
                            */
        }

        fileWrite.close();
        fileRead.close();

        //复制recorddata文件
        namebuf = gps_file[i ].getName()   +  "-data.txt";
        fileRead.open(namebuf, ios::in | ios::binary );
        if (!  fileRead.is_open())
        {
                cout << "Error opening file write" << namebuf;
                exit (1);
        }
        namebuf = gps_file[i ].getName() + intToString( databaseID) + "-data.txt";
        fileWrite.open( namebuf, ios::out | ios::binary );
        if (!  fileWrite.is_open())
        {
                cout << "Error opening file write" << namebuf;
                exit (1);
        }
        // recordno
        while (!fileRead.eof())
        {
                //  fileRead >> databuf ;


                fileRead.read( buffer , recorded[ j]    );
                fileWrite.write( buffer, recorded[ j]  );

                //  fileWrite << databuf;
        }

        //   AddFile(gps_file[i ].getName);
        for (std::vector<GPS>::iterator it = in.gps_file[i].myGpsData.begin() ; it != in.gps_file[i].myGpsData.end() ; it++ )
        {


                GPS gpsTemp = *it;

                gps_file[i ].myGpsData.push_back(gpsTemp);


        }



        std::cout << "  vector  GPS  " << std::endl;

        j = 0;
        for (std::vector<GPS>::iterator it = gps_file[i ]. myGpsData.begin() ; it !=  gps_file[i ].myGpsData.end() ; it++ )
        {

                //  fileWrite << it->toString() << std::endl;

                ++j;

                std::cout << it->toString() << std::endl;
                if (j > 10)
                {
                        break ;
                }
        }


        fileWrite.close();
        fileRead.close();




}
void  Database:: Print()
{
        cout << "输出文件名及作用" << endl;
        int i = 0;
        for ( i = 1; i <= fileno; i++ )
        {
                cout <<  " file  " <<  gps_file[i].getName() << endl; ; // << endl;
                cout <<  " des  " << des[i] << endl;
        }
        //  cout <<  gps_file[fileno].name  ; // << endl;
        // cout << des[fileno] << endl;

        //输出文件名及作用
}
int   Database:: AddFile(string name)
{
        //添加文件
        if ( fileno < fileNum)
        {
                fileno++;
        }
        else
        {
                return -1;
        }
        string str, dataFile;
        cout << "输入记录文件名称" << endl;
        //  cin >> dataFile;
        dataFile = "record"  ;

        cout << "数据文件为" << name << endl;

        str = "save" ;
        cout << "输入文件作用" << endl;
        cin >> str;

        des[fileno ] = str;
        cout << "   des  = " << des[fileno ] << endl;

        char t[256];
        sprintf(t, "%d", fileno);
        dataFile += t;
        gps_file[fileno ].setName(dataFile );


        cout << "读取文件"  << name << endl;
        gps_file[fileno ].File( name ) ;


        return fileno;

}
int  Database:: GetFile(string name, MyFile*)
{
        //获取文件

}
int  Database:: CloseFile(string names)
{
        //关闭文件

        ofstream fileWrite;

        cout  << "关闭文件  close database "  << name << endl;

        getchar();

        fileWrite.open(name + ".txt", ios::out );
        if (!  fileWrite.is_open())
        {
                cout << "Error opening file write" << name;
                exit (1);
        }


        fileWrite << name << endl;
        fileWrite << fileno << endl;

        for (int i = 0; i < fileno; ++i)
        {
                fileWrite <<  gps_file[fileno ].getName() << endl;
        }
        for (int i = 0; i < fileno; ++i)
        {
                fileWrite <<  des[fileno ]  << endl;
        }

        fileWrite  << flush;
        fileWrite.close();

}
int Database:: fun2( )
{
        string timeDataFile = "timeSortData.txt";
        gps_file[fileno ]. sortDataBytime(    gps_file[fileno ].myGpsData);
        gps_file[fileno ].outputDataToFile(gps_file[fileno ].myGpsData, timeDataFile);



        ifstream fileRead;

        fileRead.open( timeDataFile, ios::out );
        if (!  fileRead.is_open())
        {
                cout << "Error opening file write" <<  timeDataFile;
                exit (1);
        }


        int i = 0;
        char buffer[128] = {0};

        do
        {
                strcpy(buffer, "");
                fileRead.getline(buffer, 100);

                GPS gpsTemp;

                gpsTemp.translateString(buffer);

                gpsTemp.show();
                ++i;
        }
        while  (i < 10);


        fileRead.close();
   cout <<  endl;
        return 0;

}


int Database::fun3()
{


        string ObjDataFile = "ObjSortData.txt";
        gps_file[fileno ]. sortDataByObj(    gps_file[fileno ].myGpsData);
        gps_file[fileno ].outputDataToFile(gps_file[fileno ].myGpsData, ObjDataFile);



        ifstream fileRead;

        fileRead.open( ObjDataFile, ios::out );
        if (!  fileRead.is_open())
        {
                cout << "Error opening file write" <<  ObjDataFile;
                exit (1);
        }


        int i = 0;
        char buffer[128] = {0};

        do
        {
                strcpy(buffer, "");
                fileRead.getline(buffer, 100);

                GPS gpsTemp;

                gpsTemp.translateString(buffer);

                gpsTemp.show();
                ++i;
        }
        while  (i < 20);


        fileRead.close();
   cout <<  endl;
        return 0;
}


int Database::fun4()
{
        string objlist[200];

        int k;
        k =   gps_file[fileno ].scanObj(objlist);


        gps_file[fileno ].lookObj(objlist, k);
   cout <<  endl;
        return 0;
}

int Database::fun5()
{
        string objlist[200];

        int k;
        k =    gps_file[fileno ].scanObj(objlist);
        cout << "fun 5" << endl;


        gps_file[fileno ].getObjlongestTime(objlist, k);


   cout <<  endl;
    return 0;
}


string Database::  intToString(int n)
{

        std::stringstream ss;
        std::string  str;
        ss << n;
        ss >>  str;
        return str;
}
int  Database:: stringToInt(string str)
{
        return atoi(str.c_str());
}



Database:: ~Database()
{
       /*

        ofstream fileWrite;





        fileWrite.open(name + ".txt", ios::out );
        if (!  fileWrite.is_open())
        {
                cout << "Error opening file write" << name;
                exit (1);
        }


        fileWrite << name << endl;
        fileWrite << fileno << endl;

        for (int i = 0; i < fileno; ++i)
        {
                fileWrite <<  gps_file[fileno ].getName() << endl;
        }
        for (int i = 0; i < fileno; ++i)
        {
                fileWrite <<  des[fileno ]  << endl;
        }

        fileWrite.close();

        */
        delete    gps_file ;
        delete des;

}




