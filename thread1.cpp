#include <bits/stdc++.h>
#include <thread>
#include <atomic>
#include <mutex>

using namespace std;


vector<int> v;

//Mutual Exclusive (��ȣ��Ÿ��) -> ���� ���������� �ٸ� ������� �����ʴ´� 
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
		//lock�� �����ϸ� a��� �����尡 ���������� �ڿ��� ����ϰ� �ִ� ���̶�� 
		//a�� unlock�� �ϱ������� �ٸ� ������� ���������� ���� ���� ���Ѵ� 
		//m.lock();
		

		//lockGuard ���ڷ� m�� �־��ָ� �ڵ����� �����ϰ� scope�� �Ѿ�� �Ҹ��ڵ� �������ش� 
		LockGuard<mutex> lockGuard(m);
		
		//���� lockGuard�� ����	
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