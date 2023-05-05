# Lab4

* figure4-22.c 
  * myftw
  * dopath
    * lstat ➡ [fail] myfunc(FTW_NS)
    * S_ISDIR == 0 (not a directory) ➡ [is file] myfunc(FTW_F)
    * func
    * ``opendir`` + while ``readdir``
  * myfunc
    > 判斷file type
    
    * FTW_F 為file
      ➡ 再利用st_mode判斷file種類
    * FTW_D 為directory
    * FTW_DNR 無法read的directory
    * FTW_NS 無法stat


### _**can't read directory**_
  
  💡 ``chmod`` (change directory premission)
  ```
  chmod(fullpath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  ```
  
### _**count total size**_
  
  💡 ``st_size``
  
  ```
  off_t total_size;
  ...
  total_size += statbuf.st_size;
  ```

  ❗ lstat成功後即計算size (directory的st_size並非為底下所有檔案的大小 不會重複計算)

### _**count invalid / valid symbolic link**_

  💡``readlink`` + ``access``
  
  ```
  if (readlink(fullpath, buf, sizeof(buf)) != -1)
			if (access(buf, F_OK) == -1)
				invalid++;
			else
				valid++;
  ```

❗❗⚠ 判斷點設在 myfunc-file類別(FTW_F)-S_IFLNK ❌
  需設在dopath-readdir中 ✔
