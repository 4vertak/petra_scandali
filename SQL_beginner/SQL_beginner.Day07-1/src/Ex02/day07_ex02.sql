(SELECT pizzeria.name, count(*) as count, 'order' as action_type
FROM person_order
JOIN menu ON person_order.menu_id = menu.id
JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
GROUP BY pizzeria.name
ORDER BY count DESC LIMIT 3)
	
UNION
	
(SELECT pizzeria.name, count(*) as count, 'visit' as action_type
FROM person_visits
JOIN pizzeria ON person_visits.pizzeria_id = pizzeria.id
GROUP BY pizzeria.name
ORDER BY count DESC
LIMIT 3)

ORDER BY action_type, count DESC;