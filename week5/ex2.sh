input="ex2.txt"
while true
	do
	if  `ln $input lock`; then 
		readarray a < "$input"
		((counter = 0))
		for i in ${a[@]}
		do
			((counter++))
		done
		((counter--))
		((n = ${a[$counter]}))
		((n++))
		echo "$n" >> $input
		rm lock
	fi
done

