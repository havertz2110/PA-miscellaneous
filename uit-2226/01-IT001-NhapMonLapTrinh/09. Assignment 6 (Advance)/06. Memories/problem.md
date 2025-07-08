<div class="problem_description" id="problem_description">
			<h2><strong>HỒI KÝ</strong></h2>

<p style="text-align: justify;">Khoảng thời gian ngồi trên ghế nhà trường bao giờ cũng để lại trong tâm trí mỗi người những kỷ niệm đẹp đẽ, thơ mộng, êm dịu khó quên về tình bạn và tình thầy trò.</p>

<p style="text-align: justify;">Để chuẩn bị cho ngày kỷ niệm thành lập trường, Đoàn Trường phát động một phong trào viết hồi ký về những năm tháng tuổi học trò. Phong trào nhận được sự hưởng ứng nhiệt liệt của các bạn học sinh cũng như cựu học sinh, của các thầy cô đang và đã giảng dạy ở trường, của những cán bộ ở bộ phận phục vụ. Các bài viết đều rất chất lượng, khó có thể loại bỏ. Có bài thoang thoảng hương thơm dìu dịu tỏa ra buổi tối từ rặng cây ngọc lan,&nbsp; có bài đậm vị ngọt mát nhè nhẹ của những hạt ruối vàng ươm ở khóm cây trồng góc hàng rào,... Người ta quyết định phân loại các bài viết thành các chương.</p>

<p style="text-align: justify;">Kết quả biên tập là một cuốn kỷ yếu gồm <strong><em>n</em></strong> chương, chương thứ <strong><em>i</em></strong> có <strong><em>a<sub>i</sub></em></strong> trang, <strong><em>i</em></strong> = 1 ÷ <strong><em>n</em></strong>, nếu in thành một cuốn sách thì quá dày, vì vậy người ta quyết định in thành <strong><em>k</em></strong> tập, mỗi chương phải nằm gọn trong một tập, tập 1 bao gồm một số chương đầu tiên, mỗi tập tiếp theo bao gồm một số chương tiếp, theo đúng trình tự như khi in tất cả các chương liên tiếp thành một cuốn.</p>

<p style="text-align: justify;">Ban biên tập phải có nhiệm vụ phân chia sao cho số trang của tập dày nhất là ít nhất.</p>

<p style="text-align: justify;">Ví dụ, với <strong><em>n</em></strong> = 5, số trang trong mỗi chương tương ứng lần lượt là 3, 7, 12, 8, 5 và dự kiến in thành 3 tập thì tập 1 sẽ chứa chương 1 và 2 với tổng số trang là 10, tập 2 chứa chương 3 với tổng số trang là 12, tập 3 chứa hai chương cuối với tổng số trang là 13. Như vậy, tập dày nhất có số trang là 13 và đây cũng là cách phân chia phù hợp với yêu cầu đã nêu.</p>

<p style="text-align: justify;">Hãy xác định số trang của tập dày nhất nhận được sau kết quả làm việc của ban biên tập.</p>

<h3 style="text-align: justify;"><strong>Input</strong></h3>

<p style="text-align: justify;">Vào từ thiết bị nhập chuẩn:</p>

<ul>
	<li style="text-align:justify">
	<p>Dòng đầu tiên chứa 2 số nguyên <strong><em>n</em></strong> và <strong><em>k</em></strong> (1 ≤ <strong><em>k</em></strong> ≤ <strong><em>n</em></strong> ≤ 10<sup>5</sup>),</p>
	</li>
	<li style="text-align:justify">
	<p>Dòng thứ 2 chứa <strong><em>n </em></strong>số nguyên <strong><em>a<sub>1</sub></em></strong>, <strong><em>a<sub>2</sub></em></strong>, . . ., <strong><em>a<sub>n</sub></em></strong> (1 ≤ <strong><em>a<sub>i</sub></em></strong> ≤ 10<sup>9</sup>, <strong><em>i</em></strong> = 1 ÷ <strong><em>n</em></strong>).</p>
	</li>
</ul>

<h3 style="text-align: justify;"><strong>Output</strong></h3>

<p style="text-align: justify;">Đưa ra thiết bị xuất chuẩn một số nguyên – số trang của tập dày nhất.</p>

<h3 style="text-align: justify;"><strong>Ví dụ</strong></h3>

