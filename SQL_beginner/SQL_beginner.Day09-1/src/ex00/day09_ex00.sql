--create a table
CREATE TABLE person_audit (
    created TIMESTAMP WITH TIME ZONE DEFAULT current_timestamp NOT NULL,
    type_event CHAR(1) DEFAULT 'I' NOT NULL,
    row_id BIGINT NOT NULL,
    name VARCHAR,
    age INTEGER,
    gender VARCHAR,
    address VARCHAR,
	CONSTRAINT ch_type_event CHECK(type_event IN ('I','U','D'))
);

 --create a Database Trigger Function
CREATE OR REPLACE FUNCTION fnc_trg_person_insert_audit() RETURNS trigger AS $fnc_trg_person_insert_audit$
	BEGIN 
    	IF(TG_OP = 'INSERT') THEN 
        	INSERT INTO person_audit SELECT current_timestamp, 'I', new.id, new.name, new.age, new.gender, new.address;
		END IF;
	RETURN NULL;
END;
$fnc_trg_person_insert_audit$ LANGUAGE plpgsql;

--define a Database Trigger
CREATE TRIGGER trg_person_insert_audit AFTER INSERT ON person
FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_insert_audit();

--Insert into
INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk');

--Check
select * from person_audit;