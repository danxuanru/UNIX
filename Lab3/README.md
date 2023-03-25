# Lab3

* create file
  ```linux
  $ dd if=/dev/zero of={file_name} bs={block_size} count={file_size*block_size / buffer_size}
  ```

* write data to /dev/null
  ```c
  open("/dev/null", O_WRONLY)
  ```
  
* measure excution time
  ```
  $ time
  ```
  
* fsync
