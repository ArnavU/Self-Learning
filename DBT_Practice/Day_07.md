# Database Technologies

### Exception Handling
* Exception -- Runtime problems/errors.
    ```SQL
    DROP TABLE random_name;
    -- ERROR 1051 (42S02): Unknown table 'db.random_name'

    INSERT INTO books(id, name) VALUES (4001, 'SQL Book');
    -- ERROR 1062 (23000): Duplicate entry '4001' for key 'books.PRIMARY'

    DROP DATABASE performance_schema;
    -- ERROR 1044 (42000): Access denied for user 'kd0_12345_nilesh'@'localhost'
    ```
* Exception Handling -- Take action upon error.
* When error occurs, handler will be executed (if implemented).
* Exception handler types/actions
    - EXIT handler: after execution of handler, the program stops. Next line not executed.
    - CONTINUE handler: after execution of handler, the next line after the error is executed.
* Two ways to implement exception handler
    - Single Liner
    - Multi Liner PSM block --> BEGIN ... END
* Handler syntax
    ```SQL
    DECLARE action HANDLER FOR condition handler_implementation;
    -- action = EXIT or CONTINUE
    -- condition = Error code or Error alias
        -- https://dev.mysql.com/doc/mysql-errors/8.0/en/server-error-reference.html
    -- handler_implementation = Single liner or BEGIN ... END
    ```
* Prep for the demos
    ```SQL
    ALTER TABLE dept ADD PRIMARY KEY(deptno);

    DESCRIBE dept;

    SELECT * FROM dept;
    ```
* Example 1: EXIT handler
    ```SQL
    DELIMITER $$

    CREATE PROCEDURE sp_add_dept1(p_deptno INT, p_dname VARCHAR(40), p_loc VARCHAR(40))
    BEGIN
        -- declare the error handler
        DECLARE EXIT HANDLER FOR 1062
        BEGIN
            SELECT 'Dept add failed.' AS msg;
        END;
        -- perform operations
        INSERT INTO dept VALUES(p_deptno, p_dname, p_loc);
        SELECT 'Dept added successfully.' AS msg;
    END;
    $$

    DELIMITER ;
    ```

    ```SQL
    SELECT * FROM dept; -- 10, 20, 30 present

    CALL sp_add_dept1(40, 'OPERATIONS', 'BOSTON'); -- okay (success msg)

    CALL sp_add_dept1(10, 'ACC', 'MARS'); -- error: primary key (failure msg)
    ```
* Example 2: CONTINE handler
    ```SQL
    DELIMITER $$

    CREATE PROCEDURE sp_add_dept2(p_deptno INT, p_dname VARCHAR(30), p_loc VARCHAR(30))
    BEGIN
        DECLARE v_err INT DEFAULT 0;
        -- declare the error handler
        DECLARE CONTINUE HANDLER FOR 1062 SET v_err = 1; 
        -- perform operations
        INSERT INTO dept VALUES(p_deptno, p_dname, p_loc);
        IF v_err = 1 THEN
            SELECT 'Dept add failed' AS msg;
        ELSE
            SELECT 'Dept added successfully' AS msg;
        END IF;
    END;
    $$

    DELIMITER ;
    ```

    ```SQL
    CALL sp_add_dept2(50, 'TRAINING', 'PUNE');

    CALL sp_add_dept2(50, 'TRAINING', 'MUMBAI'); -- error
    ```
* Example 3: Error Alias
    ```SQL
    DELIMITER $$

    CREATE PROCEDURE sp_add_dept3(p_deptno INT, p_dname VARCHAR(30), p_loc VARCHAR(30))
    BEGIN
        DECLARE v_err INT DEFAULT 0;
        -- declare error alias
        DECLARE DUP_KEY_ERROR CONDITION FOR 1062;
        -- declare the error handler
        DECLARE CONTINUE HANDLER FOR DUP_KEY_ERROR SET v_err = 1; 
        -- perform operations
        INSERT INTO dept VALUES(p_deptno, p_dname, p_loc);
        IF v_err = 1 THEN
            SELECT 'Dept add failed' AS msg;
        ELSE
            SELECT 'Dept added successfully' AS msg;
        END IF;
    END;
    $$

    DELIMITER ;
    ```
    ```SQL
    CALL sp_add_dept3(50, 'TRAINING', 'MUMBAI'); -- error
    ```
