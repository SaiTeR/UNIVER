create or replace trigger �������_������������_����
  after insert OR UPDATE on �������  
  
for each row
declare
  cur_price Number(10,2);
begin
  SELECT �������.���� * �������.���_������� INTO cur_price FROM �������
  WHERE :new.���_���_ID = �������.���_ID;
  
  INSERT INTO �������(����) VALUES (cur_price);
end �������_������������_����;
/
