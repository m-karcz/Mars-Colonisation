X=60
Y=40
NUMBER_OF_BASES=2
RANGE=40
MAP=mars2.png
for i in {1..3}; do
  echo -e "\t\t\t\t\t\t$i of 3"
  ./ConsoleApplication1.exe $X $Y $NUMBER_OF_BASES $RANGE $MAP $i.txt
done
