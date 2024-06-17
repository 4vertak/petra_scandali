-- var_1: - название столбцов в выводе будет отличаться
-- SELECT *
-- FROM person, pizzeria
-- ORDER BY person.id, pizzeria.id ASC;

-- var_2: - название столбцов вывода идентично образцу/примеру
SELECT person.id AS "person.id", person.name AS "person.name", person.age, person.gender, person.address, pizzeria.id AS "pizzeria.id", pizzeria.name AS "pizzeria.name", pizzeria.rating
FROM person, pizzeria
ORDER BY person.id, pizzeria.id;