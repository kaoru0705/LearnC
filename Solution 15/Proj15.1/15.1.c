/* Bitwise 비트 단위 논리 연산자 Logical Operators */
/*
	bit끼리 비교
	Bitwise NOT ~ Tilde
	Bitwise And & Ampersand
	Bitwise OR | Vertical bar
	Bitwise EXCLUSIVE OR ^ Caret 기본적으로 or인데 둘 다 1일 때 0
	^는 계산법칙이 +라고 생각하면 편하다.  a ^ a = 0,  a ^ 0 = a;
	x ^ y = (x & ~y) | (~x & y)

	갖고 있냐 없냐인데 1바이트를 쓰는 건 아깝다. unsigned char has_sword = 1;
*/