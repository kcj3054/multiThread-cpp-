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
//	auto id1 = t.get_id();  // thread���� id���ִ� 
//
//	cout << "Hello Main" << endl;
//
//	t = thread(HelloThread); // ������ ���� 
//
//	auto id2 = t.get_id();
//
//	int  count = t.hardware_concurrency(); // ���� ���������� thread �� 
//	if(t.joinable()) t.join();   // t������� ���� �����尡 ���������� ��ٷ��شٴ� �� 
//
//
//
//	return 0;
//}