drop database if exists TRUONGHOC1;

-- tạo cơ sở dữ liệu TRUONGHOC1 / create database TRUONGHOC1
create database TRUONGHOC1;


--  dùng csdl TRUONGHOC1 / use database TRUONGHOC1
USE TRUONGHOC1;


-- tạo bảng TRUONG / Create table TRUONG
drop table if exists truong;
CREATE TABLE TRUONG (
    -- vì format sẽ là 000,001,... / because the format would be 000,001,...
    MATR CHAR(3) PRIMARY KEY, 
    -- vì format sẽ là cả cái tên trường nên ta sẽ cấp phát 128 varchar / because the format would be the entire school name so we should let it as 128 varchar
    TENTR VARCHAR(128) NOT NULL,
     -- vì format sẽ là cả cái địa chỉ trường nên ta sẽ cấp phát 256 varchar / because the format would be the entire school address so we should let it as 256 varchar
    DCHITR VARCHAR(256) default NULL
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;



-- tạo bảng HS / Create table HS
drop tables if exists hs;
CREATE TABLE HS (
    -- vì format sẽ là HS0000000 ( từ 0 đến 1 tr ) / because the format would be HS0000000 ( from 0 to a million )
    MAHS char(9) PRIMARY KEY,  
    -- vì các họ và tên cũng ngắn nên ta cấp 128 là vừa đủ nếu không muốn nói là dư / because the surname and names are pretty short so I think 128 is alright
    HO VARCHAR(64) NOT NULL,
    TEN VARCHAR(128) NOT NULL,
    -- cccd sẽ là có format M/F000000 ( nam/nữ,  M: 0 -> 500000 và F: 500001 ->1tr)  / the id number's format would be M/F000000 ( Male: 0->500000/Female:500001->1 million )
    CCCD VARCHAR(12),
    -- ta để kiểu char luôn thay vì date để tránh bị các lỗi vặt / let it as char so it wont cause errors
    NTNS varchar(12) NOT NULL,
    DCHI_HS VARCHAR(256) NOT NULL,
    CONSTRAINT UQ_HS_CCCD UNIQUE (CCCD)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;




drop table if exists hoc;
-- tạo bảng HOC / Create table HOC
CREATE TABLE HOC (
    MATR char(3), 
    MAHS char(9),
    -- vì format sẽ là 2019-2020,... nên vừa đủ 9 / because the format would be 2019-2020 so 9 is enough
    NAMHOC char(9),
    -- format: x,00
    DIEMTB char(4) NOT NULL,
    -- format: giỏi, khá, trung bình,... nên như vậy là đủ / format: giỏi, khá, trung bình,... so it is enough
    XEPLOAI varchar(32) NOT NULL,
    -- format: hoàn thành, chưa hoàn thành
    KQUA varchar(32) NOT NULL,
    PRIMARY KEY (MATR, MAHS, NAMHOC),
    FOREIGN KEY (MATR) REFERENCES TRUONG (MATR),
    FOREIGN KEY (MAHS) REFERENCES HS (MAHS)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


