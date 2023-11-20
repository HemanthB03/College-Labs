declare
    n integer;
    temp_sum integer;
    r integer;
begin
    n := &n;
    temp_sum := 0;
    while n <> 0 loop
        r := mod(n, 10);
        temp_sum := temp_sum + r;
        n := trunc(n / 10);
    end loop;
    dbms_output.put_line('sum of digits = '|| temp_sum);
end;
/