INSERT INTO person_discounts (id, person_id, pizzeria_id, discount)
SELECT
    ROW_NUMBER() OVER() AS id, person_id, pizzeria_id,
    CASE WHEN COUNT(*) = 1 THEN 10.5
	WHEN COUNT(*) = 2 THEN 22
	ELSE 30
	END discount
FROM person_order
	JOIN menu ON person_order.menu_id = menu.id
GROUP BY person_id, pizzeria_id;	

-- SELECT *
-- FROM person_discounts;