
#!/bin/bash

echo "Enter Password : "
#this will take password letter by letter
while [ 1 ] 
do

read -s pass_var
    # if you press enter then the condition 
    # is true and it exit the loop
    if [ $pass_var = "udhay" ]
    then
        echo "Password is correct"
        break
    fi
    echo "password is not correct.. "
done
echo
