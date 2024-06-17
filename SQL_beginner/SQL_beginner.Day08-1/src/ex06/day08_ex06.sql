-- Session #1
SHOW TRANSACTION ISOLATION LEVEL;
-- Session #2
SHOW TRANSACTION ISOLATION LEVEL;

-- Session #1
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;
-- Session #2
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

-- Session #1
SELECT sum(rating) FROM pizzeria;
-- Session #2
INSERT INTO pizzeria (id, name, rating)
VALUES (11, 'Kazan Pizza 2', 4);
COMMIT;

-- Session #1
SELECT sum(rating) FROM pizzeria;
COMMIT;
SELECT sum(rating) FROM pizzeria;
-- Session #2
SELECT sum(rating) FROM pizzeria;