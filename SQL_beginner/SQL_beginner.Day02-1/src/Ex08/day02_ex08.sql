SELECT person.name
FROM person_order
JOIN person ON person_order.person_id = person.id
JOIN menu ON person_order.menu_id = menu.id
WHERE person.gender = 'male' AND menu.pizza_name IN ('pepperoni pizza', 'mushroom pizza')
	AND person.address IN ('Moscow', 'Samara')
ORDER BY name DESC