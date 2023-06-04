for (( i = 0 ; i < 10000 ; ++ i ))
do
    if [ -d Round\ $i* ]
    then
        echo $i
        mv Round\ $i* Round$i
    fi
done
