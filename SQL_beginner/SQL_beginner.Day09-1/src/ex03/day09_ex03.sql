-- drop trigger, function and delete person_audit
DROP TRIGGER trg_person_insert_audit ON public.person;
DROP TRIGGER trg_person_update_audit ON public.person;
DROP TRIGGER trg_person_delete_audit ON public.person;

DROP function fnc_trg_person_insert_audit();
DROP function fnc_trg_person_delete_audit();
DROP function fnc_trg_person_update_audit();

truncate person_audit;

 --create a Database Trigger Function
CREATE OR REPLACE FUNCTION fnc_trg_person_audit() RETURNS trigger AS $fnc_trg_person_audit$
	BEGIN
		IF (TG_OP = 'INSERT') THEN INSERT INTO person_audit SELECT current_timestamp, 'I', NEW.*;
		RETURN NEW;
		ELSIF (TG_OP = 'UPDATE') THEN INSERT INTO person_audit SELECT current_timestamp, 'U', NEW.*;
		RETURN NEW;
        ELSIF (TG_OP = 'DELETE') THEN INSERT INTO person_audit SELECT current_timestamp, 'D', OLD.*;
		RETURN OLD;
	END IF;
	RETURN NULL;
END;
$fnc_trg_person_audit$ LANGUAGE plpgsql;

--define a Database Trigger
CREATE TRIGGER trg_person_audit AFTER INSERT OR UPDATE OR DELETE ON person
FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_audit();

--insert, update and delete
INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk');
UPDATE person SET name = 'Bulat' WHERE id = 10; 
UPDATE person SET name = 'Damir' WHERE id = 10;
DELETE FROM person WHERE id = 10;

--Check
select * from person_audit;