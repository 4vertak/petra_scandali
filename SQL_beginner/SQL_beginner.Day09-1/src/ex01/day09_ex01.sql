--create a Database Trigger Function
CREATE OR REPLACE FUNCTION fnc_trg_person_update_audit() RETURNS trigger AS $fnc_trg_person_update_audit$
    BEGIN
		IF (TG_OP = 'UPDATE') THEN INSERT INTO person_audit SELECT current_timestamp, 'U', OLD.id, OLD.name, OLD.age, OLD.gender, OLD.address;
        END IF;
        RETURN NULL;
    END;
$fnc_trg_person_update_audit$ LANGUAGE plpgsql;

--define a Database Trigger
CREATE TRIGGER trg_person_update_audit AFTER UPDATE ON person
FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_update_audit();

--Update
UPDATE person SET name = 'Bulat' WHERE id = 10;
UPDATE person SET name = 'Damir' WHERE id = 10;

--Check
SELECT * FROM person_audit;