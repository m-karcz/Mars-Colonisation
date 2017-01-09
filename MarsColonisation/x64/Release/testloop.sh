X=70
Y=40
NUMBER_OF_BASES=2
RANGE=80
MAX_SLOPE=30
MAP=img2.png

echo "Parameters: X=$X, Y=$Y, bases=$NUMBER_OF_BASES, range=$RANGE, maxslope=$MAX_SLOPE, map=$MAP"
for i in {1..5}; do
  echo -e "\t\t\t\t$i of 5"
  ./MarsColonisation.exe $X $Y $NUMBER_OF_BASES $RANGE $MAX_SLOPE $MAP $i.txt
done

read end

