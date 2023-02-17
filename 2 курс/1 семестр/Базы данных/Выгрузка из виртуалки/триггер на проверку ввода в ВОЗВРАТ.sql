select t.*, t.rowid from БНГБПЮР t

CREATE OR REPLACE TRIGGER бнгбпюрш_опнбепйю_ббндю
AFTER
     INSERT OF йк_йк_ID, оср_оср_ID, яр_яр_ID, йнк_бгпнякшу, йнк_дереи ON бнгбпюр
     
DECLARE
       CURSOR опд IS
       SELECT DISTINCT йк_йк_ID, оср_оср_ID, яр_яр_ID, йнк_бгпнякшу, йнк_дереи FROM опндюфю


BEGIN
     FOR CUR_опд IN опд
     LOOP
         IF (CUR_опд.йк_йк_ID == :new.йк_йк_ID AND CUR_опд.оср_оср_ID == :new.оср_оср_ID AND CUR_опд.яр_яр_ID == :new.яр_яр_ID)
         THEN
             IF (CUR_опд.йнк_бгпнякшу <= :new.йнк_бгпнякшу AND CUR_опд.йнк_дереи <= :new.йнк_дереи)
             THEN
                 RAISE_APPLICATION_ERROR(-20000, 'мюпсьемхе ббндю б бнгбпюр');
             END IF;
         END IF;
      END LOOP;
END;

