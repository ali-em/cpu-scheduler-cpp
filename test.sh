unzip A4-"$1".zip
(cd A4-"$1"/; make)
cp A4-"$1"/Scheduler.out .
echo "##### DIFF #####"
./Scheduler.out < sample.in | diff sample.out -

