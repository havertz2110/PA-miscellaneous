<div class="problem_description" id="problem_description">
			<p style="text-align:justify"><strong>Bảng lũy thừa</strong></p>

<p style="text-align:justify">Cho lưới ô vuông kích thước <strong><em>n</em></strong>×<strong><em>m </em></strong>gồm n dòng và m cột. Các dòng được đánh số từ trên xuống dưới bắt đầu từ 1, các cột được đánh số từ trái sang phải bắt đầu từ 1. Ô (<strong><em>i</em></strong>, <strong><em>j</em></strong>) chứa giá trị <strong><em>aij </em></strong>= <strong><em>x<sup>(i-1)×m+j</sup></em></strong>.</p>

<p style="text-align:justify">Cho <strong><em>q </em></strong>truy vấn, mỗi truy vấn xác định bởi 5 số nguyên <strong><em>x1</em></strong>, <strong><em>x2</em></strong>, <strong><em>y1</em></strong>, <strong><em>y2 </em></strong>và <strong><em>p</em></strong>, trong đó 1 ≤ <strong><em>x1 </em></strong>≤<strong><em>x2 </em></strong>≤ <strong><em>n</em></strong>, 1 ≤ <strong><em>y1 </em></strong>≤ <strong><em>y2 </em></strong>≤ <strong><em>m</em></strong>, 1 ≤ <strong><em>p </em></strong>≤ 10<sup>9</sup>+7.</p>

<p style="text-align:justify">Với mỗi truy vấn yêu cầu xác định <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAK8AAAAdCAIAAABT8qtcAAAAAXNSR0IArs4c6QAAAAlwSFlzAAAOxAAADsQBlSsOGwAABTpJREFUaEPtWzl22zAQpXIW2YWfT0CdwE6TKm06qpSbdCnduaHKqHObKk3IG/gEfi5M3kUZDAYkAGInZVJ+YmWJAGb7s0JeHY/H7PJcNIAa+PIp9dDW++1mxZ7Ndt9+ShFPIpSOhrbebjbb+rw1WD/dv908Q9RrqtvDw1N9Es2FHHp2ygSddU9VZFleNvJXSX83VVnkqK28mOA4Kw9NyagQx4z5AfdsRVElCTHRpobxVVTjlToRP85jsu4tU5wEBa5p6+MCDcjPQUCaSJAjiHpVlg0jIXipCp0rOGYKdCcIIG/RNDvytFNuF2hA9ateRBbRXUtxyKP0qWEBQVX+CNcMos4Q13l/VWisAjrmjQs2TzulQUedTWgww9dhEbJ6U0EMRPeE5FBChijlsDzONf3UUXIiomNhOVAgJnVnG2U2/2ZMnLGJn6PBGsvMFpGiM27nqVHncLw9gqkX8FhgCBHrlKWL3yx8hSH2hm5NXZdAEtHg2mfxUF9eHA+FXokerxqkI63oWEDlQB7zsZwkpGlEg7uXsOOBRWfwvaKqeLVWlbx2ljLEaNd0U4dCldE/g4o9wVNTgwLt0yN4wHEMDciop0lgOchYT/J9AAfWTmK0nto1KQNaqtkPgQJ0LtRhQcsMsiYUp3Yl0+GoSKzEMd0zVQqqWmkOX/fcKI4g81kY0zc2el1fLtYLgTo0uAXkFklQQgAg/Uvmpc7tSKgzTjX8EtgDMMRXgAFG9ZLCHA8j8HBHU4ZABCoeDdEHO6MM+TTYy0iuoxCBhrmwYKtSg2wwepHm09Z620vImY4VkPHgKtQtl+h6gJHOjOITyakwwk/dZPr13T6Nrrf3h6L6fRcyjJ1+zazU239/XrLi125NcjVvL9nttfgUIWz7/mpfzV7m5TNRYTTy8idXN766ueJ/a8xIBxr4zL9/tfDJyRGBLEN6SIKhYX196xLLZ416u9qMuRpiVyOrre0ywUc9wiApS3tN4e767yErviluoYvf7u3SWHCEpuzeoa2EJdmr7oPGDHJDLw182kELiyWoIE5psafDPG0pjB0BpEvbZUIg9YReahjYsaIylqrdl1h/JbaJrkShzGtUmQd5QuJQzxOhfKrjIZkx9/TJliXZTQT2D1p9R+W/4oSCR54N+8q516rNmF7q3lwduMAByl5XrFcueZ0OwOFF5aC8tRaZLlyrQFFsJV7xRp0OEV28jEw3n4oe5ApDVJ60wDWZtllDkawDhkfzjhm2GQ1B1IVFJId1IFICJFlSdnQbG9TzIaq5taXp5kB8sz5cYBgGA0Ua9CHRR4sOVP6OK77rTc18StYBDkEC4yWz/dbKpNXe6QXDIEpM6FSDFLFoMkMYdX5AKCA9d54p+WYgPlP1cBKe3okERreIZUYT0H7RU6x3z2V+eOyqwXb/eAipuqAgkaoVqKgGj1wfygWy6/RQ6qKyE0W3m+O73W69vrrJX94aXhFmfa8QIqthjSo+dgDDUr7d/3jIuo4hkdJU29wmkFHFYRMz5uWuAFnA84sS2wybfJuNXmLIykzr7umqXahkxim6fv8t3Y0He5ouviG8LO3XLq7QcOx/7ULph409w+dMNJH2mVIqXOQZtijDBO7D6fb2io/vLLFod56poNTEHyQErsxUnAeDMmIh9xVbctfREHHwIpYmZGQDftR4kgJKijqp/ecidAm/nl8IH4lsxIABc8OJ7jypW1lWHIjX6fmiIdYAsevjdXn+O1YgwlTl6uWcc9fA5/zvmnO3ylz8X9Awl+aXSPeChiVaZS6e/gOWqpkUUnL/yAAAAABJRU5ErkJggg==" style="height:29px; width:175px"></p>

