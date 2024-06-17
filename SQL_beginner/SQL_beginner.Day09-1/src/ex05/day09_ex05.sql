--drop function
DROP FUNCTION public.fnc_persons_female();
DROP FUNCTION public.fnc_persons_male();

--create functions
CREATE OR REPLACE FUNCTION fnc_persons(IN pgender varchar default 'female')
  RETURNS TABLE (
          id BIGINT,
          name VARCHAR,
          age INTEGER,
          gender VARCHAR,
          address VARCHAR
  ) AS $$ (SELECT * FROM person WHERE person.gender = pgender);
$$ LANGUAGE sql;

--check
select * from fnc_persons(pgender := 'male');

select * from fnc_persons();