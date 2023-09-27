USE smartfactory;

-- DDL => 테이블 수정

-- 연습 데이터베이스 생성
DROP TABLE IF EXISTS customer;
CREATE TABLE customer
( custid    CHAR(10) NOT NULL PRIMARY KEY,
  custname  VARCHAR(10) NOT NULL,
  addr      CHAR(10) NOT NULL,
  phone     CHAR(11),
  birth     DATE
);

DROP TABLE IF EXISTS orders;
CREATE TABLE orders
(  orderid   INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
   custid    CHAR(10) NOT NULL,
   prodname  CHAR(6) NOT NULL,
   price     INT  NOT NULL,
   amount    SMALLINT  NOT NULL,
   FOREIGN KEY (custid) REFERENCES customer(custid)
);

DROP TABLE IF EXISTS new_user;
create table new_user
(
	id varchar(10) not null primary key,
	pw varchar(20) not null,
    name varchar(5) not null,
    gender char(1),
    birthday date not null,
    age int not null
);

desc smartfactory.new_user;


-- ALTER TABLE 테이블명 ADD 속성이름 데이터타입; -- 속성 새로 추가하는 경우
-- ALTER TABLE 테이블명 DROP COLUMN 속성이름; -- 기존 속성 삭제하는 경우
-- ALTER TABLE 테이블명 MODIFY 속성이름 데이터타입: -- 기존 속성 수정하는 경우
-- ALTER TABLE 테이블명 RENAME COLUMIN 속성이름 TO 변경속성이름; -- 속성 이름 변경하는 경우

DROP TABLE IF EXISTS memeber;
create table member
(
	id varchar(20) not null primary key,
    name varchar(5) not null,
    age int ,
    gender char(2) not null,
    email varchar(20),
    promotion varchar(2) default 'x'
);
desc smartfactory.member;

ALTER TABLE member MODIFY id varchar(10);
ALTER TABLE member DROP column age;
ALTER TABLE member ADD interest varchar(100);
ALTER TABLE member MODIFY email varchar(50);
ALTER TABLE member MODIFY COLUMN interest varchar(100) not null; -- not null로
ALTER TABLE member MODIFY COLUMN interest varchar(100); -- null 허용으로
DESC smartfactory.member; -- 테이블 구성 출력 

-- --------------------------------------------------------------------------------------
-- DML => 데이터 수정

TRUNCATE TABLE user;
DESC smartfactory.user;
ALTER TABLE user RENAME COLUMN birtth TO birthday; 
INSERT INTO user (id, pw, name, gender, birthday, age) VALUES
	( 'hong1234', '8o4bkg', '홍길동', 'M', '1990-01-31', 33 ),
	( 'sexysung', '87awjkdf', '성춘향', 'F', '1992-03-31', 31 ),
	( 'power70', 'qxur8sda', '변사또', 'M', '1970-05-02', 53 ),
	( 'hanjo', 'jk48fn4', '한조', 'M', '1984-10-18', 39 ),
	( 'dvadva', 'k3f3ah', '송하나', 'F', '1994-06-03', 22 ),
	( 'jungkrat', '4ifha7f', '정크랫', 'M', '1975-11-11', 24 ),
    ( 'widowmaker', '38ewifh3', '위도우', NULL , '1986-06-27', 47 );
SELECT * FROM smartfactory.user; -- 테이블 출력 

UPDATE user SET pw = "songsong" WHERE id = "dvadva"; -- 보통은 PK로 찾지만 어떤 속성이든 상관 없음 
UPDATE user SET name = "핫토리" WHERE id = "hanjo";

-- --------------------------------------------------------------------------------------
-- 외래키 제약 조건 

CREATE TABLE new_customer (
    custid CHAR(10) NOT NULL PRIMARY KEY,
    custname VARCHAR(10) NOT NULL,
    addr CHAR(10) NOT NULL,
    phone CHAR(11),
    birth DATE
);

CREATE TABLE new_orders (
    orderid INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    custid CHAR(10) NOT NULL, 
    prodname CHAR(6) NOT NULL,
    price INT NOT NULL,
    amount smallint NOT NULL,
    FOREIGN KEY (custid) REFERENCES new_customer(custid) ON UPDATE CASCADE ON DELETE CASCADE 
);

-- ON UPDATE CASCADE 부모와 업데이트 동기화
-- ON DELETE CASCADE 부모와 삭제 동기화
-- RESTRICT : 변경 불가
-- SET NULL : 바뀌면 null로 
-- NO ACTION: 상관 없음 

INSERT INTO new_customer VALUES ('kiwi', '김키위', '대한민국 서울', '01012341234', '1990-03-17');
INSERT INTO new_customer VALUES ('apple', '이사과', '대한민국 포항', '01012344321', '1992-06-17');
INSERT INTO new_orders VALUES (NULL, 'kiwi', '프링글스', '3000', 5);
INSERT INTO new_orders VALUES (NULL, 'apple', '프링글스', '3000', 1);
INSERT INTO new_orders VALUES (NULL, 'kiwi', '홈런볼', '2000', 3);

