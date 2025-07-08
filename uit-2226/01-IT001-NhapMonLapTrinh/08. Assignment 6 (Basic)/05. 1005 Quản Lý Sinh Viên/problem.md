<div class="problem_description" id="problem_description">
			<p style="text-align:justify">Định nghĩa (khai báo) kiểu dữ liệu cấu trúc để quản lý sinh viên gồm các thành phần là Mã số Sinh viên (kiểu chuỗi), Họ và Tên (kiểu chuỗi), Năm sinh (kiểu chuỗi), Giới tính (kiểu ký tự), Điểm toán (kiểu số thực), Điểm lý (kiểu số thực), Điểm hóa (kiểu số thực), Điểm Trung bình (kiểu số thực). Viết Chương trình nhập và xuất thông tin của một sinh viên.</p>

<p style="text-align:justify"><strong>Lưu ý:</strong> Điểm trung bình được tính bằng công thức: (Điểm toán+Điểm lý+Điểm hóa)/3.</p>

<p style="text-align:justify"><!--<h3><span class="math-tex">\(S={ }\)</span></h3>
--></p>

<h3 style="text-align:justify"><strong>INPUT</strong></h3>

<p style="text-align:justify">Dãy các ký tự và số trong đó:</p>

<ul>
	<li style="text-align:justify">Dòng thứ 1: Chuỗi Mã số sinh viên.</li>
	<li style="text-align:justify">Dòng thứ 2: Chuỗi Họ tên sinh viên.</li>
	<li style="text-align:justify">Dòng thứ 3: Chuỗi Ngày tháng năm sinh.</li>
	<li style="text-align:justify">Dòng thứ 4: Ký tự thể hiện giới tính: <code>M</code> (Nam) hoặc <code>F</code> (Nữ).</li>
	<li style="text-align:justify">Dòng thứ 5: Số thực lưu Điểm toán.</li>
	<li style="text-align:justify">Dòng thứ 6: Số thực lưu Điểm lý.</li>
	<li style="text-align:justify">Dòng thứ 7: Số thực lưu Điểm hóa.</li>
</ul>

<h3 style="text-align:justify"><strong>OUTPUT</strong></h3>

<p style="text-align:justify">Hiển thị ra 08 thông tin của sinh viên:</p>

<ul>
	<li style="text-align:justify">Thứ tự hiển thị: <strong> Mã số Sinh viên, Họ và Tên, Năm sinh, Giới tính, Điểm toán, Điểm lý, Điểm hóa, Điểm Trung bình.</strong></li>
	<li style="text-align:justify">Mỗi thông tin cách nhau một dấu tab.</li>
	<li style="text-align:justify">Điểm trung bình hiển thị nhiều nhất ba&nbsp;số sau dấu thập phân (nếu có).</li>
</ul>

<h3 style="text-align:justify"><strong>EXAMPLE</strong></h3>

<table align="center" border="1" cellpadding="1" cellspacing="1" style="width:100%">
	<thead>
		<tr>
			<th scope="col" style="text-align:center"><strong>Input</strong></th>
			<th scope="col" style="text-align:center"><strong>Output</strong></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>
			07520504<br>
Luong Thanh<br>
31/07/1989<br>
M<br>
10<br>
9.5<br>
10<br>
</pre>
			</td>
			<td>
			07520504	 &nbsp Luong Thanh	&nbsp 31/07/1989&nbsp 	M&nbsp 	10	&nbsp 9.5	&nbsp 10&nbsp 	9.83
</pre>
			</td>
		</tr>
		<tr>
			<td>
			07520111<br>
Nguyen Anh Hong<br>
07/12/1991<br>
F<br>
8<br>
9<br>
7<br>
</pre>
			</td>
			<td>
			07520111	&nbsp Nguyen Anh Hong&nbsp 	07/12/1991	&nbsp F&nbsp 	8&nbsp 	9&nbsp 	7	&nbsp 8
</pre>
			</td>
		</tr>
		<tr>
			<td>
			08520045<br>
Ho Quang Hieu<br>
01/01/1990<br>
M<br>
6<br>
6.5<br>
7<br>
</pre>
			</td>
			<td>
			08520045&nbsp 	Ho Quang Hieu	&nbsp 01/01/1990&nbsp 	M&nbsp 	6	&nbsp 6.5	&nbsp 7&nbsp 	6.5
</pre>
			</td>
		</tr>
	</tbody>
</table>
		</div>