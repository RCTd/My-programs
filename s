#include <iostream>
#include <ctime>
#include <windows.h>
#define LX 30
#define LY 30
using namespace std;
INPUT_RECORD InputRecord;DWORD Events;
HANDLE hout =GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hin =GetStdHandle(STD_INPUT_HANDLE);
void gotoxy(int x,int y);void border(int lx,int ly);
void color(int c);void tail(int i);void con(int z);
int lx=LX,ly=LY,h[4][10],ax,ay,t[4][10],i,j,sc[10],d[2][10],s[50][50];
int tp,ti=200,hs=0,cc=170,cs=255,cf=15,cm=204,cb=15,b=0,z=1;
bool p=true;char q[10][4];
int main()
{
    SMALL_RECT DisplayArea= {0,0,lx+25,ly+3};
    SetConsoleWindowInfo(hout,TRUE,&DisplayArea);
    for(i=0;i<10;i++)for(j=0;j<4;j++)q[i][j]='0';
    INC1:system("CLS");
    gotoxy(4,0);color(cf);cout<<" or not (use arrows and enter)";
    gotoxy(0,1);cout<<"Players(1-4) ";color(12);cout<<z;gotoxy(0,0);
    if(p==true){color(12);cout<<"Wall";}else
    {
        color(cf);cout<<"Wall or ";
        color(12);cout<<"not";
    }
    while(!GetAsyncKeyState(VK_RETURN))
    {
        color(12);
        if(GetAsyncKeyState(VK_UP)&&z<9){z++;gotoxy(15,1);gotoxy(13,1);cout<<z;Sleep(200);}
        if(GetAsyncKeyState(VK_DOWN)&&z>1){z--;gotoxy(15,1);gotoxy(13,1);cout<<z;Sleep(200);}
        if(GetAsyncKeyState(VK_ESCAPE))goto FIN1;
        if(GetAsyncKeyState(VK_CONTROL))con(z);
        if(GetAsyncKeyState(VK_RIGHT)&&p==true)
        {
            gotoxy(0,0);p=false;
            color(cf);cout<<"Wall or ";
            color(12);cout<<"not";
        }
        if(GetAsyncKeyState(VK_LEFT)&&p==false)
        {
            gotoxy(0,0);p=true;
            color(12);cout<<"Wall";
            color(cf);cout<<" or not";
        }
    }
    color(cf);INC:srand (time(NULL));tp=ti;
    for(i=0;i<ly+1;i++)for(j=0;j<lx+1;j++)s[j][i]=0;//initializam vectorul 2D cu 0
    for(i=0;i<lx+1;i++){s[i][0]=7;s[i][ly+1]=7;}//  initializam marginile
    for(i=0;i<ly+1;i++){s[0][i]=7;s[lx+1][i]=7;}
    system("CLS");border(lx,ly);
    for(i=0;i<z;i++)
    {
        d[0][i]=0;sc[i]=0;d[1][i]=0;
        h[0][i]=lx/4+i*2;  h[1][i]=ly/4+i*2;t[0][i]=h[0][i];t[1][i]=h[1][i];
        ax=rand()%(lx)+1;ay=rand()%(ly)+1;// primul mar
        color(cm);gotoxy(ax,ay);cout<<'X';
        color(cf);s[ax][ay]=5;
    }
    gotoxy(lx+5,3);cout<<"High scor ";
    gotoxy(lx+5,4);cout<<"Scor ";
    //gotoxy(lx+5,5);cout<<"Speed ";
    while(1)
    {
        for(i=0;i<z;i++)
        {
            h[2][i]=h[0][i];h[3][i]=h[1][i];
            if(GetAsyncKeyState('Q'))
            {
                Sleep(200);
                while(!GetAsyncKeyState('1'))
                    Sleep(300);
            }
            if(GetAsyncKeyState(VK_ESCAPE))
                goto INC1;
            if(GetAsyncKeyState(VK_SPACE))
                Sleep(200);
            if(i==0)
            {
                if(GetAsyncKeyState(38))     d[1][i]=1;//Directiile
                if(GetAsyncKeyState(40))   d[1][i]=3;
                if(GetAsyncKeyState(37))   d[1][i]=4;
                if(GetAsyncKeyState(39))  d[1][i]=2;
            }else
            if(i==1)
            {
                if(GetAsyncKeyState(65))  d[1][i]=1;//Directiile
                if(GetAsyncKeyState(66))  d[1][i]=3;
                if(GetAsyncKeyState('V'))  d[1][i]=4;
                if(GetAsyncKeyState('N'))  d[1][i]=2;
            }else
            if(i==2)
            {
                if(GetAsyncKeyState('5'))  d[1][i]=1;//Directiile
                if(GetAsyncKeyState('T'))  d[1][i]=3;
                if(GetAsyncKeyState('R'))  d[1][i]=4;
                if(GetAsyncKeyState('Z'))  d[1][i]=2;
            }else
            if(i==3)
            {
                if(GetAsyncKeyState('S'))  d[1][i]=1;//Directiile
                if(GetAsyncKeyState('X'))  d[1][i]=3;
                if(GetAsyncKeyState('Y'))  d[1][i]=4;
                if(GetAsyncKeyState('C'))  d[1][i]=2;
            }else
            if(i==4)
            {
                if(GetAsyncKeyState('2'))  d[1][i]=1;//Directiile
                if(GetAsyncKeyState('W'))  d[1][i]=3;
                if(GetAsyncKeyState('Q'))  d[1][i]=4;
                if(GetAsyncKeyState('E'))  d[1][i]=2;
            }else
            if(i==5)
            {
                if(GetAsyncKeyState('8'))  d[1][i]=1;//Directiile
                if(GetAsyncKeyState('I'))  d[1][i]=3;
                if(GetAsyncKeyState('U'))  d[1][i]=4;
                if(GetAsyncKeyState('O'))  d[1][i]=2;
            }else
            if(i==6)
            {
                if(GetAsyncKeyState('K'))  d[1][i]=1;//Directiile
                if(GetAsyncKeyState(0xBC))  d[1][i]=3;
                if(GetAsyncKeyState('M'))  d[1][i]=4;
                if(GetAsyncKeyState(0xBE))  d[1][i]=2;
            }
            if((d[1][i]!=d[0][i])&&((((d[1][i]%2==0&&d[0][i]%2!=0)||(d[1][i]%2!=0&&d[0][i]%2==0)))||(sc[i]==0)))
                d[0][i]=d[1][i];
            s[h[0][i]][h[1][i]]=d[0][i];
            switch(d[0][i])
            {
            case 1:h[1][i]--;break;
            case 2:h[0][i]++;break;
            case 3:h[1][i]++;break;
            case 4:h[0][i]--;break;
            }//Noua pozitie a capului
            if(p==false)
            {
                if(h[0][i]==lx+1)h[0][i]=1;
                if(h[1][i]==ly+1)h[1][i]=1;
                if(h[0][i]==0)h[0][i]=lx;
                if(h[1][i]==0)h[1][i]=ly;
            }
            for(j=0;j<z;j++)if(j!=i)s[h[0][j]][h[1][j]]=8;
            if(s[h[0][i]][h[1][i]]!=0)
            {
                if(s[h[0][i]][h[1][i]]==5)//Nou mar..........................................................................
                {
                    //Beep(523,200);
                    sc[i]++;tp-=1;ret:
                    ax=rand()%(lx-3)+1;ay=rand()%(ly-3)+1;
                    color(cm);gotoxy(ax,ay);
                    if(s[ax][ay]!=0)
                        goto ret;
                    cout<<'X';s[ax][ay]=5;color(cf);
                }else
                if(h[0][i]==t[0][i]&&h[1][i]==t[1][i])
                    tail(i);
                else
                {
                    //Beep(200,200);
                    goto FIN;
                }
            }
            else// stergem coada si inlocuim pozitia ei.................................................................
                tail(i);
            if(sc[i]>0){
                color(cs);// schimba culoarea capului
                gotoxy(h[2][i],h[3][i]);cout<<'0';
            }
            color(cc);gotoxy(h[0][i],h[1][i]);cout<<'0';//CAPUL
            color(cf);gotoxy(lx+15,3);cout<<hs;gotoxy(lx+10,4);cout<<sc[0]+sc[1];
            //gotoxy(lx+12,5);cout<<"   ";gotoxy(lx+12,5);cout<<ti-tp;
        }
        Sleep(tp);
    }
    FIN:if(sc[0]+sc[1]>hs)hs=sc[0]+sc[1];goto INC;FIN1:
    return 0;
}
void color(int c)
{
    SetConsoleTextAttribute(hout,c);
}
void gotoxy(int x,int y)
{
    COORD coord;coord.X=x;coord.Y=y;
    SetConsoleCursorPosition(hout,coord);
}
void border(int lx,int ly)
{
    color(cb);gotoxy(0,0);
    for(i=0;i<lx+2;i++)cout<<'-';
    cout<<'\n';
    for(i=0;i<ly;i++)
    {
        cout<<'|';
        for(j=0;j<lx;j++)
            cout<<' ';
        cout<<"|\n";
    }
    for(i=0;i<lx+2;i++)cout<<'-';
}
void tail(int i)
{
    color(cf);
    t[2][i]=t[0][i];t[3][i]=t[1][i];
    gotoxy(t[0][i],t[1][i]);cout<<' ';
    if(s[t[0][i]][t[1][i]]==1)t[1][i]--;else
    if(s[t[0][i]][t[1][i]]==2)t[0][i]++;else
    if(s[t[0][i]][t[1][i]]==3)t[1][i]++;else
    if(s[t[0][i]][t[1][i]]==4)t[0][i]--;
    if(p==false)
    {
        if(t[0][i]==lx+1)t[0][i]=1;
        if(t[1][i]==ly+1)t[1][i]=1;
        if(t[0][i]==0)t[0][i]=lx;
        if(t[1][i]==0)t[1][i]=ly;
    }
    s[t[2][i]][t[3][i]]=0;
}
void con(int z)
{
    gotoxy(0,3);color(cf);b=0;
    for(i=0;i<z;i++)
    {
        if(i==b)color(12);else color(cf);
        cout<<"Player "<<i<<"\n";
    }while(!GetAsyncKeyState(VK_RETURN))
    {
        if(GetAsyncKeyState(VK_UP)&&b>0)
        {
            gotoxy(0,3+b);color(cf);Sleep(200);
            cout<<"Player "<<b;b--;color(12);
            gotoxy(0,3+b);cout<<"Player "<<b;
        }
        if(GetAsyncKeyState(VK_DOWN)&&b<z-1)
        {
            gotoxy(0,3+b);color(cf);Sleep(200);
            cout<<"Player "<<b;b++;color(12);
            gotoxy(0,3+b);cout<<"Player "<<b;
        }
    }Sleep(200);color(cf);
    //cod.....
    gotoxy(0,3);cout<<"Player "<<b<<'\n';color(12);
    cout<<" UP......"<<q[i][0]<<"\n";color(cf);
    cout<<" Down...."<<q[i][1]<<"\n";
    cout<<" Left...."<<q[i][2]<<"\n";
    cout<<" Right..."<<q[i][3]<<"\n";b=0;
    for(i=0;i<4;i++)cout<<"           \n";
    while(!GetAsyncKeyState(VK_RETURN))
    {
        if(GetAsyncKeyState(VK_UP)&&b>0)
        {
            if(b==1)
            {
                gotoxy(0,4);color(12);
                cout<<" UP......"<<q[i][0]<<"\n";color(cf);
                cout<<" Down...."<<q[i][1]<<"\n";
                cout<<" Left...."<<q[i][2]<<"\n";
                cout<<" Right..."<<q[i][3];
            }else
            if(b==2)
            {
                gotoxy(0,4);
                cout<<" UP......"<<q[i][0]<<"\n";
                color(12);cout<<" Down...."<<q[i][1]<<"\n";
                color(cf);cout<<" Left...."<<q[i][2]<<"\n";
                cout<<" Right..."<<q[i][3];
            }else
            {
                gotoxy(0,4);
                cout<<" UP......"<<q[i][0]<<"\n";
                cout<<" Down...."<<q[i][1]<<"\n";
                color(12);cout<<" Left...."<<q[i][2]<<"\n";
                color(cf);cout<<" Right..."<<q[i][3];
            }b--;Sleep(200);
        }
        if(GetAsyncKeyState(VK_DOWN)&&b<4)
        {
            if(b==0)
            {
                gotoxy(0,4);
                cout<<" UP......"<<q[i][0]<<"\n";
                color(12);cout<<" Down...."<<q[i][1]<<"\n";
                color(cf);cout<<" Left...."<<q[i][2]<<"\n";
                cout<<" Right..."<<q[i][3];
            }else
            if(b==1)
            {
                gotoxy(0,4);
                cout<<" UP......"<<q[i][0]<<"\n";
                cout<<" Down...."<<q[i][1]<<"\n";
                color(12);cout<<" Left...."<<q[i][2]<<"\n";
                color(cf);cout<<" Right..."<<q[i][3];
            }else
            {
                gotoxy(0,4);
                cout<<" UP......"<<q[i][0]<<"\n";
                cout<<" Down...."<<q[i][1]<<"\n";
                cout<<" Left...."<<q[i][2]<<"\n";
                color(12);cout<<" Right..."<<q[i][3];color(cf);
            }b++;Sleep(200);
        }
    }
}
