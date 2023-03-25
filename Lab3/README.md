# Lab3

* create file
  ```linux
  $ dd if=/dev/zero of={file_name} bs={block_size} count={file_size*block_size / buffer_size}
  ```

* write data to /dev/null
  ```c
  open("/dev/null", O_WRONLY)
  ```
  ⚠ O_WRONLY 來自 **<fcntl.c>**
  
* measure excution time
  ```
  $ time
  ```
  
* fsync


💬 編譯指令: gcc -o [name] file1.c file2.c ...
