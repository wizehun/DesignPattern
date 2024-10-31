﻿#include <iostream>
#include <vector>
#include <list>

int main()
{
	// 1. list 와 vector 의 메모리 구조를 다릅니다.
	std::list<int>   s = { 1,2,3,4,5 };
	std::vector<int> v = { 1,2,3,4,5 };

	// 2. s, v 의 모든 요소를 "동일한 방법" 으로 접근할수 없을까요 ?

	auto p1 = s.begin();    // p1은 s의 1번째 요소를 가리키는 반복자 객체
	auto p2 = v.begin();    // p2는 v의 1번째 요소를 가리키는 반복자 객체

	// 3. p1 과 p2 는 사용법이 동일합니다.
	++p1;
	++p2;

	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
}
