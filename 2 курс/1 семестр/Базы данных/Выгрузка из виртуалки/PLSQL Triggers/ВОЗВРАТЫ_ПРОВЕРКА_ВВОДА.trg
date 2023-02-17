CREATE OR REPLACE TRIGGER бнгбпюрш_опнбепйю_ббндю
AFTER
     INSERT OR UPDATE OF 
            йк_йк_ID, оср_оср_ID, яр_яр_ID, йнк_бгпнякшу, йнк_дереи ON бнгбпюр
            
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
END бнгбпюрш_опнбепйю_ббндю;
/