<p style="text-align:justify"><strong><em>Dữ liệu: </em></strong></p>

<ul>
	<li style="text-align:justify">Dòng đầu tiên chứa 3 số nguyên <strong><em>n</em></strong>, <strong><em>m </em></strong>và <strong><em>x </em></strong>(1 ≤ <strong><em>n</em></strong>, <strong><em>m</em></strong>, <strong><em>x </em></strong>≤ 10<sup>9</sup>),</li>
	<li style="text-align:justify">Dòng thứ 2 chứa số nguyên <strong><em>q </em></strong>(1 ≤ <strong><em>q </em></strong>≤ 10<sup>4</sup>),</li>
	<li style="text-align:justify">Mỗi dòng trong <strong><em>q </em></strong>dòng sau chứa 5 số nguyên xác định một truy vấn.</li>
</ul>

<p style="text-align:justify"><strong><em>Kết quả: </em></strong>Đưa ra kết quả mỗi truy vấn trên một dòng dưới dạng số nguyên.</p>

<p style="text-align:justify"><strong><em>Ví dụ:</em></strong></p>

<table border="1" cellspacing="0">
	<tbody>
		<tr>
			<td style="width:184.05pt">
			<p style="text-align:justify">Input</p>
			</td>
			<td style="width:115.95pt">
			<p style="text-align:justify">Output</p>
			</td>
		</tr>
		<tr>
			<td style="vertical-align:top; width:184.05pt">
			<p style="text-align:left">1 10 2<br>
			5<br>
			1 1 1 1 1000000007<br>
			1 1 1 2 1000000007<br>
			1 1 1 5 1000000007<br>
			1 1 2 4 1000000007<br>
			1 1 2 3 1000000007</p>
			</td>
			<td style="vertical-align:top; width:115.95pt">
			<p style="text-align:left">2<br>
			6<br>
			62<br>
			28<br>
			12</p>
			</td>
		</tr>
	</tbody>
</table>

		</div>