<table align="center" border="1" cellspacing="0" style="width:100%">
	<thead>
		<tr>
			<th scope="col" style=" width: 112.5pt;">
			<p style="text-align: center;"><strong><tt>INPUT</tt></strong></p>
			</th>
			<th scope="col" style="width: 90.5pt;">
			<p style="text-align: center;"><strong><tt>OUTPUT</tt></strong></p>
			</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style=" height:16.9pt; width:112.5pt">
			<p><tt>5 3</tt></p>
			<p><tt>3 7 12 8 5</tt></p>
			</td>
			<td style=" height:16.9pt; width:90.5pt">
			<p><tt>13</tt></p>
			</td>
		</tr>
		<tr>
			<td style=" height:16.9pt; width:112.5pt">
			<p>500 55<br>
			701029 64923773 174908879 592 595 748 374537 1 28680 277 30850 574055 4820855 668 8 901244 998 917384 6506 610520419 270187 22705 6 219308 8992 122061 8409067 6778 157214781 9885724 2004526 7237 1 68 246088345 987939 996921 46960331 4 973955 5224 81395261 1 357687261 37056037 65 1 964 57594 54 151558 1 6510 33 38045712 428206 67069603 7558259 44790979 38272884 23 8 742288 190282 78722 22208 31737 49792615 48326016 7 651 42075832 172 10 30 25 3 72302002 459299364 55 776 253 772432 1329634 5962620 4 10 6160105 9004834 23419 89 9047 822 806 8447950 90202 552553 279154 6382669 3449773 8177 340 62495 9395467 98215 730 13 860 10453085 6517 38235224 41 8587 1653057 3209 926257 34971993 253072 772764 9541 67 136 770 231843 177166 247107912 9425 92287747 857114 9924525 531 734702 521098 9939924 6425101 652807 3491632 3745351 456931 3580226 279 65031545 89418746 336680 1006485 480854907 92 285436 3969313 7469191 84283 46767194 3369772 117547729 823257 69120 697435 183788 30668 94483735 581428 78618 6478036 269451 456820 11116509 46 541864 967033 10 286908 84095381 93 66844 34 38663 432271 855420 2 880442289 30 2540 573301 22879393 2279600 212887 7600252 842722 33910975 401056 753325 95 992668 2 107682751 95 6254242 24404 3 833405 20110 11051 3297 704761 6034 547374 6967 146 4951324 80 11 790010 6958 526 134988 9267461 9 43526 858344 13513 1 25760727 88196821 232472 306415 7 3254320 49 373824731 967 55 445802413 37 889111 185548441 630 718057546 223530165 133108669 66041055 61482 191314726 68 59630 286 168460 9997 124984 402528 812 6381611 835936349 43309 31518 298 391741 57217076 997336 856 4654 411000797 432182645 41 9293 9 85 5624897 8022 214201 366 10 544 95 6944772 270 5 2 21 91249 446528671 714389 160605481 177601 12934461 680 43 253 887139 67 55 726748 153112 4555 197449 573965 704216 1119196 5 88 379 916645 67170 2990563 178 7439599 87480 7616535 837993 752543596 1 148642 813372 9874 614285539 119582 46478 4241810 7335864 4843 9157938 73603 5150 7246 6305774 86188437 215368609 3 48 9187 23 1 138974570 60103534 80816 7 40363026 3727243 2845872 12222172 163549 71714804 9 394 45 276031 898699 61368301 90058 5206933 9478255 9433073 498687 8632 25 5079265 6102061 121136049 4553080 3543583 600 495274 47 284267 834322 7888 404305833 934921 56562 2908705 36695161 8 781867 7 1 38740369 103 316402 4355 45525855 1116361 23232118 6799 823408 557128 91 3 84756949 972 461887 31760256 7658196 932616 9067 3817398 877 4 2344 68686489 9816 1 74129 9 82 257634 8824068 178996 68361643 398 830215 9 32049723 625739203 262 95239 9424 51 3574 918070 7 7 66583 3451 5930 7 100400 7 638470 58 3360982 9240946 5 94517935 667429 156451 3559706 778 47185 2617 89226 289996 74616301 539650 278488 44074 123048774 570727 757845401 15719 9763 4591 67 549550 39 642023 28914958 1 913501 75992761 93712 74094935 1 553048 39 92547 1 1 17953 84775176 5 36267 2345992 584599 922690 629440 518175 21528046 974892 37 498565 86634 284223 739778 83 58 17574337 92902 22230259 32325 9 9153 30 55784778 44553166 10461745 62455233 4 66 5578 385673 96324376&nbsp;</p>
			</td>
			<td style=" height:16.9pt; width:90.5pt">
			<p>880442289</p>
			</td>
		</tr>
	</tbody>
</table>
		</div>