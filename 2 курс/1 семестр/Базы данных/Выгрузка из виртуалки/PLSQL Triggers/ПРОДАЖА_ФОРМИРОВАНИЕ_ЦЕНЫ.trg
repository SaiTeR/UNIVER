create or replace trigger опндюфю_тнплхпнбюмхе_жемш
  after insert OR UPDATE on ОПНДЮФЮ  
  
for each row
declare
  cur_price Number(10,2);
begin
  SELECT осребйю.жемю * осребйю.йнк_осребнй INTO cur_price FROM осребйю
  WHERE :new.оср_оср_ID = осребйю.оср_ID;
  
  INSERT INTO опндюфю(жемю) VALUES (cur_price);
end опндюфю_тнплхпнбюмхе_жемш;
/
