```sql
DELIMITER $$
CREATE TRIGGER trig_onupdate
AFTER UPDATE ON emp
-- CREATE TABLE IF NOT EXISTS results (Value INT, Message VARCHAR(50));
FOR EACH ROW
BEGIN
    DECLARE v_msg VARCHAR(50);
    IF NEW.sal != OLD.sal THEN
        SET v_msg = CONCAT('SAL changed ', OLD.sal, ' to ', NEW.sal);
        INSERT INTO results VALUES(NEW.empno, v_msg);
    END IF;
END; $$
DELIMITER ;

CREATE TABLE IF NOT EXISTS results (Value INT, Message VARCHAR(50));

UPDATE emp SET sal = 900 WHERE empno = 7369; --800


-- again trigger on emp salary update
DELIMITER $$
CREATE TRIGGER trig_onupdate_job
BEFORE UPDATE ON emp
FOR EACH ROW
BEGIN
    DECLARE v_msg VARCHAR(50);
    IF NEW.job != OLD.job THEN
        SET v_msg = CONCAT('JOB changed from ', OLD.job, ' to ', NEW.job);
        INSERT INTO results VALUES (NEW.empno, v_msg);
    END IF;
END $$
DELIMITER ;

UPDATE emp SET job = 'President' WHERE empno = 7369;
SELECT * FROM results;

-- Trigger on tansactions
CREATE TABLE Accounts (
    acc_id INT PRIMARY KEY AUTO_INCREMENT,
    acc_type VARCHAR(50),
    amt DOUBLE(8, 2) NOT NULL
);

INSERT INTO Accounts (acc_type, amt) VALUES
("Savings", 800.50),
("Current", 687.33),
("Fixed deposit", 2323.232);

CREATE TABLE transx (
    id INT PRIMARY KEY AUTO_INCREMENT,
    acc_id INT REFERENCES accounts(id),
    tx_type VARCHAR(20),
    tx_time DATETIME,
    amount DOUBLE(8, 2)
);

-- trigger to update account balance
DELIMITER $$ 
CREATE TRIGGER update_balance
AFTER INSERT ON transx
FOR EACH ROW
BEGIN
    IF NEW.tx_type = 'Deposit' THEN
        UPDATE Accounts SET amt = amt+NEW.amount WHERE acc_id = NEW.acc_id;
    ELSE
        UPDATE Accounts SET amt = amt-NEW.amount WHERE acc_id = NEW.acc_id;
    END IF;
END $$
DELIMITER ;

-- trigger to log updates
DELIMITER $$
CREATE TRIGGER validate_balance
BEFORE UPDATE ON Accounts
FOR EACH ROW
BEGIN
    IF NEW.amt != OLD.amt AND NEW.amt < 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Withdraw Failed: Insufficient Funds.';
    END IF;
END $$
DELIMITER ;


INSERT INTO Transx (acc_id, tx_type, tx_time, amount) VALUES 
(1, 'Deposit', NOW(), 500);
INSERT INTO Transx (acc_id, tx_type, tx_time, amount) VALUES 
(1, 'Withdraw', NOW(), 500);
























```