//測驗目的：
//為了存取絕對位址把一個整數型強制轉型 (typecast) 為指標是合法的。

//https://stackoverflow.com/questions/4532000/how-to-assign-pointer-address-manually-in-c-programming-language

//存取固定的記憶體位置 (Accessing fixed memory locations)，
//設定一個絕對位址為 0x67a9 的整數型變數的值為 0xaa55，編譯器是一個純粹的 ANSI 編譯器。

//ANS：
//A1.
int *ptr;
ptr = (int *)0x67a9;
*ptr = 0xaa55;

//A2.
*(int * const)(0x67a9) = 0xaa55;