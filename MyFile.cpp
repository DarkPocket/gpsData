#include "MyFile.h"



MyFile :: MyFile()
{
        name = "";
        //      fileId=0;
        // fileId= 0;
}

void MyFile ::sortDataBytime(  vector<GPS> &myGpsData)
{
        std::cout << " 正在按时间排序数据  " << std::endl;

        std::sort(myGpsData.begin(), myGpsData.end(), GPS::SortBySmallTime);
        std::cout << "  排序完成  " << std::endl;



}

void MyFile ::sortDataByObj(   vector<GPS> &myGpsData )
{
        std::cout << " 正在按对象排序数据  " << std::endl;

        std::sort(myGpsData.begin(), myGpsData.end(), GPS::SortByObj);
        std::cout << "  排序完成  " << std::endl;

}


void MyFile ::outputDataToFile( vector<GPS> &myGpsDatas, string  fileName )
{
        ofstream fileWrite;

        fileWrite.open(fileName, ios::out );
        if (!  fileWrite.is_open())
        {
                cout << "Error opening file write" << fileName;
                exit (1);
        }

        std::cout << " 正将数据写入本地文件中 " << std::endl;

        int i = 0;
        for (std::vector<GPS>::iterator it = myGpsDatas.begin() ; it != myGpsDatas.end() ; it++ )
        {
                //  std::cout<<
                //    it->show() ;
                fileWrite << it->toString() << std::endl;

                ++i;
                //   cout << i << " ,";
                //     std::cout << it->toString() << std::endl;
                //<<std::endl;
        }

        std::cout << "写入完成  共 " << i << "条数据"  << std::endl;


        fileWrite.close();


}

void MyFile ::File(string in)
{
        //打开数据文件
        //读取数据
        //写入数据
        string allData = "allData.txt";
        //   name = allData;

        ofstream fileWrite;
        ifstream fileRead;




        fileWrite.open(allData, ios::out );
        if (!  fileWrite.is_open())
        {
                cout << "Error opening file write" << allData;
                exit (1);
        }

        //     long int counts = 0;

        fileRead.open(in, ios::in );
        if (! fileRead.is_open())
        {
                cout << "Error opening file" << in;
                exit (1);
        }

        char buffer[128] = {0};

        fileRead.getline(buffer, 100);
        //    fileWrite << buffer << endl;
        while (!fileRead.eof())
        {

                if (recordno >= recordNum)
                {
                        cout << "记录数量超过最大设定值 " << recordNum << "忽略后面数据" << endl;
                        break ;
                }
                // strcpy(buffer,"");
                fileRead.getline(buffer, 100);

                if ( strlen(buffer) < 1)
                {

                }
                else
                {
                        recordno++;
                        //    cout << buffer << endl;
                        GPS  gpsbuf ;
                        translateString(gpsbuf, buffer);
                        //    gpsbuf.show() ;
                        myGpsData.push_back(gpsbuf);
                        // fileWrite << buffer << endl;
                }

        }
        //recordno
        cout << "记录数 " << recordno << endl;



        //    std::sort(myGpsData.begin(), myGpsData.end(), GPS::SortBytime);

        int i = 0;
        for (std::vector<GPS>::iterator it = myGpsData.begin() ; it != myGpsData.end() ; it++ )
        {

                fileWrite << it->toString() << std::endl;

                ++i;

                //      std::cout << it->toString() << std::endl;
                //<<std::endl;
        }

        fileWrite.close();


        offset = new int [recordno + 1];
        recorded = new int [recordno + 1];



        ofstream dataWrite;

        string fileBuf = name + ".txt";
        string databuf = name + "-data.txt";
        long pos = 0;
        std::cout << fileBuf << std::endl;
        fileWrite.open(fileBuf, ios::out );
        dataWrite.open(databuf, ios::out | ios::binary );

        fileWrite << recordno << endl;
        for (std::vector<GPS>::iterator it = myGpsData.begin() ; it != myGpsData.end() ; it++ )
        {

                pos = dataWrite.tellp();
                recorded[ i] = 64 ;
                offset[i] = pos;



                string qstr = it->toString();
                char q[1024] = {0};
                strcpy(q, qstr.c_str() );


                //      Record recordTemp(1024, q );

                dataWrite.write(  q, recorded[ i] );


                fileWrite << recorded[ i] << " " << offset[i]  << endl;

                //      std::cout << it->toString() << std::endl;
                //<<std::endl;
        }

        dataWrite.close();

        //vector<GPS> myGpsData;
        fileRead.close();
        fileWrite.close();


        return ;
}

