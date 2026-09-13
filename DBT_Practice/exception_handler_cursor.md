## SPM WITH ERROR HANDLING
```sql
-- Practice 1) sp to add deptno, deptname and location to table (EXIT HANDLER)
DELIMITER $$ 
CREATE PROCEDURE sp_add_dept(p_deptno INT, p_dept_name VARCHAR(40), p_loc VARCHAR(40))
BEGIN
    DECLARE EXIT HANDLER FOR 1062 -- declare error handler
    BEGIN
        SELECT 'Dept add failed.' AS msg;
    END;
    INSERT INTO dept VALUES(p_deptno, p_dept_name, p_loc);
    SELECT 'Dept added successfully.' AS msg;
END $$
DELIMITER ;
CALL sp_add_dept(99, 'Software dept', 'Wardha');
SELECT * FROM dept;

-- Practice 2) sp to delete dept from dept table (EXIT HANDLER)
DELIMITER $$ 
CREATE PROCEDURE sp_delete_dept(p_deptno INT) 
BEGIN
    DECLARE EXIT HANDLER FOR SQLEXCEPTION 
    BEGIN
        SELECT 'Unable to delete dept.' AS msg;
    END;
    DELETE FROM dept WHERE deptno = p_deptno;
    SELECT 'Deletion successful.';
END $$
DELIMITER ;
CALL sp_delete_dept(99);
SELECT * FROM dept;

-- Practice 3) sp to insert deptno, deptname, location in emp table (CONTINUE HANDLER)
DELIMITER $$
CREATE PROCEDURE sp_add_dept2(p_deptno INT, p_deptname VARCHAR(40), p_loc VARCHAR(40))
BEGIN
    DECLARE v_err INT DEFAULT 0;
    DECLARE CONTINUE HANDLER FOR 1062
    BEGIN
        GET DIAGNOSTICS CONDITION 1
            @msg = MESSAGE_TEXT;
        SET v_err = 1;
        SELECT 'Continue handler in work' AS msg;
        SELECT @msg AS msg;
    END;
    INSERT INTO dept VALUES (p_deptno, p_deptname, p_loc);
    IF v_err = 1 THEN
        SELECT 'Insertion failed' AS msg;
    ELSE
        SELECT 'Insertion successful' AS msg;
    END IF;
END $$
DELIMITER ;
CALL sp_add_dept2(99, 'SDE 1', 'Pune');

DELIMITER $$ 
CREATE PROCEDURE sp_delete_dept2(p_deptno INT)
BEGIN
    DECLARE v_err INT DEFAULT 0;
    DECLARE CONTINUE HANDLER FOR SQLEXCEPTION
    BEGIN
        GET DIAGNOSTICS CONDITION 1
            @msg = MESSAGE_TEXT;
        SET v_err = 1;
        SELECT CONCAT('Deletion failed! ERR: ', @msg) AS msg;
    END;
    DELETE FROM dept WHERE deptno = p_deptno;
    IF v_err = 0 THEN
        SELECT 'Deletion successful' AS msg;
    ELSE 
        SELECT 'Deletion Failed' AS msg;
    END IF;
END $$
DELIMITER ;
CALL sp_delete_dept2(99);


-- Practice 4) use cursor to put the department info into results table
CREATE TABLE results (
    deptno INT PRIMARY KEY,
    dname VARCHAR(40),
    loc VARCHAR(40)
);

DELIMITER $$
CREATE PROCEDURE sp_cursor()
BEGIN
    DECLARE v_eoc INT DEFAULT 0;
    DECLARE v_deptno INT;
    DECLARE v_dname VARCHAR(20);
    DECLARE v_loc VARCHAR(20);
    DECLARE v_cur CURSOR FOR SELECT * FROM dept;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_eoc = 1;
    OPEN v_cur;
    curProcess: LOOP
        FETCH v_cur INTO v_deptno, v_dname, v_loc;

        IF v_eoc = 1 THEN
            LEAVE curProcess;
        END IF;

        INSERT INTO results VALUES(v_deptno, LOWER(v_dname), LOWER(v_loc));
    END LOOP;
    CLOSE v_cur;
END $$
DELIMITER ;
CALL sp_cursor();
SELECT * FROM RESULTS;

-- Practice 5) Compare rows of t1 & t2 and write the max into results table with ascii value.

DROP TABLE IF EXISTS results;
CREATE TABLE results (
    v1 VARCHAR(2)
);

CREATE TABLE t1 (c1 VARCHAR(2));
CREATE TABLE t2 (c2 VARCHAR(2));

INSERT INTO t1 VALUES ('A'), ('B'), ('C'), ('D');
INSERT INTO t2 VALUES ('B'), ('X'), ('X'), ('Y');

DELIMITER $$
CREATE PROCEDURE sp_copy_max()
BEGIN
    DECLARE v_eoc INT DEFAULT 0;
    DECLARE var1 VARCHAR(2);
    DECLARE var2 VARCHAR(2);
    DECLARE v_cur1 CURSOR FOR SELECT * FROM t1;
    DECLARE v_cur2 CURSOR FOR SELECT * FROM t2;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_eoc = 1;
    OPEN v_cur1;
    OPEN v_cur2;
    copyLoop : LOOP
        FETCH v_cur1 INTO var1;
        FETCH v_cur2 INTO var2;

        IF v_eoc = 1 THEN
            LEAVE copyLoop;
        END IF;

        IF var1 > var2 THEN
            INSERT INTO results VALUES (var1);
        ELSE
            INSERT INTO results VALUES (var2);
        END IF;
    END LOOP;
    CLOSE v_cur2;
    CLOSE v_cur1;
END $$
DELIMITER ;

CALL sp_copy_max();
SELECT * FROM results;

-- Practice 6) indexing
CREATE INDEX idx_books_name ON books(name);
CREATE UNIQUE idx_book

```SELECT
    o.snum
    , (SELECT sname FROM salespeople WHERE s.snum = o.snum) AS name
    , SUM(o.amt) AS total_amount
FROM
    Orders AS o
INNER JOIN
    Salespeople AS s
ON
    o.snum = s.snum
GROUP BY
    o.snum;