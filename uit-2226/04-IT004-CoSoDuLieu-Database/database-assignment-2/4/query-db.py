# Khai báo các thư viện cần thiết / Declare necessary libraries
import mysql.connector
import xml.etree.ElementTree as ET
import time
from tabulate import tabulate

def query_database():
    # Người dùng nhập thông tin / User input
    input_str = input("Nhập tên cơ sở dữ liệu, tên trường, năm học, xếp hạng học tập (cách nhau bằng dấu phẩy): ")

    # Tách chuỗi nhập vào thành các phần tử riêng biệt / Splitting the input string into separate elements
    inputs = input_str.split(",")

    # Gán giá trị cho các biến tương ứng / Assigning values to respective variables
    database_name = inputs[0].strip()
    ten_truong = inputs[1].strip()
    nam_hoc = inputs[2].strip()
    xep_loai = inputs[3].strip()

    # Thiết lập tên cơ sở dữ liệu dựa trên giá trị nhập vào /Establish database name based on the input
    if database_name == "truonghoc1":
        database = "truonghoc1"
    elif database_name == "truonghoc2":
        database = "truonghoc1"
    else:
        print("Tên cơ sở dữ liệu không hợp lệ.")
        return

    # Thiết lập kết nối với cơ sở dữ liệu MySQL / Establishing a connection with the MySQL database
    conn = mysql.connector.connect(
        host="localhost",
        user="root",
        password="211031",
        database=database
    )

    # Tạo con trỏ để thực hiện các truy vấn / Creating a cursor to perform queries
    cursor = conn.cursor()

    # Đo thời gian thực hiện truy vấn / Measuring query execution time
    start_time = time.time()

    # Truy vấn dữ liệu từ cơ sở dữ liệu /  Querying data from the database
    query = f"""
            SELECT hs.ho, hs.ten, hs.ntns, hoc.diemtb, hoc.xeploai, hoc.kqua
    	    FROM truong
    	    JOIN hoc ON truong.matr = hoc.matr
    	    JOIN hs ON hoc.mahs = hs.mahs
    	    WHERE truong.tentr = '{ten_truong}' AND hoc.namhoc = '{nam_hoc}' AND hoc.xeploai = '{xep_loai}';
        """
    cursor.execute(query)
    results = cursor.fetchall()

    # Tính thời gian truy vấn/ Calculating query time
    end_time = time.time()
    query_time = end_time - start_time

    #  Tạo biểu đồ để hiển thị kết quả truy vấn / Creating a table representation of the query results
    table = []

    #  Lặp qua từng dòng trong kết quả / Iterating over each row in the results
    for row in results:
        # Kết hợp cột đầu tiên và cột thứ hai để tạo họ tên đầy đủ / Combining the first and second columns to form the full name
        full_name = f"{row[0]} {row[1]}"
        # Thêm một dòng mới vào biểu đồ với các cột mong muốn / Appending a new row to the table with the desired columns
        table.append([full_name, row[2], row[3], row[4], row[5]])

    # Định nghĩa tiêu đề cho biểu đồ / Defining the headers for the table
    headers = ["Họ tên", "NTNS", "Điểm TB", "Xếp loại", "Kết quả"]
    
    # In kết quả ra 1 bảng đã được định dạng / Printing the results in a formatted table
    print(tabulate(table, headers, tablefmt="fancy_grid"))
    print(f"Thời gian truy vấn: {query_time} giây")
   
    # Tạo và xuất file XML / Creating and exporting an XML file
    xml_root = ET.Element("students")
    for row in results:
        full_name = f"{row[0]} {row[1]}"
        student_element = ET.SubElement(xml_root, "student")
        ET.SubElement(student_element, "ho_ten").text = full_name
        ET.SubElement(student_element, "ntns").text = row[2]
        ET.SubElement(student_element, "diem_tb").text = str(row[3])
        ET.SubElement(student_element, "xep_loai").text = row[4]
        ET.SubElement(student_element, "ket_qua").text = row[5]

    xml_tree = ET.ElementTree(xml_root)
    xml_filename = f"{database_name}-{ten_truong}-{nam_hoc}-{xep_loai}.xml"
    xml_tree.write(xml_filename)

    # Đóng kết nối cơ sở dữ liệu / Closing the database connection
    conn.close()


# Sử dụng hàm truy vấn cơ sở dữ liệu / Using the query_database function
query_database()
