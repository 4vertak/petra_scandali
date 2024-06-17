SELECT menu.pizza_name, name AS pizzeria_name, menu.price
FROM pizzeria
INNER JOIN menu ON pizzeria.id = pizzeria_id
WHERE menu.pizza_name = 'mushroom pizza' OR menu.pizza_name = 'pepperoni pizza'
ORDER BY pizza_name, pizzeria_name;