SELECT pizzeria_name
FROM (SELECT pizzeria.name AS pizzeria_name
    FROM pizzeria
    WHERE NOT EXISTS ( SELECT 1
        FROM menu
        INNER JOIN person_order ON person_order.menu_id = menu.id
        INNER JOIN person ON person_order.person_id = person.id
        WHERE person.gender = 'male' AND menu.pizzeria_id = pizzeria.id
    ) AND EXISTS (
        SELECT 1
        FROM menu
        INNER JOIN person_order ON person_order.menu_id = menu.id
        INNER JOIN person ON person_order.person_id = person.id
        WHERE person.gender = 'female' AND menu.pizzeria_id = pizzeria.id
    )
	
    UNION ALL
	
    SELECT pizzeria.name AS pizzeria_name
    FROM pizzeria
    WHERE NOT EXISTS (
        SELECT 1
        FROM menu
        JOIN person_order ON person_order.menu_id = menu.id
        JOIN person ON person_order.person_id = person.id
        WHERE person.gender = 'female' AND menu.pizzeria_id = pizzeria.id
    ) AND EXISTS (
        SELECT 1
        FROM menu
        JOIN person_order ON person_order.menu_id = menu.id
        JOIN person ON person_order.person_id = person.id
        WHERE person.gender = 'male' AND menu.pizzeria_id = pizzeria.id)
)
ORDER BY pizzeria_name;