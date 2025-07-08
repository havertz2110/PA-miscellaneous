char xoa[100];
#include <bits/stdc++.h>
void outFloat(float x) {
    cout << setprecision(3) << x;
}
 
void Nhap(char s[]) {
 
}
 
bool check(char s[], char s2[]) {
    for (int i = 0; i < 100; i++)
        if (s[i] != s2[i]) return false;
    return true;
}
 
void Nhap(SinhVien A[MAXN], int n) {
    cin.getline(xoa, 100);
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin.getline(A[i].MASV, 10);
        cin.getline(A[i].HoTen, 100);
        cin.getline(A[i].NgaySinh, 12);
        cin >> A[i].GioiTinh >> A[i].DiemToan >> A[i].DiemLy >> A[i].DiemHoa;
        cin.ignore();
        A[i].DTB = (A[i].DiemToan + A[i].DiemLy + A[i].DiemHoa) / 3.0;
    }
    for (int i = 0; i < n; i++) if (!check(xoa, A[i].HoTen)) {
        cout << A[i].MASV << " " << A[i].HoTen << " " <<
        A[i].NgaySinh << " " << A[i].GioiTinh << " ";
        outFloat(A[i].DiemToan);
        cout << " ";
        outFloat(A[i].DiemLy);
        cout << " ";
        outFloat(A[i].DiemHoa);
        cout << " ";
        outFloat(A[i].DTB);
        cout << "\n";
    }
}
 
void XoaTheoHoTen(SinhVien A[], int n, char xoa[]) {
 
}
 
void Xuat(SinhVien A[], int n) {
 
}