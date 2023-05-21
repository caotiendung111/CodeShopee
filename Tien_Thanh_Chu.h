#pragma once
#include "Xuat_bill.h"
#include <string>
#include "Do_Hoa.h"
#include <iostream>
using namespace std;
void tien_bang_chu(xuatbill xb)
{
	textcolor(12);
	double money = xb.get_tienmat();
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



