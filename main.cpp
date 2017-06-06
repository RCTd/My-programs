#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#define LATIME 80// 79-maxim
#define INALTIME 59// 58-maxim
#define INTARZIERE 80//80-recomandat
HANDLE hOut;
char m[INALTIME][LATIME];
int n[INALTIME][LATIME];
using namespace std;
int c=15,lan,aci;
char ch='0';
ofstream g,g1,g2;
bool start=false;
ifstream f1,f;
string fn,fm,fm1;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hOut,coord);
}
void border()
{
    system("CLS");
    c=15;
    for(int i=0; i<INALTIME; i++)
        for(int j=0; j<LATIME; j++)
            n[i][j]=15;
    SetConsoleTextAttribute( hOut, 15 );
    for(int i=0; i<LATIME-1; ++i)
    {
        cout<< '-';
        m[0][i]='-';
    }
    for(int i=0; i<INALTIME-3; ++i)
    {
        cout<<"\n|";
        m[i+1][0]='|';
        for(int j=0; j<LATIME-3; ++j)
        {
            cout<<' ';
            m[i+1][j+1]=' ';
        }
        cout<<"|";
        m[i+1][LATIME-2]='|';
    }
    cout<<"\n";
    for(int i=0; i<LATIME; ++i)
    {
        cout<<'-';
        m[INALTIME-2][i]='-';
    }
    SetConsoleTextAttribute(hOut,15);
    if(lan==1)
    {
        cout<<"Use arrow keys to move the red dot; ESC to exit;\nTAB to drow; CTRL to enter meniu; SHIFT to erase;";
        cout<<"\nH-to change the character; D-to change the color;";
    }
    else
    {
        cout<<"Foloseste sagetile pentru a misca punctul rosu; ESC pentru a iesi;\nTAB pentru a desena; CTRL pentru a intra in maniu; SHIFT pentru a sterge;";
        cout<<"\nH pentru a schimba caracterul; D pentru a schimba culoarea;";
    }
}
void aga()
{
    system("CLS");
    for(int i=0; i<INALTIME-1; i++)
        for(int j=0; j<LATIME; j++)
        {
            c=n[i][j];
            SetConsoleTextAttribute(hOut,c);
            cout<<m[i][j];
        }
    if(lan==1)
    {
        cout<<"Use arrow keys to move the red dot; ESC to exit;\nTAB to drow; CTRL to enter meniu; SHIFT to erase;";
        cout<<"\nH-to change the character; D-to change the color;";
    }
    else
    {
        cout<<"Foloseste sagetile pentru a misca punctul rosu; ESC pentru a iesi;\nTAB pentru a desena; CTRL pentru a intra in maniu; SHIFT pentru a sterge;";
        cout<<"\nH pentru a schimba caracterul; D pentru a schimba culoarea;";
    }
}
void mena()
{
    system("CLS");
    char q='0';
    int select=0;
    bool bucla=false;
    while (bucla==false)
    {
        SetConsoleTextAttribute(hOut,11);
        gotoxy(LATIME/2,13);
        cout<<char(24);
        gotoxy(LATIME/2,14);
        cout<<"W";
        gotoxy(LATIME/2,30);
        cout<<char(25);
        gotoxy(LATIME/2,29);
        cout<<"S";
        SetConsoleTextAttribute(hOut,15);
        gotoxy(LATIME/2-5,17);
        cout<<"SELECT OPTION:";
        gotoxy(LATIME/2-3,19);
        cout<<"CLEAR THE SCREEN";
        gotoxy(LATIME/2-3,21);
        cout<<"OPEN A FILE";
        gotoxy(LATIME/2-3,23);
        cout<<"SAVE THE FILE";
        gotoxy(LATIME/2-3,25);
        cout<<"DELETE A FILE";
        gotoxy(LATIME/2-3,27);
        cout<<"EXIT MENIU";
        while (q!=char(13))
        {
            SetConsoleTextAttribute(hOut,10);
            gotoxy(LATIME/2-6,19+select);
            cout<<"->";
            gotoxy(0,0);
            q=getch();
            gotoxy(LATIME/2-6,19+select);
            cout<<"  ";
            if (q=='s')
                if (select<8)
                    select+=2;
            if (q=='w')
                if (select>0)
                    select-=2;
        }
        if (select==0)//C
        {
            border();
            bucla=true;
        }
        if (select==2)//O
        {
            SetConsoleTextAttribute(hOut,15);
            cin>>fm;
            fm="D:/c++/paint/desene/"+fm;
            fn=fm+"n.txt";
            fm=fm+".txt";
            system("CLS");
            f.open(fm.c_str());
            f1.open(fn.c_str());
            for(int i=0; i<INALTIME; i++)
                for(int j=0; j<LATIME; j++)
                {
                    f1>>c;n[i][j]=c;f>>aci;
                    m[i][j]=aci;
                    SetConsoleTextAttribute(hOut,c);
                    cout<<m[i][j];
                }
            if(lan==1)
            {
                cout<<"Use arrow keys to move the red dot; ESC to exit;\nTAB to drow; CTRL to enter meniu; SHIFT to erase;";
                cout<<"\nH-to change the character; D-to change the color;";
            }
            else
            {
                cout<<"Foloseste sagetile pentru a misca punctul rosu; ESC pentru a iesi;\nTAB pentru a desena; CTRL pentru a intra in maniu; SHIFT pentru a sterge;";
                cout<<"\nH pentru a schimba caracterul; D pentru a schimba culoarea;";
            }
            g.close();
            g1.close();//aga();
            bucla=true;
        }
        if (select==4)//S
        {
            cin>>fm;
            fm="D:/c++/paint/desene/"+fm;
            fn=fm+"n.txt";
            fm1=fm+"d.txt";
            fm=fm+".txt";
            g.open(fm.c_str());
            g1.open(fn.c_str());
            g2.open(fm1.c_str());
            for(int i=0; i<INALTIME-1; i++)
            {
                for(int j=0; j<LATIME; j++)
                {
                    g<<+m[i][j];
                    g<<"\n";
                    g1<<n[i][j];
                    g1<<"\n";
                    g2<<m[i][j];
                }
                g2<<"\n";
            }
            g.close();
            g1.close();
            g2.close();
            aga();
            bucla=true;
        }
        if(select==6)//Q
        {
            cin>>fm;
            fm="D:/c++/paint/desene/"+fm;
            fn=fm+"n.txt";
            fm1=fm+"d.txt";
            fm=fm+".txt";
            remove(fm.c_str());
            remove(fm1.c_str());
            remove(fn.c_str());
            aga();
            bucla=true;
        }
        if(select==8)
        {
            aga();
            bucla=true;
        }
        select=2;
    }
}
/*void meniu()
{
    bool exit=true,exit1=true;
    while((exit==true)&&(exit1==true))
    {
        system("CLS");
        SetConsoleTextAttribute(hOut,15);
        if(lan==1)
        {
            cout<<"C-to clear the screen;\nO-to open an existing file;\n";
            cout<<"S-to save the file;\nE-to exit meniu;\nQ-to delete a file;\n";
        }else
        {
            cout<<"C-pentru a curata ecranul;\nO-pentru a deschide un fisier;\n";
            cout<<"S-pentru a salva fisierul;\nE-pentru a iesi din meniu;\nQ-pentru a sterge un fisier;\n";
        }
        cin>>men;
        if((men==113)||(men==81))//Q
        {
            cin>>de;
            d1="D:/c++/paint/desene/"+de+"/"+de+"n.txt";
            d2="D:/c++/paint/desene/"+de+"/"+de+"d.txt";
            de="D:/c++/paint/desene/"+de+"/"+de+".txt";
            remove(de.c_str());remove(d1.c_str());remove(d2.c_str());
            exit=false;
        }
        if((men==83)||(men==115))//S
        {
            exit=false;cin>>fm;
            fn="D:/c++/paint/desene/"+fm+"/"+fm+"n.txt";
            fm1="D:/c++/paint/desene/"+fm+"/"+fm+"d.txt";
            fm="D:/c++/paint/desene/"+fm+"/"+fm+".txt";
            g.open(fm.c_str());g1.open(fn.c_str());g2.open(fm1.c_str());
            for(int i=0;i<INALTIME-1;i++)
            {
                for(int j=0;j<LATIME;j++)
                {
                    g<<+m[i][j];g<<"\n";
                    g1<<n[i][j];g1<<"\n";
                    g2<<m[i][j];
                }
                g2<<"\n";
            }
            g.close();g1.close();g2.close();
        }
        if((men==67)||(men==99))//C
        {
            exit1=false;
            border();
        }
        if((men==69)||(men==101)||(exit==false))//E
            {aga();exit=false;}
        if((men==79)||(men==111))//O
        {
            exit1=false;fm='\0';fn='\0';cin>>fm;
            fn="D:/c++/paint/desene/"+fm+"/"+fm+"n.txt";
            fm="D:/c++/paint/desene/"+fm+"/"+fm+".txt";system("CLS");
            f.open(fm.c_str());f1.open(fn.c_str());
            for(int i=0;i<INALTIME;i++)
                for(int j=0;j<LATIME;j++)
                {
                    f1>>c;n[i][j]=c;
                    f>>aci;m[i][j]=aci;
                }
            if(lan==1)
            {
                cout<<"Use arrow keys to move the red dot; ESC to exit;\nTAB to drow; CTRL to enter meniu; SHIFT to erase;";
                cout<<"\nH-to change the character; D-to change the color;";
            }else
            {
                cout<<"Foloseste sagetile pentru a misca punctul rosu; ESC pentru a iesi;\nTAB pentru a desena; CTRL pentru a intra in maniu; SHIFT pentru a sterge;";
                cout<<"\nH pentru a schimba caracterul; D pentru a schimba culoarea;";
            }
            f.close();f1.close();aga();exit=false;
        }
        Sleep(INTARZIERE+50);
    }
}*/
struct ball
{
    float x,y,ox,oy;
    ball(int _x,int _y)
    {
        x=float(_x);
        y=float(_y);
    }
    void draw()
    {
        COORD p;
        p.X=int(ox);
        p.Y=int(oy);
        SetConsoleCursorPosition(hOut,p);
        if(GetAsyncKeyState(VK_TAB))
        {
            SetConsoleTextAttribute(hOut,c);//c
            cout<<ch;
            n[p.Y][p.X]=c;
            m[p.Y][p.X]=ch;
        }
        else
        {
            if(m[p.Y][p.X]==' ')
            {
                cout<<' ';
                m[p.Y][p.X]=' ';
            }
            else
            {
                if(GetAsyncKeyState(VK_SHIFT))
                {
                    cout<<' ';
                    m[p.Y][p.X]=' ';
                }
                else
                {
                    SetConsoleTextAttribute(hOut,n[p.Y][p.X]);
                    cout<<m[p.Y][p.X];
                }
            }
        }
        p.X=int(x);
        p.Y=int(y);
        int b=12;
        if(c==12)b=13;
        SetConsoleCursorPosition(hOut,p);
        SetConsoleTextAttribute(hOut,b);
        cout<<'0';
        ox=x;
        oy=y;
    }
};
void menu()
{
    char c='0';
    int select=2;
    bool bucla=false;
    while (bucla==false)
    {
        SetConsoleTextAttribute(hOut,11);
        gotoxy(LATIME/2,13);
        cout<<char(24);
        gotoxy(LATIME/2,14);
        cout<<"W";
        gotoxy(LATIME/2,28);
        cout<<char(25);
        gotoxy(LATIME/2,27);
        cout<<"S";
        SetConsoleTextAttribute(hOut,15);
        gotoxy(LATIME/2-7,17);
        cout<<"SELECT LANGUAGE:";
        gotoxy(LATIME/2-3,19);
        cout<<"ROMANA ";
        gotoxy(LATIME/2-3,21);
        cout<<"ENGLEZA";
        gotoxy(LATIME/2-3,23);
        cout<<"QUIT   ";
        while (c!=char(13))
        {
            SetConsoleTextAttribute(hOut,10);
            gotoxy(LATIME/2-6,19+select);
            cout<<"->";
            gotoxy(LATIME/2+5,19+select);
            cout<<"<-";
            gotoxy(0,0);
            c=getch();
            gotoxy(LATIME/2-6,19+select);
            cout<<"  ";
            gotoxy(LATIME/2+5,19+select);
            cout<<"  ";
            if (c=='s')
                if (select<4)
                    select+=2;
            if (c=='w')
                if (select>0)
                    select-=2;
        }
        if (select==0)
        {
            lan=2;
            start=true;
            bucla=true;
        }
        if (select==2)
        {
            lan=1;
            start=true;
            bucla=true;
        }
        if (select==4)
        {
            start=false;
            bucla=true;
        }
        select=2;
    }
}
int main()
{
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT DisplayArea= {0,0,LATIME,INALTIME+3};
    SetConsoleWindowInfo(hOut,TRUE,&DisplayArea);
    COORD f;
    f.Y=INALTIME+1;
    f.X=60;
    ball b(LATIME/2-1,INALTIME/2);
    menu();
    border();
    while(!GetAsyncKeyState(VK_ESCAPE)&&(start==true))
    {
        if(GetAsyncKeyState(VK_RIGHT)&&b.x!=LATIME-3)
            b.x+=1;
        else if(GetAsyncKeyState(VK_LEFT)&&b.x!=1)
            b.x-=1;
        if(GetAsyncKeyState(VK_DOWN)&&b.y!=INALTIME-3)
            b.y+=1;
        else if(GetAsyncKeyState(VK_UP)&&b.y!=1)
            b.y-=1;
        if(GetAsyncKeyState(0x48))//H
        {
            SetConsoleCursorPosition(hOut,f);
            cin>>ch;
            SetConsoleCursorPosition(hOut,f);
            cout<<" ";
        }
        if(GetAsyncKeyState(0x44))//D
        {
            int t=4,a=247/t-t-1;
            system("CLS");
            for(int i=-8; i!=a; i++)
            {
                for(int c=0; c<t; c++)
                {
                    SetConsoleTextAttribute(hOut,i+c*(a+8)+8);
                    cout<<i+c*(a+8)<<" for this color; ";
                }
                cout<<"\n";
            }
            SetConsoleTextAttribute(hOut,15);
            cin>>c;
            c+=8;
            aga();
        }
        if(GetAsyncKeyState(VK_CONTROL))
            mena();
        b.draw();
        Sleep(INTARZIERE);
    }
}
