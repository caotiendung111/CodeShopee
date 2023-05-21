#pragma once
#include <iostream>
using namespace std;
class DoUong
{
protected:
	int tiendouong, slb, slk, sln, sls;
	int  slbTEMP =0,slkTEMP=0,slnTEMP=0 , slsTEMP=0;
	int h, k;
	int hoadonuong[100];
	int tienb, tienk, tienn, tiens;
	int vitrix, vitriy;  //vitrix va vitriy la toa do x va y  in ra dong chu mon thu i la 
	int e;  // vị trí tại đó nếu không có món
public:
	DoUong();
	
	void showMenu2();
};
DoUong::DoUong()
{
	this->slb = 0; this->slk = 0; this->sln = 0; this->sls = 0;
	this->tiendouong = 0; this->h = 0; this->tienb = 0; this->tienn = 0; this->tienk = 0; this->tiens = 0;
	this->vitrix = 51; // = toadox
	this->vitriy = 1;
	this->e = 18;
}

void DoUong::showMenu2()
{
emiu:
	cout << " \n\n\n\n\n\n\n";
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * *  \n";
	cout << " *              DO UONG                          *" << endl;
	cout << " *-----------------------------------------------*\n";
	cout << " *			  	                 *\n";
	cout << " * [07]		BIA	             15000 dong  *" << endl;
	cout << " * [08]		NUOC NGOT            15000 dong  *" << endl;
	cout << " * [09]		NUOC KHOANG          10000 dong  *" << endl;
	cout << " * [10]		NUOC SUOI            10000 dong  *" << endl;
	cout << " *			  	                 *\n";
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	textcolor(12);
	cout << " Nhap so mon ban chon : ";
	cin >> h;
	if (h <= 4 && h > 0) {
			for (int i = 0; i < h; i++)
			{
				vitriy = vitriy + 7;
				if (vitriy > 27)
				{
					vitrix = 99;
					vitriy = 8;
				}
				gotoxy(vitrix, vitriy);
				textcolor(9);
				cout << " Mon thu " << i + 1 << " la         : ";
				cin >> k;
				if (k<=10 && k>=7)
				{
					hoadonuong[i] = k;
					switch (k)
					{
					case 7:
					{
						textcolor(14);
						gotoxy(vitrix, vitriy + 1);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix, vitriy + 2);
						cout << " *			  	                 *";
						gotoxy(vitrix, vitriy + 3);
						cout << " *             QUY KHACH CHON BIA              *";
						gotoxy(vitrix, vitriy + 4);
						cout << " * So luong             :  ";
						gotoxy(vitrix + 47, vitriy + 4);
						cout << "*";
						gotoxy(vitrix, vitriy + 5);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix + 30, vitriy + 4);
						cin >> slb;
						slbTEMP = slbTEMP + slb;
						cout << "\n";
						tienb = slbTEMP * 15000;	
						textcolor(9);
						break;
					}
					case 8:
					{
						textcolor(14);
						gotoxy(vitrix, vitriy + 1);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix, vitriy + 2);
						cout << " *			  	                 *";
						gotoxy(vitrix, vitriy + 3);
						cout << " *             QUY KHACH CHON NUOC NGOT        *";
						gotoxy(vitrix, vitriy + 4);
						cout << " * So luong             :  ";
						gotoxy(vitrix + 47, vitriy + 4);
						cout << "*";
						gotoxy(vitrix, vitriy + 5);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix + 30, vitriy + 4);
					    cin >> sln;
						slnTEMP = slnTEMP + sln;
				
						cout << "\n";
						tienn = slnTEMP * 15000;
						textcolor(9);
						break;
					}
					case 9:
					{
						textcolor(14);
						gotoxy(vitrix, vitriy + 1);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix, vitriy + 2);
						cout << " *			  	                 *";
						gotoxy(vitrix, vitriy + 3);
						cout << " *             QUY KHACH CHON NUOC KHOANG      *";
						gotoxy(vitrix, vitriy + 4);
						cout << " * So luong             :  ";
						gotoxy(vitrix + 47, vitriy + 4);
						cout << "*";
						gotoxy(vitrix, vitriy + 5);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix + 30, vitriy + 4);
					    cin >> slk;
						slkTEMP = slkTEMP + slk;
					
						cout << "\n";
						tienk = slkTEMP * 10000;
						textcolor(9);
						break;
					}
					case 10:
					{
						textcolor(14);
						gotoxy(vitrix, vitriy + 1);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix, vitriy + 2);
						cout << " *			  	                 *";
						gotoxy(vitrix, vitriy + 3);
						cout << " *             QUY KHACH CHON NUOC SUOI        *";
						gotoxy(vitrix, vitriy + 4);
						cout << " * So luong             :  ";
						gotoxy(vitrix + 47, vitriy + 4);
						cout << "*";
						gotoxy(vitrix, vitriy + 5);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix + 30, vitriy + 4);
						cin >> sls;
						slsTEMP = slsTEMP + sls;
				
						cout << "\n";
						tiens = slsTEMP * 10000;
						textcolor(9);
						break;
					}

					default:
						goto emiu;
						break;
					}
				}
				else
				{
					textcolor(14);
					e++;
					vitriy = vitriy - 6;
					gotoxy(1, e);
					cout << " Khong Co Mon Nay"; textcolor(9);
				}
		}
	}
	else
	{
		textcolor(14);
		cout << "\n\t\t\t\t Xin Loi ! Khong Du Mon Hoac Khong The Thuc Hien"; textcolor(9);
		goto emiu;

	}    			
}



