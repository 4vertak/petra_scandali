SELECT person.name AS person_name1, temp_person_table.name as person_name2, temp_person_table.address as common_address
FROM person, person temp_person_table
WHERE person.address = temp_person_table.address and person.id > temp_person_table.id
ORDER BY person_name1, person_name2, common_address;