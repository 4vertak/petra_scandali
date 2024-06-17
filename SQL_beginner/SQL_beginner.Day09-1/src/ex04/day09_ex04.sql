--create functions
CREATE OR REPLACE FUNCTION fnc_persons_female()
  RETURNS TABLE (
          id BIGINT,
          name VARCHAR,
          age INTEGER,
          gender VARCHAR,
          address VARCHAR
  ) AS $$ (SELECT * FROM person WHERE person.gender = 'female');
$$ LANGUAGE sql;

CREATE OR REPLACE FUNCTION fnc_persons_male()
  RETURNS TABLE (
          id BIGINT,
          name VARCHAR,
          age INTEGER,
          gender VARCHAR,
          address VARCHAR
  ) AS $$ (SELECT * FROM person WHERE person.gender = 'male');
$$ LANGUAGE sql;

--check
SELECT * FROM fnc_persons_male();
SELECT * FROM fnc_persons_female();