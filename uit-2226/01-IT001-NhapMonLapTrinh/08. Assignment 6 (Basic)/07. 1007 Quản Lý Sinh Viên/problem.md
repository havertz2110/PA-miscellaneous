<div class="problem_description" id="problem_description">
			<p style="text-align: justify;">Định nghĩa (khai báo) kiểu dữ liệu cấu trúc để quản lý sinh viên gồm các thành phần là Mã số Sinh viên (kiểu chuỗi), Họ và Tên (kiểu chuỗi), Năm sinh (kiểu chuỗi), Giới tính (kiểu ký tự), Điểm toán (kiểu số thực), Điểm lý (kiểu số thực), Điểm hóa (kiểu số thực), Điểm Trung bình (kiểu số thực). Viết Chương trình nhập và xuất (theo thứ tự giảm dần của MASV) danh sách gồm n (0 &lt; n ≤ 100) sinh viên.</p>

<p style="text-align: justify;"><strong>Lưu ý: </strong>Điểm trung bình được tính bằng công thức: (Điểm toán+Điểm lý+Điểm hóa)/3.</p>

<p style="text-align: justify;"><!--<h3><span class="math-tex">\(S={ }\)</span></h3>
--></p>

<h3 style="text-align: justify;"><strong>Input</strong></h3>

<p style="text-align: justify;">Dãy các ký tự và số trong đó: (Giả sử luôn thỏa điều kiện nhập)</p>

<ul>
	<li style="text-align: justify;">Dòng đầu tiên: Số lượng n phần tử trong danh sách.</li>
	<li style="text-align: justify;">(n*7) dòng liên tiếp tiếp theo: Cứ mỗi 7 dòng thể hiện 7 thông tin của một sinh viên trong mảng:
	<ul>
		<li>Dòng thứ 1: Chuỗi Mã số sinh viên</li>
		<li>Dòng thứ 2: Chuỗi Họ tên sinh viên</li>
		<li>Dòng thứ 3: Chuỗi Ngày tháng năm sinh</li>
		<li>Dòng thứ 4: Ký tự thể hiện giới tính: <code>M</code> (Nam) hoặc <code>F</code> (Nữ)</li>
		<li>Dòng thứ 5: Số thực lưu Điểm toán</li>
		<li>Dòng thứ 6: Số thực lưu Điểm lý</li>
		<li>Dòng thứ 7: Số thực lưu Điểm hóa</li>
	</ul>
	</li>
</ul>

<h3><strong>Output</strong></h3>

<p style="text-align: justify;">Hiển thị n sinh viên trong mảng trên n dòng liên tiếp (Đã được sắp theo thứ tự MASV giảm dần). Mỗi dòng hiển thị 8 thông tin theo thứ tự sau: <strong> Mã số Sinh viên, Họ và Tên, Năm sinh, Giới tính, Điểm toán, Điểm lý, Điểm hóa, Điểm Trung bình</strong>.</p>

<p style="text-align: justify;"><strong>Lưu ý:</strong></p>

<ul>
	<li style="text-align: justify;">Mỗi thông tin cách nhau một dấu <code>tab</code>.</li>
	<li style="text-align: justify;">Điểm trung bình hiển thị hai số lẻ sau dấu thập phân (nếu có). Gợi ý dùng <code>precision</code>.</li>
</ul>

<h3><strong>Ví dụ</strong></h3>

<table align="center" border="1" cellpadding="1" cellspacing="1" style="width:500px">
	<thead>
		<tr>
			<th scope="col" style="text-align: center;"><strong>Input</strong></th>
			<th scope="col" style="text-align: center;"><strong>Output</strong></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>3<br>
07520045<br>
Nguyen Thi Lan<br>
27/05/1989<br>
F<br>
10<br>
9<br>
8<br>
07520504<br>
Luong Thanh<br>
31/07/1989<br>
M<br>
10<br>
9.5<br>
10<br>
07520111<br>
Nguyen Anh Hong<br>
07/12/1991<br>
F<br>
7<br>
9<br>
8<br>
			</td>
			<td>07520504	Luong Thanh	31/07/1989	M	10	9.5	10	9.83<br>
07520111	Nguyen Anh Hong	07/12/1991	F	7	9	8	8<br>
07520045	Nguyen Thi Lan	27/05/1989	F	10	9	8	9<br>
			</td>
		</tr>
	</tbody>
</table>
		</div>