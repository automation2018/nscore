i=1
while [ $i != 1001 ]
do
 echo "user$i,pass$i" >> param2
 i=$(($i+1))
done
