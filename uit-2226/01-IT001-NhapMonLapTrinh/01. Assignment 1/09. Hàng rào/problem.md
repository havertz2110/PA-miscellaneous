<div class="problem_description" id="problem_description">
			<h2><span style="color:#3498db"><strong>SỬA HÀNG RÀO</strong></span></h2>

<p style="text-align:justify">Sau khi dựng xong nhà kho chứa cỏ, dì Poly quyết định dùng <strong><em>m</em></strong> tấm gỗ còn thừa gia cố hàng rào của vườn rau ngăn không cho gà vào phá và giao công việc này cho Tôm và Hấc Phin làm. Nhiệm vụ của hai cậu bé tội nghiệp là đóng thêm vào các tấm ván hàng rào để có hàng rào mới càng cao càng tốt. Nhìn vẽ mặt buồn thiu và lóng ngóng của 2 đứa, Jim quyết định sẽ làm giúp. Hàng rào được ghép từ <strong><em>n</em></strong> tấm gỗ cùng độ rộng như nhau và bằng độ rộng của các tấm gỗ còn thừa, tấm thứ <strong><em>i</em></strong> có độ cao <strong><em>a<sub>i</sub></em></strong>, <strong><em>i</em></strong> = 1 ÷ <strong><em>n</em></strong>. Tôm và Hấc Phin chỉ phải xếp các tấm còn thừa lên xe ba gác để Jim kéo đi. Các tấm gỗ được xếp thành một chồng, tính từ trên xuống tấm thứ <strong><em>j</em></strong> có độ dài <strong><em>b<sub>j</sub></em></strong>, <strong><em>j</em></strong> = 1 ÷ <strong><em>m</em></strong>. Jim kéo xe ba gác đi dọc theo hàng rào. Đến một tấm nào đó muốn gia cố Jim sẽ lấy một tấm gỗ từ xe đóng tiếp lên tấm gỗ trên hàng rào và độ cao mới của tấm này trên hàng rào sẽ là tổng độ cao của tấm cũ và tấm mới đóng thêm. Jim chỉ đóng thêm một tấm mới vào tấm cũ vì muốn đảm bảo độ chắc chắn của hàng rào. Jim có thể lấy tấm trên cùng ở xe hoặc vất ra khỏi xe một số tấm cho đến khi gặp tấm vừa ý. Người ta vẫn nói “<em>Khôn đâu tới trẻ, khỏe đâu tới già</em>!<em>”</em>&nbsp; Jim đã đứng tuổi và không còn sức để xếp lại các tấm gỗ bị bỏ ra vào xe. Ngoài ra, Jim cũng khá mê tín nên không quay lại lấy những tấm đã loại.</p>

<p style="text-align:justify">Hãy xác định độ cao lớn nhất có thể đạt được của hàng rào sau khi gia cố. Độ cao của hàng rào được tính bằng độ cao tấm gỗ thấp nhất trên hàng rào.</p>

<h3 style="text-align:justify"><span style="color:#3498db"><strong>Input</strong></span></h3>

<p style="text-align:justify">Vào từ thiết bị nhập chuẩn:</p>

<ul>
	<li style="text-align:justify">Dòng đầu tiên chứa số nguyên <strong><em>n</em></strong> (1 ≤ <strong><em>n</em></strong> ≤ 10<sup>5</sup>),</li>
	<li style="text-align:justify">Dòng thứ 2 chứa <strong><em>n</em></strong> số nguyên <strong><em>a<sub>1</sub></em></strong>, <strong><em>a<sub>2</sub></em></strong>, . . ., <strong><em>a<sub>n</sub></em></strong> (1 ≤ <strong><em>a<sub>i</sub></em></strong> ≤ 10<sup>8</sup>, <strong><em>i</em></strong> = 1 ÷ <strong><em>n</em></strong>),</li>
	<li style="text-align:justify">Dòng thứ 3 chứa số nguyên <strong><em>m</em></strong>&nbsp; (1 ≤ <strong><em>m</em></strong> ≤ 10<sup>5</sup>),</li>
	<li style="text-align:justify">Dòng cuối cùng chứ <strong><em>m</em></strong> số nguyên <strong><em>b<sub>1</sub></em></strong>, <strong><em>b<sub>2</sub></em></strong>, . . ., <strong><em>b<sub>m</sub></em></strong> (1 ≤ <strong><em>b<sub>j</sub></em></strong> ≤ 10<sup>8</sup>, <strong><em>j</em></strong> = 1÷ <strong><em>m</em></strong>).</li>
</ul>

<h3 style="text-align:justify"><span style="color:#3498db"><strong>Output</strong></span></h3>

<p style="text-align:justify">Đưa ra thiết bị xuất chuẩn, dòng đầu tiên chứa 2 số nguyên <strong><em>h</em></strong> và <strong><em>k</em></strong> – độ cao lớn nhất có thể của hàng rào và số tấm gỗ đã được đóng thêm, mỗi dòng trong <strong><em>k</em></strong> dòng tiếp theo chứa 2 số nguyên <strong><em>x</em></strong> và <strong><em>y</em></strong>, trong đó <strong><em>x</em></strong> – tấm gỗ trên hàng rào được đóng cao hơn, <strong><em>y</em></strong> – tấm gỗ được dùng để đóng. Đưa ra phương án có các số hiệu tấm ván được chọn là nhỏ nhất nếu tồn tại nhiều cách đóng khác nhau.</p>

<h2> Ví dụ</h2>

<table border="1" cellpadding="1" cellspacing="1" style="width:100%">
	<tbody>
		<tr>
			<td style="text-align:center; vertical-align:top; width:50%"><strong>INPUT</strong></td>
			<td style="text-align:center; vertical-align:top; width:50%"><strong>OUTPUT</strong></td>
		</tr>
		<tr>
			<td style="vertical-align:top; width:50%">6
            <br>
             2 5 4 1 7 5
             <br>
             7
             <br>
             2 3 1 3 2 4 6
             </td>
			<td style="vertical-align:top; width:50%">5 3
            <br>
            1 2
            <br>
            3 3
            <br>
            4 6
            </td>
	</tbody>
</table>