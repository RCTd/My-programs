#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#define LATIME 80// 80-maxim
#define INALTIME 59// 59-maxim
#define INTARZIERE 80//80-recomandat
HANDLE hOut;
char m[INALTIME+2][LATIME+2];
int n[INALTIME+2][LATIME+2];
using namespace std;
int c=15,w;char ch='0';
ofstream g,g1,g2;int k;char tx1[LATIME];
ifstream f,f1;string fn,fm,fm1,tx,de,d1,d2;
void border()
{
    for(int i=0;i<INALTIME;i++)
        for(int j=0;j<LATIME;j++)
            n[i][j]=15;
    SetConsoleTextAttribute( hOut, 15 );
    for(int i=0;i<LATIME-1;++i)
    {
        cout<< '-';
        m[0][i]='-';
    }
    for(int i=0;i<INALTIME-3;++i)
    {
        cout<<"\n|";
        m[i+1][0]='|';
        for(int j=0;j<LATIME-3;++j)
        {
            cout<<' ';
            m[i+1][j+1]=' ';
        }
        cout<<"|";
        m[i+1][LATIME-2]='|';
    }
    for(int i=0;i<LATIME;++i)
    {
        cout<<'-';
        m[INALTIME-2][i]='-';
    }
    SetConsoleTextAttribute(hOut,15);
    cout<<"\nUse arrow keys to move the red dot; ESC to exit;\nTAB to drow; CTRL to enter meniu; SHIFT to erase;";
    cout<<"\nH-to change the character; D-to change the colorc;";
}
void aga()
{
    system("CLS");
    for(int i=0;i<INALTIME-1;i++)
        for(int j=0;j<LATIME;j++)
        {
            k=n[i][j];
            SetConsoleTextAttribute(hOut,k);
            cout<<m[i][j];
        }
    cout<<"Use arrow keys to move the red dot; ESC to exit;\nTAB to drow; CTRL to enter meniu; SHIFT to erase;";
    cout<<"\nH-to change the character; D-to change the colorc;";
}
void meniu()
{
    bool exit=true,exit1=true;
    while((exit==true)&&(exit1==true))
    {
        system("CLS");
        SetConsoleTextAttribute(hOut,15);
        cout<<"C-to clear the screen;\nO-to open an existing file;\n";
        cout<<"S-to save the file;\nE-to exit meniu;\nQ-to delete a file;\n";
        if(GetAsyncKeyState(0x51))//Q
        {
            cin>>de;d1=de+"n.txt";d2=de+"d.txt";de+=".txt";
            remove(de.c_str());remove(d1.c_str());remove(d2.c_str());
            exit=false;
        }
        if(GetAsyncKeyState(0x53))//S
        {
            exit=false;cin>>fm;
            fn=fm+"n.txt";
            fm1=fm+"d.txt";
            fm+=".txt";g.open(fm.c_str());
            g1.open(fn.c_str());g2.open(fm1.c_str());
            for(int i=0;i<INALTIME-1;i++)
            {
                for(int j=0;j<LATIME;j++)
                {
                    g<<m[i][j];g<<"\n";
                    g1<<n[i][j];g1<<"\n";
                    g2<<m[i][j];
                }
                g2<<"\n";
            }
            g.close();g1.close();g2.close();
        }
        if(GetAsyncKeyState(0x43))//C
        {
            exit1=false;
            system("CLS");
            border();
        }
        if((GetAsyncKeyState(0x45))||(exit==false))//E
        {
            aga();
            exit=false;
        }
        if(GetAsyncKeyState(0x4F))//O
        {
            exit1=false;fm='\0';fn='\0';
            cin>>fm;fn=fm+"n.txt";int i=0,j=0;
            fm+=".txt";system("CLS");
            f.open(fm.c_str());
            f1.open(fn.c_str());
            while(getline(f,tx))
            //for(int x=0;x<INALTIME*LATIME;x++)
            {
                tx1=tx.c_str();
                j++;
                f1>>c;
                n[i][j]=c;
                m[i][j]=tx1;
                SetConsoleTextAttribute(hOut,c);
                cout<<tx;
                if(j==LATIME)
                {
                    i++;j=0;
                }
            }
            cout<<"Use arrow keys to move the red dot; ESC to exit;";
            cout<<"\nTAB to drow; CTRL to enter meniu; SHIFT to erase;";
            cout<<"\nH-to change the character; D-to change the colorc;";
            f.close();f1.close();c=15;
        }
        Sleep(INTARZIERE+50);
    }
}
struct ball
{
    float x,y,ox,oy;
    ball(int _x,int _y)
    {
        x=float(_x);y=float(_y);
    }
    void draw()
    {
        COORD p;p.X=int(ox);p.Y=int(oy);
        SetConsoleCursorPosition(hOut,p);
        if(GetAsyncKeyState(VK_TAB))
        {
            SetConsoleTextAttribute(hOut,c);//c
            cout<<ch;
            n[p.Y][p.X]=c;
            m[p.Y][p.X]=ch;
        }else
        {
            if(m[p.Y][p.X]==' ')
            {
                cout<<' ';m[p.Y][p.X]=' ';
            }else
            {
                if(GetAsyncKeyState(VK_SHIFT))
                {
                    cout<<' ';m[p.Y][p.X]=' ';
                }else
                {
                    w=n[p.Y][p.X];
                    SetConsoleTextAttribute(hOut,w);
                    cout<<m[p.Y][p.X];
                }
            }
        }
        p.X=int(x);p.Y=int(y);
        SetConsoleCursorPosition(hOut,p);
        SetConsoleTextAttribute(hOut,12);
        cout<<'0';
        ox=x;oy=y;
    }
};
int main()
{
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT DisplayArea={0,0,LATIME,INALTIME+3};
    SetConsoleWindowInfo(hOut,TRUE,&DisplayArea);
    border();COORD f;f.Y=INALTIME+1;f.X=50;
    ball b(LATIME/2-1,INALTIME/2);
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        if(GetAsyncKeyState(VK_RIGHT)&&b.x!=LATIME-3)
            b.x+=1;
        else
            if(GetAsyncKeyState(VK_LEFT)&&b.x!=1)
                b.x-=1;
        if(GetAsyncKeyState(VK_DOWN)&&b.y!=INALTIME-3)
            b.y+=1;
        else
            if(GetAsyncKeyState(VK_UP)&&b.y!=1)
                b.y-=1;
        if(GetAsyncKeyState(VK_CONTROL))
            meniu();
        if(GetAsyncKeyState(0x48))//H
        {
            SetConsoleCursorPosition(hOut,f);
            cin>>ch;
            SetConsoleCursorPosition(hOut,f);
            cout<<" ";
        }
        if(GetAsyncKeyState(0x44))//D
        {
            system("CLS");
            for(int i=1;i!=8;i++)
            {
                SetConsoleTextAttribute(hOut,i+8);
                cout<<"Press "<<i<<" for this color\n";
            }
            cin>>c;c+=8;aga();
        }
        b.draw();
        Sleep(INTARZIERE);
    }
}
