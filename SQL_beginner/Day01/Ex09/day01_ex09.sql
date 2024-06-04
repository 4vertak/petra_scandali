-- var_1:using IN
SELECT name AS "pizzeria.name"
FROM pizzeria
WHERE pizzeria.id NOT IN (SELECT pizzeria_id FROM person_visits);

-- var_2: using EXIST
-- SELECT name AS "pizzeria.name"
-- FROM pizzeria
-- WHERE NOT EXISTS (SELECT pizzeria_id FROM person_visits WHERE person_visits.pizzeria_id = pizzeria.id);