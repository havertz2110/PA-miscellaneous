# Khai báo các thư viện cần thiết / Declare necessary libraries
import glob
import xml.etree.ElementTree as ET
from tabulate import tabulate

def doc_file_xml(file):
    # Đọc và phân tích cú pháp tệp XML / Read and analayse the XML file's syntax
    tree = ET.parse(file)
    root = tree.getroot()

    # Người dùng nhập thông tin như đề yêu cầu / User input like requirements
    nguong_diem_thap = float(input("Nhập ngưỡng điểm thấp: "))
    nguong_diem_cao = float(input("Nhập ngưỡng điểm cao: "))

    table = []
    
    # Duyệt qua từng phần tử 'student' trong tệp XML / Iterating over each 'student' element in the XML file
    for student in root.findall('.//student'):
        # Lấy họ tên và điểm trung bình từ phần tử / Take fullname and CGPA from elements
        ho_ten = student.find('ho_ten').text
        diem_tb = float(student.find('diem_tb').text)
       
        # Kiểm tra xem điểm trung bình có nằm trong ngưỡng cho trước hay không / Check the CGPA if it is in the provided area or not
        if nguong_diem_thap <= diem_tb <= nguong_diem_cao:
            #Thêm họ tên và điểm trung bình vào bảng / Add fullname and respective CGPA into the table
            table.append([ho_ten, diem_tb])
    # Định nghĩa tiêu đề cho biểu đồ / Defining the headers for the table
    headers = ["Họ tên", "Điểm TB"]

    # In kết quả ra 1 bảng đã được định dạng / Printing the results in a formatted table
    print(tabulate(table, headers, tablefmt="fancy_grid"))

def main():
    # Lấy danh sách các tệp XML trong thư mục hiện tại / Get the list of XML files in the current directory
    files = glob.glob("*.xml")
    
    # Kiểm tra xem có tệp XML nào hay không / Check if there is any XML files
    if not files:
        print("Không tìm thấy file XML trong thư mục.")
        return

    # Xuất ra danh sách các file XML có sẵn / Print a list of available XML files
    print("Danh sách các file XML:")
    for i, file in enumerate(files):
        print(f"{i+1}. {file}")
    
    # Yêu cầu người dùng chọn số thứ tự của tệp XML để đọc / Ask the user to select the sequence number of the XML file to read
    file_chon = int(input("Chọn số thứ tự của file cần đọc: "))

    # Kiểm tra xem số thứ tự có hợp lệ không / Check if the sequence number is valid
    if 1 <= file_chon <= len(files):
        file_duoc_chon = files[file_chon - 1]
        doc_file_xml(file_duoc_chon)
    else:
        print("Số thứ tự không hợp lệ.")

if __name__ == '__main__':
    main()
