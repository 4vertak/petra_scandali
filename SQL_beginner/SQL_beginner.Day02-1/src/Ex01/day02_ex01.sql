-- var_1: using LEFT JOIN
SELECT missing_date::date
FROM generate_series('2022-01-01'::date, '2022-01-10', '1 day') AS missing_date
LEFT JOIN (SELECT * FROM person_visits WHERE (person_id = '1' OR person_id = '2') AND visit_date BETWEEN '2022-01-01' AND '2022-01-10') d ON missing_date = d.visit_date
WHERE visit_date IS NULL
ORDER BY missing_date;

-- var_2: using NOT EXISTS
-- SELECT missing_date::date
-- FROM generate_series('2022-01-01'::date, '2022-01-10', '1 day') AS missing_date
-- WHERE NOT EXISTS (SELECT person_id FROM person_visits WHERE (person_id = '1' OR person_id = '2') AND visit_date = missing_date)
-- ORDER BY missing_date;

-- var_3: using EXCEPT
-- SELECT missing_date::date
-- FROM generate_series('2022-01-01'::date, '2022-01-10', '1 day') AS missing_date
-- EXCEPT
-- SELECT visit_date
-- FROM person_visits
-- WHERE (person_id = '1' OR person_id = '2') AND visit_date BETWEEN '2022-01-01' AND '2022-01-10'
-- ORDER BY missing_date;