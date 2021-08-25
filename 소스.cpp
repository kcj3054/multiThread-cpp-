//#include <iostream>
//
//#include <thread>
//
//using namespace std;
//
//void HelloThread() 
//{
//	cout << "Hello Thread" << endl;
//}
//int main() {
//
//
//	thread t;
//	auto id1 = t.get_id();  // thread마다 id가있다 
//
//	cout << "Hello Main" << endl;
//
//	t = thread(HelloThread); // 스레드 시작 
//
//	auto id2 = t.get_id();
//
//	int  count = t.hardware_concurrency(); // 현재 구동가능한 thread 수 
//	if(t.joinable()) t.join();   // t스레드로 만든 스레드가 끝날때까지 기다려준다는 뜻 
//
//
//
//	return 0;
//}