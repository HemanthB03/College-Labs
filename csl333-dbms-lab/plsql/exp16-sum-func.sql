create or replace function sum_func(a in integer, b in integer)
return integer
is
c integer;
begin
c:=a+b;
return c;
end;
/

declare
a integer:=&a;
b integer:=&b;
c integer;
begin
c:=sum_func(a,b);
dbms_output.put_line('The sum is '||c);
end;
/