* Example 4: Generic Exception Handler
    * `SQLEXCEPTION` represents any sql error -- generic exception handling
    ```SQL
    DELIMITER $$

    CREATE PROCEDURE sp_add_dept4(p_deptno INT, p_dname VARCHAR(50), p_loc VARCHAR(50))
    BEGIN
        DECLARE v_err INT DEFAULT 0;
        -- declare the error handler
        DECLARE CONTINUE HANDLER FOR SQLEXCEPTION SET v_err = 1; 
        -- perform operations
        INSERT INTO dept VALUES(p_deptno, p_dname, p_loc);
        IF v_err = 1 THEN
            SELECT 'Dept add failed' AS msg;
        ELSE
            SELECT 'Dept added successfully' AS msg;
        END IF;
    END;
    $$

    DELIMITER ;
    ```
    ```SQL
    CALL sp_add_dept4(50, 'TRAINING', 'MUMBAI'); -- error
    
    CALL sp_add_dept4('ABCD', 'SECURITY', 'KASHMIR');
    ```

* How to throw exception?
    ```SQL
    SIGNAL SQLSTATE '45000';
    ```

    - SIGNAL keyword is similar to C++ "throw" keyword. It raise the error.
    - Must throw some SQL state e.g. '45000' is user defined error state.
    
    ```SQL
    SIGNAL SQLSTATE '45000'
    SET MESSAGE_TEXT = 'User-defined Error Message'; -- custom error message
    ```

### Cursors
* Cursor is an object used to process the results of SELECT query row by row.
* Cursor can be used in MySQL programs (SP, Fn, or Triggers).
* Example 1: Read depts and add deptno, dname in lower case into results table -- using cursor.
    ```SQL
    DROP PROCEDURE IF EXISTS sp_get_depts;

    DELIMITER $$

    CREATE PROCEDURE sp_get_depts()
    BEGIN
        DECLARE v_eoc INT DEFAULT 0; -- eoc flag = End of Cursor
        DECLARE v_deptno INT; -- var to get value from cursor
        DECLARE v_dname VARCHAR(20); -- var to get value from cursor
        DECLARE v_loc VARCHAR(20); -- var to get value from cursor
        -- cursor variable declaration
        DECLARE v_cur CURSOR FOR SELECT deptno, dname, loc FROM dept;
        -- cursor end error handler
        DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_eoc = 1;
        -- open the cursor
        OPEN v_cur;
        process: LOOP
            -- fetch current row from the db table into variables
            FETCH v_cur INTO v_deptno, v_dname, v_loc;
            -- if cursor end is reached, break the loop
            IF v_eoc = 1 THEN
                LEAVE process;
            END IF;
            -- if values are fetched (not end of cursor), process the data
            INSERT INTO results VALUES (v_deptno, CONCAT(LOWER(v_dname), ' - ', LOWER(v_loc)));
        END LOOP;
        -- close the cursor
        CLOSE v_cur;
    END;
    $$

    DELIMITER ;
    ```
    ```SQL
    TRUNCATE results;

    CALL sp_get_depts();

    SELECT * FROM results;
    ```
* Above example is too simple -- demonstarting cursor syntax only. Same requirement can be fulfilled using a single query.
    ```SQL
    TRUNCATE results;

    INSERT INTO results
    SELECT deptno, LOWER(dname) FROM dept;
    
    SELECT * FROM results;
    ```

