declare
    grade char(1):=&grade;
begin
    case grade
        when 'A' then dbms_output.put_line('Excellent');
        when 'B' then dbms_output.put_line('Very Good');
        when 'C' then dbms_output.put_line('Well Done');
        when 'D' then dbms_output.put_line('You Passed');
        when 'F' then dbms_output.put_line('Better Try Again');
        else dbms_output.put_line('No such grade');
    end case;
end;
/