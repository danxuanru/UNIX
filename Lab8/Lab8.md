# Lab8

* **create process**
  
  在for loop裡面fork() 形成多個child process
  
* **open every file** 

  利用`sprintf` 形成依照迴圈數的檔名
  再用fopen開檔
  ```
  sprintf(tmp, "%d-%02d.txt", i+1, w);
  FILE* file = fopen(tmp, "r");
  ```
  
* **read data**
  
  用`fscaf()`讀取txt檔中的數字
  ```
  fscanf(file, "%d", &data);
  ```
  
* **Tell & Wait**

  child process: `WAIT_PARENT() ➡ accumulation() ➡ TELL_PARENT(getppid())`
  
  father process: `TELL_CHILD(pid) ➡ WAIT_CHILD()`
  
---

`sprintf`
https://shengyu7697.github.io/cpp-sprintf/

txt讀取:
https://dotblogs.com.tw/0xde/2015/06/03/151471
