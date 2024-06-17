-- CTE (Common Table Expression) — именнованный запрос с временной таблицей результатов, который можно использовать в запросе - и доступен только во время него

-- var_1.1: using LEFT JOIN

----  ** -- пример CTE - он же используется во втором варианте
WITH date_range AS (SELECT missing_date::date FROM generate_series('2022-01-01'::date, '2022-01-10', '1 day') AS missing_date), 
	visits_dates AS (SELECT visit_date FROM person_visits WHERE (person_id = '1' OR person_id = '2') 
	AND visit_date BETWEEN '2022-01-01' AND '2022-01-10')
---- ** --
SELECT date_range.missing_date
FROM date_range
LEFT JOIN visits_dates ON date_range.missing_date = visit_date
WHERE visits_dates.visit_date IS NULL
ORDER BY date_range.missing_date;

---- var_2.1: using NOT EXISTS

-- WITH date_range AS (SELECT missing_date::date FROM generate_series('2022-01-01'::date, '2022-01-10', '1 day') AS missing_date), 
-- 	visits_dates AS (SELECT visit_date FROM person_visits WHERE (person_id = '1' OR person_id = '2') 
-- 	AND visit_date BETWEEN '2022-01-01' AND '2022-01-10')

-- SELECT missing_date
-- FROM date_range
-- WHERE NOT EXISTS (
--     SELECT 1
--     FROM visits_dates
--     WHERE visit_date = date_range.missing_date
-- )
-- ORDER BY date_range.missing_date;