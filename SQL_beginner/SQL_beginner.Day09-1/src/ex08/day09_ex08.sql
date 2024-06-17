--create fucntion
CREATE OR REPLACE FUNCTION fnc_fibonacci(IN pstop INTEGER DEFAULT 10)
RETURNS TABLE(num integer) AS $$ 
BEGIN
RETURN QUERY
WITH RECURSIVE fibonacci(num_1, num_2) AS (
    SELECT 0, 1
    UNION ALL
    SELECT num_2, num_1 + num_2
    FROM fibonacci
    WHERE num_2 < pstop
)
SELECT num_1
FROM fibonacci;
END;
$$ LANGUAGE plpgsql;

--check
select * from fnc_fibonacci(100);
select * from fnc_fibonacci();