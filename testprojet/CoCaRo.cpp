#include<iostream>
#include"../dohoa/mylib.h"
#define SIZE 14
using namespace std;
void taobang();
void play();
int main()
{
    ShowCur(0);
    play();
    while(true)
    {
        int luachon;
        gotoXY(60,28);
        SetColor(7);
        cout<<"Ban co muon choi tiep | YES => [ 1 ] || NO => [ 0 ] |: ";cin>>luachon;
        if(luachon==1)
        {
            system("cls");
            SetColor(7);
            play();
        }
        else if(luachon==0)
        {
            break;
        }
    }
    
    _getch();
    return 0;
}
void play()
{
    int x=1,y=1;
    int xcu=-100,ycu=-100;
    bool kt_run=true;
    char a[SIZE][SIZE];
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            a[i][j]=-1;
        }   
    }
    taobang();
    //=======player name========
    // gotoXY(60,15);cout<<"Nhap ten nguoi choi 1: ";
    // cin.ignore();
    // string Nplayer1;getline(cin,Nplayer1);
    // gotoXY(60,15);cout<<"                                   ";
    // gotoXY(60,15);cout<<"Nhap ten nguoi choi 2: ";
    // cin.ignore();
    // string Nplayer2;getline(cin,Nplayer2);
    // gotoXY(60,15);cout<<"                                   ";
    //=======player turn========
    int pturn=0;
    while(true)
    {
        //====scence player turn========
        if(pturn%2==0)
        {
            gotoXY(60,0);
            textcolor(10);
            cout<<"Luot cua Nguoi Choi 1 => [ O ]";
        }
        else if(pturn%2!=0)
        {
            gotoXY(60,0);
            textcolor(12);
            cout<<"Luot cua Nguoi Choi 2 => [ X ]";
        }
        //====Cac nut dieu khien=======
        if(_kbhit()==true)
        {
            char c=_getch();
            char d=c;
            if(d==-32)
            {
                d=_getch();
            }
            if(c=='w'||d==72)//len
            {
                y-=2;
                int s=0;
                for(int i=y/2;i>0;i--)
                {
                    if(a[i][x/4]=='O'||a[i][x/4]=='X')
                    {
                        s++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(a[y/2][x/4]=='O'||a[y/2][x/4]=='X')
                {
                    y=y-(2*s);
                }
                kt_run=true;
            }
            else if(c=='s'||d==80)//xuong
            {
                y+=2;
                int s=0;
                for(int i=y/2;i<14;i++)
                {
                    if(a[i][x/4]=='O'||a[i][x/4]=='X')
                    {
                        s++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(a[y/2][x/4]=='O'||a[y/2][x/4]=='X')
                {
                    y=y+(2*s);
                }
                kt_run=true;

            }
            else if(c=='a'||d==75)//trai
            {
                x-=4;
                int s=0;
                for(int i=x/4;i>0;i--)
                {
                    if(a[y/2][i]=='O'||a[y/2][i]=='X')
                    {
                        s++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(a[y/2][x/4]=='O'||a[y/2][x/4]=='X')
                {
                    x=x-(4*s);
                }
                kt_run=true;

            }
            else if(c=='d'||d==77)//phai
            {
                x+=4;
                int s=0;
                for(int i=x/4;i<14;i++)
                {
                    if(a[y/2][i]=='O'||a[y/2][i]=='X')
                    {
                        s++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(a[y/2][x/4]=='O'||a[y/2][x/4]=='X')
                {
                    x=x+(4*s);
                }
                kt_run=true;

            }
            else if(c=='o'&&pturn%2==0)
            {
                gotoXY(x,y);
                if(a[y/2][x/4]!='X')
                {
                    a[y/2][x/4]='O';
                    textcolor(10);
                    cout<<a[y/2][x/4];
                    pturn++;
                }
            }
            else if(c=='x'&&pturn&2!=0)
            {
                gotoXY(x,y);
                if(a[y/2][x/4]!='O')
                {
                    a[y/2][x/4]='X';
                    textcolor(4);
                    cout<<a[y/2][x/4];
                    pturn++;
                }
            }
            else if(c=='q')
            {
                break;
            }
        }
        //=====thang thua====
        if(a[y/2][x/4]=='O')
        {
            bool player11=true,player12=true,player13=true,player14=true,player15=true,player16=true,player17=true,player18=true;
            int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0;
            for(int j=x/4;j<(x/4)+5;j++)//phai
            {
                player11=true;
                if(a[y/2][j]!='O')
                {
                    player11=false;
                    break;
                }
                count1++;
            }
            for(int j=x/4;j>(x/4)-5;j--)//trai
            {
                player12=true;
                if(a[y/2][j]!='O')
                {
                    player12=false;
                    break;
                }
                count2++;
            }
            for(int i=y/2;i<(y/2)+5;i++)//xuong
            {
                player13=true;
                if(a[i][x/4]!='O')
                {
                    player13=false;
                    break;
                }
                count3++;
            }
            for(int i=y/2;i>(y/2)-5;i--)//len
            {
                player14=true;
                if(a[i][x/4]!='O')
                {
                    player14=false;
                    break;
                }
                count4++;
            }
            if(x/4==y/2)
            {
                for(int i=y/2,j=x/4;i<(x/4)+5;i++,j++)//cheo xuong phai
                {
                    player15=true;
                    if(a[i][j]!='O')
                    {
                        player15=false;
                        break;
                    }
                    count5++;
                }
            }
            else if(x/4>y/2)
            {
                for(int i=y/2,j=x/4;j<(x/4)+5;j++,i++)//cheo xuong phai
                {
                    player15=true;
                    if(a[i][j]!='O')
                    {
                        player15=false;
                        break;
                    }
                    count5++;
                }
            }
            else if(y/2>x/4)
            {
                for(int i=y/2,j=x/4;j<(x/4)+5;j++,i++)//cheo xuong phai
                {
                    player15=true;
                    if(a[i][j]!='O')
                    {
                        player15=false;
                        break;
                    }
                    count5++;
                }
            }
            if(x/4==y/2)
            {
                for(int i=y/2,j=x/4;i>(x/4)-5;i--,j--)//cheo len trai
                {
                    player16=true;
                    if(a[i][j]!='O')
                    {
                        player16=false;
                        break;
                    }
                    count6++;
                }
            }
            else if(x/4>y/2)
            {
                for(int i=y/2,j=x/4;j>(x/4)-5;j--,i--)//cheo len trai
                {
                    player16=true;
                    if(a[i][j]!='O')
                    {
                        player16=false;
                        break;
                    }
                    count6++;
                }
            }
            else if(y/2>x/4)
            {
                for(int i=y/2,j=x/4;j>(x/4)-5;j--,i--)//cheo len trai
                {
                    player16=true;
                    if(a[i][j]!='O')
                    {
                        player16=false;
                        break;
                    }
                    count6++;
                }
            }
            if((x/4)+(y/2)==SIZE-1)
            {
                for(int i=y/2,j=x/4;j<(x/4)+5;i--,j++)//cheo len phai
                {
                    player17=true;
                    if(a[i][j]!='O')
                    {
                        player17=false;
                        break;
                    }
                    count7++;
                }
            }
            else if((x/4)+(y/2)>SIZE-1)
            {
                for(int i=y/2,j=x/4;j<(x/4)+5;i--,j++)//cheo len phai
                {
                    player17=true;
                    if(a[i][j]!='O')
                    {
                        player17=false;
                        break;
                    }
                    count7++;
                }
            }
            else if((x/4)+(y/2)<SIZE-1)
            {
                for(int i=y/2,j=x/4;j<(x/4)+5;i--,j++)//cheo len phai
                {
                    player17=true;
                    if(a[i][j]!='O')
                    {
                        player17=false;
                        break;
                    }
                    count7++;
                }
            }
            if((x/4)+(y/2)==SIZE-1)
            {
                for(int i=y/2,j=x/4;j>(x/4)-5;i++,j--)//cheo xuong trai
                {
                    player18=true;
                    if(a[i][j]!='O')
                    {
                        player18=false;
                        break;
                    }
                    count8++;
                }
            }
            else if((x/4)+(y/2)>SIZE-1)
            {
                for(int i=y/2,j=x/4;j>(x/4)-5;i++,j--)//cheo xuong trai
                {
                    player18=true;
                    if(a[i][j]!='O')
                    {
                        player18=false;
                        break;
                    }
                    count8++;
                }
            }
            else if((x/4)+(y/2)<SIZE-1)
            {
                for(int i=y/2,j=x/4;j>(x/4)-5;i++,j--)//cheo xuong trai
                {
                    player18=true;
                    if(a[i][j]!='O')
                    {
                        player18=false;
                        break;
                    }
                    count8++;
                }
            }
            if(player11==true||player12==true||player13==true||player14==true||player15==true||player16==true||player17==true||player18==true||(count1-1)+count2==5||(count3-1)+count4==5||(count5-1)+count6==5||(count7-1)+count8==5)
            {
                bool pt=true;
                int i=1;
                while (pt==true)
                {
                    if(_kbhit()==true)
                    {
                        pt=false;
                    }
                    textcolor(i);
                    gotoXY(60,3);cout<<"$$$$$$$$ $$         $$$$$$$$  $$      $$ $$$$$$$$ $$$$$$$$";
                    gotoXY(60,4);cout<<"$$    $$ $$        $$      $$ $$      $$ $$       $$    $$";
                    gotoXY(60,5);cout<<"$$    $$ $$        $$      $$  $$    $$  $$       $$    $$";
                    gotoXY(60,6);cout<<"$$$$$$$$ $$        $$$$$$$$$$   $$  $$   $$$$$$$$ $$$$$$$$";
                    gotoXY(60,7);cout<<"$$       $$        $$      $$     $$     $$       $$$$$   ";
                    gotoXY(60,8);cout<<"$$       $$        $$      $$     $$     $$       $$  $$$ ";
                    gotoXY(60,9);cout<<"$$       $$$$$$$$  $$      $$     $$     $$$$$$$$ $$    $$";

                    gotoXY(85,11);cout<<"  $$$   ";
                    gotoXY(85,12);cout<<" $$$$   ";
                    gotoXY(85,13);cout<<"   $$   ";
                    gotoXY(85,14);cout<<"   $$   ";
                    gotoXY(85,15);cout<<"   $$   ";
                    gotoXY(85,16);cout<<"   $$   ";
                    gotoXY(85,17);cout<<"$$$$$$$$";

                    gotoXY(76,19);cout<<"$$    $$ $$$$$$$$ $$    $$";
                    gotoXY(76,20);cout<<"$$    $$    $$    $$    $$";
                    gotoXY(76,21);cout<<"$$ $$ $$    $$    $$$$  $$";
                    gotoXY(76,22);cout<<"$$ $$ $$    $$    $$$$$$$$";
                    gotoXY(76,23);cout<<"$$$$$$$$    $$    $$  $$$$";
                    gotoXY(76,24);cout<<"$$$$$$$$    $$    $$    $$";
                    gotoXY(76,25);cout<<"$$ $$ $$ $$$$$$$$ $$    $$";
                    Sleep(100);
                    if(i==15)
                    {
                        i=1;
                    }
                    i++;
                }
                break;
            }
            count1=0;count2=0;count3=0;count4=0,count5=0,count6=0,count7=0,count8=0;
        }
        if(a[y/2][x/4]=='X')
        {
            bool player11=true,player12=true,player13=true,player14=true,player15=true,player16=true,player17=true,player18=true;
            int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0;
            for(int j=x/4;j<(x/4)+5;j++)//phai
            {
                player11=true;
                if(a[y/2][j]!='X')
                {
                    player11=false;
                    break;
                }
                count1++;
            }
            for(int j=x/4;j>(x/4)-5;j--)//trai
            {
                player12=true;
                if(a[y/2][j]!='X')
                {
                    player12=false;
                    break;
                }
                count2++;
            }
            for(int i=y/2;i<(y/2)+5;i++)//xuong
            {
                player13=true;
                if(a[i][x/4]!='X')
                {
                    player13=false;
                    break;
                }
                count3++;
            }
            for(int i=y/2;i>(y/2)-5;i--)//len
            {
                player14=true;
                if(a[i][x/4]!='X')
                {
                    player14=false;
                    break;
                }
                count4++;
            }
            if(x/4==y/2)
            {
                for(int i=y/2,j=x/4;i<(x/4)+5;i++,j++)//cheo xuong phai
                {
                    player15=true;
                    if(a[i][j]!='X')
                    {
                        player15=false;
                        break;
                    }
                    count5++;
                }
            }
            else if(x/4>y/2)
            {
                for(int i=y/2,j=x/4;j<(x/4)+5;j++,i++)//cheo xuong phai
                {
                    player15=true;
                    if(a[i][j]!='X')
                    {
                        player15=false;
                        break;
                    }
                    count5++;
                }
            }
            else if(y/2>x/4)
            {
                for(int i=y/2,j=x/4;j<(x/4)+5;j++,i++)//cheo xuong phai
                {
                    player15=true;
                    if(a[i][j]!='X')
                    {
                        player15=false;
                        break;
                    }
                    count5++;
                }
            }
            if(x/4==y/2)
            {
                for(int i=y/2,j=x/4;i>(x/4)-5;i--,j--)//cheo len trai
                {
                    player16=true;
                    if(a[i][j]!='X')
                    {
                        player16=false;
                        break;
                    }
                    count6++;
                }
            }
            else if(x/4>y/2)
            {
                for(int i=y/2,j=x/4;j>(x/4)-5;j--,i--)//cheo len trai
                {
                    player16=true;
                    if(a[i][j]!='X')
                    {
                        player16=false;
                        break;
                    }
                    count6++;
                }
            }
            else if(y/2>x/4)
            {
                for(int i=y/2,j=x/4;j>(x/4)-5;j--,i--)//cheo len trai
                {
                    player16=true;
                    if(a[i][j]!='X')
                    {
                        player16=false;
                        break;
                    }
                    count6++;
                }
            }
            if((x/4)+(y/2)==SIZE-1)
            {
                for(int i=y/2,j=x/4;j<(x/4)+5;i--,j++)//cheo len phai
                {
                    player17=true;
                    if(a[i][j]!='X')
                    {
                        player17=false;
                        break;
                    }
                    count7++;
                }
            }
            else if((x/4)+(y/2)>SIZE-1)
            {
                for(int i=y/2,j=x/4;j<(x/4)+5;i--,j++)//cheo len phai
                {
                    player17=true;
                    if(a[i][j]!='X')
                    {
                        player17=false;
                        break;
                    }
                    count7++;
                }
            }
            else if((x/4)+(y/2)<SIZE-1)
            {
                for(int i=y/2,j=x/4;j<(x/4)+5;i--,j++)//cheo len phai
                {
                    player17=true;
                    if(a[i][j]!='X')
                    {
                        player17=false;
                        break;
                    }
                    count7++;
                }
            }
            if((x/4)+(y/2)==SIZE-1)
            {
                for(int i=y/2,j=x/4;j>(x/4)-5;i++,j--)//cheo xuong trai
                {
                    player18=true;
                    if(a[i][j]!='X')
                    {
                        player18=false;
                        break;
                    }
                    count8++;
                }
            }
            else if((x/4)+(y/2)>SIZE-1)
            {
                for(int i=y/2,j=x/4;j>(x/4)-5;i++,j--)//cheo xuong trai
                {
                    player18=true;
                    if(a[i][j]!='X')
                    {
                        player18=false;
                        break;
                    }
                    count8++;
                }
            }
            else if((x/4)+(y/2)<SIZE-1)
            {
                for(int i=y/2,j=x/4;j>(x/4)-5;i++,j--)//cheo xuong trai
                {
                    player18=true;
                    if(a[i][j]!='X')
                    {
                        player18=false;
                        break;
                    }
                    count8++;
                }
            }
            if(player11==true||player12==true||player13==true||player14==true||player15==true||player16==true||player17==true||player18==true||(count1-1)+count2==5||(count3-1)+count4==5||(count5-1)+count6==5||(count7-1)+count8==5)
            {
                bool pt=true;
                int i=1;
                while (pt==true)
                {
                    if(_kbhit()==true)
                    {
                        pt=false;
                    }
                    textcolor(i);
                    gotoXY(60,3);cout<<"$$$$$$$$ $$         $$$$$$$$  $$      $$ $$$$$$$$ $$$$$$$$";
                    gotoXY(60,4);cout<<"$$    $$ $$        $$      $$ $$      $$ $$       $$    $$";
                    gotoXY(60,5);cout<<"$$    $$ $$        $$      $$  $$    $$  $$       $$    $$";
                    gotoXY(60,6);cout<<"$$$$$$$$ $$        $$$$$$$$$$   $$  $$   $$$$$$$$ $$$$$$$$";
                    gotoXY(60,7);cout<<"$$       $$        $$      $$     $$     $$       $$$$$   ";
                    gotoXY(60,8);cout<<"$$       $$        $$      $$     $$     $$       $$  $$$ ";
                    gotoXY(60,9);cout<<"$$       $$$$$$$$  $$      $$     $$     $$$$$$$$ $$    $$";

                    gotoXY(85,11);cout<<"$$$$$$$$";
                    gotoXY(85,12);cout<<"      $$";
                    gotoXY(85,13);cout<<"      $$";
                    gotoXY(85,14);cout<<"$$$$$$$$";
                    gotoXY(85,15);cout<<"$$      ";
                    gotoXY(85,16);cout<<"$$      ";
                    gotoXY(85,17);cout<<"$$$$$$$$";

                    gotoXY(76,19);cout<<"$$    $$ $$$$$$$$ $$    $$";
                    gotoXY(76,20);cout<<"$$    $$    $$    $$    $$";
                    gotoXY(76,21);cout<<"$$ $$ $$    $$    $$$$  $$";
                    gotoXY(76,22);cout<<"$$ $$ $$    $$    $$$$$$$$";
                    gotoXY(76,23);cout<<"$$$$$$$$    $$    $$  $$$$";
                    gotoXY(76,24);cout<<"$$$$$$$$    $$    $$    $$";
                    gotoXY(76,25);cout<<"$$ $$ $$ $$$$$$$$ $$    $$";
                    Sleep(100);
                    if(i==15)
                    {
                        i=1;
                    }
                    i++;
                }
                break;
            }
            count1=0;count2=0;count3=0;count4=0,count5=0,count6=0,count7=0,count8=0;
        }
        //=====bien=========
        if(x<1)
        {
            x=53;
        }
        else if(x>53)
        {
            x=1;
        }
        else if(y<1)
        {
            y=27;
        }
        else if(y>27)
        {
            y=1;
        }
        //========= xoa du lieu cu======
        if(kt_run==true)
        {
            gotoXY(xcu,ycu);
            if(a[ycu/2][xcu/4]=='X'||a[ycu/2][xcu/4]=='O')
            {

            }
            else
            {
                textcolor(256);
                cout<<" ";
            }
            xcu=x;ycu=y;
        }
        //=========Di chuyen=====
        if(kt_run==true)
        {
            gotoXY(x,y);
            if(a[y/2][x/4]=='X'||a[y/2][x/4]=='O')
            {

            }
            else
            {
                textcolor(460);
                cout<<" ";
            }
            kt_run=false;
        }
        //=====speed=====
        // Sleep(100);
    }
}
void taobang()
{
    gotoXY(0,0);
    cout<<char(218);
    gotoXY(0,28);
    cout<<char(192);
    gotoXY(54,0);
    cout<<char(191);
    gotoXY(54,28);
    cout<<char(217);
    for(int x=1;x<=53;x++)
    {
        for(int y=0;y<=28;y+=2)
        {
            gotoXY(x,y);
            cout<<char(196);
            gotoXY(x,y);
            cout<<char(196);
            // Sleep(5);
        }
    }
    for(int y=1;y<=27;y++)
    {
        gotoXY(0,y);
        cout<<char(179);
        gotoXY(54,y);
        cout<<char(179);
        // Sleep(5);
    }
    for(int y=1;y<=27;y++)
    {
        for(int x=3;x<=53;x+=4)
        {
            gotoXY(x,y);
            cout<<char(179);
        }
    }
    for(int y=2;y<=27;y+=2)
    {
        for(int x=3;x<=53;x+=4)
        {
            gotoXY(x,y);
            cout<<char(197);
        }
    }
    for(int y=2;y<=27;y+=2)
    {
        gotoXY(0,y);
        cout<<char(195);
    }
    for(int y=2;y<=27;y+=2)
    {
        gotoXY(54,y);
        cout<<char(180);
    }
    for(int x=3;x<=53;x+=4)
    {
        gotoXY(x,0);
        cout<<char(194);
    }
    for(int x=3;x<=53;x+=4)
    {
        gotoXY(x,28);
        cout<<char(193);
    }
    for(int y=1;y<28;y+=2)
    {
        for(int x=1;x<54;x+=4)
        {
            gotoXY(x,y);
            cout<<" ";
            // Sleep(5);
        }   
    }    
}