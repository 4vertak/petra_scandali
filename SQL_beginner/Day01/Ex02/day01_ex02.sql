-- var_1: UNION - объединение с удалением дублирующих значений

SELECT pizza_name
FROM menu
UNION
SELECT pizza_name
FROM menu
ORDER BY pizza_name DESC;


-- var_2: DISTINCT - уникальные значения

-- SELECT DISTINCT pizza_name
-- FROM menu
-- ORDER BY pizza_name DESC;

-- var_3: GROUP BY - Не предпочтительно, лучше для группировки и подсчета
-- SELECT pizza_name
-- FROM menu
-- GROUP BY pizza_name
-- ORDER BY pizza_name DESC;