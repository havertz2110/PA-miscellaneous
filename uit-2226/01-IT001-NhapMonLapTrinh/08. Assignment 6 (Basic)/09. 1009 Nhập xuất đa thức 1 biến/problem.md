![Alt text](image.png)

<p style="text-align:justify">Viết chương trình nhập xuất đa thức một biến <span class="math-tex"><span class="MathJax_Preview" style="color: inherit; display: none;"></span><span id="MathJax-Element-3-Frame" class="mjx-chtml MathJax_CHTML" tabindex="0" style="font-size: 113%; position: relative;" data-mathml="<math xmlns=&quot;http://www.w3.org/1998/Math/MathML&quot;><mi>f</mi><mo stretchy=&quot;false&quot;>(</mo><mi>x</mi><mo stretchy=&quot;false&quot;>)</mo></math>" role="presentation"><span id="MJXc-Node-52" class="mjx-math" aria-hidden="true"><span id="MJXc-Node-53" class="mjx-mrow"><span id="MJXc-Node-54" class="mjx-mi"><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.501em; padding-bottom: 0.501em; padding-right: 0.06em;">f</span></span><span id="MJXc-Node-55" class="mjx-mo"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.445em; padding-bottom: 0.611em;">(</span></span><span id="MJXc-Node-56" class="mjx-mi"><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.224em; padding-bottom: 0.279em;">x</span></span><span id="MJXc-Node-57" class="mjx-mo"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.445em; padding-bottom: 0.611em;">)</span></span></span></span><span class="MJX_Assistive_MathML" role="presentation"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>f</mi><mo stretchy="false">(</mo><mi>x</mi><mo stretchy="false">)</mo></math></span></span><script type="math/tex" id="MathJax-Element-3">f(x)</script></span>. Sau đó nhập giá trị biến <span class="math-tex"><span class="MathJax_Preview" style="color: inherit; display: none;"></span><span id="MathJax-Element-4-Frame" class="mjx-chtml MathJax_CHTML" tabindex="0" style="font-size: 113%; position: relative;" data-mathml="<math xmlns=&quot;http://www.w3.org/1998/Math/MathML&quot;><mi>x</mi></math>" role="presentation"><span id="MJXc-Node-58" class="mjx-math" aria-hidden="true"><span id="MJXc-Node-59" class="mjx-mrow"><span id="MJXc-Node-60" class="mjx-mi"><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.224em; padding-bottom: 0.279em;">x</span></span></span></span><span class="MJX_Assistive_MathML" role="presentation"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></span></span><script type="math/tex" id="MathJax-Element-4">x</script></span>&nbsp;và tính giá trị <span class="math-tex"><span class="MathJax_Preview" style="color: inherit; display: none;"></span><span id="MathJax-Element-5-Frame" class="mjx-chtml MathJax_CHTML" tabindex="0" style="font-size: 113%; position: relative;" data-mathml="<math xmlns=&quot;http://www.w3.org/1998/Math/MathML&quot;><mi>f</mi><mo stretchy=&quot;false&quot;>(</mo><mi>x</mi><mo stretchy=&quot;false&quot;>)</mo></math>" role="presentation"><span id="MJXc-Node-61" class="mjx-math" aria-hidden="true"><span id="MJXc-Node-62" class="mjx-mrow"><span id="MJXc-Node-63" class="mjx-mi"><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.501em; padding-bottom: 0.501em; padding-right: 0.06em;">f</span></span><span id="MJXc-Node-64" class="mjx-mo"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.445em; padding-bottom: 0.611em;">(</span></span><span id="MJXc-Node-65" class="mjx-mi"><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.224em; padding-bottom: 0.279em;">x</span></span><span id="MJXc-Node-66" class="mjx-mo"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.445em; padding-bottom: 0.611em;">)</span></span></span></span><span class="MJX_Assistive_MathML" role="presentation"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>f</mi><mo stretchy="false">(</mo><mi>x</mi><mo stretchy="false">)</mo></math></span></span><script type="math/tex" id="MathJax-Element-5">f(x)</script></span>&nbsp;với kết quả hiển thị chính xác 2 số sau dấu thập phân.</p>

<p style="text-align:justify"><!--<h3><span class="math-tex">\(S={ }\)</span></h3>
--></p>

<h3 style="text-align:justify"><strong>Input</strong></h3>

<p style="text-align:justify">Dãy các số trong đó:</p>

