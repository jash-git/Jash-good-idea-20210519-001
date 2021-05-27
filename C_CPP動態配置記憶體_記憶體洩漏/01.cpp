//https://mp.weixin.qq.com/s/WvAsjLhgGlRJsxFPLAI3lw
//https://www.tutorialspoint.com/compile_cpp_online.php

#include <iostream>

using namespace std;

class Babe
{
public:
    Babe()
    {
        cout << "Create a Babe to talk with me" << endl;
    }

    ~Babe()
    {
        cout << "Babe don\'t Go away,listen to me" << endl;
    }
};


int main()
{
    int *a = new int[10];
    for(int i=0;i<10;i++)
    {
        a[i]=i;
        cout<< a[i]<<"\t";
    }
    cout<<"\n";
    delete a;        //方式1
    //delete[] a;     //方式2

    Babe* pbabe = new Babe[3];
    delete []pbabe;//會GG的寫法-> delete pbabe;
    
    pbabe = new Babe[3];
    delete[] pbabe;
   
   return 0;
}
/*
$g++ -o main *.cpp
$main
0	1	2	3	4	5	6	7	8	9	
Create a Babe to talk with me
Create a Babe to talk with me
Create a Babe to talk with me
Babe don't Go away,listen to me
Babe don't Go away,listen to me
Babe don't Go away,listen to me
Create a Babe to talk with me
Create a Babe to talk with me
Create a Babe to talk with me
Babe don't Go away,listen to me
Babe don't Go away,listen to me
Babe don't Go away,listen to me
*/