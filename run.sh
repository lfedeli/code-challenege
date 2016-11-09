#!/usr/bin/env bash



# I'll execute my programs, with the input directory paymo_input and output the files in the directory paymo_output
g++ -std=c++11 -o ./src/project ./src/project.cpp
./src/project ./paymo_input/batch_payment.txt ./paymo_input/stream_payment.txt ./paymo_output/output1.txt ./paymo_output/output2.txt ./paymo_output/output3.txt

#cp ./paymo_output/output1.txt ./insight_testsuite/tests/livio-test/paymo_output//output1.txt
#cp ./paymo_output/output2.txt ./insight_testsuite/tests/livio-test/paymo_output//output2.txt
#cp ./paymo_output/output3.txt ./insight_testsuite/tests/livio-test/paymo_output//output3.txt