<ul>
	<li style="text-align:justify">Số nguyên đầu tiên&nbsp;<span class="math-tex"><span class="MathJax_Preview" style="color: inherit; display: none;"></span><span id="MathJax-Element-6-Frame" class="mjx-chtml MathJax_CHTML" tabindex="0" style="font-size: 113%; position: relative;" data-mathml="<math xmlns=&quot;http://www.w3.org/1998/Math/MathML&quot;><mo stretchy=&quot;false&quot;>(</mo><mn>0</mn><mo>&amp;#x2264;</mo><mi>n</mi><mo>&amp;#x2264;</mo><mn>100</mn><mo stretchy=&quot;false&quot;>)</mo></math>" role="presentation"><span id="MJXc-Node-67" class="mjx-math" aria-hidden="true"><span id="MJXc-Node-68" class="mjx-mrow"><span id="MJXc-Node-69" class="mjx-mo"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.445em; padding-bottom: 0.611em;">(</span></span><span id="MJXc-Node-70" class="mjx-mn"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.39em; padding-bottom: 0.39em;">0</span></span><span id="MJXc-Node-71" class="mjx-mo MJXc-space3"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.335em; padding-bottom: 0.501em;">≤</span></span><span id="MJXc-Node-72" class="mjx-mi MJXc-space3"><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.224em; padding-bottom: 0.279em;">n</span></span><span id="MJXc-Node-73" class="mjx-mo MJXc-space3"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.335em; padding-bottom: 0.501em;">≤</span></span><span id="MJXc-Node-74" class="mjx-mn MJXc-space3"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.39em; padding-bottom: 0.39em;">100</span></span><span id="MJXc-Node-75" class="mjx-mo"><span class="mjx-char MJXc-TeX-main-R" style="padding-top: 0.445em; padding-bottom: 0.611em;">)</span></span></span></span><span class="MJX_Assistive_MathML" role="presentation"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>0</mn><mo>≤</mo><mi>n</mi><mo>≤</mo><mn>100</mn><mo stretchy="false">)</mo></math></span></span><script type="math/tex" id="MathJax-Element-6">(0 \leq n \leq 100)</script></span>: số lượng đơn thức trong đa thức.</li>
	<li style="text-align:justify"><span class="math-tex"><span class="MathJax_Preview" style="color: inherit; display: none;"></span><span id="MathJax-Element-7-Frame" class="mjx-chtml MathJax_CHTML" tabindex="0" style="font-size: 113%; position: relative;" data-mathml="<math xmlns=&quot;http://www.w3.org/1998/Math/MathML&quot;><mi>n</mi></math>" role="presentation"><span id="MJXc-Node-76" class="mjx-math" aria-hidden="true"><span id="MJXc-Node-77" class="mjx-mrow"><span id="MJXc-Node-78" class="mjx-mi"><span class="mjx-char MJXc-TeX-math-I" style="padding-top: 0.224em; padding-bottom: 0.279em;">n</span></span></span></span><span class="MJX_Assistive_MathML" role="presentation"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></span></span><script type="math/tex" id="MathJax-Element-7">n</script></span>&nbsp;cặp số tiếp theo, mỗi cặp số là một đơn thức gồm: hệ số (số thực) và số mũ (số nguyên &gt;= 0).</li>
	<li style="text-align:justify">Các đơn thức được nhập vào theo thứ tự giảm dần của số mũ, và không có đơn thức nào có cùng số mũ.</li>
</ul>

<h3 style="text-align:justify"><strong>Output</strong></h3>

<p style="text-align:justify">Như ví dụ bên dưới.</p>

<p style="text-align:justify">Lưu ý xuất đa thức:</p>

<ul>
	<li style="text-align:justify">Biến trong đa thức ký hiệu là x.</li>
	<li style="text-align:justify">Số mũ ký hiệu ^.</li>
	<li style="text-align:justify">Phép nhân không ghi ký hiệu.</li>
	<li style="text-align:justify">Các ký tự biểu diễn đa thức ghi liền nhau (không khoảng trắng).</li>
	<li style="text-align:justify">Đơn thức đầu tiên nếu hệ số là số dương thì không được xuất dấu + trước hệ số.</li>
	<li style="text-align:justify">Đơn thức có hệ số bằng 0 thì không xuất đơn thức đó.</li>
	<li style="text-align:justify">Đơn thức có hệ số bằng 1 hoặc -1 thì không xuất số 1.</li>
	<li style="text-align:justify">Đơn thức có số mũ bằng 0 thì chỉ xuất hệ số của đơn thức.</li>
	<li style="text-align:justify">Đơn thức có số mũ bằng 1 thì không xuất số mũ.</li>
</ul>

<h3 style="text-align:justify"><strong>Example</strong></h3>

<table align="center" border="1" cellpadding="1" cellspacing="1" style="width:75%">
	<thead>
		<tr>
			<th scope="col" style="text-align:center"><strong>Input</strong></th>
			<th scope="col" style="text-align:center"><strong>Output</strong></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align:justify">7<br>
			2 15<br>
			-1 10<br>
			0 8<br>
			1 5<br>
			6 2<br>
			-8.5 1<br>
			-10.52 0<br>
			2</td>
			<td style="text-align:justify">Da thuc vua nhap la: 2x^15-x^10+x^5+6x^2-8.5x-10.52<br>
			Voi x=2, gia tri da thuc la: 64540.48</td>
		</tr>
		<tr>
			<td style="text-align:justify">4<br>
			0 20<br>
			-10 6<br>
			1 5<br>
			-1 0<br>
			3.55</td>
			<td style="text-align:justify">Da thuc vua nhap la: -10x^6+x^5-1<br>
			Voi x=3.55, gia tri da thuc la: -19452.85</td>
		</tr>
		<tr>
			<td style="text-align:justify">3<br>
			0 4<br>
			0 3<br>
			0 1<br>
			10</td>
			<td style="text-align:justify">Da thuc vua nhap la: 0<br>
			Voi x=10, gia tri da thuc la: 0.00</td>
		</tr>
	</tbody>
</table>
		</div>