var
  C: array of integer;
  n, m, s0: integer;

type 
  ai = array of integer;

procedure outputProc(c: ai; control: integer);
begin
  var i, s: integer;
  for i := 1 to length(c) - 1 do
  begin
    s := s + c[i];
  end;
  
  if s = control then 
  begin
    for i := 1 to length(c) - 1 do
    begin
      write(c[i]); 
    end;
    writeln(''); 
  end;

end;

procedure comb(k: integer);
begin
  for var i := C[k - 1] + 1 to n - m + k do
  begin
    C[k] := i;                     
    if k = m then outputProc(C, s0)
    else comb(k + 1);
  end
  
end;


begin
  read(n, m, s0);
  setLength(C, m + 1);
  C[0] := 0; comb(1);

end.