* Example 2: Compare rows of t1 & t2 and write the max into results table with ascii value. 
    ```SQL
    SELECT * FROM t1; -- A, B, C, D
    SELECT * FROM t2; -- B, C, X, Y
    ```
    ```SQL
    DELIMITER $$

    CREATE PROCEDURE sp_cursor()
    BEGIN
        DECLARE v_val1 VARCHAR(10);
        DECLARE v_val2 VARCHAR(10);
        DECLARE v_eoc INT DEFAULT 0;
        DECLARE v_cur1 CURSOR FOR SELECT c1 FROM t1;
        DECLARE v_cur2 CURSOR FOR SELECT c2 FROM t2;
        DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_eoc = 1;
        OPEN v_cur1;
        OPEN v_cur2;
        compare: LOOP
            FETCH v_cur1 INTO v_val1;
            IF v_eoc = 1 THEN
                LEAVE compare;
            END IF;
            FETCH v_cur2 INTO v_val2;
            IF v_eoc = 1 THEN
                LEAVE compare;
            END IF;
            IF v_val1 > v_val2 THEN
                INSERT INTO results VALUES (NULL, CONCAT('Max ', v_val1));
            ELSE
                INSERT INTO results VALUES (NULL, CONCAT('Max ', v_val2));
            END IF;
        END LOOP;
        CLOSE v_cur2;
        CLOSE v_cur1;
    END;
    $$

    DELIMITER ;
    ```

    ```SQL
    TRUNCATE results;

    CALL sp_cursor();

    SELECT * FROM results;
    ```
* Cursor steps
    * step 1: declare cursor variable with SELECT query.
        > DECLARE v_cur CURSOR FOR SELECT ...;
    * step 2: declare end-of-cursor error handler -- NOT FOUND error.
        > DECLARE CONTINUE HANDLER FOR NOT FOUND SET v_err = 1;
    * step 3: open the cursor
        > OPEN v_cur;
    * step 4: fetch current row into the variables.
        > FETCH v_cur INTO var1, var2, ...;
    * step 5: if end of cursor (NOT FOUND error -> v_err set to 1), leave the loop; otherwise process the current row.
        - Repeat steps 4 & 5 for all the rows -- in LOOP.
    * step 6: close the cursor
        - CLOSE v_cur;
* MySQL Cursor characteristics:
    - Read-only -- can only read values using cursor (cannnot UPDATE them back in table).
    - Forward-only -- each FETCH will get the next row (cannot traverse in reverse direction).
    - Asensitive -- while processing the cursor row by row, if any record is updated externally (by some other client), then the modified record (changes) will be visible with cursor. 
* Cursor applications:
    - Process the rows one by one.
* How cursor works internally?
    - When cursor is "OPEN"ed, by default it is at 0th position (at beginning - no row fetched yet).
    - On first "FETCH" operation, first row of the SELECT query is fetched into the given variables and internally position is set to the next row.
    - On next "FETCH" the next row will be fetched into the variables and again position is set to the next row.
    - When cursor is "CLOSE"d, cannot use cursor further.


### Indexes
* Indexes on db tables are used to speedup search operations (WHERE clause).
* Types of indexes:
    - Simple/Regular Index
    - Composite Index
    - Unique Index
* Syntax:
    > CREATE INDEX idx_name ON tablename(colname ASC|DESC);
* Simple Index
    ```SQL
    DESCRIBE books;

    SELECT * FROM books WHERE name = 'C++ Primer';

    EXPLAIN FORMAT=TRADITIONAL
    SELECT * FROM books WHERE name = 'C++ Primer';
    -- display the execution plan of the query: FORMAT=TRADITIONAL|JSON|TREE

    EXPLAIN ANALYZE
    SELECT * FROM books WHERE name = 'C++ Primer';
    ```
* Simple Index
    ```SQL
    CREATE INDEX idx_book_name ON books(name);

    SELECT * FROM books WHERE name = 'C++ Primer';

    EXPLAIN ANALYZE
    SELECT * FROM books WHERE name = 'C++ Primer';
    -- Index lookup on books using idx_book_name (name = 'C++ Primer')
    -- makes WHERE clause execution much faster
    ```
