<div class="problem_description" id="problem_description">
			<p><a name="_Toc435817356"><strong><span style="color:#002060">BÀI </span></strong></a><strong><span style="color:#002060">KIỂM</span></strong><strong><span style="color:#002060"> TRA</span></strong></p>

<p style="text-align:justify"><img src="download.png" style="float:right">Alice và Bob là đôi bạn thân trong lớp và thường giúp nhau trong giờ học. Hôm nay sẽ có tiết kiểm tra toán và như mọi khi – sẽ có <strong><em>k</em></strong> đề khác nhau. Lớp học có <strong><em>n</em></strong> học sinh. Các bàn trong lớp xếp thành một hàng dọc, mỗi bàn 2 người ngồi. Vị trí bên trái của bàn đánh số là 1, vị trí bên phải – đánh số 2. Đề bài được phát bắt đầu từ vị trí 1 của bàn 1 rồi đến vị trí 2 của bàn 1, tiếp theo là vị trí 1 của bàn 2, rồi tới vị trí 2 của bàn 2, . . . lần lượt các đề 1, đề 2, đề 3, . . . cho tới đề <strong><em>k</em></strong> rồi lại quay lại đề 1, đề 2, . . . cho tới khi tất cả các học sinh đều nhận được đề.</p>

<p style="text-align:justify">Alice đến trước và ngồi vào vị trí quen thuộc của mình: hàng <strong><em>p</em></strong> và vị trí <strong><em>q</em></strong>. Bob đến sau và muốn ngồi vào nơi sẽ nhận được cùng đề với Alice và ở dãy bàn gần với dãy bàn của Alice nhất. Nếu có 2 cách ngồi thì Bob sẽ chọn bàn ở phía trước của Alice.</p>

<p style="text-align:justify">Hãy xác định bàn <strong><em>u</em></strong> và vị trí <strong><em>v</em></strong> trong bàn nơi Bob cần phải ngồi. Nếu không có cách ngồi thỏa mãn thì đưa ra một số -1.</p>

<p style="text-align:justify"><strong><em>Dữ liệu:</em></strong> Vào từ thiết bị nhập chuẩn:</p>

<ul>
	<li style="text-align:justify">Dòng đầu tiên chứa một số nguyên <strong><em>n</em></strong> (2 ≤ <strong><em>n</em></strong> ≤ 10<sup>9</sup>),</li>
	<li style="text-align:justify">Dòng thứ 2 chứa số nguyên <strong><em>k</em></strong> (2 ≤ <strong><em>k</em></strong> ≤ <strong><em>n</em></strong>),</li>
	<li style="text-align:justify">Dòng thứ 3 chứa số nguyên <strong><em>p</em></strong> (1 ≤ <strong><em>p</em></strong> ≤ (<strong><em>n</em></strong>+1)/2),</li>
	<li style="text-align:justify">Dòng thứ 4 chứa số nguyên <strong><em>q</em></strong> (1 ≤ <strong><em>q</em></strong> ≤ 2).</li>
</ul>

<p style="text-align:justify"><strong><em>Kết quả:</em></strong> Đưa ra thiết bị xuất chuẩn một dòng 2 số nguyên <strong><em>u</em></strong> và <strong><em>v</em></strong> tìm được hoặc số -1 nếu không có cách ngồi thỏa mãn điều kiện đã nêu.</p>

<p style="text-align:justify"><strong><em>Ví dụ:</em></strong></p>
<table border="1" cellpadding="1" cellspacing="1" style="width:100%">
	<tbody>
		<tr>
			<td style="text-align:center; vertical-align:top; width:50%"><strong>INPUT</strong></td>
			<td style="text-align:center; vertical-align:top; width:50%"><strong>OUTPUT</strong></td>
		</tr>
		<tr>
			<td style="vertical-align:top; width:50%">25<br>
            2<br>
            1<br>
            2
             </td>
			<td style="vertical-align:top; width:50%">2 2</td>
		</tr>
	</tbody>
</table>