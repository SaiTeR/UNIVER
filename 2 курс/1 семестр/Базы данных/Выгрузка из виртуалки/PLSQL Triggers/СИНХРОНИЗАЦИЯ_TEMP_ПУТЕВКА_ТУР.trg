CREATE OR REPLACE TRIGGER �������������_TEMP_�������_���
AFTER DELETE OR INSERT OR UPDATE OF ���_���_ID, ���_���_ID
ON �������_���
 
FOR EACH ROW
BEGIN
IF DELETING
    THEN
    INSERT INTO TEMP_�������_���(���_���_ID)VALUES (:old.���_���_ID);

ELSE
    INSERT INTO TEMP_�������_���(���_���_ID) VALUES (:NEW.���_���_ID);

    IF UPDATING AND :old.���_���_ID <> :new.���_���_ID
    THEN
       INSERT INTO TEMP_�������_���(���_���_ID) VALUES (:old.���_���_ID);

    END IF;
END IF;
END;
/
