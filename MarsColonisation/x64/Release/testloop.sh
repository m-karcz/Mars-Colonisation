X=100
Y=70
NUMBER_OF_BASES=3
RANGE=80
MAX_SLOPE=30
MAP=mars2.png

echo "Parameters: X=$X, Y=$Y, bases=$NUMBER_OF_BASES, range=$RANGE, maxslope=$MAX_SLOPE, map=$MAP"
for i in {1..3}; do
  echo -e "\t\t\t\t$i of 3"
  ./MarsColonisation.exe $X $Y $NUMBER_OF_BASES $RANGE $MAX_SLOPE $MAP $i.txt
done
