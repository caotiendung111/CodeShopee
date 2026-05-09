# 🍜 CodeShopee - Ứng Dụng Đặt Đồ Ăn & Đồ Uống

<div align="center">

[![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://cplusplus.com/)
[![Windows](https://img.shields.io/badge/Windows-0078D4?style=flat-square&logo=windows&logoColor=white)](#)
[![Console](https://img.shields.io/badge/Console-App-orange?style=flat-square)](#)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)

**Ứng Dụng Quản Lý & Tính Toán Hóa Đơn Nhà Hàng Thực Phẩm**

[Tính Năng](#-tính-năng-chính) • [Hướng Dẫn](#-hướng-dẫn-sử-dụng) • [Cấu Trúc](#-kiến-trúc)

</div>

---

## 📖 Giới Thiệu

**CodeShopee** là một ứng dụng Windows Console viết bằng **C++** cho phép khách hàng:
- 🍲 Chọn **Đồ Ăn** (6 loại)
- 🥤 Chọn **Đồ Uống** (4 loại)
- 💰 **Tính giá tiền** tự động
- 📄 **Xuất Hóa Đơn** chi tiết với ngày giờ
- 🔤 **Hiển thị giá bằng chữ** (Viết chữ số tiền bằng chữ)

Ứng dụng có giao diện colorful, tương tác động, và xuất hóa đơn chuyên nghiệp.

---

## 🚀 Tính Năng Chính

### 🍽️ Loại Đồ Ăn (DoAn)

| Mã | Tên Món | Giá | Ghi Chú |
|:--:|---------|-----|--------|
| 1 | **Phở Bò** | 45,000 đ | Súp cốt lửu |
| 2 | **Mì Quảng** | 40,000 đ | Mì nước |
| 3 | **Bún Thit Nướng** | 40,000 đ | Bún cấp |
| 4 | **Phở Khô** | 50,000 đ | Phở xào |
| 5 | **Cơm Gà** | 50,000 đ | Cơm chiên |
| 6 | **Bún Cháy Cá** | 45,000 đ | Bún nước |

### 🥤 Loại Đồ Uống (DoUong)

| Mã | Tên Đồ Uống | Giá | Ghi Chú |
|:--:|-------------|-----|--------|
| 07 | **Bia** | 15,000 đ | Bia lạnh |
| 08 | **Nước Ngọt** | 15,000 đ | Soda, Pepsi, Coca |
| 09 | **Nước Khoáng** | 10,000 đ | Nước lọc |
| 10 | **Nước Suối** | 10,000 đ | Nước tinh khiết |

---

## 🛠️ Kiến Trúc Chương Trình

### 📦 Cấu Trúc File

```
CodeShopee/
├── Main.cpp              # Main program - logic chính
├── Do_An.h               # Class Đồ Ăn (6 loại)
├── Do_Uong.h             # Class Đồ Uống (4 loại)
├── Get_Info.h            # Class nhập thông tin khách
├── Xuat_bill.h           # Class xuất hóa đơn
├── Do_Hoa.h              # Utility functions (colors, gotoxy)
├── Tien_Thanh_Chu.h      # Chuyển số thành chữ
└── [Các file .gch]       # Precompiled headers
```

---

## 🏗️ Các Class Chính

### 1️⃣ **DoAn Class** - Lớp Đồ Ăn

```cpp
class DoAn 
{
    // Biến đếm số lượng từng loại
    int slpho, slmi, slbt, slpgl, slcga, slbc;
    
    // Biến tổng lũy tích số lượng
    int slphoTEMP, slmiTEMP, slbtTEMP, ...
    
    // Giá tiền từng loại
    int tienpho, tienbt, tienpgl, tiencga, tienbc, tienm;
    
    // Tọa độ hiển thị x, y
    int vitrix, vitriy;
    
public:
    DoAn();                      // Constructor
    void showMenu1();            // Hiển thị menu 6 loại đồ ăn
};
```

**Các Hàm Chính:**
- `DoAn()` - Khởi tạo constructor
- `showMenu1()` - Hiển thị menu đồ ăn và xử lý lựa chọn

**Logic:**
1. Nhập số lượng món muốn chọn (1-6)
2. Với mỗi món:
   - Hiển thị menu chi tiết
   - Nhập mã món (1-6)
   - Nhập số lượng
   - Tính tiền: `giá × số lượng`
   - Lũy tích tổng số lượng vào `*TEMP`
   - Tính tổng tiền cho loại đó

### 2️⃣ **DoUong Class** - Lớp Đồ Uống

```cpp
class DoUong
{
    // Biến đếm số lượng từng loại
    int slb, slk, sln, sls;              // Bia, Nước Khoáng, Nước Ngọt, Nước Suối
    
    // Biến tổng lũy tích
    int slbTEMP, slkTEMP, slnTEMP, slsTEMP;
    
    // Giá tiền từng loại
    int tienb, tienk, tienn, tiens;
    
    // Tọa độ hiển thị
    int vitrix, vitriy;
    
public:
    DoUong();                    // Constructor
    void showMenu2();            // Hiển thị menu 4 loại đồ uống
};
```

**Các Hàm Chính:**
- `DoUong()` - Khởi tạo
- `showMenu2()` - Hiển thị menu đồ uống

**Logic:** Tương tự DoAn nhưng chỉ 4 loại (mã 07-10)

### 3️⃣ **Get_Info Class** - Nhập Thông Tin

```cpp
class Get_Info
{
protected:
    char kh[50];        // Tên khách hàng
    char adress[50];    // Địa chỉ
    char sodt[50];      // Số điện thoại
    
public:
    void nhap();        // Nhập thông tin khách
};
```

**Tính Năng:**
- Nhập Họ và Tên
- Nhập Địa Chỉ
- Nhập Số Điện Thoại (+84)
- **Hiệu ứng typing** (từng chữ hiện lên với Sleep 50ms)

### 4️⃣ **xuatbill Class** - Xuất Hóa Đơn

```cpp
class xuatbill : public DoAn, public DoUong, public Get_Info
{
public:
    void nhap();                    // Nhập thông tin khách
    void showMenu();                // Menu chính (chọn Đồ Ăn / Đồ Uống)
    void showMenu1();               // Gọi DoAn::showMenu1()
    void showMenu2();               // Gọi DoUong::showMenu2()
    void check2();                  // Xoá giao diện
    void bill();                    // Xuất hóa đơn chi tiết
    void tien_bang_chu();           // Viết giá tiền bằng chữ
};
```

**Các Hàm Chính:**
- `bill()` - **Xuất hóa đơn** chi tiết (Xuat_bill.h)
- `tien_bang_chu()` - **Chuyển số → chữ** (Tien_Thanh_Chu.h)

---

## 📊 Quy Trình Hoạt Động

```
┌─────────────────────────────────────────────────────────┐
│                    START: Main.cpp                      │
└─────────────────────────────────────────────────────────┘
                            ↓
        ┌───────────────────────────────────────┐
        │  xb.nhap() - Nhập Thông Tin Khách    │
        │  (Tên, Địa chỉ, SĐT)                 │
        └───────────────────────────────────────┘
                            ↓
        ┌───────────────────────────────────────┐
        │     xb.showMenu() - Menu Chính        │
        │     Chọn: 1=Đồ Ăn, 2=Đồ Uống         │
        └───────────────────────────────────────┘
                    ↙                    ↘
          Chọn 1: Đồ Ăn           Chọn 2: Đồ Uống
                    ↓                    ↓
      xb.showMenu1()              xb.showMenu2()
      (DoAn::showMenu1())         (DoUong::showMenu2())
                    ↓                    ↓
      Chọn 6 loại:               Chọn 4 loại:
      1-Phở Bò                   07-Bia
      2-Mì Quảng                 08-Nước Ngọt
      3-Bún Thit Nướng           09-Nước Khoáng
      4-Phở Khô                  10-Nước Suối
      5-Cơm Gà
      6-Bún Cháy Cá
                    ↓                    ↓
          Nhập số lượng            Nhập số lượng
          Tính giá tiền            Tính giá tiền
                    ↓                    ↓
        Hỏi: "Muốn gọi thêm không?"
        ↙ (Có: 1)               (Không: 2) ↘
                    ↓                    ↓
              Tiếp tục                Xuất Bill
              chọn loại              
             khác lần 2
                    ↓
        ┌───────────────────────────────────────┐
        │   xb.bill() - Xuất Hóa Đơn            │
        │   - Tên khách                         │
        │   - Địa chỉ                          │
        │   - Số ĐT                            │
        │   - Danh sách món + giá               │
        │   - Tổng cộng                        │
        │   - Ngày/Giờ (hệ thống)              │
        └───────────────────────────────────────┘
                            ↓
        ┌──────────────────────────���────────────┐
        │ xb.tien_bang_chu()                    │
        │ Viết giá tiền bằng chữ                │
        │ Ví dụ: 250000 → Hai tram nam muoi    │
        └───────────────────────────────────────┘
                            ↓
        ┌───────────────────────────────────────┐
        │          Bấm phím để thoát             │
        │          END: main()                  │
        └───────────────────────────────────────┘
```

---

## 💻 Chi Tiết Code Main

### Main.cpp - Phần Chính

```cpp
int main()
{
    ShowCur(0);                 // Ẩn con trỏ
    xuatbill xb;                // Tạo object
    
    xb.nhap();                  // Nhập thông tin khách
    system("cls");              // Xóa màn hình
    
    // Vòng lặp chính - Chọn Đồ Ăn hoặc Đồ Uống
    b:
    xb.showMenu();              // Hiển thị menu
    int chonmenu;
    cin >> chonmenu;
    system("cls");
    
    switch (chonmenu)
    {
    case 1:  // Chọn Đồ Ăn
    {
        xb.showMenu1();         // Hiển thị menu đồ ăn
        
        // Hỏi có muốn gọi thêm đồ uống không
        int option;
        if (option == 1)
            xb.showMenu2();     // Gọi menu đồ uống
        else
            chonmenu = 0;       // Thoát
    }
    break;
    
    case 2:  // Chọn Đồ Uống
    {
        xb.showMenu2();         // Hiển thị menu đồ uống
        
        // Hỏi có muốn gọi thêm đồ ăn không
        int option1;
        if (option1 == 1)
            xb.showMenu1();     // Gọi menu đồ ăn
        else
            chonmenu = 0;       // Thoát
    }
    break;
    
    default:
        goto b;                 // Quay lại menu
    }
    
    // Xuất hóa đơn
    system("cls");
    xb.check2();                // Xóa giao diện
    system("cls");
    
    // Lấy ngày giờ hệ thống
    time_t baygio = time(0);
    tm* ltm = localtime(&baygio);
    cout << "Da Nang, Ngay : " << ltm->tm_mday 
         << " / " << 1 + ltm->tm_mon 
         << " / " << 1900 + ltm->tm_year << endl;
    
    // Xuất bill & chữ
    xb.bill();
    xb.tien_bang_chu();
    
    _getch();                   // Bấm phím để thoát
    return 0;
}
```

---

## 📄 Hóa Đơn Chi Tiết

### Định Dạng Output

```
                HOA DON CAFE - NHA HANG DUC DUNG
        ================================================
        
                Da Nang, Ngay : 21 / 05 / 2023
                Thoi Gian     : 14:30:45 PM
        
        ================================================
        Khach hang        : Cao Tien Dung
        Que Quan          : Da Nang
        So Dien Thoai     : (+84) 0123456789
        ================================================
        
        DO AN:
        -------
        1. Pho Bo x 2             = 90,000 dong
        2. Com Ga x 1             = 50,000 dong
        
        DO UONG:
        --------
        1. Bia x 3                = 45,000 dong
        2. Nuoc Khoang x 2        = 20,000 dong
        
        ================================================
        TONG CONG                 = 205,000 dong
        ================================================
        
        SO TIEN BANG CHU:
        Hai tram nam muoi nghin dong
        
        TRAN NAM NHAN
        CAFE DUC DUNG
        CAM ON QUY KHACH DA QUAY LAI
```

---

## 🎨 Giao Diện & Hiệu Ứng

### Màu Sắc Sử Dụng

```cpp
textcolor(9);    // Light Blue - Tiêu đề menu
textcolor(11);   // Light Cyan - Thông tin
textcolor(12);   // Light Red - Cảnh báo, input
textcolor(14);   // Yellow - Tiêu đề, output
```

### Hiệu Ứng Gõ Chữ (Typing Effect)

```cpp
char welcome[100] = "VUI LONG NHAP THONG TIN LIEN HE";
for (int i = 0; i < strlen(welcome); i++) {
    gotoxy(x++, y);
    cout << welcome[i];
    Sleep(50);              // Gõ từng chữ với khoảng 50ms
}
```

### Định Vị Con Trỏ (gotoxy)

```cpp
gotoxy(x, y);               // Đặt con trỏ tại (x, y)
cout << "Text";             // In ra tại vị trí đó
```

---

## ⚙️ Xử Lý Dữ Liệu

### 1. Tính Toán Giá Tiền

```cpp
// Phở Bò
if (j == 1) {
    cin >> slpho;
    slphoTEMP = slphoTEMP + slpho;      // Lũy tích
    tienpho = slphoTEMP * 45000;        // Tính tổng
}

// Tương tự với các loại khác
```

### 2. Quản Lý Tọa Độ Hiển Thị

```cpp
int vitrix = 51;    // X (cột)
int vitriy = 1;     // Y (dòng)

// Mỗi loại món chiếm 7 dòng
for (int i = 0; i < n; i++)
{
    vitriy = vitriy + 7;
    
    // Nếu vượt quá màn hình, chuyển sang bên phải
    if (vitriy > 27) {
        vitrix = 99;
        vitriy = 8;
    }
    
    gotoxy(vitrix, vitriy);
    cout << "Mon thu " << i+1;
}
```

### 3. Xác Thực Input

```cpp
if (j <= 6 && j > 0) {
    // Hợp lệ - xử lý
    hoadonan[i] = j;
} else {
    // Không hợp lệ
    cout << "Khong Co Mon Nay";
    // Quay lại input
}
```

---

## 🐛 Các Vấn Đề & Lưu Ý

| Vấn Đề | Mô Tả | Giải Pháp |
|--------|-------|----------|
| ⚠️ Chỉ Windows | Dùng `windows.h` | Không chạy trên Linux/Mac |
| 📦 Goto label | Dùng `goto` nhiều | Nên dùng hàm/vòng lặp thay vì |
| 💾 Dữ liệu tạm thời | Không lưu file | Thêm save/load file bill |
| 🔢 Chuyển chữ | Phức tạp | Có thể optimize hơn |
| 🎨 Giao diện fixed | Console cố định | Nên làm GUI |

---

## 🔮 Nâng Cấp Tương Lai

- [ ] **Lưu hóa đơn** vào file .txt hoặc .pdf
- [ ] **Database khách hàng** lịch sử gọi hàng
- [ ] **Menu quản lý** thêm/xóa/sửa món
- [ ] **Khuyến mãi & Giảm giá** theo phần trăm
- [ ] **Port sang GUI** (Qt/WinForms)
- [ ] **Hỗ trợ nhiều nhà hàng** (chuỗi)
- [ ] **Tích hợp thanh toán** (QR code, e-wallet)
- [ ] **Web version** để order online

---

## 🚀 Hướng Dẫn Sử Dụng

### 1️⃣ Yêu Cầu

- **OS**: Windows (do dùng windows.h)
- **Compiler**: g++, MSVC, Dev-C++, Code::Blocks
- **C++ Standard**: C++11 hoặc cao hơn

### 2️⃣ Biên Dịch & Chạy

```bash
# Biên dịch
g++ -o CodeShopee Main.cpp

# Chạy
./CodeShopee
```

### 3️⃣ Sử Dụng Ứng Dụng

1. **Nhập Thông Tin:**
   - Họ và Tên
   - Địa Chỉ
   - Số Điện Thoại

2. **Chọn Menu:**
   - Nhấn `1` - Chọn Đồ Ăn
   - Nhấn `2` - Chọn Đồ Uống

3. **Gọi Món:**
   - Nhập số lượng loại món (1-6 cho ăn, 1-4 cho uống)
   - Nhập mã từng món
   - Nhập số lượng mỗi món

4. **Hỏi Tiếp Tục:**
   - Nhấn `1` - Gọi thêm loại khác
   - Nhấn `2` - Thoát & Xuất Bill

5. **Xem Hóa Đơn:**
   - Thông tin khách & địa chỉ
   - Chi tiết từng món
   - Tổng tiền (số + chữ)

---

## 📚 Tài Liệu Tham Khảo

- [C++ Reference](https://cplusplus.com/)
- [Windows Console API](https://learn.microsoft.com/en-us/windows/console/)
- [gotoxy, textcolor functions](https://www.tutorialspoint.com/cplusplus/)

---

## 📞 Thông Tin Tác Giả

### 👨‍💻 Nhà Phát Triển
**Cao Tiến Dũng** (Dung Harry)

### 🏫 Bối Cảnh
- **Loại Dự Án**: Mini Project / Dự Án Thực Tập
- **Mục Đích**: Quản lý đặt hàng nhà hàng/cafe
- **Năm**: 2023

### 🤝 Liên Hệ
- 🐙 GitHub: [@caotiendung111](https://github.com/caotiendung111)
- 📧 Email: tiendung04dtvt@email.com
- 📘 Facebook: [Dung Harry](https://facebook.com/dungh)

---

## 📜 Giấy Phép

Dự án này được cấp phép dưới **MIT License**.

---

<div align="center">

### ⭐ Nếu thấy dự án này hữu ích, hãy ⭐ Star cho mình!

**Made with ❤️ by Cao Tiến Dũng**

```
    🍽️  CodeShopee - Order Now!  🍜
    Fast - Convenient - Delicious
```

</div>
