<div class="problem_description" id="problem_description">
			<p><strong>B. ROBOT</strong></p>

<p style="text-align:justify"><span >Công ty X-TRANS đang sản xuất robot vận chuyển hàng hóa tự động trên mặt đất. Để làm việc đó, X-TRANS tiến hành huấn luyện robot trên một địa hình phẳng được chia thành một lưới các ô vuông gồm </span><strong><em>m</em></strong><span > hàng (đánh số từ <em>1 </em>đến </span><strong><em>m</em></strong><span >) và </span><strong><em>n</em></strong><span > cột (đánh số từ 1 đến </span><strong><em>n</em></strong><span >).</span></p>

<p style="text-align:justify"><span >Robot của X-TRANS có kích thước bằng đúng một ô vuông và có thể thực hiện các lệnh di chuyển đến các ô liền cạnh với ô đang đứng. Giả sử robot đang đứng ở ô (X, Y), nó có thể thực hiện một trong bốn lệnh di chuyển sau:</span></p>

<p><strong>U</strong><span >: robot di chuyển đến ô (X-1, Y)</span></p>

<p><strong>D</strong><span >: robot di chuyển đến ô (X+1, Y)</span></p>

<p><strong>L</strong><span >: robot di chuyển đến ô (X, Y-1)</span></p>

<p><strong>R</strong><span >: robot di chuyển đến ô (X, Y+1)</span></p>

<p style="text-align:justify"><span >Để mô hình huấn luyện gần với địa hình thực tế, X-TRANS đặt các vật cản tại </span><em>p</em><span > ô vuông trên lưới địa hình để không cho robot đi vào. Robot chỉ có thể thực hiện một lệnh di chuyển nếu như ô mà nó cần di chuyển đến nằm bên trong lưới địa hình và không chứa vật cản. Nếu robot không thể thực hiện một lệnh, nó sẽ hủy lệnh đó và tiến hành thực hiện lệnh tiếp theo.</span></p>

<p style="text-align:justify"><span >X-TRANS tiến hành thử nghiệm robot với một tập gồm </span><em>k</em><span > lệnh để</span><span > kiểm tra xem robot có thể di chuyển từ ô (1,1) và kết thúc tại ô (</span><em><strong>m</strong>, <strong>n</strong></em><span >) sau khi thực hiện lần lượt các lệnh này hay không. Nếu robot không kết thúc tại ô (</span><strong><em>m</em>,<span > </span><em>n</em></strong><span >), X-TRANS cần tìm cách xóa đi một số ít nhất các lệnh trong tập </span><strong><em>k</em></strong><span > lệnh để robot sẽ kết thúc tại ô (</span><strong><em>m</em>,<span > </span><em>n</em></strong><span >) sau khi thực hiện tập các lệnh còn lại.</span></p>

<p style="text-align:justify"><img src="https://lh4.googleusercontent.com/amyaINKQ0DxkwV_Jhc1AlHqXjYEBIOvXDyM7L_wI7deG_HIlz-mv-SGqmFWZjYwUr7isJiB6pEcSJireoGw25TLMg49uhC171wtk3kAaKA5oxh_AaVwtXYAiQ0SApB_mbbZzlFPq" style="float:right; height:136px; margin-left:4px; margin-right:4px; margin-top:0px; width:160px"><span >Giả sử robot đang đứng ở ô (1, 1) trên lưới địa hình được mô tả như hình bên (các ô màu xám chứa các vật cản), nếu robot thực hiện tập lệnh </span><strong>RDDDDRRRRRUD</strong><span >, nó sẽ kết thúc tại ô (2, 5). Để robot kết thúc tại ô (5, 5), X-TRANS cần xóa 3 lệnh để robot thực hiện tập lệnh còn lại là</span></p>

<p><strong>DDDRRRRRD</strong><span >.</span></p>

<p><strong><em>Dữ liệu:&nbsp;</em></strong></p>

<ul>
	<li>
	<p><span >Dòng đầu tiên chứa 4 số nguyên: </span><em><strong>m</strong>, <strong>n</strong>, <strong>p</strong>, <strong>k</strong></em><span > (1 ≤ </span><em><strong>m</strong>, <strong>n</strong></em><span > ≤ 40, </span><em><strong>p</strong>, <strong>k</strong></em><span > ≤ 200). Dòng thứ hai chứa một xâu gồm </span><strong><em>k</em></strong><span > kí tự thể hiện </span><strong><em>k</em></strong><span > lệnh điều khiển robot.</span></p>
	</li>
</ul>

<ul>
	<li>
	<p><em><strong>p</strong> </em><span >dòng tiếp theo, mỗi dòng chứa 2 số nguyên dương</span><em> <strong>x</strong> </em><span >và</span><em> <strong>y</strong> </em><span >cho biết có đặt một vật cản</span><em> </em><span >tại ô (</span><em><strong>x</strong>, <strong>y</strong></em><em>).</em><span > Không đặt vật cản tại hai ô (1, 1) và (</span><em><strong>m</strong>, <strong>n</strong></em><span >).</span></p>
	</li>
</ul>

<p style="text-align:justify"><strong><em>Kết quả:&nbsp;</em></strong></p>

<p style="text-align:justify"><span >Một số</span><em> </em><span >nguyên là số lượng ít nhất các lệnh cần xóa để</span><em> </em><span >robot</span><em> </em><span >sẽ kết thúc tại ô (</span><em><strong>m</strong>, <strong>n</strong></em><span >) sau khi thực hiện tập các lệnh còn lại. Nếu không tồn tại cách xóa, ghi ra -1.</span></p>

<p><strong><em>Ví dụ:</em></strong></p>

<table border="1" bordercolor="#ccc" cellpadding="5" cellspacing="0" style="border-collapse:collapse">
	<tbody>
		<tr>
			<td style="height:0pt; vertical-align:top">&nbsp;
			<table cellspacing="0">
				<tbody>
					<tr>
						<td style="height:0pt; vertical-align:top">
						<p style="text-align:center"><tt><strong>INPUT</strong></tt></p>
						</td>
					</tr>
					<tr>
						<td style="height:0pt; vertical-align:top">
						<p><tt><strong>5 5 2 12</strong></tt></p>
						<p><tt><strong>RDDDDRRRRRUD</strong></tt></p>
						<p><tt><strong>2</strong></tt></p>
						<p><tt><strong>2</strong></tt></p>
						<p><tt><strong>5</strong></tt></p>
						<p><tt><strong>3</strong></tt></p>
						</td>
					</tr>
				</tbody>
			</table>
			</td>
			<td style="height:0pt; vertical-align:top">&nbsp;
			<table cellspacing="0">
				<tbody>
					<tr>
						<td style="height:0pt; vertical-align:top">
						<p style="text-align:center"><tt><strong>OUTPUT</strong></tt></p>
						</td>
					</tr>
					<tr>
						<td style="height:0pt; vertical-align:top">
						<p><tt><strong>3</strong></tt></p>
						<br>
						<br>
						<br>
						<br>
						&nbsp;</td>
					</tr>
				</tbody>
			</table>
			</td>
		</tr>
	</tbody>
</table>
		</div>