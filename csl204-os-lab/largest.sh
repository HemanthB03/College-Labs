echo "Enter three numbers: "
read a
read b
read c

if ((a>b))
then
    if ((a>c))
    then
        echo "$a is largest"
    else 
        echo "$c is largest"
    fi
else
    if ((b>c))
    then 
        echo "$b is largest"
    else 
        echo "$c is largest"
    fi
fi