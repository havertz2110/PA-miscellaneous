<div class="problem_description" id="problem_description">
			
<p>Viết chương trình nhập vào ngày tháng năm. Kiểm tra ngày tháng năm nhập vào có hợp lệ hay không?</p>

<p>Giả sử:</p>

<p><!--[if !supportLists]-->·&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <!--[endif]-->năm hợp lệ: năm&nbsp; &gt;&nbsp; 0,&nbsp;</p>

<p><!--[if !supportLists]-->·&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <!--[endif]-->tháng 2 có 28 ngày (năm không nhuận), hoặc 29 ngày (năm nhuận),</p>

<p><!--[if !supportLists]-->·&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <!--[endif]-->năm nhuận: chia hết cho 4 nhưng không chia hết cho 100, hoặc chia hết cho 400,</p>

<p><!--[if !supportLists]-->·&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <!--[endif]-->tháng 4, 6, 9, 11 có 30 ngày,</p>

<p><!--[if !supportLists]-->·&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <!--[endif]-->Các tháng còn lại có 31 ngày.</p>

<p><u>Lưu ý:</u> Các bạn ưu tiên kiểm tra theo thứ tự: năm, tháng, ngày.</p>

<p><strong>INPUT:</strong></p>

<p>Nhập ngay, thang, nam trên cùng một dòng (ba số nguyên cách nhau bởi khoảng trắng). </span></p>

<p><strong>OUTPUT</strong></p>

<p>Định dạng như ví dụ minh họa. </span></p>

<p><strong>VÍ DỤ:</strong></p>

<table border="1" cellpadding="0" cellspacing="5" style="width:398.25pt">
	<tbody>
		<tr>
			<td style="width:91.85pt">
			<p>INPUT</p>
			</td>
			<td style="width:301.9pt">
			<p>OUTPUT</p>
			</td>
		</tr>
		<tr>
			<td style="vertical-align:bottom; width:91.85pt">
			<p>1 1 1</span></p>
			</td>
			<td style="vertical-align:bottom; width:301.9pt">
			<p>1/1/1 la ngay hop le.</span></p>
			</td>
		</tr>
		<tr>
			<td style="vertical-align:bottom; width:91.85pt">
			<p>13 5 0</span></p>
			</td>
			<td style="vertical-align:bottom; width:301.9pt">
			<p>Nam khong hop le.</p>
			</td>
		</tr>
		<tr>
			<td style="vertical-align:bottom; width:91.85pt">
			<p>>12 13 1990</p>
			</td>
			<td style="vertical-align:bottom; width:301.9pt">
			<p>Thang khong hop le.</p>
			</td>
		</tr>
		<tr>
			<td style="vertical-align:bottom; width:91.85pt">
			<p>29 2 2019</p>
			</td>
			<td style="vertical-align:bottom; width:301.9pt">
			<p>29/2/2019 la ngay khong hop le.</p>
			</td>
		</tr>
	</tbody>
</table>

