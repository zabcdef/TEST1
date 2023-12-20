# TEST1
## **！！新增的寻迹代码和修改过的行走代码在tracecar分支里！！**

---
## 网址：

[工程文件](https://github.com/zabcdef/TEST1.git)

(https://github.com/zabcdef/TEST1.git)

## 克隆方法：
在你想要克隆到的文件夹打开git——bash，然后直接输入克隆指令即可，文件就会出现在文件夹里

**克隆指令**：`git clone https://github.com/zabcdef/TEST1.git`

克隆完了以后你会发现只有一个main分支，所以想要查看其他分支必须和远端同步分支。

**与远端同步分支代码**：以同步tracecar分支为例 `git checkout -b tracecar origin/tracecar`



之后更新代码***建议***在自己的分支上更新，把main分支的代码保留，这样方便之后查错误 

## 上传方法：
### 代码
` git commit -m "你的注释（这个必须写点啥，否则git会报错）" `

`git push origin //你的分支名`

## 我之前踩过的坑：
按q退出log界面或者乱七八糟莫名其妙的界面 

主分支叫main，不是master