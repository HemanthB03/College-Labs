declare
    a integer:=&a;
    b integer:=&b;
    c integer;
begin
    c:=a+b;
    dbms_output.put_line('sum is '||c);
end;
/