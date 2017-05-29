#include <iostream>
#include <fstream>
#include <windows.h>
#define LATIME 80// 80-maxim
#define INALTIME 59// 59-maxim
#define INTARZIERE 80//80-recomandat
HANDLE hOut;
char m[INALTIME+2][LATIME+2];
using namespace std;
void border()
{
    int i;
    SetConsoleTextAttribute( hOut, 15 );
    for(int i=0;i<LATIME-1;++i)
    {
        cout<< '-';
        m[0][i]='-';
    }
    for(int i=0;i<INALTIME-2;++i)
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
        m[INALTIME-1][i]='-';
    }
    SetConsoleTextAttribute(hOut,15);
    cout<<"\nUse arrow keys to move the red dot; ESC to exit;\nTAB to drow; CTRL to enter meniu;";
};
void meniu()
{
    bool exit=true;
    ofstream g;int c=15;
    ifstream f;
    string fn,tx,ch;
    while(exit==true)
    {
        system("CLS");
        SetConsoleTextAttribute(hOut,15);
        cout<<"C-to clear the screen;\nO-to open an existing file;\n";
        cout<<"S-to save the file;\nH-to change the character;\n";
        cout<<"D-to change the colorc;\nE-to exit meniu\n";
        if(GetAsyncKeyState(0x44))//D
        {
            for(int i=1;i!=8;i++)
            {
                SetConsoleTextAttribute(hOut,i+8);
                cout<<"\nPress "<<i<<" for this color";
            }cout<<endl;
            cin>>c;exit=false;
        }
        if(GetAsyncKeyState(0x48))//H
        {
            cout<<"Choose the character to write with: ";
            cin>>ch;exit=false;
        }
        if(GetAsyncKeyState(0x53))//S
        {
            exit=false;cin>>fn;
            fn+=".txt";g.open(fn.c_str());
            for(int i=0;i<INALTIME-1;i++)
            {
                for(int j=0;j<LATIME;j++)
                    g<<m[i][j];
                g<<"\n";
            }
            g.close();
        }
        if(GetAsyncKeyState(0x4F))//O
        {
            exit=false;fn='\0';
            cin>>fn;fn+=".txt";
            system("CLS");
            SetConsoleTextAttribute(hOut,15);
            f.open(fn.c_str());
            while(getline(f,tx))
                cout<<tx;
            cout<<"Use arrow keys to move the red dot; ESC to exit;";
            for(int i=1;i!=8;i++)
            {
                SetConsoleTextAttribute(hOut,i+8);
                cout<<i<<"=0; ";
            }
            cout<<"\nTAB to drow; CTRL to enter meniu";
            f.close();
        }
        if(GetAsyncKeyState(0x43))//C
        {
            exit=false;
            system("CLS");
            border();
        }
        if((GetAsyncKeyState(0x45))||(exit==false))//E
        {
            exit=false;
            system("CLS");
            for(int i=0;i<INALTIME;i++)
                for(int j=0;j<LATIME;j++)
                    cout<<m[i][j];
            cout<<"Use arrow keys to move the red dot;"<<endl;
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
        COORD p;p.X=int(ox);p.Y=int(oy);int c=15;
        SetConsoleCursorPosition(hOut,p);char ch='0';
        if(GetAsyncKeyState(VK_TAB))
        {
            if(GetAsyncKeyState(VK_CONTROL))
                meniu();
            SetConsoleTextAttribute(hOut,c);//c
            cout<<ch;
            m[p.Y][p.X]=ch;/* */
        }else
        {
            cout<<' ';m[p.Y][p.X]=' ';
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
    border();int c=15;bool started=true;
    ball b(LATIME/2-1,INALTIME/2);
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        if(GetAsyncKeyState(VK_RIGHT)&&b.x!=LATIME-3)
            b.x+=1;
        else
            if(GetAsyncKeyState(VK_LEFT)&&b.x!=1)
                b.x-=1;
        if(GetAsyncKeyState(VK_DOWN)&&b.y!=INALTIME-2)
            b.y+=1;
        else
            if(GetAsyncKeyState(VK_UP)&&b.y!=1)
                b.y-=1;
        if(GetAsyncKeyState(VK_CONTROL))
            meniu();
        b.draw();
        Sleep(INTARZIERE);
    }
}