SELECT * FROM smartfactory.new_customer;
SELECT * FROM smartfactory.new_orders;

-- --------------------------------------------------------------------------------------
-- 실습 

INSERT INTO customer VALUES('bunny', '강해린', '대한민국 서울', '01012341234', '2000-02-23');
INSERT INTO customer VALUES('hello', '이지민', '대한민국 포항', '01022221234', '1999-08-08');
INSERT INTO customer VALUES('kiwi', '최지수', '미국 뉴욕', '01050005000', '1990-12-25');
INSERT INTO customer VALUES('imminji01', '강민지', '영국 런던', '01060001000', '1995-01-11');
INSERT INTO customer VALUES('lalala', '홍지수', '미국 로스앤젤레스', '01010109090', '2007-05-16');
INSERT INTO customer VALUES('jjjeee', '홍은정', '대한민국 서울', '01099991111', '2004-08-17');
INSERT INTO customer VALUES('wow123', '이민혁', '일본 삿포로', '01011223344', '1994-05-31');
INSERT INTO customer VALUES('minjipark', '박민지', '프랑스 파리', '01088776655', '1998-04-08');
INSERT INTO customer VALUES('jy9987', '강지연', '일본 삿포로', '01012312323', '1996-09-01');
SELECT * FROM smartfactory.customer;

INSERT INTO orders VALUES(NULL, 'jy9987', '프링글스', 3500, 2);
INSERT INTO orders VALUES(NULL, 'kiwi', '새우깡', 1200, 1);
INSERT INTO orders VALUES(NULL, 'hello', '홈런볼', 4200, 2);
INSERT INTO orders VALUES(NULL, 'minjipark', '맛동산', 2400, 1);
INSERT INTO orders VALUES(NULL, 'bunny', '오감자', 1500, 4);
INSERT INTO orders VALUES(NULL, 'jjjeee', '양파링', 2000, 1);
INSERT INTO orders VALUES(NULL, 'hello', '자갈치', 1300, 2);
INSERT INTO orders VALUES(NULL, 'jjjeee', '감자깡', 1200, 4);
INSERT INTO orders VALUES(NULL, 'bunny', '죠리퐁', 1500, 3);
INSERT INTO orders VALUES(NULL, 'kiwi', '꼬깔콘', 1700, 2);
INSERT INTO orders VALUES(NULL, 'hello', '버터링', 4000, 2);
INSERT INTO orders VALUES(NULL, 'minjipark', '칙촉', 4000, 1);
INSERT INTO orders VALUES(NULL, 'wow123', '콘초', 1700, 3);
INSERT INTO orders VALUES(NULL, 'imminji01', '꼬북칩', 2000, 2);
INSERT INTO orders VALUES(NULL, 'bunny', '썬칩', 1800, 5);
INSERT INTO orders VALUES(NULL, 'kiwi', '고구마깡', 1300, 3);
INSERT INTO orders VALUES(NULL, 'jy9987', '오징어집', 1700, 5);
INSERT INTO orders VALUES(NULL, 'jjjeee', '바나나킥', 2000, 4);
INSERT INTO orders VALUES(NULL, 'imminji01', '초코파이', 5000, 2);
SELECT * FROM smartfactory.orders;

TRUNCATE TABLE user;
INSERT INTO user( id, pw, name, gender, birthday, age ) VALUES( 'hong1234', '8o4bkg', '홍길동', 'M', '1990-01-31', 33 );
INSERT INTO user( id, pw, name, gender, birthday, age ) VALUES( 'sexysung', '87awjkdf', '성춘향', 'F', '1992-03-31', 31 );
INSERT INTO user( id, pw, name, gender, birthday, age ) VALUES( 'power70', 'qxur8sda', '변사또', 'M', '1970-05-02', 53 );
INSERT INTO user( id, pw, name, gender, birthday, age ) VALUES( 'hanjo', 'jk48fn4', '한조', 'M', '1984-10-18', 39 );
INSERT INTO user( id, pw, name, birthday, age ) VALUES( 'widowmaker', '38ewifh3', '위도우', '1986-06-27', 47 );
INSERT INTO user( id, pw, name, gender, birthday, age ) VALUES( 'dvadva', 'k3f3ah', '송하나', 'F', '1994-06-03', 22 );
INSERT INTO user( id, pw, name, gender, birthday, age ) VALUES( 'jungkrat', '4ifha7f', '정크랫', 'M', '1975-11-11', 24 );
SELECT * FROM smartfactory.user;

-- 1
select *
from user
order by birthday asc;

-- 2
select *
from user
where gender = "M"
order by name desc;

-- 3
select id, name
from user
where birthday like("199%");

-- 4
select *
from user
where birthday like("%-06-%")
order by birthday asc;

-- 5 
select *
from user
where gender = "M" and birthday like("197%");

-- 6
select *
from user
order by age desc
limit 2;

-- 7 
select *
from user
where age > 24 and age < 51;


