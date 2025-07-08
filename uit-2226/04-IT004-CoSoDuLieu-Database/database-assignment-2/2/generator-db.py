# Khai báo các thư viện cần thiết
# declare some necessary libraries
import csv
import json
import mysql.connector
from faker import Faker
import random
from random import choice
from collections import Counter
from datetime import date, timedelta, datetime
import time

# Lưu thời điểm bắt đầu
# Save start time
start_time = time.time()

# Đầu tiên, ta tạo bảng TRUONG
# First of all, we create table TRUONG

# Ta tạo danh sách các mã trường, aka matr. Ta lấy 200 trường THPT ở trên TP.HCM và đặt từ 001 đến 200
# We create a list of School Code, aka matr. We take 200 highschool in HCM city and place respectively from 001 to 200
matr_list = ['001', '002', '003', '004', '005', '006', '007', '008', '009', '010', '011', '012', '013', '014', '015',
             '016', '017', '018', '019', '020', '021', '022', '023', '024', '025', '026', '027', '028', '029', '030',
             '031', '032', '033', '034', '035', '036', '037', '038', '039', '040', '041', '042', '043', '044', '045',
             '046', '047', '048', '049', '050', '051', '052', '053', '054', '055', '056', '057', '058', '059', '060',
             '061', '062', '063', '064', '065', '066', '067', '068', '069', '070', '071', '072', '073', '074', '075',
             '076', '077', '078', '079', '080', '081', '082', '083', '084', '085', '086', '087', '088', '089', '090',
             '091', '092', '093', '094', '095', '096', '097', '098', '099', '100', '101', '102', '103', '104', '105',
             '106', '107', '108', '109', '110', '111', '112', '113', '114', '115', '116', '117', '118', '119', '120',
             '121', '122', '123', '124', '125', '126', '127', '128', '129', '130', '131', '132', '133', '134', '135',
             '136', '137', '138', '139', '140', '141', '142', '143', '144', '145', '146', '147', '148', '149', '150',
             '151', '152', '153', '154', '155', '156', '157', '158', '159', '160', '161', '162', '163', '164', '165',
             '166', '167', '168', '169', '170', '171', '172', '173', '174', '175', '176', '177', '178', '179', '180',
             '181', '182', '183', '184', '185', '186', '187', '188', '189', '190', '191', '192', '193', '194', '195',
             '196', '197', '198', '199', '200']

