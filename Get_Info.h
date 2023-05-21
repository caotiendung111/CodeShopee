#pragma once
#include <iostream>
#include <string>
#include "Do_Hoa.h"
using namespace std;
class Get_Info
{
protected:
	char kh[50];
	char adress[50];
	char  sodt[50];
public:
	void nhap() {
		char fb[100];
		char wel[100] = "VUI LONG NHAP THONG TIN LIEN HE ";
		char welcome3[100] = "HO VA TEN          : ";
		char welcome4[100] = "DIA CHI HIEN TAI   : ";
		char welcome5[100] = "SO DIEN THOAI      : (+84) ";
		cout << "\n\n\n\t\t\t\t\t";
		cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
		cout << "\t\t\t\t\t *                                                         *" << endl;
		cout << "\t\t\t\t\t *---------------------------------------------------------*\n";	  	           
		cout << "\t\t\t\t\t *                                                         *" << endl;
		cout << "\t\t\t\t\t *                                                         *" << endl;
		cout << "\t\t\t\t\t * 	                                                   *" << endl;
		cout << "\t\t\t\t\t * 	                                                   *" << endl;
		cout << "\t\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		int x = 49;
		for (int we = 0; we < strlen(wel); we++) {
			textcolor(12);
			gotoxy(x++, 5);
			cout << wel[we];
			
			Sleep(50);
		}
		textcolor(9);
		int x1 = 49;
		for (int wlc3 = 0; wlc3 < strlen(welcome3); wlc3++) {
			gotoxy(x1++, 8);
			cout << welcome3[wlc3];
	
			Sleep(50);
		}
		textcolor(14);
		cin.getline(kh, 50);
		textcolor(9);
		int x2 = 49;
		for (int wlc4 = 0; wlc4 < strlen(welcome4); wlc4++) {
			gotoxy(x2++, 9);
			cout << welcome4[wlc4];
		
			Sleep(50);
		}
		textcolor(14);
		cin.getline(adress, 50);
		textcolor(9);	
		int x3 = 49;
		for (int wlc5 = 0; wlc5 < strlen(welcome5); wlc5++) {
			gotoxy(x3++, 10);
			cout << welcome5[wlc5];
		
			Sleep(50);
		}
		textcolor(14);
		cin.getline(sodt, 50);
		textcolor(9);
	}
	
};

