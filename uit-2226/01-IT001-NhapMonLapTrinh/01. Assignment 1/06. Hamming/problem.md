<div class="problem_description" id="problem_description">
			<p><strong><span style="color:#0070c0">KHOẢNG CÁCH HAMMING</span></strong></p>

<p style="text-align:justify">Trên giờ Tin học Hermione được làm quen với một khái niệm khoảng cách mới – khoảng cách Hamming của các số thập phân. Khoảng cách Hamming giữa 2 số nguyên không âm <strong><em>x</em></strong>, <strong><em>y</em></strong> là số lượng các chữ số khác nhau trong dạng biểu diễn thập phân ở cùng một vị trí của 2 số. Nếu một số có ít chữ số hơn số kia thì bổ sung thêm các số 0 không có nghĩa để 2 số có cùng số lượng chữ số.</p>

<p style="text-align:justify">Ví dụ, <strong><em>x</em></strong> = 315, <strong><em>y</em></strong> = 345 thì khoảng cách Hamming <strong><em>h(x,y)</em></strong> = 2. Với <strong><em>x</em></strong> = 315, <strong><em>y</em></strong> = 3 có <strong><em>h</em></strong>(315, 3) = <strong><em>h</em></strong>(315, 003) = 3.</p>

<p style="text-align:justify">Hermione không có cảm tình lắm với khái niệm khoảng cách này, nhưng sớm hay muộn cũng phải làm bài tập với nó. Vì vậy Hermione quyết định tăng cường thêm khả năng mới cho đũa thần của mình: chỉ cần chỉ đũa thần vào 2 số <strong><em>a </em></strong>và <strong><em>b</em></strong> (<strong><em>a</em></strong> ≤ <strong><em>b</em></strong>) đũa thần sẽ cho biết ngay khoảng cách lớn nhất có thể đạt được giữa 2 số <strong><em>x</em></strong> và <strong><em>y</em></strong> thuộc đoạn [<strong><em>a</em></strong>, <strong><em>b</em></strong>]. Ví dụ, với <strong><em>a</em></strong> = 11, <strong><em>b</em></strong> = 17, kết quả sẽ là 1 (có thể chọn <strong><em>x</em></strong> = 11, <strong><em>y</em></strong> = 16). Sau một hồi chật vật, cuối cùng Hermione cũng hoàn thành xong việc huấn luyện.</p>

<p style="text-align:justify">Hãy xác định kết quả Hermione sẽ nhận được khi chỉ vào 2 số <strong><em>a</em></strong> và <strong><em>b</em></strong>.</p>

<h2>Dữ liệu:</h2>
Vào từ thiết bị nhập chuẩn gồm 2 dòng, dòng đầu tiên chứa số nguyên <strong><em>a</em></strong>, dòng thứ 2 chứa số nguyên <strong><em>b</em></strong> (1 ≤ <strong><em>a</em></strong> ≤ <strong><em>b</em></strong> ≤ 10<sup>1 000 000</sup>).</p>

<h2>Kết quả:</h2>
 Đưa ra thiết bị xuất chuẩn một số nguyên – khoảng cách lớn nhất tìm được.</p>

<h2>Ví dụ:</h2>

<table border="1" cellpadding="1" cellspacing="1" style="width:100%">
	<tbody>
		<tr>
			<td style="text-align:center; vertical-align:top; width:50%"><strong>INPUT</strong></td>
			<td style="text-align:center; vertical-align:top; width:50%"><strong>OUTPUT</strong></td>
		</tr>
		<tr>
			<td style="vertical-align:top; width:50%">315<br>
             345<br>
             </td>
			<td style="vertical-align:top; width:50%">2</td>
		</tr>
		<tr>
			<td style="vertical-align:top; width:50%">3<br>315
            </td>
			<td style="vertical-align:top; width:50%">3</td>
		</tr> 
	</tbody>
</table>
