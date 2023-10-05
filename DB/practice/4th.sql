USE smartfactory;
-- 한 번 use를 쓰면 그 뒤로는 계속 같은 DB사용
-- use를 안쓰면 SELECT * FROM smartfactory.user ~ 로 가능 



SELECT gender, COUNT(name)
FROM user 
GROUP BY gender;

SELECT gender, COUNT(name) AS genderCnt -- 출력하는 열 이름 설정 
FROM user 
GROUP BY gender;



SELECT *
FROM orders;

SELECT SUM(amount)
FROM orders;

SELECT COUNT(DISTINCT orderid) -- null 제외, 중복 제외하고 카운트 
FROM orders;

select custid, count(*) from orders group by custid; -- 고객별 주문 횟수

select custid, sum(amount) from orders group by custid; -- 고객별 주문 상품 개수의 합  

select custid, sum(price * amount) from orders group by custid; -- 고객별 총 주문액 

select prodname, sum(amount) from orders group by prodname; -- 상품별 판매 개수 

-- 주문 금액이 만원 이상인 고객의 주문한 횟수, 주문금액 
select custid, sum(amount), sum(price * amount) 
from orders 
group by custid
having sum(price * amount) >= 10000;

-- order 테이블에서 총 주문 금액이 15000원 이상인 사람의 id와 총 주문 금액 표시(열 이름이 총 주문 금액으로)
select custid, sum(price * amount) as "총 주문 금액"
from orders
group by custid
having sum(price * amount) >= 15000;

-- 과자 이름 기준으로 많이 팔린 순으로 내림차순 정렬, 표시는 과자 이름과 총 판매 개수, 판매 개수가 동일할때는 과자 이름 순으로 오름차순 정렬
select prodname as '과자 이름', sum(amount) as "총 판매 개수" -- 띄어 쓰기를 하려면 따옴표
from orders
group by prodname
order by `총 판매 개수` desc, prodname; -- 별칭으로 하려면 따옴표가 아니라 1옆에 백탭 `



-- join --

show tables;


select *
from customer;

select *
from orders;


-- customer * orders
select *
from customer, orders;


-- inner join
select * -- 여기에서 필요한 열을 검색
from customer
inner join orders on customer.custid = orders.custid; 
select *
from customer, orders
where customer.custid = orders.custid;
select *
from customer, orders
where customer.custid = orders.custid and price = 1500; -- 순서는 상관 없지만 조인과 조건을 where에 같이 적음 





USE codingon;

DROP TABLE IF EXISTS authors;
CREATE TABLE authors (
    author_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(50)
);

DROP TABLE IF EXISTS books;
CREATE TABLE books (
    book_id INT PRIMARY KEY AUTO_INCREMENT,
    author_id INT NOT NULL,
    title VARCHAR(100) NOT NULL,
    publication_date DATE NOT NULL
    -- FOREIGN KEY (author_id) REFERENCES authors(author_id) ON UPDATE CASCADE ON DELETE CASCADE
);

INSERT INTO authors (author_id, first_name, last_name, email) VALUES
	(1, 'J.K.', 'Rowling', 'jkrowling@gmail.com'),
	(2, 'George R.R.', 'Martin', 'grmartin@yahoo.com'),
	(3, 'Stephen', 'King', 'sking@hotmail.com'),
	(5, '아가사', '크리스티', 'agatha.christie@example.com');

INSERT INTO books (title, author_id, publication_date) VALUES 
	('Harry Potter and the Philosopher''s Stone', 1, '1997-06-26'),
    ('A Game of Thrones', 2, '1996-08-06'),
    ('The Shining', 3, '1977-01-28'),
    ('스탠드', 3, '1978-01-01'),
    ('Lucky Day', 4, '2023-03-01');
    
SELECT * FROM codingon.authors;
SELECT * FROM codingon.books;
       
-- 교집합 
select *
from authors
inner join books on authors.author_id = books.author_id;
select *
from authors, books
where authors.author_id = books.author_id;

-- JOIN이 되는 테이블의 데이터 성격과 칼럼명등이 동일해야 하는 제약 조건이 있음
-- 모든칼럼 조회 시(*) NATURAL JOIN 의 기준이 되는 칼럼들이 다른칼럼보다 먼저 출력됨
select * 
from authors
natural join books;

select *
from authors
left outer join books on authors.author_id = books.author_id;

select *
from authors
right outer join books on authors.author_id = books.author_id;

-- 
select *
from authors
union all select author_id from books;

-- Full outer join => left outer + right outer
select authors.author_id, books.title
from authors
left outer join books on authors.author_id = books.author_id
union
select authors.author_id, books.title
from authors
right outer join books on authors.author_id = books.author_id;


-- ----------------------------------------------------------
USE codingon;

DROP TABLE IF EXISTS customers;
CREATE TABLE customers (
    id VARCHAR(50) PRIMARY KEY NOT NULL,
    name VARCHAR(50) NOT NULL,
    email VARCHAR(255) NOT NULL,
    address VARCHAR(255) NOT NULL
);

DROP TABLE IF EXISTS orders;
CREATE TABLE orders (
    id int PRIMARY KEY NOT NULL auto_increment,
    customer_id VARCHAR(50),
    date DATE NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES customers(id) ON UPDATE CASCADE ON DELETE CASCADE 
);

DROP TABLE IF EXISTS order_detail;
CREATE TABLE order_detail (
    order_id INT,
    item VARCHAR(50) NOT NULL,
	quantity INT NOT NULL,
    FOREIGN KEY (order_id) REFERENCES orders(id) ON UPDATE CASCADE ON DELETE CASCADE 
);

INSERT INTO customers (id, name, email, address) VALUES
('john123', 'John Smith', 'john.smith@gmail.com', '123 Main St, Anytown, USA'),
('jane456', 'Jane Doe', 'jane.doe@yahoo.com', '456 Oak Ave, Somewhere'),
('alice789', 'Alice Johnson', 'alice.johnson@hotmail.com', '789 Elm St, Nowhere');

INSERT INTO orders (id, customer_id, date) VALUES
(1, 'john123', '2022-01-01'),
(2, 'john123', '2022-02-01'),
(3, 'jane456', '2022-03-01');

INSERT INTO order_detail (order_id, item, quantity) VALUES
(1, 'pen', 10),
(1, 'toy', 2),
(2, 'clothes', 5),
(3, 'socks', 100);

SELECT * FROM codingon.customers;
SELECT * FROM codingon.orders;
SELECT * FROM codingon.order_detail;

-- orders 테이블에 총 금액(total)컬럼 추가하기 
ALTER TABLE orders ADD total INT;

-- total 값 업데이트 
UPDATE orders SET total = 10000 WHERE id = 1;
UPDATE orders SET total = 15000 WHERE id = 2;
UPDATE orders SET total = 20000 WHERE id = 3;

-- 이름 수정
UPDATE customers SET name = 'John Park' WHERE id = 'john123';

