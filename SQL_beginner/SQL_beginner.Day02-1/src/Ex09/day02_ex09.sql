SELECT person.name
FROM person_order
JOIN person ON person_order.person_id = person.id
JOIN menu ON person_order.menu_id = menu.id
WHERE person.gender = 'female' AND menu.pizza_name IN ('pepperoni pizza')

INTERSECT

SELECT person.name
FROM person_order
JOIN person ON person_order.person_id = person.id
JOIN menu ON person_order.menu_id = menu.id
WHERE person.gender = 'female' AND menu.pizza_name IN ('cheese pizza')
ORDER BY name