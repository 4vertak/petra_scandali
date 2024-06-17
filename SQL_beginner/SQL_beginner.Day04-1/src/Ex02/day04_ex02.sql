CREATE VIEW v_generated_dates AS
SELECT generated_date::DATE
FROM generate_series('2022-01-01'::DATE, '2022-01-31', '1 day') as generated_date
ORDER BY generated_date;

---- for view:

-- SELECT *
-- FROM v_generated_dates;