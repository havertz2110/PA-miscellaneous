#include <bits/stdc++.h>
void outFloat(float x) {
    cout << setprecision(3) << x;
}
 
bool cmp(SinhVien a, SinhVien b) {
    for (int i = 0; i < 10; i++) {
        if (a.MASV[i] < b.MASV[i]) return false;
        if (a.MASV[i] > b.MASV[i]) return true;
    }
}
 
void Nhap(SinhVien A[MAXN], int n) {
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
    sort(A, A + n, cmp);
    for (int i = 0; i < n; i++) {
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
 
void SapXepGiamTheoMASV(SinhVien A[], int n) {
 
}
 
void Xuat(SinhVien A[], int n) {
 
}