#include <iostream>
#include "../dohoa/mylib.h"
#include<thread>
#include<mutex>
using namespace std;
mutex m;
void green()
{
	int x=40;
	int y=0;
	while(true)
	{
		m.lock();
		SetColor(10);
		gotoXY(x,y);
		cout<<"0";
		m.unlock();
		y++;
		Sleep(170);
	}
}
void yellow()
{
	int x=80;
	int y=0;
	while(true)
	{
		m.lock();
		SetColor(14);
		gotoXY(x,y);
		cout<<"0";
		m.unlock();
		y++;
		Sleep(170);
	}
}
int main()
{
	// thread th1(green);
	// thread th2(yellow);

	// th1.join();
	// th2.join();
	cout<<"  (`\\ .-') /`            .-') _ "<<endl;
	cout<<"   `.( OO ),'           ( OO ) )"<<endl;
	cout<<",--./  .--.  ,-.-') ,--./ ,--,' "<<endl;
	cout<<",--./  .--.  ,-.-') ,--./ ,--,'  "<<endl;
	cout<<"|      |  |  |  |OO)|   \\ |  |\\ "<<endl;

	cout<<"█████";

	






	_getch();
    return 0;
}