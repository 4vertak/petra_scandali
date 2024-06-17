-- COALESCE возвращает '-' если person.name == NULL

-- var_1: using NOT IN 
-- SELECT COALESCE(person.name, '-') AS person_name, visit_date AS visit_date, COALESCE(pizzeria.name, '-') AS pizzeria_name
-- FROM (SELECT * FROM person_visits WHERE visit_date NOT IN (SELECT visit_date FROM person_visits WHERE visit_date NOT BETWEEN '2022-01-01' AND '2022-01-03')) AS date
-- FULL JOIN pizzeria ON date.pizzeria_id = pizzeria.id
-- FULL JOIN person ON date.person_id = person.id
-- ORDER BY person_name, visit_date, pizzeria_name;

-- var_2:  not using NOT IN ;)) - чет лучше не придумал))
SELECT COALESCE(person.name, '-') AS person_name, visit_date AS visit_date, COALESCE(pizzeria.name, '-') AS pizzeria_name
FROM (SELECT * FROM person_visits WHERE visit_date BETWEEN '2022-01-01' AND '2022-01-03') AS date
FULL JOIN pizzeria ON date.pizzeria_id = pizzeria.id
FULL JOIN person ON date.person_id = person.id
ORDER BY person_name, visit_date, pizzeria_name;