# Ta tạo danh sách các tên trường, aka tentr.
# We create a list of School Name, aka tentr.
tentr_list = ['THPT Bùi Thị Xuân', 'THPT Trưng Vương', 'THPT Giồng Ông Tố', 'THPT Nguyễn Thị Minh Khai',
              'THPT Lê Quý Đôn', 'THPT Nguyễn Trãi', 'Phổ thông Năng khiếu thể thao Olympic', 'THPT Hùng Vương',
              'THPT Mạc Đĩnh Chi', 'THPT Bình Phú', 'THPT Lê Thánh Tôn', 'THPT Lương Văn Can', 'THPT Ngô Gia Tự',
              'THPT Tạ Quang Bửu', 'THPT Nguyễn Huệ', 'THPT Nguyễn Khuyến', 'THPT Nguyễn Du', 'THPT Nguyễn Hiền',
              'THPT Võ Trường Toản', 'THPT Thanh Đa', 'THPT Võ Thị Sáu', 'THPT Gia Định', 'THPT Phan Đăng Lưu',
              'THPT Gò Vấp', 'THPT Nguyễn Công Trứ', 'THPT Phú Nhuận', 'THPT Tân Bình', 'THPT Nguyễn Chí Thanh',
              'THPT Trần Phú', 'THPT Nguyễn Thượng Hiền', 'THPT Thủ Đức', 'THPT Nguyễn Hữu Huân', 'THPT Tam Phú',
              'THPT Củ Chi', 'THPT Quang Trung', 'THPT An Nhơn Tây', 'THPT Trung Phú', 'THPT Trung Lập',
              'THPT Nguyễn Hữu Cầu', 'THPT Lý Thường Kiệt', 'THPT Bình Chánh', 'THPT Ten Lơ Man', 'THPT Marie Curie',
              'THPT Trần Khai Nguyên', 'THPT Nguyễn An Ninh', 'THPT Nam Kỳ Khởi Nghĩa', 'THPT Nguyễn Thái Bình',
              'THPT Nguyễn Trung Trực', 'THPT Hàn Thuyên', 'THPT Hoàng Hoa Thám', 'THPT Thăng Long', 'THPT Phước Long',
              'THPT Bà Điểm', 'THPT Tân Phong', 'THPT Trường Chinh', 'THPT Phú Hòa', 'THPT Tân Thông Hội',
              'THPT Tây Thạnh', 'THPT Long Trường', 'THPT Nguyễn Văn Cừ', 'THPT Nguyễn Hữu Tiến', 'THPT Bình Khánh',
              'THPT Cần Thạnh', 'THPT Trần Hưng Đạo', 'THPT Hiệp Bình', 'Tiểu học THCS và THPT Quốc Văn Sài Gòn',
              'THPT Trần Quang Khải', 'THPT Vĩnh Lộc', 'THPT Việt Âu', 'THPT Việt Nhật', 'THPT Hưng Đạo',
              'TH - THCS - THPT Chu Văn An', 'Trung học Thực hành Đại học Sư phạm',
              'Phổ thông Năng Khiếu - ĐHQG Tp. HCM', 'THPT Lý Thái Tổ', 'THPT Trần Quốc Tuấn', 'THPT An Dương Vương',
              'THPT Trần Nhân Tông', 'THPT Đông Dương', 'THPT Phước Kiển', 'THPT Nhân Việt', 'THPT An Nghĩa',
              'THPT Phú Lâm', 'Trung học cơ sở và trung học phổ thông Phùng Hưng', 'THPT Nguyễn Hữu Cảnh',
              'THPT Nguyễn Văn Linh', 'Phân hiệu THPT Lê Thị Hồng Gấm', 'THPT Nguyễn Thị Diệu', 'THPT Quốc Trí',
              'THPT Vĩnh Viễn', 'THCS - THPT Trần Cao Vân', 'THPT Bách Việt', 'THPT Việt Mỹ Anh',
              'THCS và THPT Nam Việt', 'THPT Văn Lang', 'THPT Bình Hưng Hòa', 'THPT Bình Tân', 'THPT Nguyễn Tất Thành',
              'THPT Nguyễn Văn Tăng', 'THPT Trần Văn Giàu', 'THPT Phạm Văn Sáng', 'THPT Đào Sơn Tây', 'THPT Tân Túc',
              'THCS và THPT Hai Bà Trưng', 'THPT Thủ Khoa Huân', 'THPT Vĩnh Lộc B', 'THPT Dương Văn Dương',
              'THPT Võ Văn Kiệt', 'Tiểu học THCS và THPT Mùa Xuân', 'THPT Năng khiếu TDTT Huyện Bình Chánh',
              'THPT Lê Trọng Tấn', 'THPT Linh Trung', 'THPT Dương Văn Thì', 'THPT Bình Chiểu', 'THPT Hồ Thị Bi',
              'THPT Phong Phú', 'THPT Thủ Thiêm', 'THPT Ngô Quyền', 'THPT Thạnh Lộc', 'THPT An Lạc',
              'THPT Lê Minh Xuân', 'THPT Đa Phước', 'THCS và THPT Đăng Khoa', 'THCS và THPT Hồng Hà',
              'TH THCS THPT Tuệ Đức (2)', 'THCS và THPT Nguyễn Bỉnh Khiêm', 'Tiểu học THCS và THPT Ngô Thời Nhiệm',
              'THCSTHPT An Đông', 'THCS THPT  Ngôi Sao', 'THCS-THPT Phan Bội Châu', 'TH - THCS - THPT VẠN HẠNH',
              'THPT Nam Sài Gòn', 'THCS-THPT Hồng Đức', 'THCS và THPT Bắc Sơn', 'THCS và THPT Phạm Ngũ Lão',
              'THCS và THPT Bạch Đằng', 'THPT Đông Đô', 'TH THCS và THPT Quốc Tế', 'THCS và THPT  Việt Thanh',
              'THCS và THPT Trí Đức', 'THCS và THPT Thái Bình', 'TH-THCS-THPT Thanh Bình', 'THCS và THPT Nhân Văn',
              'THCS - THPT Nguyễn Khuyến', 'TH THCS và THPT Trương Vĩnh Ký', 'THCS THPT Phan Châu Trinh',
              'THCS - THPT Duy Tân', 'THPT Nguyễn Hữu Thọ', 'THCS và THPT Châu Á Thái Bình Dương',
              'Tiểu học THCS và THPT Việt Mỹ', 'THCS và THPT Đức Trí', 'THCS và THPT Đinh Thiện Lý',
              'THCS - THPT Sao Việt', 'TH THCS và THPT Nam Mỹ', 'Trung học thực hành Sài Gòn', 'THCS - THPT Lạc Hồng',
              'THCS và THPT Quang Trung Nguyễn Huệ', 'THCS và THPT Khai Minh', 'THCS  VÀ THPT NGỌC VIỄN ĐÔNG',
              'Tiểu học THCS và THPT Tân Phú', 'THCS - THPT Bác Ái', 'THCS và THPT Sương Nguyệt Anh',
              'THCS và THPT Diên Hồng', 'THPT Minh Đức', 'THPT Thành Nhân', 'THCS và THPT Hoa Lư',
              'THCS và THPT Đào Duy Anh', 'THCS và THPT ĐINH TIÊN HOÀNG', 'THPT Lương Thế Vinh', 'THPT Năng Khiếu TDTT',
              'THCS và THPT Việt Anh', 'THCS và THPT Hoa Sen', 'Tiểu học THCS và THPT Vinschool', 'THPT Phạm Phú Thứ',
              'THCS và THPT Thạnh An', 'TH THCS và THPT Trí Tuệ Việt', 'Tiểu học THCS và THPT Lê Thánh Tông',
              'PTDL Hermann Gmeiner', 'Tiểu học THCS và THPT Việt Úc', 'THCS Song ngữ Quốc tế Horizon',
              'Tiểu học THCS và THPT Quốc tế Canada', 'TiH - THCS - THPT QUỐC TẾ BẮC MỸ',
              'Tiểu học THCS và THPT Thái Bình Dương', 'TH THCS VÀ THPT Nguyễn Tri Phương',
              'Tiểu học THCS và THPT Anh Quốc', 'Tiểu học THCS và THPT Emasi Nam Long', 'Tiểu học THCS và THPT Mỹ Việt',
              'Tiểu học THCS và THPT Emasi Vạn Phúc', 'Tiểu học THCS và THPT Hoàng Gia',
              'Tiểu học THCS và THPT Albert Einstein', 'THPT chuyên Lê Hồng Phong', 'THPT chuyên Trần Đại Nghĩa',
              'THPT Chuyên Năng khiếu TDTT Nguyễn Thị Định', 'Tiểu học THCS và THPT Quốc tế Khai Sáng',
              'Trường Quốc tế Việt Nam - Phần Lan', 'Trường Quốc tế Việt Nam - Phần Lan',
              'Tiểu học THCS  và THPT Quốc tế Á Châu', 'Tiểu học THCS và THPT Hòa Bình', 'TiH - THCS - THPT Tây Úc',
              'Tiểu học THCS và THPT Úc Châu'
              ]

