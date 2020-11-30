#!/bin/bash
# Create text files with all combinations. BOM - little endian
#
./ex2 mac_input-utf-16.txt test_mac_copy.txt
./ex2 mac_input-utf-16.txt test_mac_to_unix.txt -mac -unix
./ex2 mac_input-utf-16.txt test_mac_to_win.txt -mac -win
./ex2 mac_input-utf-16.txt test_mac_to_mac.txt -mac -mac
./ex2 mac_input-utf-16.txt test_mac_to_unix_keep.txt -mac -unix -keep
./ex2 mac_input-utf-16.txt test_mac_to_win_keep.txt -mac -win -keep
./ex2 mac_input-utf-16.txt test_mac_to_mac_keep.txt -mac -mac -keep
./ex2 mac_input-utf-16.txt test_mac_to_unix_swap.txt -mac -unix -swap
./ex2 mac_input-utf-16.txt test_mac_to_win_swap.txt -mac -win -swap
./ex2 mac_input-utf-16.txt test_mac_to_mac_swap.txt -mac -mac -swap
./ex2 win_input-utf-16.txt test_win_copy.txt
./ex2 win_input-utf-16.txt test_win_to_unix.txt -win -unix
./ex2 win_input-utf-16.txt test_win_to_win.txt -win -win
./ex2 win_input-utf-16.txt test_win_to_mac.txt -win -mac
./ex2 win_input-utf-16.txt test_win_to_unix_keep.txt -win -unix -keep
./ex2 win_input-utf-16.txt test_win_to_win_keep.txt -win -win -keep
./ex2 win_input-utf-16.txt test_win_to_mac_keep.txt -win -mac -keep
./ex2 win_input-utf-16.txt test_win_to_unix_swap.txt -win -unix -swap
./ex2 win_input-utf-16.txt test_win_to_win_swap.txt -win -win -swap
./ex2 win_input-utf-16.txt test_win_to_mac_swap.txt -win -mac -swap
./ex2 unix_input-utf-16.txt test_unix_copy.txt
./ex2 unix_input-utf-16.txt test_unix_to_unix.txt -unix -unix
./ex2 unix_input-utf-16.txt test_unix_to_win.txt -unix -win
./ex2 unix_input-utf-16.txt test_unix_to_mac.txt -unix -mac
./ex2 unix_input-utf-16.txt test_unix_to_unix_keep.txt -unix -unix -keep
./ex2 unix_input-utf-16.txt test_unix_to_win_keep.txt -unix -win -keep
./ex2 unix_input-utf-16.txt test_unix_to_mac_keep.txt -unix -mac -keep
./ex2 unix_input-utf-16.txt test_unix_to_unix_swap.txt -unix -unix -swap
./ex2 unix_input-utf-16.txt test_unix_to_win_swap.txt -unix -win -swap
./ex2 unix_input-utf-16.txt test_unix_to_mac_swap.txt -unix -mac -swap
# Create text files with all combinations. BOM - big endian
#
./ex2 mac_input-utf-16_swap.txt stest_mac_copy.txt
./ex2 mac_input-utf-16_swap.txt stest_mac_to_unix.txt -mac -unix
./ex2 mac_input-utf-16_swap.txt stest_mac_to_win.txt -mac -win
./ex2 mac_input-utf-16_swap.txt stest_mac_to_mac.txt -mac -mac
./ex2 mac_input-utf-16_swap.txt stest_mac_to_unix_keep.txt -mac -unix -keep
./ex2 mac_input-utf-16_swap.txt stest_mac_to_win_keep.txt -mac -win -keep
./ex2 mac_input-utf-16_swap.txt stest_mac_to_mac_keep.txt -mac -mac -keep
./ex2 mac_input-utf-16_swap.txt stest_mac_to_unix_swap.txt -mac -unix -swap
./ex2 mac_input-utf-16_swap.txt stest_mac_to_win_swap.txt -mac -win -swap
./ex2 mac_input-utf-16_swap.txt stest_mac_to_mac_swap.txt -mac -mac -swap
./ex2 win_input-utf-16_swap.txt stest_win_copy.txt
./ex2 win_input-utf-16_swap.txt stest_win_to_unix.txt -win -unix
./ex2 win_input-utf-16_swap.txt stest_win_to_win.txt -win -win
./ex2 win_input-utf-16_swap.txt stest_win_to_mac.txt -win -mac
./ex2 win_input-utf-16_swap.txt stest_win_to_unix_keep.txt -win -unix -keep
./ex2 win_input-utf-16_swap.txt stest_win_to_win_keep.txt -win -win -keep
./ex2 win_input-utf-16_swap.txt stest_win_to_mac_keep.txt -win -mac -keep
./ex2 win_input-utf-16_swap.txt stest_win_to_unix_swap.txt -win -unix -swap
./ex2 win_input-utf-16_swap.txt stest_win_to_win_swap.txt -win -win -swap
./ex2 win_input-utf-16_swap.txt stest_win_to_mac_swap.txt -win -mac -swap
./ex2 unix_input-utf-16_swap.txt stest_unix_copy.txt
./ex2 unix_input-utf-16_swap.txt stest_unix_to_unix.txt -unix -unix
./ex2 unix_input-utf-16_swap.txt stest_unix_to_win.txt -unix -win
./ex2 unix_input-utf-16_swap.txt stest_unix_to_mac.txt -unix -mac
./ex2 unix_input-utf-16_swap.txt stest_unix_to_unix_keep.txt -unix -unix -keep
./ex2 unix_input-utf-16_swap.txt stest_unix_to_win_keep.txt -unix -win -keep
./ex2 unix_input-utf-16_swap.txt stest_unix_to_mac_keep.txt -unix -mac -keep
./ex2 unix_input-utf-16_swap.txt stest_unix_to_unix_swap.txt -unix -unix -swap
./ex2 unix_input-utf-16_swap.txt stest_unix_to_win_swap.txt -unix -win -swap
./ex2 unix_input-utf-16_swap.txt stest_unix_to_mac_swap.txt -unix -mac -swap
# Compare all files. BOM - big endian
#
cmp mac_input-utf-16.txt test_mac_copy.txt
cmp mac_input-utf-16.txt test_mac_to_mac.txt
cmp mac_input-utf-16.txt test_win_to_mac.txt
cmp mac_input-utf-16.txt test_unix_to_mac.txt
cmp mac_input-utf-16_keep.txt test_mac_to_mac_keep.txt
cmp mac_input-utf-16_keep.txt test_win_to_mac_keep.txt
cmp mac_input-utf-16_keep.txt test_unix_to_mac_keep.txt
cmp mac_input-utf-16_swap.txt test_mac_to_mac_swap.txt
cmp mac_input-utf-16_swap.txt test_win_to_mac_swap.txt
cmp mac_input-utf-16_swap.txt test_unix_to_mac_swap.txt
cmp win_input-utf-16.txt test_win_copy.txt
cmp win_input-utf-16.txt test_mac_to_win.txt
cmp win_input-utf-16.txt test_win_to_win.txt
cmp win_input-utf-16.txt test_unix_to_win.txt
cmp win_input-utf-16_keep.txt test_mac_to_win_keep.txt
cmp win_input-utf-16_keep.txt test_win_to_win_keep.txt
cmp win_input-utf-16_keep.txt test_unix_to_win_keep.txt
cmp win_input-utf-16_swap.txt test_mac_to_win_swap.txt
cmp win_input-utf-16_swap.txt test_win_to_win_swap.txt
cmp win_input-utf-16_swap.txt test_unix_to_win_swap.txt
cmp unix_input-utf-16.txt test_unix_copy.txt
cmp unix_input-utf-16.txt test_mac_to_unix.txt
cmp unix_input-utf-16.txt test_win_to_unix.txt
cmp unix_input-utf-16.txt test_unix_to_unix.txt
cmp unix_input-utf-16_keep.txt test_mac_to_unix_keep.txt
cmp unix_input-utf-16_keep.txt test_win_to_unix_keep.txt
cmp unix_input-utf-16_keep.txt test_unix_to_unix_keep.txt
cmp unix_input-utf-16_swap.txt test_mac_to_unix_swap.txt
cmp unix_input-utf-16_swap.txt test_win_to_unix_swap.txt
cmp unix_input-utf-16_swap.txt test_unix_to_unix_swap.txt
# Compare all files. BOM - little endian
#
cmp mac_input-utf-16_swap.txt stest_mac_copy.txt
cmp mac_input-utf-16_swap.txt stest_mac_to_mac.txt
cmp mac_input-utf-16_swap.txt stest_win_to_mac.txt
cmp mac_input-utf-16_swap.txt stest_unix_to_mac.txt
cmp mac_input-utf-16_swap.txt stest_mac_to_mac_keep.txt
cmp mac_input-utf-16_swap.txt stest_win_to_mac_keep.txt
cmp mac_input-utf-16_swap.txt stest_unix_to_mac_keep.txt
cmp mac_input-utf-16_keep.txt stest_mac_to_mac_swap.txt
cmp mac_input-utf-16_keep.txt stest_win_to_mac_swap.txt
cmp mac_input-utf-16_keep.txt stest_unix_to_mac_swap.txt
cmp win_input-utf-16_swap.txt stest_win_copy.txt
cmp win_input-utf-16_swap.txt stest_mac_to_win.txt
cmp win_input-utf-16_swap.txt stest_win_to_win.txt
cmp win_input-utf-16_swap.txt stest_unix_to_win.txt
cmp win_input-utf-16_swap.txt stest_mac_to_win_keep.txt
cmp win_input-utf-16_swap.txt stest_win_to_win_keep.txt
cmp win_input-utf-16_swap.txt stest_unix_to_win_keep.txt
cmp win_input-utf-16_keep.txt stest_mac_to_win_swap.txt
cmp win_input-utf-16_keep.txt stest_win_to_win_swap.txt
cmp win_input-utf-16_keep.txt stest_unix_to_win_swap.txt
cmp unix_input-utf-16_swap.txt stest_unix_copy.txt
cmp unix_input-utf-16_swap.txt stest_mac_to_unix.txt
cmp unix_input-utf-16_swap.txt stest_win_to_unix.txt
cmp unix_input-utf-16_swap.txt stest_unix_to_unix.txt
cmp unix_input-utf-16_swap.txt stest_mac_to_unix_keep.txt
cmp unix_input-utf-16_swap.txt stest_win_to_unix_keep.txt
cmp unix_input-utf-16_swap.txt stest_unix_to_unix_keep.txt
cmp unix_input-utf-16_keep.txt stest_mac_to_unix_swap.txt
cmp unix_input-utf-16_keep.txt stest_win_to_unix_swap.txt
cmp unix_input-utf-16_keep.txt stest_unix_to_unix_swap.txt


