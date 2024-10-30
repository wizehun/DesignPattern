// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"

int main()
{
	// 1. 서버의 핸들을 얻어 옵니다. (서버 이름으로 찾음)
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다. (int 값 3개 전달)
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;
}

// 그런데 위와 같이 만들면?
// 1. 모든 클라이언트 제작자가 IPC 기술이 필요하다. (서버 접속하고, 명령코드/파라미터 전달)
// 2. 서버의 장애 처리를 클라이언트가 직접 해야한다.
// 3. 덧셈은 1, 뺄셈은 2 같은 명령코드를 외우고 있어야 한다.
// 좀더 편하게 하는 방법?