# Ta tạo danh sách các địa chỉ trường, aka dchitr
# We create a list of School Address, aka dchitr
dchitr_list = ['73 - 75 Bùi Thị Xuân', '3 Nguyễn Bỉnh Khiêm', '200/10 Nguyễn Thị Định', '275 Điện Biên Phủ',
               '110 Nguyễn Thị Minh Khai Phường 6 Quận 3 TP.Hồ Chí Minh', '364 Nguyễn Tất Thành',
               'Đại học Thể dục thể thao TP. Hồ Chí Minh - Khu phố 6 - phường Linh Trung - Quận Thủ Đức - TP. Hồ Chí Minh',
               '124 Hùng Vương', '04 Tân Hòa Đông', '102 Đường Trần Văn Kiểu Phường 1  Quận 6 TPHCM', '124 đường 17',
               '173 Phạm Hùng', '360E Bến Bình Đông', '909 Tạ Quang Bửu',
               'Đường Nguyễn Văn Tăng Kp Châu Phúc Cẩm P.LTM Q9', '50 Thành Thái', 'XX-1 Đồng Nai',
               '3 Dương Đình Nghệ-P8-Q11', '482 Đường Nguyễn Thị Đặng - Khu Phố 1',
               '186 Nguyễn Xí phường 26 quận Bình Thạnh TP.HCM', '95 Đinh Tiên Hoàng', '195/29 Xô Viết Nghệ Tĩnh',
               '27 Nguyễn Văn Đậu', '90A Nguyễn Thái Sơn', '97 Quang Trung Phường 8 Quận Gò Vấp TP.HCM',
               'Số 5 Hoàng Minh Giám', '19 Hoa Bằng', '1A Nguyễn Hiến Lê', '18 Lê Thúc Hoạch', '544 Cách Mạng Tháng 8',
               '166/24 Đặng Văn Bi', '11 Đoàn Kết', '31 Phú Châu Kp5', 'Tỉnh lộ 8 Khu phố 1', 'Ấp Phước An',
               '227Đường Tỉnh lộ 7 Ấp Chợ Cũ Xã An Nhơn Tây Huyện Củ Chi TP.HCM', '1318 tỉnh lộ 8 Ấp 12',
               '91/3 Trung Lập Ấp Trung Bình.', 'Tô Ký Ấp Mỹ Huề Xã Trung Chánh Huyện Hóc Môn TP. HCM.',
               'Đường Nam Thới 2 Ấp Nam Thới Xã Thới Tam Thôn', 'D17/1D Huỳnh Văn Trí',
               '8 Trần Hưng Đạo Phường Phạm Ngũ Lão Quận 1 Tp.Hồ Chí Minh', '159 Nam Kỳ Khởi Nghĩa',
               '225 Nguyễn Tri Phương', '93 Trần Nhân Tôn', '269/8 Nguyễn Thị Nhỏ', '913-915 Lý Thường Kiệt',
               '9/168 Lê Đức Thọ', '37 Đặng Văn Ngữ', '6 Hoàng Hoa Thám', '114-116 Hải Thượng Lãn Ông',
               'Dương Đình Hội Khu phố 6 - Phường Phước Long B - Q.9',
               'Số7 Nguyễn Thị Sóc Ấp Bắc Lânxã Bà Điểm Huyện Hóc Môn', '19F Nguyễn Văn Linh', '1 DN11 Khu phố 4',
               'Số 25 đường Huỳnh Thị Bẵng Ấp Phú Lợi', 'Ấp Bàu Sim', '27 Đường C2',
               '309 Võ Văn Hát Kp Phước Hiệp phường Long Trường Quận 9 Tp. Hồ Chí Minh',
               '100A ấp 6 xã Xuân Thới Thương Huyện Hóc Môn', '9A Ấp 7', 'Ấp Bình An',
               '346 Đường Duyên Hải - Khu Phố Miễu Ba - Thị trấn Cần Thạnh - huyện Cần Giờ', '88/955E Lê Đức Thọ',
               'Số 63 đường Hiệp Bình khu phố 6', '300 Hòa Bình', '343D Lạc Long Quân',
               '87 Đường Số 3 Kdc Vĩnh Lộc Phường Bình Hưng Hòa B Bình Tân TP.HCM', '30/2 Quốc lộ 1A',
               '371 Nguyễn Kiệm', '103 Nguyễn Văn Đậu', 'Số 7 Đường Số 1 Khu Phố 1',
               '280 An Dương Vương Phường 4 Quận 5 Tp. Hồ Chí Minh', '153 Nguyễn Chí Thanh', '1/22/2a Nguyễn Oanh',
               '236/10-12 Thái Phiên', 'đường số 3khu phố 6 phường Trường Thọ quận Thủ Đức', '66 Tân Hóa',
               '114/37/12A-E Đường số 10', 'Số 1163 Đường Lê Văn Lương Ấp 3', '41-39 Đoàn Hồng Phước', 'Ấp An Nghĩa',
               '12-24 đường số 3 chợ Phú Lâm', '14A Đường số 1 Phường 16 Quận Gò vấp TP Hồ Chí Minh', '845 Hương Lộ 2',
               'Số 02 Đường 3154 Phạm Thế Hiển  Phường 07 Quận 08', '147 Pasteur', '12 Trần Quốc Toản',
               '313 Nguyễn Văn Luông', '73/7 Lê Trọng Tấn - Phường Sơn Kỳ Quận Tân Phú', '126 Tô Hiệu',
               '653 Quốc lộ 13 Kp3', '252 Lạc Long Quân', '25 21/1-3 23/7-9 Dương Đức Hiền', '02-04 Tân Thành',
               '79/19 Đường Số 4 Kp7 P.BHH Q.Bình Tân', '117/4H Hồ Văn Long', '249C Nguyễn Văn Luông',
               'Đường số 1 KP Tái Định Cư Long Bửu', '203/40 Đường Trục Phường 13Quận Bình Thạnh TP.Hồ Chí Minh',
               'Ấp 3', '53/5 Đường 10 Khu phố 3 Linh Xuân Thủ Đức',
               'C1/3K Khu Phố 3 Đường Bùi Thanh Khiết Thị Trấn Tân Túc Huyện Bình Chánh', '51/4 Nguyễn Thị Nhỏ',
               '481/8 Trường Chinh', 'Đường số 3 Khu Dân Cư Vĩnh Lộc Bxã VĨnh Lộc B huyện Bình Chánh TPHCM',
               '39 Đường số 6 KDC Phú Gia Ấp 2', '629 Bình Đông', '92 Nguyễn Hữu Cảnh phường 22 Quận Bình Thạnh',
               'Ấp 1 Mai Bá Hương xã Lê Minh Xuân huyện Bình Chánh', 'Số 5 Đường D2 Phường Sơn Kỳ Quận Tân Phú', 'nan',
               'nan', 'nan', 'nan', 'nan', '1 Đường Vũ Tông Phan', '1360 Huỳnh Tấn Phát', 'đường Nguyễn Thị Sáu - KP1',
               '595 Kinh Dương Vương Phường An Lạc Quận Bình Tân', 'G11/1 Ấp 7 Xã Lê Minh Xuân H. Bình Chánh',
               'D14/410A QL 50 xã Đa Phước -Huyện Bình Chánh TP.HCM', '571 Cô Bắc', '170 Quang Trung',
               '249/108 Tân Thới Nhất 17', '140 Lý Chính Thắng', '65D Hồ Bá Phấn', '91 Nguyễn Chí Thanh',
               'Đường số 18 Khu dân cư An Lạc', 'nan', '781e Lê Hồng Phong P12 Q10', 'Khu A Nam Sài Gòn',
               'Số 8Đường Hồ Đắc DiPhường Tây ThạnhQuận Tân Phú TP Hồ Chí Minh',
               '338/24 Nguyễn Văn Quá P. Đông Hưng Thuận Quận 12', '69/11 Phạm Văn Chiêu P14 Gò Vấp',
               '53/1 Phan Văn Hớn', '12B Nguyễn Hữu Cảnh', '305 Nguyễn Trọng Tuyển Phường 10 Quận Phú Nhuận',
               '261 Cộng Hòa', '1333A Thoại Ngọc Hầu', '10 Trương Hoàng Thanh', '192/12 Nguyễn Thái Bình', '17 Sơn Kỳ',
               '136 Cộng Hòa', 'nan', 'Số 12 Đường 23', '106 Nguyễn Giản Thanh', '2 Bến Vân Đồn',
               '33 C D E Nguyễn Bỉnh Khiêm', 'nan', '39/23 Bùi Văn Ba khu phố 2', 'Lô 01 Khu A Nam Sài Gòn',
               '650q/15 Nguyễn Hữu Thọ', 'nan', '220 Tần Bình Trọng', '2276/5 Quốc lộ 1A', '223 Nguyễn Tri Phương',
               '410 Tân Kỳ Tân Quý', 'nan', '519 Kênh Tân Hóa', '187 Gò Cẩm Đệm P.10 Q.Tân Bình TP.HCM', '249 Hòa Hảo',
               '11 Thành Thái  phường 14 quận 10', '277 Tân Quý', '69/12 Nguyễn Cửu Đàm P. Tân Sơn Nhì Q. Tân Phú',
               '201 Phan Văn Hớn', '355 Nguyễn Văn Luông', '85 Chế Lan Viên', '131 Cô Bắc', '43 Điện Biên Phủ',
               '269A Nguyễn Trọng Tuyển P10 Phú Nhuận', '26 Phan Chu Trinh',
               'Tòa CC3 khu đô thị Vinhomes Central Park 720A Điện Biên Phủ', '425 - 435 Gia Phú', 'nan', 'nan', 'nan',
               '697 Quang Trung', '594 Ba Tháng Hai - phường 14 - Quận 10 - Tp. HCM', '6-6A-8 dường số 44',
               'Số 86 Đường 23', '1 Đường 5A Kdc Trung Sơn', '125 Bạch Đằng', '61a Đường 30', 'nan', 'nan',
               '95 Phan Văn Hớn-Phường Tân Thới Nhất-Quận 12 - Thành Phố Hồ Chí Minh', 'nan', 'nan',
               'Khu Dân Cư 13c đại lộ Nguyễn Văn Linh xã Phong Phú huyện Bình Chánh TP Hồ Chí Minh',
               '235 Nguyễn Văn Cừ', '53 Nguyễn Du', '215 Đường Hoàng Ngân', 'nan', 'nan', 'nan',
               'Số 41/3-41/4 Bis Trần Nhật Duật', '69 Trịnh Đình Thảo', '157 Lý Chính Thắng', 'nan'
               ]

