#include <iostream>
#include <windows.h>
#include <string>
#include<ctime>
#include<time.h>
#include <conio.h>
#include <stdlib.h>
#include "Do_Hoa.h"
#include "Get_Info.h"
#include "Do_An.h"
#include "Do_Uong.h"
#include "Xuat_bill.h"
#include "MainChinhTour.h"
using namespace std;
int main()
{

	ShowCur(0); 
	xuatbill xb;
	
   /* xb.MainXuatDKDN();*/
	
	xb.nhap();
	system("cls");
	b:
	xb.showMenu();
	int chonmenu;
	cin >> chonmenu;
	system("cls");
	switch (chonmenu)
		{
		case 1:
		{
			xb.showMenu1();
			dong876:
			gotoxy(1, 31);
			cout << " Quy Khach Muon Goi Them Do Uong Khong ?\n";
			cout << " 1-co" << endl;
			cout << " 2-khong" << endl;
			int option;
			cout << " Your Choice ? : ";
			cin >> option;
			switch (option )
			{
			case 1 :
			{
				system("cls");
				xb.showMenu2();
			}
			break;
			case 2: {
				chonmenu = 0;
			}
				  break;
			default:
				goto dong876;
				break;
			}		
	}
		break;
		case 2:
		{
			xb.showMenu2();
		dong903:
			gotoxy(1, 31);
			cout << " Quy Khach Muon Goi Them Do An Khong?\n";
			cout << " 1-co" << endl;
			cout << " 2-khong" << endl;
			cout << " Your Choice ? : ";
			int option1;
			cin >> option1;
			switch (option1)
			{
			case 1:
			{
				system("cls");
				xb.showMenu1();
			}
			break;
			case 2 :
				chonmenu = 0;
				break;
			default:
				goto dong903;
				break;
			}		
		}break;
		default:
			goto b;	
			break;
		}
	
	system("cls");
	xb.check2(); //xoá thêm giao di?n
	system("cls");
	time_t baygio = time(0);
	tm* ltm = localtime(&baygio);
	cout << "\n\t\t\t\t Da Nang, Ngay : " << ltm->tm_mday << " / " << 1 + ltm->tm_mon << " / " << 1900 + ltm->tm_year << endl;
	cout << "\n\t\t\t\t Thoi Gian     : " << ltm->tm_hour << ":";
	cout << 1 + ltm->tm_min << ":";
	cout << 1 + ltm->tm_sec << endl; // in ra ngày và gi? t?i dà n?ng 
	xb.bill();
	xb.tien_bang_chu();
	textcolor(12);
	cout << "dong";
	_getch();
	return 0;
}

