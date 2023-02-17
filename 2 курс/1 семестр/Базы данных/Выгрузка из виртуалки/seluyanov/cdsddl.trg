-- E:\seluyanov\cdsddl.trg
--
-- Generated for Oracle 10g on Thu Dec 15  01:45:13 2022 by Server Generator 10.1.2.6.18
 

PROMPT Creating Trigger '�������_ID_GENERATE'
CREATE OR REPLACE TRIGGER �������_ID_GENERATE
 BEFORE INSERT
 ON �������
 FOR EACH ROW
BEGIN
    SELECT ���_SEQ.NEXTVAL INTO :NEW.���_ID FROM DUAL;
END;
/
SHOW ERROR


PROMPT Creating Trigger '��������_��������_�����'
CREATE OR REPLACE TRIGGER ��������_��������_�����
 AFTER INSERT OR UPDATE OF ���_���_ID
, ���_�����
, ���_��������
, ��_��_ID
, ��_��_ID
 ON �������
 FOR EACH ROW
DECLARE

       CURSOR ��� IS
       SELECT 
              ��_��_ID, 
              ���_���_ID, 
              ���_��������, 
              ���_����� 
       FROM �������;
BEGIN
     FOR CUR_��� IN ���
     LOOP
         IF CUR_���.��_��_ID = :new.��_��_ID AND CUR_���.���_���_ID = :new.���_���_ID
         THEN
             IF CUR_���.���_�������� < :new.���_�������� AND CUR_���.���_����� < :new.���_�����
             THEN
                 RAISE_APPLICATION_ERROR(-20000, '��������� ����� ������ � �������');
             END IF;
         END IF;
      END LOOP;
END;
/
SHOW ERROR






PROMPT Creating Trigger '���_ID_GENERATE'
CREATE OR REPLACE TRIGGER ���_ID_GENERATE
 BEFORE INSERT
 ON ���
 FOR EACH ROW
BEGIN
    SELECT ���_SEQ.NEXTVAL INTO :NEW.���_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger '�������_ID_GENERATE'
CREATE OR REPLACE TRIGGER �������_ID_GENERATE
 BEFORE INSERT
 ON �������
 FOR EACH ROW
BEGIN
    SELECT ���_SEQ.NEXTVAL INTO :NEW.���_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger '������_ID_GENERATE'
CREATE OR REPLACE TRIGGER ������_ID_GENERATE
 BEFORE INSERT
 ON ������
 FOR EACH ROW
BEGIN
    SELECT ��_SEQ.NEXTVAL INTO :NEW.��_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger '�������_ID_GENERATE'
CREATE OR REPLACE TRIGGER �������_ID_GENERATE
 BEFORE INSERT
 ON �������
 FOR EACH ROW
BEGIN
    SELECT ���_SEQ.NEXTVAL INTO :NEW.���_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger '�������_ID_GENERATE'
CREATE OR REPLACE TRIGGER �������_ID_GENERATE
 BEFORE INSERT
 ON �������
 FOR EACH ROW
BEGIN
    SELECT ���_SEQ.NEXTVAL INTO :NEW.���_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger '�����_ID_GENERATE'
CREATE OR REPLACE TRIGGER �����_ID_GENERATE
 BEFORE INSERT
 ON �����
 FOR EACH ROW
BEGIN
    SELECT ���_SEQ.NEXTVAL INTO :NEW.���_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger '�������_����������_����'
CREATE OR REPLACE TRIGGER �������_����������_����
 AFTER DELETE OR INSERT OR UPDATE OF ���_���_ID
, ���_���_ID
 ON �������_���
DECLARE

  CURSOR TMP_������� IS
      SELECT DISTINCT ���_���_ID FROM TEMP_�������_���;
      
  SUMM_��� NUMBER(10,2);
BEGIN
  SUMM_��� := 0;
  FOR CUR_��� IN TMP_�������
  LOOP
      SELECT SUM(���.���������) INTO SUMM_��� FROM �������_���, ���
      WHERE 
            �������_���.���_���_ID = ���.���_ID AND
            CUR_���.���_���_ID = �������_���.���_���_ID;
       
      IF SUMM_��� IS NULL
      THEN
         SUMM_��� := 0;
      END IF;
      UPDATE ������� SET ���� = SUMM_��� 
      WHERE �������.���_ID = CUR_���.���_���_ID;
  END LOOP;
  
  DELETE TEMP_�������_���; 
END;
/
SHOW ERROR


PROMPT Creating Trigger '�������������_TEMP_�������_���'
CREATE OR REPLACE TRIGGER �������������_TEMP_�������_���
 AFTER DELETE OR INSERT OR UPDATE OF ���_���_ID
, ���_���_ID
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
SHOW ERROR




PROMPT Creating Trigger '������_ID_GENERATE'
CREATE OR REPLACE TRIGGER ������_ID_GENERATE
 BEFORE INSERT
 ON ������
 FOR EACH ROW
BEGIN
    SELECT ���_SEQ.NEXTVAL INTO :NEW.���_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger '���������_ID_GENERATE'
CREATE OR REPLACE TRIGGER ���������_ID_GENERATE
 BEFORE INSERT
 ON ���������
 FOR EACH ROW
BEGIN
    SELECT ��_SEQ.NEXTVAL INTO :NEW.��_ID FROM DUAL;
END;
/
SHOW ERROR




PROMPT Creating Trigger '���_����_ID_GENERATE'
CREATE OR REPLACE TRIGGER ���_����_ID_GENERATE
 BEFORE INSERT
 ON ���_����
 FOR EACH ROW
BEGIN
    SELECT ��_SEQ.NEXTVAL INTO :NEW.��_ID FROM DUAL;
END;
/
SHOW ERROR





