# Lab5

### **_getc & putc_**
   ```
   getc(fp)
   ```
   char -> **EOF**
### **_fgets & fputs_**
  ```
  fgets(buf, buf_size, fp)
  ```
  [fgets] pointer -> **NULL**
### **_setvnuf_**
  ```
  setvbuf(fp, buf, mode, buf_size);
  ```

---
* **count the loop iteration**:
  
  add a counter into loop
  
* **create a 100mb file**:

  ``dd if=/dev/zero of=100mb_file bs=1024 count=102400``

* **measure the execution time**

  ``time ./exe_fig5_4 < 100mb_file``

* **change the buffer mode**:
  > use **``setvbuf``**
  * fully buffered  **__IOFBF_**
  * line buffered  **__IOLBF_**
  * unbuffered  **__IONBF_**
