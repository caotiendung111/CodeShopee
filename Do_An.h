#pragma once
#include <iostream>
class DoAn 
{
protected:
	int slphoTEMP = 0, slmiTEMP = 0, slbtTEMP = 0, slpglTEMP = 0, slbcTEMP = 0 , slcgaTEMP = 0;
	int tiendoan, slpho, slbt, slpgl, slcga, slbc, slm;
	int n, j;
	int hoadonan[100];
	int tienpho, tienbt , tienpgl , tiencga, tienbc, tienm;
	int vitrix,vitriy;  //vitrix va vitriy la toa do x va y  in ra dong chu mon thu i la 
	int e; // vị trí tại đó nếu không có món 
	int z; // loi qua nhieu mon
public:
	DoAn();
	void showMenu1();
};
DoAn::DoAn()
{
	this->tienpho = 0;
	this->tienm = 0;
	this->tienpgl = 0;
	this->tiencga = 0;
	this->tienbc = 0;
	this->tienbt = 0;
	this->tiendoan = 0;
	this->slpho= 0;
	this->slbt = 0;
	this->slpgl = 0;
	this->slcga = 0;
	this->slbc = 0;
	this->slm = 0;
	this->n = 0;
	this->vitrix = 51; // = toadox
	this->vitriy = 1;
	this->e = 22;
	this->z = 22;
}
void DoAn::showMenu1()
{
emiu:
	cout << " \n\n\n\n\n\n\n";
		cout << " * * * * * * * * * * * * * * * * * * * * * * * * *  \n";
		cout << " *                       DO AN                   *" << endl;
		cout << " *-----------------------------------------------*\n";
		cout << " *			  	                 *\n";
		cout << " * [1]		PHO BO		     45000 dong  *" << endl;
		cout << " * [2]		MI QUANG	     40000 dong  *" << endl;
		cout << " * [3]		BUN THIT NUONG	     40000 dong  *" << endl;
		cout << " * [4]		PHO KHO              50000 dong  *" << endl;
		cout << " * [5]		COM GA               50000 dong  *" << endl;
		cout << " * [6]		BUN CHA CA           45000 dong  *" << endl;
		cout << " *			  	                 *\n";
		cout << " * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;	
		textcolor(12);
		cout << "\n Nhap so mon ban chon : ";
		cin >> n;
		if ( n<=6 && n>0) {
			for (int i = 0; i < n; i++)
			{
			em:
				vitriy = vitriy + 7;
				if (vitriy > 27)
				{
					vitrix = 99;
					vitriy = 8;
				}
				gotoxy(vitrix,vitriy);
				textcolor(9);
				cout << " Mon thu " << i + 1 << " la         : "; 
				cin >> j;
				if (j <= 6 && j > 0	)
				{
					hoadonan[i] = j;		
					switch (j)
					{
					case 1:
					{
						
						textcolor(14);	 
						gotoxy(vitrix, vitriy + 1);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix, vitriy + 2);
						cout << " *			  	                 *";
						gotoxy(vitrix, vitriy + 3);
						cout << " *             QUY KHACH CHON PHO BO           *";
						gotoxy(vitrix, vitriy + 4);
						cout << " * So luong             :  "; 
						gotoxy(vitrix + 47, vitriy+4);
						cout << "*";
						gotoxy(vitrix, vitriy + 5);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix + 30, vitriy + 4);
						cin >> slpho;			
						slphoTEMP = slphoTEMP + slpho;	
						cout << "\n";
						tienpho = slphoTEMP * 45000;
						textcolor(9);
						break;
					}
					case 2:
					{
						textcolor(14);
						gotoxy(vitrix, vitriy + 1);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix, vitriy + 2);
						cout << " *			  	                 *";
						gotoxy(vitrix, vitriy + 3);
						cout << " *             QUY KHACH CHON MI QUANG         *";
						gotoxy(vitrix, vitriy + 4);
						cout << " * So luong             :  ";
						gotoxy(vitrix + 47, vitriy + 4);
						cout << "*";
						gotoxy(vitrix, vitriy + 5);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix + 30, vitriy + 4);


						cin >> slm;
						
						slmiTEMP = slmiTEMP + slm;
						cout << "\n";
						tienm = slmiTEMP * 40000;
						textcolor(9);
						break;
					}
					case 3:
					{
						textcolor(14);
						gotoxy(vitrix, vitriy + 1);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix, vitriy + 2);
						cout << " *			  	                 *";
						gotoxy(vitrix, vitriy + 3);
						cout << " *             QUY KHACH CHON BUN THIT NUONG   *";
						gotoxy(vitrix, vitriy + 4);
						cout << " * So luong             :  ";
						gotoxy(vitrix + 47, vitriy + 4);
						cout << "*";
						gotoxy(vitrix, vitriy + 5);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix + 30, vitriy + 4);
						cin >> slbt;
						slbtTEMP = slbtTEMP + slbt;
						cout << "\n";
						tienbt = slbtTEMP * 40000;
						textcolor(9);
						break;
					}
					case 4:
					{
						textcolor(14);
						gotoxy(vitrix, vitriy + 1);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix, vitriy + 2);
						cout << " *			  	                 *";
						gotoxy(vitrix, vitriy + 3);
						cout << " *             QUY KHACH CHON PHO KHO          *";
						gotoxy(vitrix, vitriy + 4);
						cout << " * So luong             :  ";
						gotoxy(vitrix + 47, vitriy + 4);
						cout << "*";
						gotoxy(vitrix, vitriy + 5);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix + 30, vitriy + 4);
						cin >> slpgl;
						slpglTEMP = slpglTEMP + slpgl;	
						cout << "\n";
						tienpgl = slpglTEMP * 50000;
						textcolor(9);
						break;
					}
					case 5:
					{
						textcolor(14);
						gotoxy(vitrix, vitriy + 1);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix, vitriy + 2);
						cout << " *			  	                 *";
						gotoxy(vitrix, vitriy + 3);
						cout << " *             QUY KHACH CHON COM GA           *";
						gotoxy(vitrix, vitriy + 4);
						cout << " * So luong             :  ";
						gotoxy(vitrix + 47, vitriy + 4);
						cout << "*";
						gotoxy(vitrix, vitriy + 5);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix + 30, vitriy + 4);
						
						cin >> slcga;
						slcgaTEMP = slcgaTEMP + slcga;
						cout << "\n";
						tiencga = slcgaTEMP * 50000;
						textcolor(9);
						break;
					}
					case 6:
					{
						textcolor(14);
						gotoxy(vitrix, vitriy + 1);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix, vitriy + 2);
						cout << " *			  	                 *";
						gotoxy(vitrix, vitriy + 3);
						cout << " *             QUY KHACH CHON BUN CHA CA       *";
						gotoxy(vitrix, vitriy + 4);
						cout << " * So luong             :  ";
						gotoxy(vitrix + 47, vitriy + 4);
						cout << "*";
						gotoxy(vitrix, vitriy + 5);
						cout << " * * * * * * * * * * * * * * * * * * * * * * * *";
						gotoxy(vitrix + 30, vitriy + 4);
					
						cin >> slbc;
						slbcTEMP = slbcTEMP + slbc;
						cout << "\n";
						tienbc = slbcTEMP * 45000;
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
			gotoxy(1,z);
			cout << " Xin Loi ! Khong Du Mon Hoac Khong The Thuc Hien";
			textcolor(9);
		}

	
}
