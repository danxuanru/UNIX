## LAB1

### 更動fig1.10 模擬ls, cp, mkdir, cd的功能

📝 exec系列的執行原理 [參考](https://jasonblog.github.io/note/linux_system/linuxxi_tong_bian_cheng_zhi_jin_cheng_ff08_wu_ff09.html)
  
   > 把當前進程替換為一個新進程，且新進程與原進程有相同的PID
   
   _從PATH環境變數中查找檔案並執行_

* #### ls 
  
  > _無參數的指令 直接丟入exec執行_ 
  
  
  
* #### cp、mkdir

  > _有參數的指令 須將輸入字串拆開後 再丟入exec執行_

  - execlp()
  - execvp()
  
  💡 strtok()處理 [參考](https://shengyu7697.github.io/cpp-string-split/)
  
  ❓ (char * const*)型態 [參考](https://reurl.cc/pL51Xb)
  
* #### cd 
  
  > _判斷指令為cd後 做目錄變動chdir()_
  
  - chdir()
  
  ⚠ 字串比較不能直接srt1==str2 需使用**strcmp**(str1, str2)==0
