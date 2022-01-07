
#!/bin/bash 

 
echo "Enter the size you want"
read r

s=0

echo "Enter Numbers"
for((i=1;i<=r;i++))
do
  read n           #get number
  s=$((s + n)) #sum+=n
done

echo $s
