begin
  var k: integer;
  readln(k);
  var M: array of string;
  SetLength(M, k);
  for var i:= 0 to (k - 1) do
  begin
    var symbl: char; //символ
    var wrd: string;// слово
    var check: boolean;
    while (symbl <> '#') or not((1040 <= ord(symbl)) and (ord(symbl) <= 1103)) do
    begin
      readln(symbl);
      wrd += symbl;
    end;
    
    if not((1040 <= ord(wrd[wrd.Length])) and (ord(wrd[wrd.Length]) <= 1103)) then
      check:= True;
        for var j:= 0 to (k - 1) do
          if M[j] = wrd then
          begin
            check:= False;
            break;
          end;
        if check then
          M[i]:= wrd
    
    else if (wrd[wrd.Length] = '#') then
    begin
      wrd[wrd.Length]:= ' ';
      for var j:= 0 to (k - 1) do
          if M[j] = wrd then
          begin
            check:= False;
            break;
          end;
        if check then
          M[i]:= wrd;
        
      break;
    end;
  end;
  
  writeln(M);
end.