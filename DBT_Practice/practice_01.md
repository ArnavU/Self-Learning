```sql
SELECT
    o.snum
    , (SELECT DISTINCT sname FROM salespeople WHERE snum = o.snum) AS name
    , SUM(o.amt) AS total_amount
FROM
    Orders AS o
INNER JOIN
    Salespeople AS s
ON
    o.snum = s.snum
GROUP BY
    o.snum;


-- customers who have never placed any orders
SELECT
    *
FROM
    Customers AS c
LEFT JOIN
    Orders AS o
ON
    c.cnum = o.cnum
WHERE
    o.cnum IS NULL;

-- procedure to take snum and return out param -> sname, orders, total_amt
drop procedure if exists sp_getSalesPersonDetails;
DELIMITER $$
CREATE PROCEDURE sp_getSalesPersonDetails(p_snum INT, OUT p_sname VARCHAR(40), OUT p_total_amt DOUBLE)
BEGIN
    SELECT 
        SUM(o.amt) 
        , sname
    INTO
        p_total_amt
        , p_sname
    FROM
        salespeople AS sp
    INNER JOIN
        orders AS o
    ON
        sp.snum = o.snum
    WHERE
        o.snum = p_snum
    GROUP BY
        o.snum, sp.sname
    LIMIT 1;
END $$
DELIMITER ;
CALL sp_getSalesPersonDetails(1007, @sname1, @total1);
SELECT 2001 AS cnum, @sname1 AS sname, @total1 AS total;

-- trigger 
DROP TRIGGER IF EXISTS order_update_trig;
DELIMITER $$
CREATE TRIGGER order_update_trig
BEFORE INSERT ON orders
FOR EACH ROW
BEGIN
    IF NEW.amt < 100 THEN 
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Order amount less than 100 cannot be inserted';
    END IF;
END $$
DELIMITER ;
INSERT INTO orders values (3015, 100, '2026-09-13', 2006, 1001); 

-- function to add two numbers
DROP FUNCTION IF EXISTS fn_add;

DELIMITER $$
CREATE FUNCTION fn_add(p_num1 INT, p_num2 INT)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_res INT;
    SET v_res = IFNULL(p_num1, 0) + IFNULL(p_num2, 0);
    RETURN v_res;
END;
$$
DELIMITER ;
SELECT fn_add(22, 7);
SELECT fn_add(22, NULL);
SELECT fn_add(NULL, NULL);
```