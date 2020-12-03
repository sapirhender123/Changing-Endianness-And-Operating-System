##########
# command line args checks

./a.out mac_input-utf-16.txt

./a.out mac_input-utf-16.txt dontWriteMe1.txt -mac
test -e dontWriteMe1.txt && echo Check-1 failed

./a.out fileWhichDoesntExist.txt dontWriteMe2.txt
test -e dontWriteMe2.txt && echo Check-2 failed

./a.out mac_input-utf-16.txt -mac
test -e "-mac" && echo Check-3 failed

./a.out mac_input-utf-16.txt dontWriteMe4.txt -mac -swap
test -e dontWriteMe4.txt && echo Check-4 failed

./a.out mac_input-utf-16.txt testfile.hello
./a.out testfile.hello worldworld.test
test -e worldworld.test || echo Check-5 failed


rm -f "./-mac" dontWriteMe1.txt dontWriteMe2.txt dontWriteMe4.txt testfile.hello worldworld.test