* Composite Index
    ```SQL
    SELECT * FROM books
    WHERE subject = 'C Programming' AND author = 'Yashwant Kanetkar';

    EXPLAIN ANALYZE
    SELECT * FROM books
    WHERE subject = 'C Programming' AND author = 'Yashwant Kanetkar';
    -- Table scan on books

    CREATE INDEX idx_books_subject_author ON books(subject ASC, author ASC);

    SELECT * FROM books
    WHERE subject = 'C Programming' AND author = 'Yashwant Kanetkar';

    EXPLAIN ANALYZE
    SELECT * FROM books
    WHERE subject = 'C Programming' AND author = 'Yashwant Kanetkar';
    -- Index lookup on books using idx_books_subject_author
    ```
    ```SQL
    -- search all clerk in dept 20
    SELECT * FROM emp WHERE deptno=20 AND job='CLERK';

    EXPLAIN ANALYZE
    SELECT * FROM emp WHERE deptno=20 AND job='CLERK';

    CREATE INDEX idx_emp_dept_job ON emp(deptno, job);

    SELECT * FROM emp WHERE deptno=20 AND job='CLERK';

    EXPLAIN ANALYZE
    SELECT * FROM emp WHERE deptno=20 AND job='CLERK';
    ```
* Unique Index
    * Ensures that value is not duplicated.    
    ```SQL
    CREATE UNIQUE INDEX idx_emp_ename ON emp(ename);

    EXPLAIN ANALYZE
    SELECT * FROM emp WHERE ename='KING';

    DESCRIBE emp;
    ```

    ```SQL
    CREATE UNIQUE INDEX idx_books_name ON books(name);
    -- Error: Duplicate entry 'ANSI C Programming' for key 'books.idx_books_name'

    CREATE UNIQUE INDEX idx_books_name_author ON books(name, author);
    -- composite unique index - combination of columns should be unique

    EXPLAIN ANALYZE
    SELECT * FROM books WHERE name='ANSI C Programming' AND author = 'Dennis Ritchie';
    ```
* Limitations of Indexes
    - CREATE INDEX will take significant time if too many records in the table.
    - Creating index will occupy some space on server disk.
    - Indexes are updated on each DML operation. It will slow down DML execution.
    - Creating indexes on externally stored columns (like TEXT or BLOB) is limited (not full support in MySQL). Also they may be slower. In MySQL you can create index on first 10 chars/bytes of TEXT/BLOB.
        ```SQL
        CREATE TABLE test1(c1 CHAR(10), c2 VARCHAR(10), c3 TEXT(10));
        -- ...
        CREATE INDEX idx1 ON test1(c1); -- okay (efficient)
        CREATE INDEX idx2 ON test1(c3); -- may be error
        CREATE INDEX idx2 ON test1(c3(10)); -- okay
        ```
* When PK, FK, and UNIQUE constraints are applied on table; they internally create indexes.
* There are two index categories - MySQL index internals:
    * Clustered index
        * Usually MySQL creates clustered index on Primary Key (PK).
        * If no primary key for the table, MySQL may use unique key (UK) for clustered index.
        * If no PK or UK is present, MySQL may create a hidden/synthentic column with unique values and use it to create clustered index.
        * Clustered index stores the value of that column and corresponding row data (or address).
    * Non-clustered index
        * The other indexes (other than clustered index) created on table are non-clustered index a.k.a. secondary index.
        * When searched using non-clustered index, internally it first find the clustered index entry and then it finds the actual row data (or address).
    * Example:
        ```SQL
        CREATE TABLE emp (id INT PRIMARY KEY, name VARCHAR(20), sal DOUBLE, job VARCHAR(20));
        -- ...
        CREATE INDEX idx1 ON emp(job);
        -- ...
        ```
        * index on "id" column i.e. primary key is clustered index.
        * index on "job" and other columns are non-clustered indexes.

### MySQL DCL - Data Control Language
* Security is built-in in RDBMS.
    * Authentication -- User login with username & password.
    * PRIVILEGES (i.e. Permissions) -- Authorization
