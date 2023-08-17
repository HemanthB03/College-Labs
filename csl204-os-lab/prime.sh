echo "Enter a number:"
read number
i=2
 
if [ $number -eq 1 ]
then
    echo "$number is neither prime nor composite."
    exit
fi
 
while [ $i -lt $number ]
do
    if [ $((number%i)) -eq 0 ]
    then
        echo "$number is not a prime number."
        exit
    fi
   ((i++))
done
 
echo "$number is a prime number."