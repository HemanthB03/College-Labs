declare
    a integer:=&a;
    b integer:=&b;
    c integer:=&c;
begin
    if(a>b and a>c) then
        dbms_output.put_line('largest is '||a);
        elsif(b>c) then
        dbms_output.put_line('largest is '||b);
        else
        dbms_output.put_line('largest is '||c);
    end if;
end;
/