<div class="problem_description" id="problem_description">
			<p>Nhập ma trận vuông A&nbsp;(n x n). Kiểm tra A có phải là ma trận Frobenius hay không.</p>

<p>Ma trận Frobenius được định nghĩa là ma trận vuông thoả các tính chất sau:</p>

<ol>
	<li>Tất cả các phần tử trên đường chéo chính bằng 1.</li>
	<li>Có tối đa một cột mà các phần tử dưới đường chéo chính có thể nhận giá trị bất kì.</li>
	<li>Ngoài ra, tất cả các phần tử khác có giá trị bằng 0.</li>
</ol>

<p><strong><em>INPUT</em></strong></p>

<ul>
	<li>2 số nguyên là số dòng, số cột của ma trận A.</li>
	<li>Giá trị các phần tử của ma trận A là số thực.</li>
</ul>

<p><strong><em>OUTPUT</em></strong></p>

<ul>
	<li>"Yes", nếu A là ma trận Frobenius.</li>
	<li>"No", nếu A không là ma trận Frobenius.</li>
</ul>

<p><strong><em>VÍ DỤ</em></strong></p>

<table border="1" cellpadding="1" cellspacing="1" style="width:500px">
	<tbody>
		<tr>
			<td colspan="1" rowspan="1">
			<p><strong>Input</strong></p>
			</td>
			<td colspan="1" rowspan="1">
			<p><strong>Output</strong></p>
			</td>
		</tr>
		<tr>
			<td colspan="1" rowspan="1">
			<p>16 16</p>
			<p>1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0</p>
			<p>0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0</p>
			<p>0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0</p>
			<p>0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0</p>
			<p>0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0</p>
			<p>0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0</p>
			<p>0 0 0 0 0 50 1 0 0 0 0 0 0 0 0 0</p>
			<p>0 0 0 0 0 71 0 1 0 0 0 0 0 0 0 0</p>
			<p>0 0 0 0 0 65 0 0 1 0 0 0 0 0 0 0</p>
			<p>0 0 0 0 0 77 0 0 0 1 0 0 0 0 0 0</p>
			<p>0 0 0 0 0 81 0 0 0 0 1 0 0 0 0 0</p>
			<p>0 0 0 0 0 87 0 0 0 0 0 1 0 0 0 0</p>
			<p>0 0 0 0 0 83 0 0 0 0 0 0 1 0 0 0</p>
			<p>0 0 0 0 0 51 0 0 0 0 0 0 0 1 0 0</p>
			<p>0 0 0 0 0 7 0 0 0 0 0 0 0 0 1 0</p>
			<p>0 0 0 0 0 15 0 0 0 0 0 0 0 0 0 1</p>
			</td>
			<td colspan="1" rowspan="1">
			<p>Yes</p>
			<p>&nbsp;</p>
			<p>&nbsp;</p>
			<p>&nbsp;</p>
			</td>
		</tr>
		<tr>
			<td colspan="1" rowspan="1">
			<p>10 10</p>
			<p>1 0 0 0 0 0 0 0 0 0</p>
			<p>0 1 0 0 0 0 0 0 0 0</p>
			<p>0 0 1 0 0 0 0 0 0 0</p>
			<p>0 0 0 1 0 0 0 0 0 0</p>
			<p>0 0 0 0 1 0 0 0 0 0</p>
			<p>0 0 0 0 0 1 0 0 0 0</p>
			<p>0 0 0 0 0 8 1 0 0 0</p>
			<p>0 0 0 0 0 4 0 1 0 0</p>
			<p>0 0 0 0 0 40 0 84 1 0</p>
			<p>0 0 0 0 0 25 0 16 0 1</p>
			</td>
			<td colspan="1" rowspan="1">
			<p>No</p>
			<p>&nbsp;</p>
			</td>
		</tr>
	</tbody>
</table>

