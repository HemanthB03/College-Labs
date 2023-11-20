create or replace procedure inctax(sal in integer, tax out integer) is
    a integer;
begin
    a:=sal*12;
    if(a<=100000) then
        tax:=0;
    elsif(a<=150000 and a>100000) then
        tax:=((a-100000)*0.1);
    elsif(a<=200000 and a>150000) then
        tax:=((a-100000)*0.2);
    elsif(a>200000) then
        tax:=((a-100000)*0.3);
    end if;
end;
/

declare
    t tax.tax_amount%type;
    s employee.salary%type;
    no employee.eno%type;
    dno employee.deptno%type;
begin
    no:=&no;
    select salary, deptno into s, dno from employee where eno=no;
    inctax(s, t);
    insert into tax(eno, deptno, tax_amount) values(no, dno, t);
    dbms_output.put_line('Emp No:'||no);
    dbms_output.put_line('Dept No:'||dno);
    dbms_output.put_line('Tax:'||t);
commit;
end;
/