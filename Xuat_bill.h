#pragma once
#include <iostream>
#include "Do_An.h"
#include "Do_Uong.h"
#include "MainChinhTour.h"
#include "Get_Info.h"
#include "Do_Hoa.h"
#include <Windows.h>

using namespace std;
class xuatbill : public DoAn, public DoUong, public MainChinhTour,  public Get_Info
{
protected:
	int thempho = 0, themmi = 0, thembt = 0, thempkgl = 0, themcga = 0, thembc = 0; // thêm d? an
	int thembia = 0, themngot = 0, themkhoang = 0, themsuoi = 0;
	int id , id1 , msp, msp1, tongcong, pgh, gg, mgg, ptvc;
	float km;
	long tienmat;
public:
	xuatbill();
	void set_tienmat(long tienmat)
	{
		this->tienmat = tienmat;
	};
	long get_tienmat() { return tienmat; }
	void nhapdiachi();
	void xuatdiachi();
	void bill();
	void magiamgia();
	void showMenu();
	void check2(); // dã ?n
	void tien_bang_chu();
};
void xuatbill::tien_bang_chu()
{
	
		textcolor(12);
		double money = get_tienmat();
		int int_part = (int)money;
		int dec_part = (int)(money * 100);
		dec_part = dec_part % 100;

		string ones[] = { "khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin" };
		string tens_multiple[] = { "", "", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi" };
		string tens_power[] = { "", "muoi", "tram", "ngan", "muoi", "tram", "trieu", "muoi", "tram", "ty" };
		string words = "";
		// xu li phan nghin
		int i = 0;
		if (int_part > 0)
		{
			while (int_part > 0)
			{
				int n = int_part % 10;
				int_part /= 10;

				if (n > 0)
				{
					if (n == 1 && i == 0)
						words = "mot " + tens_power[i] + " " + words;
					else if (n == 5 && i == 1)
						words = "nam " + tens_power[i] + " " + words;
					else
						words = ones[n] + " " + tens_power[i] + " " + words;
				}
				++i;
			}
		}

		// xi li phan thap phan 
		if (dec_part > 0)
		{
			i = 0;
			words += "ph?y ";
			while (dec_part > 0)
			{
				int n = dec_part % 10;
				dec_part /= 10;

				if (n > 0)
				{
					if (n == 1 && i == 1)
						words += "mot ";
					else if (n == 5 && i == 0)
						words += "nam ";
					else
						words += ones[n] + " ";

					words += tens_multiple[i] + " ";
				}
				++i;
			}
		}

		cout << " " << words;

		textcolor(9);
}
xuatbill::xuatbill()
{
	this->thempho = 0;
	this->tongcong = 0;
	this->id = 0;;
	this->id1 = 0;
	this->msp = 0;
	this->msp1 = 0;
}
void xuatbill::check2()
{
	
	int chonxoathemok;

	do
	{
		cout << "\n\t\t\t ";
		cout << "\n\t\t\t\t * * * * * * * * * * * * * * * * * * * * * *\n";
		cout << "\t\t\t\t *         Ban Muon Yeu Cau Gi Khong?      *" << endl;
		cout << "\t\t\t\t *-----------------------------------------*\n";
		cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * *\n";
		cout << "\t\t\t\t *                                         *" << endl;
		cout << "\t\t\t\t * [1]     Xoa San Pham                    *" << endl;
		cout << "\t\t\t\t * [2]     Them San Pham                   *" << endl;
		cout << "\t\t\t\t * [0]     XUAT BILL RA MAN HINH !         *" << endl;
		cout << "\t\t\t\t *                                         *" << endl;
		cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "\t\t\t\t Your choose ? : ";
		textcolor(14);
		cin >> chonxoathemok; textcolor(9);
		switch (chonxoathemok)
		{
		case 0:
		{
			break; 
		}

		case 1: 
		{
			int ckonXoa;
			do
			{
				textcolor(12);
				cout << "\n\n\t\t\t\t Ban muon Lam Gi? "; textcolor(9);
				cout << "\n\n" << endl;
				cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * \n";
				cout << "\t\t\t\t *                                               *\n";
				cout << "\t\t\t\t *      [1] Xoa Do An  ||  [2] Xoa Do Uong       *" << endl;
				cout << "\t\t\t\t *         [3] Hien Thi List Sau Khi Xoa         *" << endl;
				cout << "\t\t\t\t *               [4] Quay Lai                    *\n";
				cout << "\t\t\t\t *-----------------------------------------------*\n";
				cout << "\t\t\t\t *                                               *\n";
				cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * *\n";
				cout << "\n\t\t\t\t Your choose? ";
				textcolor(14);  cin >> ckonXoa; textcolor(9);
				switch (ckonXoa)
				{
				case 1:
				{

					for (int i = 0; i < n - 1; i++)//xoa bo phan tu trung nhau 
					{
						j = i + 1;
						while (j < n)
							if (hoadonan[i] == hoadonan[j])
							{
								for (int k = j; k < n - 1; k++)
									hoadonan[k] = hoadonan[k + 1]; //xoa bo phan tu trung nhau
								n = n - 1;
							}
							else j = j + 1;
					} //xoa bo phan tu trung nhau
					textcolor(14);
					cout << "\n\t\t\t\t *Ten hang               : Don Gia" << "        : So luong" << endl;
					cout << "\n\t\t\t\t [Do An]";

					textcolor(9);
					if (n == 0)
					{
						cout << "                 : Khong Co San Pham";
					}
					else
					{
						for (int i = 0; i < n; i++)// in ra thông tin s?n ph?m và s? lu?ng d? xoá
						{
							if (hoadonan[i] == 1)
							{
								cout << "\n\t\t\t\t [1] PHO BO                  : 45000 dong" << "     : x" << slphoTEMP;
							}
							if (hoadonan[i] == 2)
							{
								cout << "\n\t\t\t\t [2] MI QUANG                : 40000 dong" << "     : x" << slmiTEMP;
							}
							if (hoadonan[i] == 3)
							{
								cout << "\n\t\t\t\t [3] BUN THIT NUONG          : 40000 dong" << "     : x" << slbtTEMP;
							}
							if (hoadonan[i] == 4)
							{
								cout << "\n\t\t\t\t [4] PHO KHO GIA LAI         : 50000 dong" << "     : x" << slpglTEMP;
							}
							if (hoadonan[i] == 5)
							{
								cout << "\n\t\t\t\t [5] COM GA HOI AN           : 50000 dong" << "     : x" << slcgaTEMP;
							}
							if (hoadonan[i] == 6)
							{
								cout << "\n\t\t\t\t [6] BUN CHA CA              : 45000 dong" << "     : x" << slbcTEMP;
							}
						}
					}
					cout << "\n\t\t\t\t Nhap ma san pham: ";
					bool removeSuccess = false; // kiem tra phan tu xoa
					cin >> id;
					if (id == 1) { tienpho = 0; slphoTEMP = 0; }
					if (id == 2) { tienm = 0; slmiTEMP = 0; }
					if (id == 3) { tienbt = 0; slbtTEMP = 0; }
					if (id == 4) { tienpgl = 0; slpglTEMP = 0; }
					if (id == 5) { tiencga = 0;  slcgaTEMP = 0; }
					if (id == 6) { tienbc = 0;  slbcTEMP = 0; } //gia tien se bang 0 neu bi xoa 

					for (int i = 0; i < n; i++)
					{

						if (hoadonan[i] == id) { // xoa bo phan tu nay
							for (int j = i; j < n - 1; j++)
							{

								hoadonan[j] = hoadonan[j + 1];

							}
							n--;
							removeSuccess = true;
						}

					}
					if (!removeSuccess)
					{
						cout << "\n\t\t\t\t <==Khong tim thay ";
						textcolor(14); cout << " [Do An] "; textcolor(9);
						cout << " can xoa ==>   \n";

					}
					else
					{
						cout << "\n\t\t\t\t <==Xoa ";
						textcolor(14); cout << " [Do An] "; textcolor(9);
						cout << " thanh cong ==>   \n";

					}
				}

				break;
				case 2:
				{
					for (int i = 0; i < n - 1; i++)//xoa bo phan tu trung nhau 
					{
						j = i + 1;
						while (j < n)
							if (hoadonan[i] == hoadonan[j])
							{
								for (int k = j; k < n - 1; k++)
									hoadonan[k] = hoadonan[k + 1]; //xoa bo phan tu trung nhau
								n = n - 1;
							}
							else j = j + 1;
					} //xoa bo phan tu trung nhau
					textcolor(14);
					cout << "\n\t\t\t\t *Ten hang               : Don Gia" << "        : So luong" << endl;
					cout << "\n\t\t\t\t [Do Uong]";

					textcolor(9);
					if (h == 0)
					{
						cout << "               :Khong Co San Pham";
					}
					else
					{
						for (int i = 0; i < h; i++)
						{
							if (hoadonuong[i] == 7)
							{
								cout << "\n\t\t\t\t [07] BIA                : 15000 dong" << "     : x" << slbTEMP;
							}
							if (hoadonuong[i] == 8)
							{
								cout << "\n\t\t\t\t [08] NUOC NGOT          : 15000 dong" << "     : x" << slnTEMP;
							}
							if (hoadonuong[i] == 9)
							{
								cout << "\n\t\t\t\t [09] NUOC KHOANG        : 10000 dong" << "     : x" << slkTEMP;
							}
							if (hoadonuong[i] == 10)
							{
								cout << "\n\t\t\t\t [10] NUOC SUOI          : 10000 dong" << "     : x" << slsTEMP;
							}
						}
					}

					cout << "\n\t\t\t\t Nhap ma san pham: ";
					int id1;
					bool removeSuccess1 = false;
					cin >> id1;
					if (id1 == 7) { tienb = 0; }

					if (id1 == 8) { tienn = 0; }

					if (id1 == 9) { tienk = 0; }

					if (id1 == 10) { tiens = 0; }

					for (int i = 0; i < h; i++)
					{
						if (hoadonuong[i] == id1) { // xoa bo phan tu nay
							for (int k = i; k < h - 1; k++)
							{
								hoadonuong[k] = hoadonuong[k + 1];
							}
							h--;

							removeSuccess1 = true;
						}

					}
					if (!removeSuccess1) {
						cout << "\n\t\t\t\t <==Khong tim thay ";
						textcolor(14); cout << " [Do Uong] "; textcolor(9);
						cout << " can xoa ==>   \n";


					}
					else
					{
						cout << "\n\t\t\t\t <==Xoa ";
						textcolor(14); cout << " [Do Uong] "; textcolor(9);
						cout << " thanh cong ==>   \n";
					}

				}
				break;
				case 3:
				{

					cout << "\n\t\t\t\t *Danh Sach Sau Khi Xoa*";
					textcolor(14);
					cout << "\n\t\t\t\t *Ten hang               : Don Gia" << "        : So luong" << endl;
					cout << "\n\t\t\t\t [Do An]"; textcolor(9);

					for (int i = 0; i < n - 1; i++)//xoa bo phan tu trung nhau 
					{
						j = i + 1;
						while (j < n)
							if (hoadonan[i] == hoadonan[j])
							{
								for (int k = j; k < n - 1; k++)
									hoadonan[k] = hoadonan[k + 1]; //xoa bo phan tu trung nhau
								n = n - 1;
							}
							else j = j + 1;
					} //xoa bo phan tu trung nhau

					if (n == 0)
					{
						cout << "                 : Khong Co San Pham";
					}
					else//in ra man hinh san pham sau khi xoa cua Do An
					{
						for (int i = 0; i < n; i++)// in ra thông tin s?n ph?m và s? lu?ng
						{
							if (hoadonan[i] == 1)
							{
								cout << "\n\t\t\t\t PHO BO                  : 45000 dong" << "     : x" << slphoTEMP;
							}
							if (hoadonan[i] == 2)
							{
								cout << "\n\t\t\t\t MI QUANG                : 40000 dong" << "     : x" << slmiTEMP;
							}
							if (hoadonan[i] == 3)
							{
								cout << "\n\t\t\t\t BUN THIT NUONG          : 40000 dong" << "     : x" << slbtTEMP;
							}
							if (hoadonan[i] == 4)
							{
								cout << "\n\t\t\t\t PHO KHO GIA LAI         : 50000 dong" << "     : x" << slpglTEMP;
							}
							if (hoadonan[i] == 5)
							{
								cout << "\n\t\t\t\t COM GA HOI AN           : 50000 dong" << "     : x" << slcgaTEMP;
							}
							if (hoadonan[i] == 6)
							{
								cout << "\n\t\t\t\t BUN CHA CA              : 45000 dong" << "     : x" << slbcTEMP;
							}
						}
					}


					textcolor(14);
					cout << "\n\t\t\t\t [Do Uong]"; textcolor(9);
					if (h == 0)
					{
						cout << "               : Khong Co San Pham";
					}
					else
					{ //in ra man hinh san pham sau khi xoa cua Do Uong
						cout << endl;
						for (int i = 0; i < h; i++)
						{
							if (hoadonuong[i] == 7)
							{
								cout << "\n\t\t\t\t BIA                     : 15000 dong" << "     : x" << slbTEMP;
							}
							if (hoadonuong[i] == 8)
							{
								cout << "\n\t\t\t\t NUOC NGOT               : 15000 dong" << "     : x" << slnTEMP;
							}
							if (hoadonuong[i] == 9)
							{
								cout << "\n\t\t\t\t NUOC KHOANG             : 10000 dong" << "     : x" << slkTEMP;
							}
							if (hoadonuong[i] == 10)
							{
								cout << "\n\t\t\t\t NUOC SUOI               : 10000 dong" << "     : x" << slsTEMP;
							}
						}
					}

				
				}
				break;
				case 4:
				{
					system("cls");					
					break;
				}
				break;
				default:
					textcolor(14);
					cout << "\n\t\t\t\t Sai Chuc Nang Vui Long Thu Lai ";
					textcolor(9);
					break;
				}
			} while (ckonXoa != 4);
		}

		break;
		case 2: //case2 c?a menu chính (thêm d? an)
		{
			int ckonThem = 0;
			do
			{

				textcolor(12);
				cout << "\n\n\t\t\t\t Ban muon Lam Gi? ";
				textcolor(9);
				cout << "\n\n" << endl;
				cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * \n";
				cout << "\t\t\t\t *                                               *\n";
				cout << "\t\t\t\t *      [1] Them Do An  ||  [2] Them Do Uong     *" << endl;
				cout << "\t\t\t\t *         [3] Hien Thi List sau khi them        *" << endl;
				cout << "\t\t\t\t *               [4] Quay lai                    *\n";
				cout << "\t\t\t\t *-----------------------------------------------*\n";
				cout << "\t\t\t\t *                                               *\n";
				cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * *\n";
				cout << "\n\t\t\t\t Your choose? ";

				textcolor(14);  cin >> ckonThem; textcolor(9);
				switch (ckonThem)
				{
				case 1:
				{
					textcolor(14);
					cout << "\n\t\t\t\t [Menu Do An]"; textcolor(9);
					cout << "\n\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * *  \n";
					cout << "\t\t\t\t *                       DO AN                     *" << endl;
					cout << "\t\t\t\t *-------------------------------------------------*\n";
					cout << "\t\t\t\t *			  	                   *\n";
					cout << "\t\t\t\t * [1]		PHO BO		       45000 dong  *" << endl;
					cout << "\t\t\t\t * [2]		MI QUANG	       40000 dong  *" << endl;
					cout << "\t\t\t\t * [3]		BUN THIT NUONG	       40000 dong  *" << endl;
					cout << "\t\t\t\t * [4]		PHO KHO GIA LAI        50000 dong  *" << endl;
					cout << "\t\t\t\t * [5]		COM GA HOI AN          50000 dong  *" << endl;
					cout << "\t\t\t\t * [6]		BUN CHA CA             45000 dong  *" << endl;
					cout << "\t\t\t\t *			  	                   *\n";
					cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
					cout << "\n\t\t\t\t Nhap ma san pham: ";

					cin >> msp;
					switch (msp)
					{
					case 1:
					{

						hoadonan[n++] = 1;
						cout << "\n\t\t\t\t Them Bao Nhieu? : ";
						cin >> thempho;
						slphoTEMP = slphoTEMP + thempho;
						tienpho = slphoTEMP * 45000;
						cout << "\n\t\t\t\t Ban Da Them " << thempho << " [PHO BO] ";
					}
					break;
					case 2:
					{
						hoadonan[n++] = 2;
						cout << "\n\t\t\t\t Them Bao Nhieu? : ";
						cin >> themmi;
						slmiTEMP = slmiTEMP + themmi;
						tienm = slmiTEMP * 40000;
						cout << "\n\t\t\t\t Ban Da Them " << themmi << "[Mi Quang] ";
					}
					break;
					case 3:
					{
						hoadonan[n++] = 3;
						cout << "\n\t\t\t\t Them Bao Nhieu? : ";
						cin >> thembt;
						slbtTEMP = slbtTEMP + thembt;
						tienbt = slbtTEMP * 40000;
						cout << "\n\t\t\t\t Ban Da Them " << thembt << "[Bun Thit Nuong] ";
					}
					break;
					case 4:
					{
						hoadonan[n++] = 4;
						cout << "\n\t\t\t\t Them Bao Nhieu? : ";
						cin >> thempkgl;
						slpglTEMP = slpglTEMP + thempkgl;
						tienpgl = slpglTEMP * 50000;
						cout << "\n\t\t\t\t Ban Da Them " << thempkgl << "[PHO KHO GIA LAI] ";
					}
					break;
					case 5:
					{
						hoadonan[n++] = 5;
						cout << "\n\t\t\t\t Them Bao Nhieu? : ";
						cin >> themcga;
						slcgaTEMP = slcgaTEMP + themcga;
						tiencga = slcgaTEMP * 50000;
						cout << "\n\t\t\t\t Ban Da Them " << themcga << "[Com Ga Hoi An] ";
					}
					break;
					case 6:
					{
						hoadonan[n++] = 6;
						cout << "\n\t\t\t\t Them Bao Nhieu? : ";
						cin >> thembc;
						slbcTEMP = slbcTEMP + thembc;
						tienbc = slbcTEMP * 45000;
						cout << "\n\t\t\t\t Ban Da Them " << thembc << "[Bun Cha Ca] ";
					}
					break;
					default:
						cout << "\n\t\t\t\t Khong Tim Ra Ma San Pham";
						break;
					}
				}
				break;
				case 2:
				{
					textcolor(14);
					cout << "\n\t\t\t\t [Menu Do Uong]"; textcolor(9);
					cout << "\n\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * *  \n";
					cout << "\t\t\t\t *              DO UONG                            *" << endl;
					cout << "\t\t\t\t *-------------------------------------------------*\n";
					cout << "\t\t\t\t *			  	                   *\n";
					cout << "\t\t\t\t * [07]		BIA	               15000 dong  *" << endl;
					cout << "\t\t\t\t * [08]		NUOC NGOT              15000 dong  *" << endl;
					cout << "\t\t\t\t * [09]		NUOC KHOANG            10000 dong  *" << endl;
					cout << "\t\t\t\t * [10]		NUOC SUOI              10000 dong  *" << endl;
					cout << "\t\t\t\t *			  	                   *\n";
					cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
					cout << "\n\t\t\t\t Nhap ma san pham: ";
					cin >> msp1;
					switch (msp1)
					{
					case 7:
					{

						hoadonuong[h++] = 7;
						cout << "\n\t\t\t\t Them Bao Nhieu? : ";
						cin >> thembia;
						slbTEMP = slbTEMP + thembia;
						tienb = slbTEMP * 15000;
						cout << "\n\t\t\t\t Ban Da Them " << thembia << " [BIA] ";
					}
					break;
					case 8:
					{
						hoadonuong[h++] = 8;
						cout << "\n\t\t\t\t Them Bao Nhieu? : ";
						cin >> themngot;
						slnTEMP = slnTEMP + themngot;
						tienn = slnTEMP * 15000;
						cout << "\n\t\t\t\t Ban Da Them " << themngot << "[NUOC NGOT] ";
					}
					break;
					case 9:
					{
						hoadonuong[h++] = 9;
						cout << "\n\t\t\t\t Them Bao Nhieu? : ";
						cin >> themkhoang;
						slkTEMP = slkTEMP + themkhoang;
						tienk = slkTEMP * 10000;
						cout << "\n\t\t\t\t Ban Da Them " << themkhoang << "[NUOC KHOANG] ";
					}
					break;
					case 10:
					{
						hoadonuong[h++] = 10;
						cout << "\n\t\t\t\t Them Bao Nhieu? : ";
						cin >> themsuoi;
						slsTEMP = slsTEMP + themsuoi;
						tiens = slsTEMP * 10000;
						cout << "\n\t\t\t\t Ban Da Them " << themsuoi << "[NUOC SUOI] ";
					}
					break;
					default:
						cout << "\n\t\t\t\t Khong Tim Ra Ma San Pham";
						break;
					}
				}
				break;
				case 3:
				{
					cout << "\n\t\t\t\t *Danh Sach Sau Khi Them*";	
					textcolor(14);
					cout << "\n\t\t\t\t *Ten hang               : Don Gia" << "        : So luong" << endl;
					cout << "\n\t\t\t\t [Do An]"; textcolor(9);

					for (int i = 0; i < n - 1; i++)//xoa bo phan tu trung nhau 
					{
						j = i + 1;
						while (j < n)
							if (hoadonan[i] == hoadonan[j])
							{
								for (int k = j; k < n - 1; k++)
									hoadonan[k] = hoadonan[k + 1]; //xoa bo phan tu trung nhau
								n = n - 1;
							}
							else j = j + 1;
					} //xoa bo phan tu trung nhau cua Do An

					
					if (n == 0)
					{
						cout << "                 : Khong Co San Pham";
					}
					else//in ra man hinh san pham sau khi xoa cua Do An
					{
						for (int i = 0; i < n; i++)// in ra thông tin s?n ph?m và s? lu?ng
						{
							if (hoadonan[i] == 1)
							{
								cout << "\n\t\t\t\t PHO BO                  : 45000 dong" << "     : x" << slphoTEMP;
							}
							if (hoadonan[i] == 2)
							{
								cout << "\n\t\t\t\t MI QUANG                : 40000 dong" << "     : x" << slmiTEMP;
							}
							if (hoadonan[i] == 3)
							{
								cout << "\n\t\t\t\t BUN THIT NUONG          : 40000 dong" << "     : x" << slbtTEMP;
							}
							if (hoadonan[i] == 4)
							{
								cout << "\n\t\t\t\t PHO KHO GIA LAI         : 50000 dong" << "     : x" << slpglTEMP;
							}
							if (hoadonan[i] == 5)
							{
								cout << "\n\t\t\t\t COM GA HOI AN           : 50000 dong" << "     : x" << slcgaTEMP;
							}
							if (hoadonan[i] == 6)
							{
								cout << "\n\t\t\t\t BUN CHA CA              : 45000 dong" << "     : x" << slbcTEMP;
							}
						}
					}

					for (int i = 0; i < h - 1; i++)//xoa bo phan tu trung nhau 
					{
						int a = i + 1;
						while (a < h)
							if (hoadonuong[i] == hoadonuong[a])
							{
								for (int k = a; k < h - 1; k++)
									hoadonuong[k] = hoadonuong[k + 1]; //xoa bo phan tu trung nhau
								h = h - 1;
							}
							else a = a + 1;
					} //xoa bo phan tu trung nhau cua Do Uong
					textcolor(14);
					cout << "\n\t\t\t\t [Do Uong]"; textcolor(9);
					if (h == 0)
					{
						cout << "               : Khong Co San Pham";
					}
					else
					{ //in ra man hinh san pham sau khi xoa cua Do Uong
						cout << endl;
						for (int i = 0; i < h; i++)
						{
							if (hoadonuong[i] == 7)
							{
								cout << "\n\t\t\t\t BIA                     : 15000 dong" << "     : x" << slbTEMP;
							}
							if (hoadonuong[i] == 8)
							{
								cout << "\n\t\t\t\t NUOC NGOT               : 15000 dong" << "     : x" << slnTEMP;
							}
							if (hoadonuong[i] == 9)
							{
								cout << "\n\t\t\t\t NUOC KHOANG             : 10000 dong" << "     : x" << slkTEMP;
							}
							if (hoadonuong[i] == 10)
							{
								cout << "\n\t\t\t\t NUOC SUOI               : 10000 dong" << "     : x" << slsTEMP;
							}
						}
					}

				}
				break;
				case 4:
				{
					system("cls");
				}
				break;
				default:
					textcolor(14);
					cout << "\n\t\t\t\t Sai Chuc Nang Vui Long Thu Lai ";
					textcolor(9);
					break;
				}
			} while (ckonThem != 4);
		}
		break;
		default:
			textcolor(14);
			cout << "\n\t\t\t\t Sai Chuc Nang Vui Long Thu Lai ";
			textcolor(9);
			break;
		}
	} while (chonxoathemok != 0);
}
void xuatbill::showMenu()
{
	textcolor(12); cout << " Tour BrJ Xin Chao  \n "; textcolor(9);
	cout << "\n\n Quy Khach    :	   "; textcolor(14); cout << kh << endl; textcolor(9);
	cout << "\n Dia Chi      :    "; textcolor(14); cout << adress << endl; textcolor(9);
	cout << "\n SDT          :    "; textcolor(14); cout << sodt  << endl; textcolor(9);
	textcolor(9);
	cout << "\n\n" << endl << endl;
	cout << "\n";
	cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * *\n";
	cout << "\t\t\t\t *           THUC DON CHINH            *" << endl;
	cout << "\t\t\t\t *-------------------------------------*\n";
	cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * *\n";
	cout << "\t\t\t\t *                                     *" << endl;
	cout << "\t\t\t\t * [1]          DO AN                  *" << endl;
	cout << "\t\t\t\t * [2]          NUOC UONG              *" << endl;
	cout << "\t\t\t\t *                                     *" << endl;
	cout << "\t\t\t\t * * * * * * * * * * * * * * * * * * * *" << endl;
	textcolor(12);
	cout << "\n\t\t\t\t Your choice : ";
	textcolor(9);

}
void xuatbill::bill()
{
	cout << "\n\t\t\t\t *****************************************" << endl;
	cout << "\n\t\t\t\t *Khach hang        : "; textcolor(14); cout << kh << endl; textcolor(9);
	cout << "\n\t\t\t\t *Dia chi giao hang : "; textcolor(14);  cout << adress << endl; textcolor(9);
	cout << "\n\t\t\t\t *So Dien Thoai     : "; textcolor(14);  cout << "0";   cout << sodt << endl; textcolor(9);
	textcolor(14);
	cout << "\n\t\t\t\t *Ten hang               : Don Gia" << "        : So luong" << endl;
	cout << "\n\t\t\t\t [Do An]"; textcolor(9);
	for (int i = 0; i < n - 1; i++)//xoa bo phan tu trung nhau 
	{
		j = i + 1;
		while (j < n)
			if (hoadonan[i] == hoadonan[j])
			{
				for (int k = j; k < n - 1; k++)
					hoadonan[k] = hoadonan[k + 1]; //xoa bo phan tu trung nhau
				n = n - 1;
			}
			else j = j + 1;
	} //xoa bo phan tu trung nhau

	if (n == 0)
	{
		cout << "                 : Khong Co San Pham";
	}
	else//in ra man hinh san pham sau khi xoa cua Do An
	{
		for (int i = 0; i < n; i++)// in ra thông tin s?n ph?m và s? lu?ng
		{
			if (hoadonan[i] == 1)
			{
				cout << "\n\t\t\t\t PHO BO                  : 45000 dong" << "     : x" << slphoTEMP;
			}
			if (hoadonan[i] == 2)
			{
				cout << "\n\t\t\t\t MI QUANG                : 40000 dong" << "     : x" << slmiTEMP;
			}
			if (hoadonan[i] == 3)
			{
				cout << "\n\t\t\t\t BUN THIT NUONG          : 40000 dong" << "     : x" << slbtTEMP;
			}
			if (hoadonan[i] == 4)
			{
				cout << "\n\t\t\t\t PHO KHO GIA LAI         : 50000 dong" << "     : x" << slpglTEMP;
			}
			if (hoadonan[i] == 5)
			{
				cout << "\n\t\t\t\t COM GA HOI AN           : 50000 dong" << "     : x" << slcgaTEMP;
			}
			if (hoadonan[i] == 6)
			{
				cout << "\n\t\t\t\t BUN CHA CA              : 45000 dong" << "     : x" << slbcTEMP;
			}
		}
	}
	tiendoan = tienpho + tienm + tienbt + tienpgl + tiencga + tienbc;
	cout << "\n\t\t\t\t *Tong tien do an        : " << tiendoan << " dong" << endl;
	textcolor(14);
	cout << "\n\t\t\t\t [Do Uong]"; textcolor(9);
	if (h == 0)
	{
		cout << "               : Khong Co San Pham";
	}
	else
	{ //in ra man hinh san pham sau khi xoa cua Do Uong
		cout << endl;
		for (int i = 0; i < h; i++)
		{
			if (hoadonuong[i] == 7)
			{
				cout << "\n\t\t\t\t BIA                     : 15000 dong" << "     : x" << slbTEMP;
			}
			if (hoadonuong[i] == 8)
			{
				cout << "\n\t\t\t\t NUOC NGOT               : 15000 dong" << "     : x" << slnTEMP;
			}
			if (hoadonuong[i] == 9)
			{
				cout << "\n\t\t\t\t NUOC KHOANG             : 10000 dong" << "     : x" << slkTEMP;
			}
			if (hoadonuong[i] == 10)
			{
				cout << "\n\t\t\t\t NUOC SUOI               : 10000 dong" << "     : x" << slsTEMP;
			}
		}
	}
	tiendouong = tienb + tienk + tienn + tiens;
	cout << "\n\t\t\t\t *Tong tien do uong      : " << tiendouong << " dong" << endl;
	tongcong = tiendoan + tiendouong;
	cout << "\n\t\t\t\t *Thanh Tien             : " << tongcong << " dong";
	cout << "\n\t\t\t\t *Phi giao hang ( " << km << " km ) : " << pgh << " dong";
	cout << "\n\t\t\t\t *Voucher                : " << "giam " << ptvc << "%" << " \n\t\t\t\t *Giam " << (tongcong * (ptvc) / 100) * 1.0 << " dong";
	cout << "\n\t\t\t\t ------------------------------";
	cout << "\n\t\t\t\t *Tong thanh toan : " << (tongcong * (100 - ptvc) / 100) * 1.0 + pgh << " dong";
	cout << "\n\t\t\t\t ------------------------------";
	cout << "\n\t\t\t\t *Tien mat : " << (tongcong * (100 - ptvc) / 100) * 1.0 + pgh << " dong";
	cout << "\n\t\t\t\t";
	tienmat = (tongcong * (100 - ptvc) / 100) * 1.0 + pgh;
}

