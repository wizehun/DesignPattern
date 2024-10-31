﻿﻿// 7_객체생성정리 - 118 page
class Rect
{
};

// 디자인 패턴의 핵심 #4. 객체를 생성하는 다양한 방법을 알아 두세요
// 
// 객체를 만드는 방법

// 1. Rect rc;		// 수명이 정해져 있다
                    // 전역변수 : 파괴되지 않는다.
                    // 지역변수 : {} 을 벗어날때
                    // => 사용자가 원하는 시점 파괴는 안됨. 


// 2. Rect* rc = new Rect;    // 가장 자유로운 방법
//							  // 가장 자유로운 것이 가장 좋다는 것은 아님		

// 아래의 다양한 방법도 꼭 고려해 보세요


// 3. Rect* rc = Rect::create()  : static 멤버 함수 사용
//								   다양한 제약을 사용할수 있다.
//					A. 오직 한개만 만들수 있게 -> 싱글톤
//					B. 속성이 동일하면 공유    => 플라이 웨이트
//					C. 생성함수주소를 함수 인자로 전달하거나
//					   자료구조에 보관

// 디자인 패턴 : factory method 가 있습니다. - 다음시간
// java 에서 위 3번 기술을 "static factory method" 라고 합니다.



// 4. Rect* rc = sample->clone();  // 견본을 먼저 만들어서 등록하고(공장)
//							  // 복사본을 사용한 객체 생성 - Prototype

// 5. Rect* rc = factory.create() : 공장을 통한 객체 생성


