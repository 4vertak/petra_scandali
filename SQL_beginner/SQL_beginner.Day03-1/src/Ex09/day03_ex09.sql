-- table person_visits: | id | person_id (Denis = 4, Irina = 6) | pizzeria_id | visit_date |

INSERT INTO person_visits VALUES(
	(SELECT MAX(id) + 1 FROM person_visits),
	(SELECT id FROM person WHERE name = 'Denis'),
	(SELECT id FROM pizzeria WHERE name = 'Dominos'),
	'2022-02-24');

INSERT INTO person_visits VALUES(
	(SELECT MAX(id) + 1 FROM person_visits),
	(SELECT id FROM person WHERE name = 'Irina'),
	(SELECT id FROM pizzeria WHERE name = 'Dominos'),
	'2022-02-24');