-- CREATE SEQUENCE creates a new sequence number generator

CREATE SEQUENCE seq_person_discounts START WITH 1;
ALTER TABLE person_discounts ALTER COLUMN id SET DEFAULT nextval('seq_person_discounts');
SELECT setval('seq_person_discounts', (SELECT COUNT(*) + 1 FROM person_discounts));


-- -- The view pg_sequences provides access to useful information about each sequence in the database.
-- SELECT *
-- FROM pg_sequences
-- WHERE sequencename = 'seq_person_discounts'