* User creation (by root user)
    ```SQL
    CREATE DATABASE trainreservation;

    CREATE USER 'mgr'@'%' IDENTIFIED BY 'mgr@123';
    -- @'localhost' -> can login from local machine i.e. server machine only
    -- @'ip-addr' -> can login from client machine with given ip-addr only
    -- @'%' -> can login from any client machine

    GRANT ALL ON trainreservation.* TO mgr@'%' WITH GRANT OPTION;
    -- full permissions to all objects in trainreservation db
    -- plus permissions to give permissions to other users

    FLUSH PRIVILEGES;
    -- activate these permissions    

    CREATE USER teamlead@'%' IDENTIFIED BY 'teamlead@123';
    CREATE USER dev1@'%' IDENTIFIED BY 'dev1@123';
    CREATE USER dev2@'%' IDENTIFIED BY 'dev2@123';
    ```

* Users & Permissions are stored in system databases/tables.
    ```SQL
    -- with root login
    SHOW DATABASES;

    SELECT user, host FROM mysql.user;

    USE information_schema;

    SHOW TABLES;

    SELECT * FROM tables;
    ```
* DROP USER
    ```SQL
    -- with root login
    DROP USER username@'machine';
    ```

* PRIVILEGES
    * Two types -- System Privileges and Object Privileges
    * System Privileges -- only for admin level users (root)
        * CREATE USER, CREATE DATABASE, DROP USER, ...
    * Object Privileges -- for general users
        * Table level, Procedure level, ...
        * SELECT, INSERT, UPDATE, DELETE, CALL, ...

* Security Example:
    * dba(root) --> mgr --> teamlead --> dev1 & dev2
    ```SQL
    -- with mgr login
    USE trainreservation;

    CREATE TABLE trains(id INT, name VARCHAR(20));

    GRANT INSERT, UPDATE, SELECT ON trainreservation.* TO teamlead@'%' WITH GRANT OPTION;
    
    GRANT CREATE ON trainreservation.* TO teamlead@'%';
    ```

    ```SQL
    -- with teamlead login
    SHOW DATABASES;

    USE trainreservation;

    SHOW TABLES;

    CREATE TABLE passengers(id INT, name VARCHAR(30));

    INSERT INTO passengers VALUES (1, 'P1');

    SELECT * FROM passengers;

    DELETE FROM passengers;

    GRANT INSERT, SELECT ON trainreservation.* TO dev1@'%';

    GRANT DELETE, SELECT ON trainreservation.* TO dev2@'%';
    -- Error 

    GRANT SELECT ON trainreservation.* TO dev2@'%';
    ```
    ```SQL
    -- with dev1 login
    SHOW TABLES;

    INSERT INTO passengers VALUES (2, 'P2'), (3, 'P3');
    SELECT * FROM passengers;

    UPDATE passengers SET name = LOWER(name);
    -- Error
    ```
    ```SQL
    -- with dev2 login
    SHOW TABLES;

    INSERT INTO trains VALUES (3, 'T3');
    -- Error

    SELECT * FROM trains;
    ```
    ```SQL
    -- with mgr login
    REVOKE UPDATE ON trainreservation.* FROM teamlead@'%';
    ```
    ```SQL
    -- with teamlead "new" login
    UPDATE passengers SET name=LOWER(name);
    -- Error
    ```
* root user can create another admin login and give full permissions
    ```SQL
    -- with root login
    CREATE USER admin@'%' IDENTIFIED BY 'admin@123';

    GRANT ALL ON *.* TO admin@'%' WITH GRANT OPTION;
    -- now admin can perform all ops on db.

    -- ...

    REVOKE ALL ON *.* FROM admin@'%';
    ```

### Views
* View -- Represents View (Projection) of Table(s).
* Depends on SELECT statement. You can select one/more columns (including computed columns) and/or one/more rows.
* View doesn't have any storage (data is not stored on disk). Only View's SELECT query is stored in databases' metadata.
* Syntax:
    ```SQL
    CREATE VIEW viewname AS SELECT ...;

    SHOW FULL TABLES;

    SELECT ... FROM viewname ...;
    -- may perform DML operations on some views;

    DROP VIEW viewname;
    ```
