X=100
Y=60
NUMBER_OF_BASES=3
RANGE=80
MAP=mars2.png

echo "Parameters: X=$X, Y=$Y, bases=$NUMBER_OF_BASES, range=$RANGE, map=$MAP"
for i in {1..5}; do
  echo -e "\t\t\t\t$i of 5"
  ./ConsoleApplication1.exe $X $Y $NUMBER_OF_BASES $RANGE $MAP $i.txt
done
