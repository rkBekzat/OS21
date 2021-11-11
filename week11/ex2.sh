echo "Hello world" > lofsdisk/file1
echo "Hello second world" > lofsdisk/file2
sudo chmod 777 lofsdisk/


sudo mkdir -p lofsdisk/{bin,lib64,lib}
sudo cp /bin/{bash,cat,echo,ls} lofsdisk/bin
libs="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for i in $libs; do sudo cp "$i" "${J}${i}"; done
libs="$(ldd /bin/cat | egrep -o '/lib.*\.[0-9]')"
for i in $libs; do sudo cp "$i" "${J}${i}"; done
libs="$(ldd /bin/echo | egrep -o '/lib.*\.[0-9]')"
for i in $libs; do sudo cp "$i" "${J}${i}"; done
libs="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for i in $libs; do sudo cp "$i" "${J}${i}"; done


sudo gcc -o ex2.out ex2.c

sudo cp ./ex2.out lofsdisk/

sudo chroot lofsdisk ./ex2.out >> ex2.txt

./ex2.out >> ex2.txt
