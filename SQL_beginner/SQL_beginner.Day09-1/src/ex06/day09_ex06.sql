--create function
CREATE FUNCTION fnc_person_visits_and_eats_on_date(IN pperson VARCHAR default 'Dmitriy', IN pprice NUMERIC default 500, IN pdate DATE default '2022-01-08')
    RETURNS TABLE (name VARCHAR) AS $$ 
    BEGIN
    RETURN QUERY SELECT pizzeria.name as pizzeria_name
		FROM person_visits
		JOIN person_order ON person_order.person_id = person_visits.person_id
		JOIN pizzeria ON person_visits.pizzeria_id = pizzeria.id
		JOIN menu ON menu.id = person_order.menu_id AND menu.pizzeria_id = pizzeria.id
		JOIN person ON person.id = person_order.person_id AND person.id = person_visits.person_id
		WHERE person.name = pperson and menu.price < pprice and person_order.order_date = pdate;
END; $$LANGUAGE plpgsql;

--check
select *
from fnc_person_visits_and_eats_on_date(pprice := 800);

select *
from fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');