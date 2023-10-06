USE codingon;


-- 서브쿼리
select max(price * amount) from orders;

select orderid, custid, prodname 
from orders 
where price * amount = 10000;

select orderid, custid, prodname 
from orders
where price * amount = (select max(price * amount) from orders);
    
SELECT custid 
from orders; -- orders 테이블에 주문이력 있는 고객

select custname 
from customer 
where custid IN (SELECT custid from orders);


-- --------------------------------------------------------------------
-- 실습

-- 1. 2022-01-01 ~ 2022-02-01 기간동안 주문한 고객의 아이디를 중복 없이 가져오기
SELECT DISTINCT customer_id 
FROM orders 
WHERE date >= '2022-01-01' AND date <= '2022-02-01'; -- string 타입이 아니라 date타입이라 가능함

-- 2. 2022-01-01 ~ 2022-02-01 기간동안 주문한 고객의 이름 중복 없이 가져오기 (서브쿼리)
SELECT DISTINCT name
FROM customers
WHERE id = (SELECT DISTINCT customer_id FROM orders WHERE date >= '2022-01-01' AND date <= '2022-02-01');

-- 3. 총 금액이 가장 높은 데이터 가져오기 (MAX 함수 사용하지 않고)
SELECT total
FROM orders
ORDER BY total DESC
LIMIT 1;

-- 4. 총 금액이 가장 높은 데이터 가져오기(MAX 함수 사용해서)
SELECT MAX(total)
FROM orders;

-- 5. 각각의 customer가 몇 개의 주문을 했는지 검색하기
SELECT customer_id, COUNT(*) -- 주문 횟수
FROM orders
GROUP BY customer_id;


select orders.customer_id, sum(quantity) as total_quantity -- 주문 물품 갯수 
from orders, order_detail
WHERE orders.id = order_detail.order_id 
group by customer_id;

select o.customer_id as "사용자아이디"  ,sum(od.quantity) as "주문갯수"
from orders o ,order_detail od
where o.id = od.order_id
group by o.customer_id;
-- 6. 21000원 이상 결제한 고객의 총 금액 total_price로 가져오기
SELECT customer_id, SUM(total) as total_price
FROM orders
GROUP BY customer_id
HAVING `total_price` >= 21000;

-- 7. 각 주문 정보에 대해 고객 정보와 주문 정보를 함께 가져오기
SELECT * -- orders + customers
FROM orders, customers
WHERE orders.customer_id = customers.id;

SELECT order_detail.*, customers.* -- order_detail + customers
FROM  order_detail, orders, customers
WHERE order_detail.order_id = orders.id AND orders.customer_id = customers.id
ORDER BY order_detail.order_id;

-- 8. 주문을 하지 않은 고객 정보도 가져오기
SELECT *
FROM orders
LEFT OUTER JOIN customers ON orders.customer_id = customers.id
UNION
SELECT *
FROM orders
RIGHT OUTER JOIN customers ON orders.customer_id = customers.id;

SELECT *
FROM orders
RIGHT OUTER JOIN customers ON orders.customer_id = customers.id;





-- -------------------------마지막 연습-----------------------------------

/*
Table 1: employees
Columns: employee_id (PK), first_name, last_name, email, phone_number, hire_date, job_id(FK), salary, commission_pct, manager_id(FK), department_id(FK)

Table 2: jobs
Columns: job_id (PK), job_title, min_salary, max_salary

Table 3: departments
Columns: department_id (PK), department_name, manager_id, location_id
*/
DROP DATABASE IF EXISTS final;
CREATE DATABASE final CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci;
USE final;

/*
참고) DECIMAL(M, D) 자료형
https://velog.io/@dlawogus/MySQL-DataTypes-DECIMAL
*/

DROP TABLE IF EXISTS jobs;
CREATE TABLE jobs(
job_id INT PRIMARY KEY NOT NULL auto_increment,
job_title VARCHAR(20),
min_salary DECIMAL(8, 2),
max_salary DECIMAL(9, 2)
);
INSERT INTO jobs VALUES
  (1, 'Manager', 80000.00, 120000.00),
  (2, 'Developer', 60000.00, 100000.00),
  (3, 'Designer', 50000.00, 90000.00),
  (4, 'Salesperson', 40000.00, 80000.00),
  (5, 'Accountant', 50000.00, 100000.00);

DROP TABLE IF EXISTS departments;
CREATE TABLE departments(
department_id INT PRIMARY KEY NOT NULL auto_increment,
department_name VARCHAR(20),
manager_id INT UNIQUE,
location_id VARCHAR(20)
);
INSERT INTO departments VALUES
(1, 'Engineering', 3, 'New York'),
(2, 'Sales', 5, 'Los Angeles'),
(3, 'Marketing', 7, 'Chicago'),
(4, 'Accounting', 8, 'Houston'),
(5, 'IT', 10, 'San Francisco');

