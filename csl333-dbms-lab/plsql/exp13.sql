declare
    name varchar(20);
    no integer;
    total integer;
begin
    select rollno, name, (mark1+mark2+mark3) into no, name, total from student13 where rollno=&no;
    
    dbms_output.put_line('--------------------');
    dbms_output.put_line('Student Name: '||name);
    dbms_output.put_line('Roll No: '||no);
    dbms_output.put_line('Total Marks: '||total);

    if total>=250 then
        dbms_output.put_line('Grade: Distinction');
    elsif total<250 and total>=180 then
        dbms_output.put_line('Grade: First Class');
    elsif total<180 and total>=120 then
        dbms_output.put_line('Grade: Second Class');
    elsif total<120 and total>=80 then
        dbms_output.put_line('Grade: Third Class');
    elsif total<80 then
        dbms_output.put_line('Grade: Fail');
    end if;

    dbms_output.put_line('--------------------');
end;
/