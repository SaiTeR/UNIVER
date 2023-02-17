CREATE OR REPLACE TRIGGER яхмупнмхгюжхъ_TEMP_осребйю_рсп
AFTER DELETE OR INSERT OR UPDATE OF оср_оср_ID, рсп_рсп_ID
ON осребйю_рсп
 
FOR EACH ROW
BEGIN
IF DELETING
    THEN
    INSERT INTO TEMP_осребйю_рсп(оср_оср_ID)VALUES (:old.оср_оср_ID);

ELSE
    INSERT INTO TEMP_осребйю_рсп(оср_оср_ID) VALUES (:NEW.оср_оср_ID);

    IF UPDATING AND :old.оср_оср_ID <> :new.оср_оср_ID
    THEN
       INSERT INTO TEMP_осребйю_рсп(оср_оср_ID) VALUES (:old.оср_оср_ID);

    END IF;
END IF;
END;
/
