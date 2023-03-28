# Lab3

* create file
  ```linux
  $ dd if=/dev/zero of={file_name} bs={block_size} count={file_size*block_size / buffer_size}
  ```

* write data to /dev/null
  ```C
  int devNull = open("/dev/null", O_WRONLY)  // return fd
  ...
  write(devNull, ...)  
  ```
  ⚠ O_WRONLY 來自 **<fcntl.c>**
  
* measure excution time
  ```
  $ time 
  ```
  
  * **real**: 執行開始到結束的時間
  * **user**: 執行代碼花費的CPU時間
  * **sys**: 在kernel中運行花費的CPU時間
  
  單個CPU: real $\geq$ user + sys
  
* fsync
  


💬 編譯指令: gcc -o [name] file1.c file2.c ...
