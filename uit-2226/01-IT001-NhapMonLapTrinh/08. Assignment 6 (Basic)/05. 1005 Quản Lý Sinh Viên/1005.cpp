string masv, hoten, ngaysinh;
 
void Nhap(SinhVien &A) {
    getline(cin, masv);
    getline(cin, hoten);
    getline(cin, ngaysinh);
    cin >> A.GioiTinh >> A.DiemToan >> A.DiemLy >> A.DiemHoa;
    A.DTB = (A.DiemToan + A.DiemLy + A.DiemHoa) / 3.0;
}
 
void Xuat(SinhVien A) {
    cout << masv << " " << hoten << " " << ngaysinh << " " << A.GioiTinh << " " << A.DiemToan << " " << A.DiemLy << " " << A.DiemHoa << " ";
    int a = A.DTB;
    float b = a;
    if (b == A.DTB) cout << a;
    else cout << setprecision(2) << fixed << A.DTB;
}