# Kết hợp các danh sách thành một danh sách dữ liệu
# After creating those lists, we combine them into 1 data list
data = zip(matr_list, tentr_list, dchitr_list)

# Ghi dữ liệu vào tệp CSV
# Write all those generated data into CSV file for further works
with open('truong.csv', 'w', newline='', encoding='utf-8') as truong_file:
    writer = csv.writer(truong_file)
    writer.writerow(['MATR', 'TENTR', 'DCHITR'])
    writer.writerows(data)

# Tiếp theo, chúng ta tạo bảng HS
# First of all, we create table HS

# Ta sử dụng Faker để tạo dữ liệu 1 cách random
# We use Faker to generate data randomly
fake = Faker('vi_VN')

# Ta tạo danh sách những cái họ thông dụng ở Việt Nam
# We create ở list of common people's surnames in Vietnam
ho_list = {'Trần', 'Hoàng', 'Trương', 'Lý', 'Vương', 'Ngô', 'Lưu', 'Thái', 'Dương', 'Từ', 'Tôn', 'Mã', 'Châu', 'Hồ',
           'Quách', 'Hà', 'Cao', 'Lâm', 'La', 'Trịnh', 'Lương', 'Hàn', 'Chu', 'Triệu', 'Nguyễn', 'Lê', 'Vũ', 'Võ',
           'Đường', 'Đinh', 'Đoàn', 'Trịnh', 'Đào', 'Phạm', 'Phùng', 'Mai', 'Tô', 'Phí', 'Tạ', 'Thân', 'Lâm', 'Tống',
           'Hoa', 'Từ', 'Thường', 'Tiêu', 'Ngọ', 'Kim', 'Tôn Thất', 'Triệu', 'Mạc', 'Thái', 'Thạch', 'Quách', 'Đàm',
           'Đồng Văn', 'Huỳnh', 'Phan', 'Đặng', 'Bùi', 'Hồ', 'Đỗ', 'Âu Dương', 'Dư', 'Nghiêm', 'Viên', 'Ma', 'Mạch',
           'Lỗ', 'Tiêu', 'Thẩm', 'Trình', 'Uông', 'Ung', 'Ưng', 'Vi', 'Văn', 'Yên', 'Nhâm', 'Doãn', 'Chung', 'Cáp',
           'Ái Tân Giác La', 'Thành Cát', 'Mãn', 'Nỗ Nhĩ', 'Lã', 'Khuất', 'Khúc', 'Khâu', 'Khổng', 'Kha', 'Hứa', 'Cáp',
           'Bế', 'Bầnh', 'Chiêm', 'Chế', 'Cồ', 'Cổ', 'Phó', 'Hạ', 'Hầu', 'Kiều', 'Tùy', 'Lục', 'Đồng ', 'Đổng'}

