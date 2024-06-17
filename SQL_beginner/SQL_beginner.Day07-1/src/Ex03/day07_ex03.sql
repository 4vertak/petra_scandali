WITH tmp_orders AS (
        SELECT name, COUNT(*) AS count, 'order' AS action_type
        FROM person_order
        INNER JOIN menu ON menu.id = person_order.menu_id
        INNER JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
        GROUP BY name
        ORDER BY count DESC
),
    tmp_visits AS
    (
        SELECT name, COUNT(*) AS count, 'visit' AS action_type
        FROM person_visits
        INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
        GROUP BY name
        ORDER BY count DESC
)
SELECT pz.name, COALESCE(tmp_v.count, 0) + COALESCE(tmp_o.count, 0) AS total_count
FROM pizzeria pz
FULL JOIN tmp_orders tmp_o ON tmp_o.name = pz.name
FULL JOIN tmp_visits tmp_v ON tmp_v.name = pz.name
ORDER BY total_count DESC, name;