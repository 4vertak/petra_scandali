 --create a Database Trigger Function
CREATE OR REPLACE FUNCTION fnc_trg_person_delete_audit() RETURNS trigger AS $fnc_trg_person_delete_audit$
    BEGIN
        IF (TG_OP = 'DELETE') 
        	THEN INSERT INTO person_audit SELECT current_timestamp, 'D', OLD.id, OLD.name, OLD.age, OLD.gender, OLD.address;
        END IF;
        RETURN NULL;
    END;
$fnc_trg_person_delete_audit$ LANGUAGE plpgsql;

--define a Database Trigger
CREATE TRIGGER trg_person_delete_audit AFTER DELETE
    ON person
    FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_delete_audit();
    
--Delete
DELETE FROM person WHERE id = 10;

--Check
select * from person_audit;