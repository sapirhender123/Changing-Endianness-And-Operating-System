////Create text files with all combinations. BOM - little endian
//#
//./a.out mac_input-utf-16.txt test_mac_copy.txt
//./a.out mac_input-utf-16.txt test_mac_to_unix.txt -mac -unix
//./a.out mac_input-utf-16.txt test_mac_to_win.txt -mac -win
//./a.out mac_input-utf-16.txt test_mac_to_mac.txt -mac -mac
//./a.out mac_input-utf-16.txt test_mac_to_unix_keep.txt -mac -unix -keep
//./a.out mac_input-utf-16.txt test_mac_to_win_keep.txt -mac -win -keep
//./a.out mac_input-utf-16.txt test_mac_to_mac_keep.txt -mac -mac -keep
//./a.out mac_input-utf-16.txt test_mac_to_unix_swap.txt -mac -unix -swap
//./a.out mac_input-utf-16.txt test_mac_to_win_swap.txt -mac -win -swap
//./a.out mac_input-utf-16.txt test_mac_to_mac_swap.txt -mac -mac -swap
//./a.out win_input-utf-16.txt test_win_copy.txt
//./a.out win_input-utf-16.txt test_win_to_unix.txt -win -unix
//./a.out win_input-utf-16.txt test_win_to_win.txt -win -win
//./a.out win_input-utf-16.txt test_win_to_mac.txt -win -mac
//./a.out win_input-utf-16.txt test_win_to_unix_keep.txt -win -unix -keep
//./a.out win_input-utf-16.txt test_win_to_win_keep.txt -win -win -keep
//./a.out win_input-utf-16.txt test_win_to_mac_keep.txt -win -mac -keep
//./a.out win_input-utf-16.txt test_win_to_unix_swap.txt -win -unix -swap
//./a.out win_input-utf-16.txt test_win_to_win_swap.txt -win -win -swap
//./a.out win_input-utf-16.txt test_win_to_mac_swap.txt -win -mac -swap
//./a.out unix_input-utf-16.txt test_unix_copy.txt
//./a.out unix_input-utf-16.txt test_unix_to_unix.txt -unix -unix
//./a.out unix_input-utf-16.txt test_unix_to_win.txt -unix -win
//./a.out unix_input-utf-16.txt test_unix_to_mac.txt -unix -mac
//./a.out unix_input-utf-16.txt test_unix_to_unix_keep.txt -unix -unix -keep
//./a.out unix_input-utf-16.txt test_unix_to_win_keep.txt -unix -win -keep
//./a.out unix_input-utf-16.txt test_unix_to_mac_keep.txt -unix -mac -keep
//./a.out unix_input-utf-16.txt test_unix_to_unix_swap.txt -unix -unix -swap
//./a.out unix_input-utf-16.txt test_unix_to_win_swap.txt -unix -win -swap
//./a.out unix_input-utf-16.txt test_unix_to_mac_swap.txt -unix -mac -swap
//# Create text files with all combinations. BOM - big endian
//#
//./a.out mac_input-utf-16_swap.txt stest_mac_copy.txt
//./a.out mac_input-utf-16_swap.txt stest_mac_to_unix.txt -mac -unix
//./a.out mac_input-utf-16_swap.txt stest_mac_to_win.txt -mac -win
//./a.out mac_input-utf-16_swap.txt stest_mac_to_mac.txt -mac -mac
//./a.out mac_input-utf-16_swap.txt stest_mac_to_unix_keep.txt -mac -unix -keep
//./a.out mac_input-utf-16_swap.txt stest_mac_to_win_keep.txt -mac -win -keep
//./a.out mac_input-utf-16_swap.txt stest_mac_to_mac_keep.txt -mac -mac -keep
//./a.out mac_input-utf-16_swap.txt stest_mac_to_unix_swap.txt -mac -unix -swap
//./a.out mac_input-utf-16_swap.txt stest_mac_to_win_swap.txt -mac -win -swap
//./a.out mac_input-utf-16_swap.txt stest_mac_to_mac_swap.txt -mac -mac -swap
//./a.out win_input-utf-16_swap.txt stest_win_copy.txt
//./a.out win_input-utf-16_swap.txt stest_win_to_unix.txt -win -unix
//./a.out win_input-utf-16_swap.txt stest_win_to_win.txt -win -win
//./a.out win_input-utf-16_swap.txt stest_win_to_mac.txt -win -mac
//./a.out win_input-utf-16_swap.txt stest_win_to_unix_keep.txt -win -unix -keep
//./a.out win_input-utf-16_swap.txt stest_win_to_win_keep.txt -win -win -keep
//./a.out win_input-utf-16_swap.txt stest_win_to_mac_keep.txt -win -mac -keep
//./a.out win_input-utf-16_swap.txt stest_win_to_unix_swap.txt -win -unix -swap
//./a.out win_input-utf-16_swap.txt stest_win_to_win_swap.txt -win -win -swap
//./a.out win_input-utf-16_swap.txt stest_win_to_mac_swap.txt -win -mac -swap
//./a.out unix_input-utf-16_swap.txt stest_unix_copy.txt
//./a.out unix_input-utf-16_swap.txt stest_unix_to_unix.txt -unix -unix
//./a.out unix_input-utf-16_swap.txt stest_unix_to_win.txt -unix -win
//./a.out unix_input-utf-16_swap.txt stest_unix_to_mac.txt -unix -mac
//./a.out unix_input-utf-16_swap.txt stest_unix_to_unix_keep.txt -unix -unix -keep
//./a.out unix_input-utf-16_swap.txt stest_unix_to_win_keep.txt -unix -win -keep
//./a.out unix_input-utf-16_swap.txt stest_unix_to_mac_keep.txt -unix -mac -keep
//./a.out unix_input-utf-16_swap.txt stest_unix_to_unix_swap.txt -unix -unix -swap
//./a.out unix_input-utf-16_swap.txt stest_unix_to_win_swap.txt -unix -win -swap
//./a.out unix_input-utf-16_swap.txt stest_unix_to_mac_swap.txt -unix -mac -swap
//# Compare all files. BOM - big endian
//#
//cmp mac_input-utf-16.txt test_mac_copy.txt
//        cmp mac_input-utf-16.txt test_mac_to_mac.txt
//        cmp mac_input-utf-16.txt test_win_to_mac.txt
//        cmp mac_input-utf-16.txt test_unix_to_mac.txt
//        cmp mac_input-utf-16_keep.txt test_mac_to_mac_keep.txt
//        cmp mac_input-utf-16_keep.txt test_win_to_mac_keep.txt
//        cmp mac_input-utf-16_keep.txt test_unix_to_mac_keep.txt
//        cmp mac_input-utf-16_swap.txt test_mac_to_mac_swap.txt
//        cmp mac_input-utf-16_swap.txt test_win_to_mac_swap.txt
//        cmp mac_input-utf-16_swap.txt test_unix_to_mac_swap.txt
//        cmp win_input-utf-16.txt test_win_copy.txt
//        cmp win_input-utf-16.txt test_mac_to_win.txt
//        cmp win_input-utf-16.txt test_win_to_win.txt
//        cmp win_input-utf-16.txt test_unix_to_win.txt
//        cmp win_input-utf-16_keep.txt test_mac_to_win_keep.txt
//        cmp win_input-utf-16_keep.txt test_win_to_win_keep.txt
//        cmp win_input-utf-16_keep.txt test_unix_to_win_keep.txt
//        cmp win_input-utf-16_swap.txt test_mac_to_win_swap.txt
//        cmp win_input-utf-16_swap.txt test_win_to_win_swap.txt
//        cmp win_input-utf-16_swap.txt test_unix_to_win_swap.txt
//        cmp unix_input-utf-16.txt test_unix_copy.txt
//        cmp unix_input-utf-16.txt test_mac_to_unix.txt
//        cmp unix_input-utf-16.txt test_win_to_unix.txt
//        cmp unix_input-utf-16.txt test_unix_to_unix.txt
//        cmp unix_input-utf-16_keep.txt test_mac_to_unix_keep.txt
//        cmp unix_input-utf-16_keep.txt test_win_to_unix_keep.txt
//        cmp unix_input-utf-16_keep.txt test_unix_to_unix_keep.txt
//        cmp unix_input-utf-16_swap.txt test_mac_to_unix_swap.txt
//        cmp unix_input-utf-16_swap.txt test_win_to_unix_swap.txt
//        cmp unix_input-utf-16_swap.txt test_unix_to_unix_swap.txt
//# Compare all files. BOM - little endian
//#
//cmp mac_input-utf-16_swap.txt stest_mac_copy.txt
//        cmp mac_input-utf-16_swap.txt stest_mac_to_mac.txt
//        cmp mac_input-utf-16_swap.txt stest_win_to_mac.txt
//        cmp mac_input-utf-16_swap.txt stest_unix_to_mac.txt
//        cmp mac_input-utf-16_swap.txt stest_mac_to_mac_keep.txt
//        cmp mac_input-utf-16_swap.txt stest_win_to_mac_keep.txt
//        cmp mac_input-utf-16_swap.txt stest_unix_to_mac_keep.txt
//        cmp mac_input-utf-16_keep.txt stest_mac_to_mac_swap.txt
//        cmp mac_input-utf-16_keep.txt stest_win_to_mac_swap.txt
//        cmp mac_input-utf-16_keep.txt stest_unix_to_mac_swap.txt
//        cmp win_input-utf-16_swap.txt stest_win_copy.txt
//        cmp win_input-utf-16_swap.txt stest_mac_to_win.txt
//        cmp win_input-utf-16_swap.txt stest_win_to_win.txt
//        cmp win_input-utf-16_swap.txt stest_unix_to_win.txt
//        cmp win_input-utf-16_swap.txt stest_mac_to_win_keep.txt
//        cmp win_input-utf-16_swap.txt stest_win_to_win_keep.txt
//        cmp win_input-utf-16_swap.txt stest_unix_to_win_keep.txt
//        cmp win_input-utf-16_keep.txt stest_mac_to_win_swap.txt
//        cmp win_input-utf-16_keep.txt stest_win_to_win_swap.txt
//        cmp win_input-utf-16_keep.txt stest_unix_to_win_swap.txt
//        cmp unix_input-utf-16_swap.txt stest_unix_copy.txt
//        cmp unix_input-utf-16_swap.txt stest_mac_to_unix.txt
//        cmp unix_input-utf-16_swap.txt stest_win_to_unix.txt
//        cmp unix_input-utf-16_swap.txt stest_unix_to_unix.txt
//        cmp unix_input-utf-16_swap.txt stest_mac_to_unix_keep.txt
//        cmp unix_input-utf-16_swap.txt stest_win_to_unix_keep.txt
//        cmp unix_input-utf-16_swap.txt stest_unix_to_unix_keep.txt
//        cmp unix_input-utf-16_keep.txt stest_mac_to_unix_swap.txt
//        cmp unix_input-utf-16_keep.txt stest_win_to_unix_swap.txt
//        cmp unix_input-utf-16_keep.txt stest_unix_to_unix_swap.txt
//
//
