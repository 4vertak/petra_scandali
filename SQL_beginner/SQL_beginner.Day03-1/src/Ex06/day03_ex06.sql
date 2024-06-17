SELECT menu.pizza_name, pizzeria1.name AS pizzeria_name1, pizzeria2.name AS pizzeria_name2, menu.price
FROM menu
JOIN menu AS menu_temp ON menu.price = menu_temp.price
JOIN pizzeria AS pizzeria1 ON menu.pizzeria_id = pizzeria1.id
JOIN pizzeria AS pizzeria2 ON menu_temp.pizzeria_id = pizzeria2.id
WHERE menu.id > menu_temp.id AND menu.pizza_name = menu_temp.pizza_name
ORDER BY pizza_name;

