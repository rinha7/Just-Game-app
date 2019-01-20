
#How to Ninja Setting!

1. Ninja 실행 파일 만들기

``` bash
git clone git://github.com/martine/ninja.git
cd ninja
./bootstrap.py
```

순서로 실행

2.cmake 설치
```bash
sudo apt-get install cmake
```

3. 본인의 프로젝트에서 아래 명령 실행
```bash
mkdir bulid
cd build
cmake .. -G Ninja
ninja
```