DROP TABLE IF EXISTS employees;
CREATE TABLE employees(
employee_id INT PRIMARY KEY NOT NULL auto_increment,
first_name VARCHAR(20),
last_name VARCHAR(20),
email VARCHAR(50),
phone_number VARCHAR(20),
hire_date DATE,
job_id INT,
salary DECIMAL(9, 2),
commission_pct DECIMAL(3, 2),
manager_id INT,
department_id INT,
FOREIGN KEY (job_id) REFERENCES jobs(job_id) ON UPDATE CASCADE ON DELETE CASCADE,
FOREIGN KEY (manager_id) REFERENCES departments(manager_id) ON UPDATE CASCADE ON DELETE CASCADE,
FOREIGN KEY (department_id) REFERENCES departments(department_id) ON UPDATE CASCADE ON DELETE CASCADE
);
INSERT INTO employees VALUES
  (1, 'John', 'Doe', 'johndoe@example.com', '555-1234', '2021-01-01', 1, 100000.00, 0.05, 3, 1),
  (2, 'Jane', 'Smith', 'janesmith@example.com', '555-5678', '2021-02-01', 2, 80000.00, NULL, 3, 1),
  (3, 'Bob', 'Johnson', 'bobjohnson@example.com', '555-9012', '2021-03-01', 1, 90000.00, 0.02, 5, 2),
  (4, 'Alice', 'Williams', 'alicewilliams@example.com', '555-3456', '2021-04-01', 3, 70000.00, NULL, 5, 2),
  (5, 'Mike', 'Brown', 'mikebrown@example.com', '555-7890', '2021-05-01', 4, 120000.00, 0.08, NULL, 3),
  (6, 'Sara', 'Lee', 'saralee@example.com', '555-2345', '2021-06-01', 4, 75000.00, NULL, 7, 4),
  (7, 'Tom', 'Jackson', 'tomjackson@example.com', '555-6789', '2021-07-01', 5, 110000.00, 0.03, NULL, 4),
  (8, 'Karen', 'Davis', 'karendavis@example.com', '555-1234', '2021-08-01', 5, 95000.00, NULL, 7, 4),
  (9, 'David', 'Miller', 'davidmiller@example.com', '555-5678', '2021-09-01', 2, 85000.00, NULL, 10, 5),
  (10, 'Lisa', 'Wilson', 'lisawilson@example.com', '555-9012', '2021-10-01', 1, 110000.00, 0.06, NULL, 5);

-- < 실습 문제 >
-- 1. IT 부서에서 일하는 모든 직원을 반환하는 쿼리를 작성합니다.
SELECT *
FROM employees
WHERE department_id = 5;


-- 2. 각 부서의 총 직원 수를 반환하는 쿼리를 작성합니다.
-- (department_id, num_employees)
SELECT department_id, COUNT(department_id) as num_employees
FROM employees
GROUP BY department_id;

-- 3. $80,000 이상의 급여를 받는 모든 직원의 이름을 반환하는 쿼리를 작성합니다.
-- (first_name, last_name, salary)
SELECT first_name, last_name, salary
FROM employees
WHERE salary >= 80000;

-- 4. 영업부에서 근무하며 $50,000 이상의 급여를 받는 모든 직원의 이름과 급여를 반환하는 쿼리를 작성합니다.
-- (first_name, last_name, salary)
SELECT first_name, last_name, salary
FROM employees
WHERE salary >= 50000 AND department_id = 2;


-- 5. 직함과 직함별 평균 급여를 반환하는 조회를 작성합니다.
-- (job_id, avg_salary)
SELECT job_id, AVG(salary) as avg_salary
FROM employees
GROUP BY job_id;

-- 6. 모든 직원들에 대한 직책과 최대 급여를 반환하는 조회를 작성합니다.
-- (job_title, max_salary)
SELECT job_title, MAX(salary) as max_salary
FROM employees
LEFT JOIN jobs on employees.job_id = jobs.job_id
GROUP BY job_title;

-- 7. 가장 높은 연봉을 받는 직원 상위 10명의 이름과 급여를 반환하는 쿼리를 작성합니다.
-- (first_name, last_name, salary)
SELECT first_name, last_name, salary
FROM employees
ORDER BY salary DESC
LIMIT 10;

-- 8. 최저임금을 받는 하위 5명의 직원들의 이름과 급여를 반환하는 쿼리를 작성하세요.
-- (first_name, last_name, salary)
SELECT first_name, last_name, salary
FROM employees
ORDER BY salary
LIMIT 5;

-- 9. 관리자와 동일한 직함을 가진 모든 직원의 이름을 반환하는 쿼리를 작성합니다.
-- 직원(employee_id)과 상사/관리자(manager_id) 의 job_id 가 일치하는 sql문 작성해라 
-- 힌트) 셀프 조인!! 
-- (first_name, last_name)
SELECT em2.first_name as first_name, em2.last_name as last_name
FROM employees as em1
JOIN employees as em2 ON em1.employee_id = em2.manager_id
WHERE em1.job_id = em2.job_id;

-- 10. 2021년에 채용된 모든 직원의 이름을 반환하는 쿼리를 작성합니다.
-- (first_name, last_name, hire_date)
SELECT first_name, last_name, hire_date
FROM employees
-- WHERE hire_date LIKE ('2021%');
-- WHERE YEAR(hire_date) LIKE 2021;
WHERE YEAR(hire_date) = 2021;

-- 11. 수수료를 받는 모든 직원의 이름과 급여를 반환하는 쿼리를 작성합니다.
-- (first_name, last_name, salary, commission_pct)
SELECT first_name, last_name, salary, commission_pct
FROM employees
WHERE commission_pct IS NOT NULL;

-- 12. 수수료를 받지 않는 모든 직원의 이름과 급여를 반환하는 쿼리를 작성합니다.
-- (first_name, last_name, salary, commission_pct)
SELECT first_name, last_name, salary, commission_pct
FROM employees
WHERE commission_pct IS NULL;

-- 13. 관리자보다 먼저 고용된 모든 직원의 이름을 반환하는 쿼리를 작성합니다.
SELECT em2.first_name as first_name, em2.last_name as last_name
FROM employees as em1
JOIN employees as em2 ON em1.employee_id = em2.manager_id
WHERE em1.hire_date > em2.hire_date;

-- 14. 관리자보다 높은 수수료를 받는 직원의 이름과 급여를 반환하는 쿼리를 작성합니다.
SELECT em2.first_name as first_name, em2.last_name as last_name
FROM employees as em1
JOIN employees as em2 ON em1.employee_id = em2.manager_id
WHERE em1.commission_pct < em2.commission_pct;