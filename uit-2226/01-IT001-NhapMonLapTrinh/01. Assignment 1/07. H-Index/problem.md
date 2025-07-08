<div class="problem_description" id="problem_description">
			<h3 style="text-align:justify"><strong><span style="color:#0070c0">H-Index</span></strong></h3>

<p style="text-align:justify">Làm thế nào để đánh giá sự thành công của một nhà khoa học?&nbsp;Dựa vào số bài báo được công bố hay dựa vào số lần một bài báo được trích dẫn tới ở công trình của những người khác? Cả hai tham số đó đều quan trọng.</p>

<p style="text-align:justify">Một bài báo có điểm số trích dẫn là <strong><em>c</em></strong> nếu nó được trích dẫn tới <strong><em>c</em></strong> lần trong các công trình của những nhà khoa học khác. Một trong số các cách đánh giá sự thành công của một nhà khoa học là tính chỉ số ảnh hưởng <strong><em>H_Index</em></strong> dựa trên sự kết hợp giữa số lượng bài báo và chỉ số trích dẫn của các bài báo đó.</p>

<p style="text-align:justify">Chỉ số <strong><em>H_Index</em></strong><em>&nbsp;</em>của một nhà khoa học bằng <strong><em>k</em></strong> lớn nhất nếu người đó có <strong><em>k</em></strong> bài báo, mỗi bài có điểm số trích dẫn không nhỏ hơn <strong><em>k</em></strong>. Ví dụ, một người có 10 bài báo, mỗi bài báo được trích dẫn không dưới 10 lần thì <strong><em>H_Index</em></strong> của người đó ít nhất là bằng 10.</p>

<p style="text-align:justify">Một người có <strong><em>n</em></strong> bài báo, bài báo thứ <strong><em>i</em></strong> có điểm trích dẫn là <strong><em>c<sub>i</sub></em></strong>, <strong><em>i</em></strong> = 1 ÷ <strong><em>n</em></strong>. Hãy xác định <strong><em>H_Index</em></strong> của người đó.</p>

<h2>Input:</h2>

<p style="text-align:justify">Vào từ thiết bị nhập chuẩn:</p>

<ul>
	<li style="text-align:justify">Dòng đầu tiên chứa một số nguyên <strong><em>n</em></strong> (1 ≤ <strong><em>n</em></strong> ≤ 5×10<sup>5</sup>),</li>
	<li style="text-align:justify">Dòng thứ 2 chứa <strong><em>n</em></strong> số nguyên <strong><em>c<sub>1</sub></em></strong>, <strong><em>c<sub>2</sub></em></strong>, . . ., <strong><em>c<sub>n</sub></em></strong> (0 ≤ <strong><em>c<sub>i</sub></em></strong> ≤ 10<sup>6</sup>, <strong><em>i</em></strong> = 1 ÷ <strong><em>n</em></strong>).</li>
</ul>

<h2>Output:</h2>

<p style="text-align:justify">Đưa ra thiết bị xuất chuẩn một số nguyên – <strong><em>H_Index</em></strong> tìm được.</p>

<h2>Ví dụ:</h2>

<table border="1" cellpadding="1" cellspacing="1" style="width:100%">
	<tbody>
		<tr>
			<td style="text-align:center; vertical-align:top; width:50%"><strong>INPUT</strong></td>
			<td style="text-align:center; vertical-align:top; width:50%"><strong>OUTPUT</strong></td>
		</tr>
		<tr>
			<td style="vertical-align:top; width:50%">5<br>
             8 5 3 4 10<br>
             </td>
			<td style="vertical-align:top; width:50%">4</td>
		</tr>
	</tbody>
</table>