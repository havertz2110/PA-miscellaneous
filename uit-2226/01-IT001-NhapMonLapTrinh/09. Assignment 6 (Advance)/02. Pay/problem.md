<div class="problem_description" id="problem_description">
			<p><strong>Pay</strong></p>

<p style="text-align:justify">Alice open an online shop. She got a list of n products ready to ship out to her beloved customers in a very strict order. Product <strong><em>i</em></strong> have the shipping fee </span><strong><em>a</span></em></strong><strong><em>i</span></em></strong>, </span><strong><em>i </span></em></strong>= 1 ÷ </span><strong><em>n</span></em></strong>, when she contact the shipping company, they let her in on a brand new promotion program: Ship 10-19 products together in one shipment and the product with the smallest shipping fee will get free shipping. Ship 20-29 products in one shipment and two products with the smallest shpping fee will get free shipping. In short, for every 10 products ship together, you get 1 free shipping among those with the smallest shipping fee.</span></p>

<p style="text-align:justify">Now this is a very tempting promotion program. However, Alice can't change the order in which those product have to get shipped. Customers will be pissed if they find out the product that was ordered last get shipped first. What Alice can do is group any ammount of consecutive product in her list into one single shipment. Techincally, the product that was ordered last can get shipped *together* with the product that was order first, as long as it is not shipped before.</span></p>

<p style="text-align:justify"><strong>Input</strong>:</p>

<ul>
	<li style="text-align:justify">The first line is the integer </span><strong><em>n </span></em></strong>(1 ≤ </span><strong><em>n </span></em></strong>≤ 10<sup>5</sup>),</span></li>
	<li style="text-align:justify">The second line contains <strong><em>n</em></strong> integers </span><strong><em>a<sub>1</sub></span></em></strong>, <strong><em>a<sub>2</sub></em></strong>, . . ., <strong><em>a<sub>n</sub> </em></strong>(1 ≤ <strong><em>a<sub>i</sub> </em></strong>≤ 10<sup>9</sup>, <strong><em>i </em></strong>= 1 ÷ <strong><em>n</em></strong>)</span>.</span></li>
</ul>

<p style="text-align:justify"><strong>Output</strong>: Output one single integer. The minimum fee Alice will have to pay.</span></p>

<p style="text-align:justify"><strong>Example</span></strong>:</span></p>

<table border="1" cellspacing="0">
	<tbody>
		<tr>
			<td style="width:290.35pt">
			<p style="text-align:justify">Input</span></p>
			</td>
			<td style="width:3.0cm">
			<p style="text-align:justify">Output</span></p>
			</td>
		</tr>
		<tr>
			<td style="vertical-align:top; width:290.35pt">
			<p>12<br>
			1 1 10 10 10 10 10 10 9 10 10 10</span></p>
			</td>
			<td style="vertical-align:top; width:3.0cm">
			<p>92</span></p>
			</td>
		</tr>
	</tbody>
</table>

	