# Ta tạo danh sách những cái tên thông dụng ở Việt Nam
# We create ở list of common people's names in Vietnam
ten_list = {'Trung', 'Quân', 'Hải', 'Đức', 'Ân', 'An', 'Thịnh', 'Linh', 'Hiếu', 'Quốc', 'Duy', 'Tuấn', 'Tân', 'Đăng',
            'Nam', 'Thành', 'Việt', 'Khánh', 'Vũ', 'Phong', 'Cường', 'Tâm', 'Nhật', 'Sơn', 'Phúc', 'Thái', 'Lâm', 'Tấn',
            'Ngọc', 'Đạt', 'Hiệp', 'Tài', 'Dũng', 'Hồng', 'Huy', 'Hà', 'Khải', 'Thiện', 'Nghĩa ', 'Vương', 'Tiến',
            'Vinh', 'Hoàng', 'Đông ', 'Nhân', 'Khắc', 'Thanh', 'Tùng', 'Thắng', 'Hùng', 'Bình', 'Trí', 'Kiên', 'Tuệ',
            'Hào', 'Thế', 'Thiên', 'Vĩ', 'Hoa', 'Dương', 'Quang', 'Sỹ', 'Lượng', 'Xuân', 'Phương', 'Tú', 'Tuyến',
            'Tuyết', 'Long', 'Hưng', 'Hòa', 'Khoa', 'Khôi', 'Khang', 'Nhất', 'Nhị', 'Tam', 'Tứ', 'Ngũ', 'Lục', 'Liên',
            'Kim', 'Chung', 'Nhựt', 'Ưng', 'Thắm', 'Quỳnh', 'Giang', 'Quế', 'Quy', 'Quyết', 'Thất', 'Bát', 'Cửu', 'Tây',
            'Bắc', 'Tông', 'Tín', 'Kỳ', 'Thư', 'Cát', 'Tường', 'Kiều', 'Anh', 'Tuyền', 'Mĩ', 'Pháp', 'Vân', 'Văn'}

# Tạo danh sách các địa chỉ bao gồm các quận và phường của quận đó
# We create a list of addresses including districts and wards of that district 
phuong_quan = {
    'Quận 1': ['Phường Tân Định', 'Phường Cầu Kho', 'Phường Cầu Ông Lãnh', 'Phường Cô Giang', 'Phường Nguyễn Cư Trinh',
               'Phường Đa Kao', 'Phường Bến Nghé', 'Phường Bến Thành', 'Phường Nguyễn Thái Bình',
               'Phường Phạm Ngũ Lão'],
    'Quận 3': ['Phường 1', 'Phường 2', 'Phường 3', 'Phường 4', 'Phường 5', 'Phường Võ Thị Sáu', 'Phường 09',
               'Phường 10', 'Phường 11', 'Phường 12', 'Phường 13', 'Phường 14'],
    'Quận 4': ['Phường 1', 'Phường 2', 'Phường 3', 'Phường 4', 'Phường 6', 'Phường 8', 'Phường 09', 'Phường 10',
               'Phường 13', 'Phường 14', 'Phường 15', 'Phường 16', 'Phường 18'],
    'Quận 5': ['Phường 1', 'Phường 2', 'Phường 3', 'Phường 4', 'Phường 5', 'Phường 6', 'Phường 7', 'Phường 8',
               'Phường 09', 'Phường 10', 'Phường 11', 'Phường 12', 'Phường 13', 'Phường 14'],
    'Quận 6': ['Phường 1', 'Phường 2', 'Phường 3', 'Phường 4', 'Phường 5', 'Phường 6', 'Phường 7', 'Phường 8',
               'Phường 09', 'Phường 10', 'Phường 11', 'Phường 12', 'Phường 13', 'Phường 14'],
    'Quận 7': ['Phường Bình Thuận', 'Phường Phú Mỹ', 'Phường Phú Thuận', 'Phường Tân Hưng', 'Phường Tân Kiểng',
               'Phường Tân Phong', 'Phường Tân Phú', 'Phường Tân Quy', 'Phường Tân Thuận Đông', 'Phường Tân Thuận Tây'],
    'Quận 8': ['Phường 1', 'Phường 2', 'Phường 3', 'Phường 4', 'Phường 5', 'Phường 6', 'Phường 7', 'Phường 8',
               'Phường 09', 'Phường 10', 'Phường 11', 'Phường 12', 'Phường 13', 'Phường 14', 'Phường 15', 'Phường 16'],
    'Quận 10': ['Phường 1', 'Phường 2', 'Phường 4', 'Phường 5', 'Phường 6', 'Phường 7', 'Phường 8', 'Phường 09',
                'Phường 10', 'Phường 11', 'Phường 12', 'Phường 13', 'Phường 14', 'Phường 15'],
    'Quận 11': ['Phường 1', 'Phường 2', 'Phường 3', 'Phường 4', 'Phường 5', 'Phường 6', 'Phường 7', 'Phường 8',
                'Phường 09', 'Phường 10', 'Phường 11', 'Phường 12', 'Phường 13', 'Phường 14', 'Phường 15', 'Phường 16'],
    'Quận 12': ['Phường An Phú Đông', 'Phường Đông Hưng Thuận', 'Phường Hiệp Thành', 'Phường Tân Chánh Hiệp',
                'Phường Tân Hưng Thuận', 'Phường Tân Thới Hiệp', 'Phường Tân Thới Nhất', 'Phường Thạnh Lộc',
                'Phường Thạnh Xuân', 'Phường Thới An', 'Phường Trung Mỹ Tây'],
    'Quận Tân Bình': ['Phường 1', 'Phường 2', 'Phường 3', 'Phường 4', 'Phường 5', 'Phường 6', 'Phường 7', 'Phường 8',
                      'Phường 09', 'Phường 10', 'Phường 11', 'Phường 12', 'Phường 13', 'Phường 14', 'Phường 15'],
    'Quận Bình Thạnh': ['Phường 1', 'Phường 2', 'Phường 3', 'Phường 5', 'Phường 6', 'Phường 7', 'Phường 11',
                        'Phường 12', 'Phường 13', 'Phường 14', 'Phường 15', 'Phường 17', 'Phường 19', 'Phường 21',
                        'Phường 22', 'Phường 24', 'Phường 25', 'Phường 26', 'Phường 27', 'Phường 28'],
    'Quận Bình Tân': ['Phường An Lạc', 'Phường An Lạc A', 'Phường Bình Hưng Hòa', 'Phường Bình Hưng Hoà A',
                      'Phường Bình Hưng Hoà B', 'Phường Bình Trị Đông', 'Phường Bình Trị Đông A',
                      'Phường Bình Trị Đông B', 'Phường Tân Tạo', 'Phường Tân Tạo A'],
    'Thủ Đức': ['An Khánh', 'An Lợi Đông', 'An Phú', 'Bình Chiểu', 'Bình Thọ', 'Bình Trưng Đông', 'Bình Trưng Tây',
                'Cát Lái', 'Hiệp Bình Chánh', 'Hiệp Bình Phước', 'Hiệp Phú', 'Linh Chiểu', 'Linh Đông', 'Linh Tây',
                'Linh Trung', 'Linh Xuân', 'Long Bình', 'Long Phước', 'Long Thạnh Mỹ', 'Long Trường', 'Phú Hữu',
                'Phước Bình', 'Phước Long A', 'Phước Long B', 'Tam Bình', 'Tam Phú', 'Tăng Nhơn Phú A',
                'Tăng Nhơn Phú B', 'Tân Phú', 'Thảo Điền', 'Thạnh Mỹ Lợi', 'Thủ Thiêm', 'Trường Thạnh', 'Trường Thọ'],
    'Quận Gò Vấp': ['Phường 1', 'Phường 3', 'Phường 4', 'Phường 5', 'Phường 6', 'Phường 7', 'Phường 8', 'Phường 09',
                    'Phường 10', 'Phường 11', 'Phường 12', 'Phường 13', 'Phường 14', 'Phường 15', 'Phường 16',
                    'Phường 17'],
    'Quận Phú Nhuận': ['Phường 1', 'Phường 2', 'Phường 3', 'Phường 4', 'Phường 5', 'Phường 7', 'Phường 8', 'Phường 09',
                       'Phường 10', 'Phường 11', 'Phường 13', 'Phường 15', 'Phường 17'],
    'Quận Tân Phú': ['Phường Hiệp Tân', 'Phường Hoà Thạnh', 'Phường Phú Thạnh', 'Phường Phú Thọ Hoà',
                     'Phường Phú Trung', 'Phường Sơn Kỳ', 'Phường Tân Qúy', 'Phường Tân Sơn Nhì', 'Phường Tân Thành',
                     'Phường Tân Thới Hoà', 'Phường Tây Thạnh'],
    'Huyện Bình Chánh': ['Thị trấn Tân Túc', 'Xã An Phú Tây', 'Xã Bình Chánh', 'Xã Bình Hưng', 'Xã Bình Lợi',
                         'Xã Đa Phước', 'Xã Hưng Long', 'Xã Lê Minh Xuân', 'Xã Phạm Văn Hai', 'Xã Phong Phú',
                         'Xã Quy Đức', 'Xã Tân Kiên', 'Xã Tân Nhựt', 'Xã Tân Quý Tây', 'Xã Vĩnh Lộc A',
                         'Xã Vĩnh Lộc B'],
    'Huyện Hóc Môn': ['Thị trấn Hóc Môn', 'Xã Bà Điểm', 'Xã Đông Thạnh', 'Xã Nhị Bình', 'Xã Tân Hiệp',
                      'Xã Tân Thới Nhì', 'Xã Tân Xuân', 'Xã Thới Tam Thôn', 'Xã Trung Chánh', 'Xã Xuân Thới Đông',
                      'Xã Xuân Thới Sơn', 'Xã Xuân Thới Thượng'],
    'Huyện Củ Chi': ['Thị trấn Củ Chi', 'Xã An Nhơn Tây', 'Xã An Phú', 'Xã Bình Mỹ', 'Xã Hòa Phú', 'Xã Nhuận Đức',
                     'Xã Phạm Văn Cội', 'Xã Phú Hòa Đông', 'Xã Phú Mỹ Hưng', 'Xã Phước Hiệp', 'Xã Phước Thạnh',
                     'Xã Phước Vĩnh An', 'Xã Tân An Hội', 'Xã Tân Phú Trung', 'Xã Tân Thạnh Đông', 'Xã Tân Thạnh Tây',
                     'Xã Tân Thông Hội', 'Xã Thái Mỹ', 'Xã Trung An', 'Xã Trung Lập Hạ', 'Xã Trung Lập Thượng'],
    'Huyện Nhà Bè': ['Thị trấn Nhà Bè', 'Xã Hiệp Phước', 'Xã Long Thới', 'Xã Nhơn Đức', 'Xã Phú Xuân', 'Xã Phước Kiển',
                     'Xã Phước Lộc'],
    'Huyện Cần Giờ': ['Thị trấn Cần Thạnh', 'Xã An Thới Đông', 'Xã Bình Khánh', 'Xã Long Hòa', 'Xã Lý Nhơn',
                      'Xã Tam Thôn Hiệp', 'Xã Thạnh An'],
}

