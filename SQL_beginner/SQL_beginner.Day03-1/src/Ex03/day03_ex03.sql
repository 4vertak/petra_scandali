SELECT pizzeria.name AS pizzeria_name
FROM (SELECT pizzeria_id
	FROM person_visits
    JOIN person ON person_visits.person_id = person.id
    WHERE person.gender = 'male'
    EXCEPT ALL
    SELECT pizzeria_id
    FROM person_visits
    JOIN person ON person_visits.person_id = person.id
    WHERE person.gender = 'female'
) AS male_only
JOIN pizzeria ON male_only.pizzeria_id = pizzeria.id

UNION ALL

SELECT pizzeria.name AS pizzeria_name
FROM (SELECT person_visits.pizzeria_id
    FROM person_visits
    JOIN person ON person_visits.person_id = person.id
    WHERE person.gender = 'female'
    EXCEPT ALL
    SELECT person_visits.pizzeria_id
    FROM person_visits
    JOIN person ON person_visits.person_id = person.id
    WHERE person.gender = 'male'
) AS female_only
JOIN pizzeria ON female_only.pizzeria_id = pizzeria.id

ORDER BY pizzeria_name;