* Examples:

```SQL
USE classwork;

CREATE VIEW v1_emp AS
SELECT ename, job, deptno, sal, sal * 0.5 AS da FROM emp;
-- view has all rows and few columns from the base table + comupted cols 

SHOW TABLES;

SHOW FULL TABLES;

DESCRIBE v1_emp;

SELECT * FROM v1_emp;

SELECT deptno, SUM(sal), SUM(da) FROM v1_emp
GROUP BY deptno;
```

```SQL
CREATE VIEW v2_emp AS
SELECT empno, ename, deptno, sal FROM emp WHERE sal < 1000;
-- view with limited rows and cols

SHOW FULL TABLES;

DESCRIBE v2_emp;

SELECT * FROM v2_emp;

INSERT INTO v2_emp VALUES (1000, 'JOHN', 40, 500.0);
-- view doesn't have space/memory
-- DML ops performed on view will actually will perform op on base table 

SELECT * FROM v2_emp;
-- new row is visible

SELECT * FROM emp;
-- new row is visible here.
```

```SQL
INSERT INTO v2_emp VALUES (1001, 'JANE', 40, 1500.0);
-- still works - even if sal > 1000.0

SELECT * FROM v2_emp;
-- new row is not visible here

SELECT * FROM emp;
-- but new row is visible here
-- inconsistent behaviour
```

* `WITH CHECK OPTION` will check the WHERE clause condition on each DML operation. And if WHERE clause is violated, then the DML operation fails.

```SQL
DROP VIEW v2_emp;

CREATE VIEW v3_emp AS
SELECT empno, ename, deptno, sal FROM emp WHERE sal < 1000
WITH CHECK OPTION;

DESCRIBE v3_emp;

SHOW CREATE VIEW v3_emp;

INSERT INTO v3_emp VALUES (1001, 'JANE', 40, 1500.0);
-- ERROR 1369 (HY000): CHECK OPTION failed

EXPLAIN ANALYZE
SELECT * FROM v3_emp;
-- -> Filter: (emp.sal < 1000.00)
--    -> Table scan on emp
-- Queries targeting the views are internally converted to queries targetting the underlying table and then the execution plan is created.
```

* View Types:
    * Complex View: SELECT query is producing columns which are computed (not present in original table). It may contain joins, subqueries, grouping, etc. **DML operations cannot be performed on Complex Views**.
    * Simple View: SELECT query only selecting columns/rows from original table - not computing columns dynamically. **DML operations can be performed on such views**.

```SQL
CREATE VIEW v4_emp AS
SELECT deptno, SUM(sal) total, AVG(sal) avgsal, COUNT(empno) cnt FROM emp
GROUP BY deptno;

SELECT * FROM v4_emp;

SELECT * FROM v4_emp
WHERE avgsal > 2500;

INSERT INTO v4_emp VALUES (50, 10000.0, 2000.0, 5);
-- Error: cannot insert into complex views
```

```SQL
CREATE VIEW v5_emp AS
SELECT * FROM v4_emp ORDER BY total DESC;

SELECT * FROM v5_emp;

SHOW CREATE VIEW v5_emp;

DROP VIEW v4_emp;

SELECT * FROM v5_emp;
```

* Applications
    * Security -- Hide part of table (rows/cols).
    * Hide source of the table (CREATE TABLE).
    * Simplify the complex queries.
        ```SQL
        CREATE VIEW v_emp_category AS
        SELECT empno, ename, sal, CASE
        WHEN sal < 1500 THEN 'POOR'
        WHEN sal > 2500 THEN 'RICH'
        ELSE 'MIDDLE'
        END category
        FROM emp;

        SELECT * FROM v_emp_category;

        SELECT category, COUNT(empno) FROM v_emp_category
        GROUP BY category;

        EXPLAIN ANALYZE
        SELECT category, COUNT(empno) FROM v_emp_category
        GROUP BY category;
        ```

