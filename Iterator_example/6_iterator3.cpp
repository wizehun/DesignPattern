﻿#include <iostream>
#include <vector>
#include <list>

// Java의 반복자 사용법을 설명하는 코드

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// java style iterator 코드

    // #1. 컨테이너(컬렉션)에서 반복자를 꺼내려면 "iterator()" 함수 사용
    // => 모든 컬렉션에는 iterator() 함수가 있다.
    // => 그 의미는? 컬렉션이 지켜야하는 인터페이스가 있다는 것
	auto it1 = s.iterator();
	auto it2 = v.iterator();

    // #2. it1, it2 는 다른 컬렉션의 반복자 객체이다.
    // => 그런데 사용법은 동일하다.
    // => 그 의미는? 모든 iterator 클래스가 지켜야 하는 규칙이 있다.

	while (it1.hasNext())
	{
		std::cout << it1.next() << std::endl;   // next() 함수 : 값 반환 + 다음으로 이동
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}
