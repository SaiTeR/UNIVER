CREATE OR REPLACE TRIGGER ��������_��������_�����
AFTER
     INSERT OR UPDATE OF 
            ��_��_ID, ���_���_ID, ��_��_ID, ���_��������, ���_����� ON �������
            
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
END ��������_��������_�����;
/
