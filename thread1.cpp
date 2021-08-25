#include <bits/stdc++.h>
#include <thread>
#include <atomic>
#include <mutex>

using namespace std;


vector<int> v;

//Mutual Exclusive (상호배타적) -> 내가 쓰고있으면 다른 사람한테 주지않는다 
mutex m;
template<typename T>

class LockGuard 
{
public:
	LockGuard(T & m)
	{
		_mutext = &m;
		_mutext->lock();

	}

	~LockGuard()
	{
		_mutext->unlock();
	}
private:
	T* _mutext;
};
void Push() {

	for (int i = 0; i < 1000000; i++)
	{
		//lock을 설정하면 a라는 스레드가 공유영역의 자원을 사용하고 있는 중이라면 
		//a가 unlock을 하기전에는 다른 스레드는 공유영역에 접근 하지 못한다 
		//m.lock();
		

		//lockGuard 인자로 m을 넣어주면 자동으로 생성하고 scope를 넘어갈때 소멸자도 생성해준다 
		LockGuard<mutex> lockGuard(m);
		
		//위의 lockGuard랑 동일	
		lock_guard<mutex> lockGuard(m);
		
		v.push_back(i);

		//m.unlock();
	}
}
int main() {

	thread t1(Push);
	thread t2(Push);

	t1.join();
	t2.join();

	cout << v.size() << endl;
	return 0;
}