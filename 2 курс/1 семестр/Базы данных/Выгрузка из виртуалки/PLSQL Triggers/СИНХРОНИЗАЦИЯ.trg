CREATE OR REPLACE TRIGGER "������������� TEMP_�������_���"
AFTER 
      INSERT OR 
      UPDATE OR 
      DELETE 
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
