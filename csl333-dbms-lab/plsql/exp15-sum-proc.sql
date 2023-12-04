create or replace procedure sum_proc(a in integer, b in integer)
is
c integer;
begin
c:=a+b;
dbms_output.put_line('The sum is '||c);
end;
/

declare
a integer:=&a;
b integer:=&b;
begin
sum_proc(a,b);
end;
/