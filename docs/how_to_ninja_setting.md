
#How to Ninja Setting!

1. Ninja 실행 파일 만들기

``` bash
git clone git://github.com/martine/ninja.git
cd ninja
./bootstrap.py
```
ninja 파일이 생성된 것을 확인한 후 이 파일을 적절한 path에 복사합니다.


혹은 sudo apt-get install ninja-build 명령어를 입력하여 ninja를 설치합니다.



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

Ninja는 cmake 3.13버전 이상을 요구하므로 홈페이지에 가서 cmake 최신버전을 받아야합니다.


https://cmake.org/download/
