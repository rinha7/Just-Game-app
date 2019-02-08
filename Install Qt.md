Install Qt
=
### Qt site
`https://www.qt.io/`

### Qt 다운로드
`wget http://download.qt.io/official_releases/qt/5.7/5.7.0/qt-opensource-linux-x64-5.7.0.run`
```
chmod +x qt-opensource-linux-x64-5.7.0.run
./qt-opensource-linux-x64-5.7.0.run
```
### 의존성
g++ 및 generic font configuration library, OpenGL libraries 필요 
```
sudo apt-get install build-essential
sudo apt-get install libfontconfig1
sudo apt-get install mesa-common-dev
sudo apt-get install libglu1-mesa-dev -y
```
### Trouble Shooting
**Qt Creator needs a compiler set up to build**
 ***error: g++: Command not found***
 `sudo apt-get install build-essential`

  **error: GL/gl.h: No such file or directory**
`sudo apt-get install mesa-common-dev` 

