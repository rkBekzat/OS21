echo Bekzat >../week1/file.txt

i_node=$(ls -i ../week1/file.txt | awk '{print $1;}')

rm -f ex2.txt

link ../week1/file.txt _ex2.txt >>ex2.txt
find .. -inum $i_node >>ex2.txt
find .. -inum $i_node -exec rm {} \; >> ex2.txt
