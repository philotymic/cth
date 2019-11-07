QT5 - tips
==========

great instructions on how to create simplest qt5 app and more:
https://vitux.com/compiling-your-first-qt-program-in-ubuntu/

Setting up QT5
--------------

NOTE: qt5 is part of anaconda2

UNTESTED
qt5 install commands:

```
 sudo apt-get update
 sudo apt-get install build-essential
 sudo apt-get install qtcreator
 sudo apt install qt5-default
 sudo apt-get install qt5-doc qtbase5-examples qtbase5-doc-html
```

Setting up QT5 project
----------------------

After you have few .cpp files in your new qt project directory:

- go to <project-dir>
- execute command below to build <project-dir>.pro file
```
 qmake -project
```
- insert line below into <project-dir>.pro file (https://vitux.com/compiling-your-first-qt-program-in-ubuntu/ step 4)
```
QT += gui widgets 
```
- execute command below to build Makefile
```
qmake <project-dir>.pro
```


