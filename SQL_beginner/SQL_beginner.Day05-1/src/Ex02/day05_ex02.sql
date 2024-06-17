CREATE INDEX idx_person_name ON person(upper(name));

SET enable_seqscan = off;

EXPLAIN ANALYZE

SELECT *
FROM person
WHERE upper(person.name)='Anna';