### Temporary Tables
- Temporary Table -- Represents a temporary table used to store data temporarily during a session.
- Created using `CREATE TEMPORARY TABLE`.
- Data is stored physically, but the table exists only for the current session.
- Temporary table is visible **only to the session/connection that created it**.
- When the session ends, the temporary table is automatically dropped.
- It can also be explicitly dropped using `DROP TEMPORARY TABLE`.
- Syntax:
  ```SQL
  CREATE TEMPORARY TABLE tablename (
      column1 datatype,
      column2 datatype,
      ...
  );

  INSERT INTO tablename VALUES (...);

  SELECT ... FROM tablename ...;
  
  DROP TEMPORARY TABLE tablename;

  CREATE TEMPORARY TABLE tablename AS
  SELECT ...;
  ```
- Examples:

```SQL
CREATE TEMPORARY TABLE temp_emp (
    empno INT,
    ename VARCHAR(20),
    sal DOUBLE
);

INSERT INTO temp_emp VALUES (1, 'JOHN', 1000.0);
INSERT INTO temp_emp VALUES (2, 'JANE', 1500.0);

SELECT * FROM temp_emp;

DESCRIBE temp_emp;

SHOW TEMPORARY TABLES;
-- Error: Temporary Tables cannot be viewed.

DROP TEMPORARY TABLE temp_emp;
```

 - `CREATE TEMPORARY TABLE ... AS SELECT ...` can be used to create a temporary table from the result of a query.

```SQL
CREATE TEMPORARY TABLE temp_high_emps AS
SELECT empno, ename, deptno, sal FROM emp
WHERE sal > 2500;

SELECT * FROM temp_high_emps;
```

- Temporary tables support normal DML operations -- `INSERT`, `UPDATE`, and `DELETE`.

```SQL
INSERT INTO temp_high_emps
VALUES(1000, 'JOHN', 50, 3000.0);
-- record stored in memory of temp table

SELECT * FROM temp_high_emps;

SELECT * FROM emp;

DELETE FROM temp_high_emps
WHERE sal > 3500.0;
-- record deleted from memory of temp table

SELECT * FROM temp_high_emps;

SELECT * FROM emp;
-- changes in temp table not reflected in main table
```

 - Temporary Table vs Normal Table:
  - **Normal Table:** Exists until explicitly dropped.
  - **Temporary Table:** Exists only for the current session.
  - **Normal Table:** Can be accessed by other sessions, subject to permissions.
  - **Temporary Table:** Can be accessed only by the session that created it.
  - **Normal Table:** Remains in the database after the session ends.
  - **Temporary Table:** Automatically disappears when the session ends.
- Temporary tables are **session-specific**.

```SQL
-- Session 1
CREATE TEMPORARY TABLE test(c1 INT, c2 INT);
INSERT INTO test VALUES(10, 20);
INSERT INTO test VALUES(11, 22);
INSERT INTO test VALUES(1, 2);
SELECT * FROM test;
```

```SQL
-- Session 2
SELECT * FROM test;
-- ERROR: Table 'classwork.test' doesn't exist
```

- A temporary table can have the **same name as a permanent table**. The temporary table hides/shadows the permanent table within that session.

```SQL
SELECT * FROM dept;

CREATE TEMPORARY TABLE dept (deptid INT, dname VARCHAR(20));

DESCRIBE dept;

INSERT INTO dept VALUES (1, 'TEST');
SELECT * FROM dept;
-- get rows from temp table

DROP TEMPORARY TABLE dept;

SELECT * FROM dept;
-- get rows from permanent table
```

- Applications:
  - **Intermediate Results** -- Store results of complex queries for further processing.
  - **Complex Queries** -- Break a large query into multiple simpler steps.
  - **Data Processing** -- Store temporary data during calculations/transformations.
  - **Testing** -- Work with temporary data without permanently modifying the database.
