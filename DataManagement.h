


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
        int fileno;    //�趨���� 50
        MyFile * gps_file; //���������ļ�
        string* des; //�ļ�����


public:
        static int databaseID ;
        Database(string in);
        Database(const Database& in);//�������캯����������ݿ⸴��
        //���ݿ⡢�ļ����ƼӺ�׺��2����ͬʱ����ļ����и���
        void Print();//����ļ���������
        int  AddFile(string name); //����ļ�
        int GetFile(string name, MyFile*); //��ȡ�ļ�
        int CloseFile(string name); //�ر��ļ�
        ~Database();



     string intToString(int n);
     int stringToInt(string str);
        int fun2( );
        int fun3();
        int fun4();
        int fun5();
};
//���ݿ��Ӧ�ļ�  Trajectory
//�ļ�ͷ{���ݿ����ơ��ļ��������ļ����ơ��ļ�����} //�����ϴ洢��ʽ









#endif // DATAMANAGEMENT_H
