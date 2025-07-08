void outFloat(float x) {
    cout << setprecision(3) << x;
}
 
void Nhap(SinhVien A[MAXN], int n) {
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        cin.getline(A[i].MASV, 10);
        cin.getline(A[i].HoTen, 100);
        cin.getline(A[i].NgaySinh, 12);
        cin >> A[i].GioiTinh >> A[i].DiemToan >> A[i].DiemLy >> A[i].DiemHoa;
        cin.ignore();
        A[i].DTB = (A[i].DiemToan + A[i].DiemLy + A[i].DiemHoa) / 3.0;
    }
    for (int i = 1; i <= n; i++) {
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
 
void Xuat(SinhVien A[], int n) {
 
}