X=30
Y=30
NUMBER_OF_BASES=3
RANGE=80
MAP=img.jpg

echo "Parameters: X=$X, Y=$Y, bases=$NUMBER_OF_BASES, range=$RANGE, map=$MAP"
for i in {1..3}; do
  echo -e "\t\t\t\t$i of 3"
  ./ConsoleApplication1.exe $X $Y $NUMBER_OF_BASES $RANGE $MAP $i.txt
done
