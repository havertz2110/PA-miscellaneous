<div class="problem_description" id="problem_description">
			<h2><strong>ĐƯỜNG ĐI</strong><strong> </strong></h2>

<p>Cho lưới ô vuông kích thước <strong>n×m</strong>, các hàng được đánh số từ 1 đến <strong>n</strong> từ trên xuống dưới, các cột được đánh số từ 1 đến <strong>m</strong> từ trái qua phải. Mỗi ô của lưới chứa một số nguyên không âm.</p>

<p>Từ một ô có thể chuyển sang ô bên dưới cùng cột bằng phép di chuyển ‘<strong>D</strong>’ hay chuyển sang ô bên phải cùng hàng bằng phép di chuyển ‘<strong>L</strong>’.</p>

<p><img src="download.png" style="margin-left:100px; margin-right:100px"></p>

<p>Xét các đường đi từ ô (1, 1) tới ô (<strong>n</strong>, <strong>m</strong>). Mỗi đường đi tương ứng với một xâu <strong>m+n-2</strong> ký tự, mỗi ký tự thuộc tập {‘<strong>D</strong>’, ‘<strong>L</strong>’}. Giá trị của đường đi là tích các số ở những ô thuộc đường đi. Giá trị nhận được có thể kết thúc bằng nhiều chữ số 0 ở cuối, điều này làm cho người ngoài có cảm giác như kết quả được làm tròn nhiều chữ số sau khi tính. Để giảm bớt cảm giác đó Alice muốn tìm đường đi sao cho giá trị đường đi có ít chữ số 0 nhất ở cuối.</p>

<p>Hãy xác định số lượng số 0 ít nhất có thể đạt được và chỉ ra đường đi có thứ tự từ điển nhỏ nhất tương ứng.</p>

<p><strong><em>Dữ liệu: </em></strong><span>Vào từ thiết bị nhập chuẩn</span>:</p>

<ul>
	<li>Dòng đầu tiên chứa 2 số nguyên <strong>n</strong> và <strong>m</strong> ghi cách nhau một dấu trắng (1 ≤ <strong>n</strong>, <strong>m</strong> ≤ 10<sup>3</sup>),</li>
</ul>

<ul>
	<li>Dòng thứ <strong>i</strong> trong <strong>n</strong> dòng tiếp theo chứa <strong>m</strong> số nguyên ghi cách nhau một dấu trắng <strong>a<sub>i1</sub></strong>, <strong>a<sub>i2</sub></strong>, . . ., <strong>a<sub>im</sub></strong> xác định giá trị các ô trên dòng <strong>i</strong> (0 ≤ <strong>a<sub>ij</sub></strong> ≤ 10<sup>9</sup>, <strong>j</strong> = 1 ÷ <strong>m</strong>).</li>
</ul>

<p><strong><em>Kết quả:</em></strong> <span>Đưa ra thiết bị xuất chuẩn</span>:</p>

<ul>
	<li>Dòng thứ nhất chứa một số nguyên – số lượng chữ số <strong>0</strong> ở cuối của giá trị đường xác định được,</li>
	<li>Dòng thứ 2 chứa xâu <strong>n+m-2</strong> ký tự từ tập {‘<strong>D</strong>’, ‘<strong>L</strong>’} xác định đường đi tìm được.</li>
</ul>

<p><strong><em>Ví dụ: </em></strong></p>

<table border="1" cellspacing="0">
	<tbody>
		<tr>
			<td style=" width:108.0pt">
			<p style="text-align:center"><strong><tt><span>INPUT</span></tt></strong></p>
			</td>
			<td style="vertical-align:top; width:43.15pt">
			<p style="text-align:center">&nbsp;</p>
			</td>
			<td style=" width:101.8pt">
			<p style="text-align:center"><strong><tt><span>OUTPUT</span></tt></strong></p>
			</td>
		</tr>
		<tr>
			<td style=" height:16.9pt; width:108.0pt">
			<p><strong><tt>3 4</tt></strong></p>
			<p><strong><tt>1 3 3 4</tt></strong></p>
			<p><strong><tt>2 3 4 7</tt></strong></p>
			<p><strong><tt>0 5 5 8</tt></strong></p>
			</td>
			<td style="height:16.9pt; vertical-align:top; width:43.15pt">
			<p>&nbsp;</p>
			</td>
			<td style=" height:16.9pt; width:101.8pt">
			<p><strong><tt><span>0</span></tt></strong></p>
			<p><strong><tt><span>DLLLD</span></tt></strong></p>
			</td>
		</tr>
	</tbody>
</table>
		</div>