ho_list = list(ho_list) #Chuyển ho_list thành 1 danh sách / Convert ho_list to a list
ten_list = list(ten_list) # Chuyển tem_list thành 1 danh sách / Convert ten_list to a list

hs_data = []  # Danh sách để lưu trữ dữ liệu /  Create a list to store data

birth_years = [2004, 2005, 2006]  # Danh sách các năm sinh / List of birth years
birth_years_weights = [1, 1, 1] # Trọng số cho mỗi năm sinh ( để đảm bảo các học sinh ở 3 lứa tuổi bằng nhau ) /  Weights for each birth year (ensure the same number of students of 3 ages)
birth_year_counter = Counter()  # Đếm số lượng học sinh theo từng năm sinh

cccd_numbers_male = list(range(1, 500001))  # Số căn cước công dân cho giới tính nam / ID number for male
cccd_numbers_female = list(range(1, 500001))  # Số căn cước công dân cho giới tính nữ / ID number for female
random.shuffle(cccd_numbers_male)  # Sắp xếp ngẫu nhiên / Randomize those numbers above
random.shuffle(cccd_numbers_female)  # Sắp xếp ngẫu nhiên / Randomize those numbers above

mahs_to_ntns = {} # Sử dụng dictionary để ánh xạ mahs sang ntns tương ứng/ Dictionary to map student codes (mahs) to birth dates (ntns)

