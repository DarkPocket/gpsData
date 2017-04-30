#include <iostream>
#include "DataManagement.h"

using namespace std;


int test( )
{

        //fun1
        string databaeName = "Trajectory";
        Database Trajectory( databaeName) ;
        string dataFileName = "rawdata.txt";  //rawdatastest.txt";
        Trajectory.AddFile(dataFileName);

        //        Trajectory.Print();

        //fun2
        //排序输出数据
        Trajectory.fun2();

       Trajectory.fun3();
        Trajectory.fun4();
        Trajectory.fun5();

        Trajectory.CloseFile(dataFileName  );

        Database Trajectory2(Trajectory);

        Trajectory2.Print();
        Trajectory2.fun4();



        return 0;
}


int main()
{
        test();

        cout << "Hello world!" << endl;

        system("pause");
        return 0;
}
