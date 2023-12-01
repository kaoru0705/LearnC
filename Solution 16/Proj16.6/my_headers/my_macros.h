#pragma once

#define MAX(X,Y)        ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y)        ((X) < (Y) ? (X) : (Y))
#define ABS(X)          ((X) < 0 ? -(X):(X))

#define GRAVITY         9.8
#define PI              3.141592

// 매크로를 이렇게 파일에 몰아 넣는 방식 c++이나 객체지향에서는 max min gravity 이런 걸 표준라이브러리 널리 쓰이는 오픈소스에서 가져다 함수로 씀