for i in range(1, 1000001):
    mahs = f"HS{i:07}" # Tạo 1 mahs / Generate a student code (mahs)
  
    ho = random.choice(ho_list) # Lấy 1 cái họ ngẫu nhiên từ danh sách / take a random surname from the list
    ten = random.choice(ten_list) # Lấy 1 cái tên ngẫu nhiên từ danh sách / take a random name from the list 
  
    if i <= 500000:
        gioi_tinh = "M" # Giới tính nam / Male 
        cccd = f"M{cccd_numbers_male[i - 1]:06}" # tạo số căn cước công dân / generate the id number
    else:
        gioi_tinh = "F" # Giới tính nữ / Female
        cccd = f"F{cccd_numbers_female[i - 500001]:06}"  # tạo số căn cước công dân / generate the id number
    # Dẫn đến số cccd dưới 500k là nam, ngược lại là nữ / This leads to one who has their id number below 500k is male and vice versa 
  
    birth_year = random.choices(birth_years, weights=birth_years_weights)[0]  # Chọn ngẫu nhiên 1 năm sinh / Randomly select a birth year
    birth_year_counter[birth_year] += 1 # Tăng bộ đếm cho năm sinh đã chọn / Increment the counter for the selected birth year
    min_birth_date = date(birth_year, 1, 1) # Ngày sinh tối thiểu cho năm sinh đã chọn / Minimum birth date for the selected birth year
    max_birth_date = date(birth_year, 12, 31) # Ngày sinh tối đa cho năm sinh đã chọn / Maximum birth date for the selected birth year
    random_birth_date = min_birth_date + timedelta(days=random.randint(0, 365)) # Tạo 1 ngày tháng sinh ngẫu nhiên với năm đã chọn / Generate a random birth date within the year
    ntns = random_birth_date.strftime("%d/%m/%Y")  # Format lại định dạng của ntns thành dạng chuỗi / Format the birth date as a string
    mahs_to_ntns[mahs] = ntns  # Ánh xạ mahs với ntns / Map the student code (mahs) to the birth date (ntns)
  
    quan = choice(list(phuong_quan.keys())) # Chọn 1 quận ngâu nhiên / Select a random district
    phuong = choice(phuong_quan[quan]) # Chọn 1 phường ngẫu nhiên tương ứng với quận / Select a random ward within district
    dia_chi = f"{phuong}, {quan}, Thành phố Hồ Chí Minh" #  Chỉnh lại định dạng địa chỉ / Format the address 
  
    hs_data.append((mahs, ho, ten, cccd, ntns, dia_chi)) # Thêm thông tin hs vừa tạo vào danh sách / Add the student data to the list

# Ghi dữ liệu vào tệp CSV
# Write generated data into CSV file
with open('hs.csv', 'w', newline='', encoding='utf-8') as hs_file:
    writer = csv.writer(hs_file)
    writer.writerow(['MAHS', 'HO', 'TEN', 'CCCD', 'NTNS', 'DCHI_HS'])
    writer.writerows(hs_data)

# Sau khi kết thúc tạo bảng HS, ta tạo dữ liệu cho bảng HOC
# After creating table HS, we move further on table HOC

# Thứ nhất, ta tạo 1 hàm để xếp loại hpc sinh dựa trên điểm trung bình (diemtb) của chúng
# First, we create a function for student ranking based on their CGPA  (diemtb)
def generate_xeploai(diemtb):
    if diemtb >= 9.0:
        return "Xuất sắc"
    elif diemtb >= 8.0:
        return "Giỏi"
    elif diemtb >= 7.0:
        return "Khá"
    elif diemtb >= 5.0:
        return "Trung bình"
    else:
        return "Yếu"

# Thứ hai, ta tạo 1 hàm đê tính kết quả năm học dựa trên xếp loại của chúng
# Second, we create a function for student's result based on their ranking
def generate_kqua(xeploai):
    if xeploai == "Yếu":
        return "Chưa hoàn thành"
    else:
        return "Hoàn thành"

hoc_data = [] # Danh sách để lưu trữ dữ liệu /  Create a list to store data
             
for i in range(1, 1000001):
    matr = random.choice(matr_list) # Chọn 1 matr ngâu nhiên / Choose a school code (matr) randomly
  
    mahs = f"HS{i:07}" # Tạo mã hs / Create mahs
  
    ntns = mahs_to_ntns[mahs] # Lấy ngày sinh tương ứng với mã hs đã được ánh xạ ở trên 
    ntns_date = datetime.strptime(ntns, "%d/%m/%Y").date()  # Chuyển đổi NTNS thành đối tượng date / Change NTNS format from string to date

    # Mục đích của phần code dưới đây đó là để tạo cho cột namhoc, vì bối cảnh là ở năm 2022 nên nếu 2004 sẽ có 3 năm học đó là 19-20,20-21,21-22 và cứ thế
    # The purpose of the code below is to create the namhoc column, because the context is in 2022, so if 2004 there will be 3 school years that are 19-20, 20-21, 21-22 and so on.
    if ntns_date.year == 2004:
        for a in range(1, 4):
            if a == 1:
                namhoc = '2019-2020'
            elif a == 2:
                namhoc = '2020-2021'
            elif a == 3:
                namhoc = '2021-2022'
            diemtb = round(random.uniform(4, 10), 2) # Tạo điểm trung bình ngẫu nhiên / Create CGPA randomly
            xeploai = generate_xeploai(diemtb) # Tạo xếp loại dựa trên điểm trung bình / Create rank based on CGPA
            ketqua = generate_kqua(xeploai) # Tạo kết quả học tập dựa trên xếp loại / Create result based on rank
            hoc_data.append((matr, mahs, namhoc, diemtb, xeploai, ketqua)) # Thêm dữ liệu học tập vào danh sách / Add data into the list
    elif ntns_date.year == 2005:
        for a in range(1, 3):
            if a == 1:
                namhoc = '2020-2021'
            elif a == 2:
                namhoc = '2021-2022'
            diemtb = round(random.uniform(4, 10), 2)
            xeploai = generate_xeploai(diemtb)
            ketqua = generate_kqua(xeploai)
            hoc_data.append((matr, mahs, namhoc, diemtb, xeploai, ketqua))
    elif ntns_date.year == 2006:
        namhoc = '2021-2022'
        diemtb = round(random.uniform(4, 10), 2)
        xeploai = generate_xeploai(diemtb)
        ketqua = generate_kqua(xeploai)
        hoc_data.append((matr, mahs, namhoc, diemtb, xeploai, ketqua))

# GHi dữ liệu vào tập csv
# Write generate data into CSV file
with open('hoc.csv', 'w', newline='', encoding='utf-8') as hoc_file:
    writer = csv.writer(hoc_file)
    writer.writerow(['MATR', 'MAHS', 'NAMHOC', 'DIEMTB', 'XEPLOAI', 'KQUA'])
    writer.writerows(hoc_data)

# Nếu có thể, ta hãy thêm 1 chút tính bảo mật vào bài làm này, ta sẽ sử dụng 1 file cấu hình mạng để phòng khi mã nguồn có bị lộ ra thì các hacker vẫn không thể thực hiện sql injection được database gây mất mát dữ liệu
# If possible, let's add a little security to this exercise, we will use a network configuration file so that in case the source code is exposed, hackers still cannot perform sql injection.

