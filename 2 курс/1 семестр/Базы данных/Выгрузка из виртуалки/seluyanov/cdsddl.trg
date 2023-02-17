-- E:\seluyanov\cdsddl.trg
--
-- Generated for Oracle 10g on Thu Dec 15  01:45:13 2022 by Server Generator 10.1.2.6.18
 

PROMPT Creating Trigger 'бнгбпюр_ID_GENERATE'
CREATE OR REPLACE TRIGGER бнгбпюр_ID_GENERATE
 BEFORE INSERT
 ON бнгбпюр
 FOR EACH ROW
BEGIN
    SELECT бгп_SEQ.NEXTVAL INTO :NEW.бгп_ID FROM DUAL;
END;
/
SHOW ERROR


PROMPT Creating Trigger 'бнгбпюрш_опнбепйю_ббндю'
CREATE OR REPLACE TRIGGER бнгбпюрш_опнбепйю_ббндю
 AFTER INSERT OR UPDATE OF оср_оср_ID
, йнк_дереи
, йнк_бгпнякшу
, яр_яр_ID
, йк_йк_ID
 ON бнгбпюр
 FOR EACH ROW
DECLARE

       CURSOR опд IS
       SELECT 
              йк_йк_ID, 
              оср_оср_ID, 
              йнк_бгпнякшу, 
              йнк_дереи 
       FROM опндюфю;
BEGIN
     FOR CUR_опд IN опд
     LOOP
         IF CUR_опд.йк_йк_ID = :new.йк_йк_ID AND CUR_опд.оср_оср_ID = :new.оср_оср_ID
         THEN
             IF CUR_опд.йнк_бгпнякшу < :new.йнк_бгпнякшу AND CUR_опд.йнк_дереи < :new.йнк_дереи
             THEN
                 RAISE_APPLICATION_ERROR(-20000, 'мюпсьемхе ббндю дюммшу б бнгбпюр');
             END IF;
         END IF;
      END LOOP;
END;
/
SHOW ERROR






PROMPT Creating Trigger 'рсп_ID_GENERATE'
CREATE OR REPLACE TRIGGER рсп_ID_GENERATE
 BEFORE INSERT
 ON рсп
 FOR EACH ROW
BEGIN
    SELECT рсп_SEQ.NEXTVAL INTO :NEW.рсп_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger 'осребйю_ID_GENERATE'
CREATE OR REPLACE TRIGGER осребйю_ID_GENERATE
 BEFORE INSERT
 ON осребйю
 FOR EACH ROW
BEGIN
    SELECT оср_SEQ.NEXTVAL INTO :NEW.оср_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger 'йкхемр_ID_GENERATE'
CREATE OR REPLACE TRIGGER йкхемр_ID_GENERATE
 BEFORE INSERT
 ON йкхемр
 FOR EACH ROW
BEGIN
    SELECT йк_SEQ.NEXTVAL INTO :NEW.йк_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger 'охрюмхе_ID_GENERATE'
CREATE OR REPLACE TRIGGER охрюмхе_ID_GENERATE
 BEFORE INSERT
 ON охрюмхе
 FOR EACH ROW
BEGIN
    SELECT охр_SEQ.NEXTVAL INTO :NEW.охр_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger 'опндюфю_ID_GENERATE'
CREATE OR REPLACE TRIGGER опндюфю_ID_GENERATE
 BEFORE INSERT
 ON опндюфю
 FOR EACH ROW
BEGIN
    SELECT опд_SEQ.NEXTVAL INTO :NEW.опд_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger 'нрекэ_ID_GENERATE'
CREATE OR REPLACE TRIGGER нрекэ_ID_GENERATE
 BEFORE INSERT
 ON нрекэ
 FOR EACH ROW
BEGIN
    SELECT нрк_SEQ.NEXTVAL INTO :NEW.нрк_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger 'осребйю_оепепюявер_жемш'
CREATE OR REPLACE TRIGGER осребйю_оепепюявер_жемш
 AFTER DELETE OR INSERT OR UPDATE OF оср_оср_ID
, рсп_рсп_ID
 ON осребйю_рсп
DECLARE

  CURSOR TMP_осребйх IS
      SELECT DISTINCT оср_оср_ID FROM TEMP_осребйю_рсп;
      
  SUMM_рсп NUMBER(10,2);
BEGIN
  SUMM_рсп := 0;
  FOR CUR_оср IN TMP_осребйх
  LOOP
      SELECT SUM(рсп.ярнхлнярэ) INTO SUMM_рсп FROM осребйю_рсп, рсп
      WHERE 
            осребйю_рсп.рсп_рсп_ID = рсп.рсп_ID AND
            CUR_оср.оср_оср_ID = осребйю_рсп.оср_оср_ID;
       
      IF SUMM_рсп IS NULL
      THEN
         SUMM_рсп := 0;
      END IF;
      UPDATE осребйю SET жемю = SUMM_рсп 
      WHERE осребйю.оср_ID = CUR_оср.оср_оср_ID;
  END LOOP;
  
  DELETE TEMP_осребйю_рсп; 
END;
/
SHOW ERROR


PROMPT Creating Trigger 'яхмупнмхгюжхъ_TEMP_осребйю_рсп'
CREATE OR REPLACE TRIGGER яхмупнмхгюжхъ_TEMP_осребйю_рсп
 AFTER DELETE OR INSERT OR UPDATE OF оср_оср_ID
, рсп_рсп_ID
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
SHOW ERROR




PROMPT Creating Trigger 'ярпюмю_ID_GENERATE'
CREATE OR REPLACE TRIGGER ярпюмю_ID_GENERATE
 BEFORE INSERT
 ON ярпюмю
 FOR EACH ROW
BEGIN
    SELECT ярп_SEQ.NEXTVAL INTO :NEW.ярп_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger 'янрпсдмхй_ID_GENERATE'
CREATE OR REPLACE TRIGGER янрпсдмхй_ID_GENERATE
 BEFORE INSERT
 ON янрпсдмхй
 FOR EACH ROW
BEGIN
    SELECT яр_SEQ.NEXTVAL INTO :NEW.яр_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger 'бхд_рспю_ID_GENERATE'
CREATE OR REPLACE TRIGGER бхд_рспю_ID_GENERATE
 BEFORE INSERT
 ON бхд_рспю
 FOR EACH ROW
BEGIN
    SELECT бр_SEQ.NEXTVAL INTO :NEW.бр_ID FROM DUAL;
END;
/
SHOW ERROR