string MyFile ::translateString(GPS &gpsbuf, string str)
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
        //    cout << times << endl ;
        //    cout << a << " " << b << endl ;
        gpsbuf.setObjId( id);
        gpsbuf.setx( a);
        gpsbuf.sety(b);
        gpsbuf.setTime(times);

        //   gpsbuf.show();

        //    printf("b name %s \n", buf[4]);

        //   cout << "id name " << id << endl ;
        /*
        sscanf(bufstr, "%[^,],%lf,%lf,%s", buf[1], &a, &b, buf[2]);
        // sscanf(bufstr, "%[^,]%[^,]%[^,]%s", buf[1], buf[2],  buf[3], buf[4]);
        // sscanf(bufstr, "%[^,]%s %s %s", buf[1], buf[2],  buf[3], buf[4]);
        //  a = atof(buf[2] );
        //   b = atof(buf[3] );

        cout << buf[1] << endl;
        cout << buf[2] << endl ;

        printf("a %lf ", a);
        printf("b %lf ", b);
        cout << a << " " << b << endl ;
        cout << buf[3] << endl;
        */

        return buf1;
}

string MyFile ::getName()
{
        return name;
}

string MyFile ::setName(string names)
{

        //cout<<"setName"<<endl;
        name = names;
        return name;
}
void MyFile ::setRecordno(int num)
{
        if ((num > 0) && ( num < recordNum ))
        {
                recordno = num;
        }
        else
        {
                recordno = 1;
        }
}


int MyFile ::scanObj( string objList[])
{


        int i = 0, j = 0, k = 1;
        for (std::vector<GPS>::iterator it = myGpsData.begin() ; it != myGpsData.end() ; it++ )
        {


                for (j = 0; j < k; ++j)
                {
                        if ( it->getObj( ) == objList[j])
                        {
                                break ;
                        }
                }
                if (j == k)
                {
                        objList[k++] = it->getObj( ) ;

                }

                ++i;
                //     cout << i << " ,";
                //     std::cout <<  it->getObj( )  << std::endl;

        }

        for (j = 0; j < k; ++j)
        {
                std::cout << objList[j] << std::endl;
        }

        return k;
}

void MyFile ::lookObj(  string objList[] , int k)
{
        int x;

        cout << "共 " << k - 1 << " 个对象" << endl;


        cout << "访问第x个对象" << endl;
        cin >> x;

        if ((x < 1) || (x > k - 1))
        {
                cout << "访问对象不存在" << endl;
                x = 1;
                cout << "自动访问第1个对象" << endl;
        }

        int j = 0;
        for (std::vector<GPS>::iterator it = myGpsData.begin() ; it != myGpsData.end() ; it++ )
        {
                if (  it->getObj( ) == objList[x ])
                {
                        j++;

                        std::cout <<  it->toString()  << std::endl;
                        if (j > 10)
                        {
                                break;
                        }

                }


        }

}

int MyFile ::getObjlongestTime(  string objList[] , int k)
{
        int j = 0, x = 1, i;

        Time timeTemp[k][2];



        for (std::vector<GPS>::iterator it = myGpsData.begin() ; it != myGpsData.end() ; it++ )
        {
                if (  it->getObj( ) == objList[x ])
                {
                        // cout<<
                        //    it->show();
                }
                else
                {
                        ++x;
                        j = 0;
                }
                if (j == 0)
                {
                        timeTemp[x][0] = it->getTime( );
                        timeTemp[x][1] = timeTemp[x][0];
                }
                j++;

                if (  timeTemp[x][1] < it->getTime( ))
                {
                        timeTemp[x][1] = it->getTime( );
                }

                /*
                                cout << x << "  . ";
                                cout << timeTemp[x][0].toString() << " - " ;
                                cout << timeTemp[x][1].toString() << endl;

                                getchar();
                */

        }
        long int longestTime = 0, t = 0;
//int j=0;
        cout << "  时间 " << endl;
        for (i = 1; i < k; ++i)
        {
                t = Time::   get_Difference_between_times(   timeTemp[i][0], timeTemp[i][1] );
                if (longestTime < t)
                {
                        j=i;
                        longestTime = t;
                }


        }

        cout << j << ". ";
        cout << timeTemp[j][0].toString() << " - " ;
        cout << timeTemp[j][1].toString() << endl;

        cout << " 时间长度   " << longestTime << "s" << endl;


   cout <<  endl;
}