# Đọc thông tin xác thực từ file cấu hình / Read the configuration file
# with open('config.json') as config_file:
#   config = json.load(config_file)

# Các thông tin trong file cấu hình ( config.json ) / Information in the config file ( config.json ) 
# {
#  "host": "localhost",
#  "user": "root",
#  "password": "211031",
#  "database": "truonghoc1",
# }

# Thiết lập kết nối với cơ sở dữ liệu MySQL / Deploy connection to MySQL database
# conn = mysql.connector.connect(
#    host=config['host'],
#    user=config['user'],
#    password=config['password'],
#    database=config['database']
# )

# ĐÃ HẾT  / END

# Nhập thông tin kết nối trực tiếp
# Enter direct connection information
host = "localhost" # Thông thường nếu cơ sở dữ liệu cũng nằm trên cùng 1 máy thì sẽ là "localhost" / Normally if the database is also on the same machine, it will be "localhost"
user = "root" # Thực hiện lệnh SELECT USER(); sẽ hiện ra <user>@<host> / Execute command SELECT USER(); will pop up <user>@<host>
password = "211031" # Password MySQL của ta / Your MySQL password
database = "truonghoc1"

# Thiết lập kết nối với cơ sở dữ liệu MySQL
# Establish connection to MySQL database
conn = mysql.connector.connect(
    host=host,
    user=user,
    password=password,
    database=database
)

# Tạo con trỏ để thực hiện các truy vấn
# Create a cursor to execute queries
cursor = conn.cursor()

# Chuyển dữ liệu từ tệp CSV vào bảng TRUONG
# Transfer data from csv file to table TRUONG
with open('truong.csv', 'r', encoding='utf-8') as truong_file:
    truong_data = csv.reader(truong_file)
    next(truong_data)  # Bỏ qua dòng tiêu đề
    for row in truong_data:
        matr, tentr, dchitr = row
        query = "INSERT INTO TRUONG VALUES (%s, %s, %s)"
        values = (matr, tentr, dchitr)
        cursor.execute(query, values)

# Chuyển dữ liệu từ tệp CSV vào bảng HS
# Transfer data from csv file to table HS
with open('hs.csv', 'r', encoding='utf-8') as hs_file:
    hs_data = csv.reader(hs_file)
    next(hs_data)  # Bỏ qua dòng tiêu đề
    for row in hs_data:
        mahs, ho, ten, cccd, ntns, dia_chi = row
        query = "INSERT INTO HS VALUES (%s, %s, %s, %s, %s, %s)"
        values = (mahs, ho, ten, cccd, ntns, dia_chi)
        cursor.execute(query, values)

# Chuyển dữ liệu từ tệp CSV vào bảng HOC
# Transfer data from csv file to table HOC
with open('hoc.csv', 'r', encoding='utf-8') as hoc_file:
    hoc_data = csv.reader(hoc_file)
    next(hoc_data)  # Bỏ qua dòng tiêu đề
    for row in hoc_data:
        matr, mahs, namhoc, diemtb, xeploai, ketqua = row
        query = "INSERT IGNORE INTO HOC VALUES (%s, %s, %s, %s, %s, %s)" # INSERT IGNORE để bỏ qua các giá trị trùng ( vì nó phải có ) / INSERT IGNORE to to ignore duplicate values (as it should be)
        values = (matr, mahs, namhoc, diemtb, xeploai, ketqua)
        cursor.execute(query, values)

#Lưu ý cách chuyển dữ liệu như trên sẽ giúp ta tránh được bị SQL injection / Note that transferring data this way may help us preventing SQL Injection

# Lưu các thay đổi vào cơ sở dữ liệu
# Commit changes into the database
conn.commit()

# Đóng kết nối và con trỏ
# CLose connection and the cursor
cursor.close()
conn.close()

# Lưu thời điểm kết thúc
# Save end time
end_time = time.time()

# Tính thời gian chạy
# Calculate running time
execution_time = end_time - start_time

# In ra thời gian chạy
# Print running time
print(f"Đã thực thi xong câu 2, thời gian chạy câu 2 mất: {execution_time} giây = {execution_time / 60} phút")

# Nếu gặp lỗi như thế này trong khi chạy / If you encounter this error while running:
# |raise get_exception(packet)
# |mysql.connector.errors.DatabaseError: 1205(HY000): Lock wait timeoutexceeded; try restartingtransaction

# Ta sẽ thấy lỗi như thế mày nếu nội dung cơ sở dữ liệu mà ta đang cố truy cập 
# You will see this message if database contents you are trying to access 

# đã bị khóa bởi một tiến trình trước đó. MySQL sẽ đợi một khoảng thời gian nhất định để khóa được gỡ bỏ
# has been locked by a previous process.  MySQL will wait a certain amount of time for the lock to be removed

# trước khi từ bỏ và đưa ra lỗi đó.Lúc này, ta có thể fix bằng dùng lệnh "SHOW PROCESSLIST;" để xem các tiến trình đang chặn/ đang ngủ
# before it gives up and throws that error. To fix this, we can use "SHOW PROCESSLIST" to trace out those blocking/sleeping process

# nếu có, ta thực thi lệnh "kill {id}" để kết thúc các tiến trình đó
# Once you locate the blocking/sleep process, find it's id and run "kill{id}" in order to finish the process

# Nếu vẫn còn, ta vào C:\ProgramData\MySQL\MySQL Server 8.0\my.ini hay my.cnf, tìm [mysqld] và thêm cái này ngay dưới:
# IF you stil see the message, we access to this C:\ProgramData\MySQL\MySQL Server 8.0\my.ini or my.cnf, find [mysqld] and add this right under it :

#[mysqld]
#innodb_lock_wait_timeout=120

# Lí do là vì thời gian chờ khóa cho InnoDB mặc định là 50 giây, nếu chờ lâu hơn sẽ dẫn đến lỗi, do đó, ta sẽ tăng giá trị thời gian chờ khóa cho InnoDB bằng cách đặt innodb_lock_wait_timeout,
# The reason for this is because the innodb_lock_wait_timeout, default is 50 sec. IF somethins is longer than that, it will throw an error like before, thus, we  consider increasing the lock wait timeout value 
# for InnoDB
