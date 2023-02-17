CREATE OR REPLACE TRIGGER �������_����������_����

AFTER DELETE OR INSERT OR UPDATE OF ���_���_ID, ���_���_ID
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
