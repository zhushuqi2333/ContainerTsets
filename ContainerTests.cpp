#include "pch.h"
#include <iostream>
using namespace std;
const long ASIZE = 250000;
long get_a_target_long() 
{
long target = 0;

	cout << "target (0~" << RAND_MAX << "):" ;
	cin >> target;
	return target;
}

string get_a_target_string()
{
long target = 0;
char buf[10];

	cout << "target (0~" << RAND_MAX << "):" ;
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}

int compareLongs(const void* a, const void* b )
{
	return ( *(long*)a - *(long*)b );// 将a转化为long类型的指针，并取其指向地址的值（即target的值）
}

int compareStrings(const void* a, const void* b)
{
	if (*(string*)a > *(string*)b)
		return 1;
	else if (*(string*)a < *(string*)b)
		return -1;
	else
		return 0;
}

#include<array>
#include<ctime>
#include<cstdlib>
#include<iostream>
namespace jj01
{
void test_array()
{
	cout << endl << "test array .........." << endl;

array<long, ASIZE> c;

clock_t timeStart = clock();
	for (long i = 0; i < ASIZE; i++) {
		c[i] = rand();
	}
	cout << "milli-seconds：" << clock() - timeStart << endl;
	cout << "c.size() = " << c.size() << endl;
	cout << "c.front() = " << c.front() << endl;
	cout << "c.back() = " << c.back() << endl;
	cout << "c.data() = " << c.data() << endl;

long target = get_a_target_long();

	timeStart = clock();
	qsort(c.data(), ASIZE, sizeof(long), compareLongs);//数组首地址，数组有多少项，每项大小，比大小函数
	long* flag = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
	cout << "qsort()+bsearch(),milli-seconds:" << clock() - timeStart << endl;
	if (flag != NULL)
		cout << "found," << *flag << endl;
	else
		cout << "not found!!!" << endl;
}
}

#include<vector>
#include<string>
#include<cstdlib>//qsort,bsearch,abort
#include<cstdio>//snprintf
#include<iostream>
#include<string>
#include<ctime>
#include<algorithm>//算法，sort
#include<stdexcept>//抛出异常
namespace jj02
{
void test_vector(long& value)//传引用
{
	cout << endl << "test vector.........." << endl;
vector<string> c;
char buf[10];
clock_t timeStart = clock();
	for (long i = 0; i < value; i++) 
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));//buf是一个char数组，需要转化为string类型，才能放入vector中
		}//如果系统无法再分配空间了，就会引发异常
		catch (exception& p)//捕获了异常，抓住了异常
		{
			cout << "i=" << i << " " << p.what() << endl;
			abort();//退出程序
		}
		
	}
	cout << "milli-seconds:" << clock() - timeStart << endl;
	cout << "c.size() = " << c.size() << endl;
	cout << "c.front() = " << c.front() << endl;
	cout << "c.back() = " << c.back() << endl;
	cout << "c.data() = " << c.data() << endl;
	cout << "c.capicy() = " << c.capacity() << endl;
	//vector两倍增长，放入1，变成2，放入2，不变，放入3，变成4，放入4，不变
	//放入5，变成8,放入6,7,8，均不变，所以capacity是容器能存储的元素个数
	//而size是容器目前存在的元素个数
string target = get_a_target_string();
	{
	timeStart = clock();
	auto flag = ::find(c.begin(), c.end(), target);
	cout << "::find().milli-seconds:" << clock() - timeStart << endl;
	if (flag != c.end()) 
		cout << "found," << *flag << endl;
	else 
		cout << "not found" << endl;
	}

	{
	timeStart = clock();
	sort(c.begin(), c.end());
string* flag = (string*)bsearch(&target, c.data(), c.size(), sizeof(string), compareStrings);
	cout << "qsort()+bsearch(),milli-seconds:" << clock() - timeStart << endl;
	if (flag != NULL)
		cout << "found," << *flag << endl;
	else
		cout << "not found!!!" << endl;
	}
}
}

#include<list>
#include<string>
#include<cstdlib>//qsort,bsearch,abort
#include<cstdio>//snprintf
#include<iostream>
#include<string>
#include<ctime>
#include<algorithm>//算法，sort
#include<stdexcept>//抛出异常
namespace jj03
{
	void test_list(long& value)//传引用
	{
		cout << endl << "test list.........." << endl;
		list<string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++)
		{
			try
			{
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));//buf是一个char数组，需要转化为string类型，才能放入vector中
			}//如果系统无法再分配空间了，就会引发异常
			catch (exception& p)//捕获了异常，抓住了异常
			{
				cout << "i=" << i << " " << p.what() << endl;
				abort();//退出程序
			}

		}
		cout << "milli-seconds:" << clock() - timeStart << endl;
		cout << "c.size() = " << c.size() << endl;
		cout << "c.front() = " << c.front() << endl;
		cout << "c.back() = " << c.back() << endl;
		cout << "c.max_size() = " << c.max_size() << endl;

	string target = get_a_target_string();
		timeStart = clock();
	auto flag = ::find(c.begin(), c.end(), target);
		cout << "::find().milli-seconds:" << clock() - timeStart << endl;
		if (flag != c.end())
			cout << "found," << *flag << endl;
		else
			cout << "not found" << endl;
		timeStart = clock();
		c.sort();
		cout << "c.sort(),milli-seconds:" << clock() - timeStart << endl;

	}
}

#include <forward_list>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
namespace jj04
{
	void test_forward_list(long& value)
	{
		cout << endl << "test_forward_list().......... \n";

		forward_list<string> c;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i)
		{
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_front(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds : " << (clock() - timeStart) << endl;
		cout << "forward_list.max_size()= " << c.max_size() << endl;  //536870911
		cout << "forward_list.front()= " << c.front() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = find(c.begin(), c.end(), target);
		cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;

		if (pItem != c.end())
			cout << "found, " << *pItem << endl;
		else
			cout << "not found! " << endl;

		timeStart = clock();
		c.sort();
		cout << "c.sort(), milli-seconds : " << (clock() - timeStart) << endl;

		c.clear();
	}
}

#include<deque>
#include<cstdlib>//qsort,bsearch,abort
#include<cstdio>//snprintf
#include<iostream>
#include<string>
#include<ctime>
#include<algorithm>//算法，sort
#include<stdexcept>//抛出异常
namespace jj05
{
	void test_deque(long& value)//传引用
	{
		cout << endl << "test deque.........." << endl;
		deque<string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++)
		{
			try
			{
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));//buf是一个char数组，需要转化为string类型，才能放入vector中
			}//如果系统无法再分配空间了，就会引发异常
			catch (exception& p)//捕获了异常，抓住了异常
			{
				cout << "i=" << i << " " << p.what() << endl;
				abort();//退出程序
			}

		}
		cout << "milli-seconds:" << clock() - timeStart << endl;
		cout << "c.size() = " << c.size() << endl;
		cout << "c.front() = " << c.front() << endl;
		cout << "c.back() = " << c.back() << endl;
		cout << "c.max_size() = " << c.max_size() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto flag = ::find(c.begin(), c.end(), target);
		cout << "::find().milli-seconds:" << clock() - timeStart << endl;
		if (flag != c.end())
			cout << "found," << *flag << endl;
		else
			cout << "not found" << endl;
		timeStart = clock();
		::sort(c.begin(), c.end());
		cout << "::sort(c.begin(), c.end()),milli-seconds:" << clock() - timeStart << endl;
	}
}

#include<set>
#include<cstdlib>//qsort,bsearch,abort
#include<cstdio>//snprintf
#include<iostream>
#include<string>
#include<ctime>
#include<algorithm>//算法，sort
#include<stdexcept>//抛出异常
namespace jj06
{
	void test_multiset(long& value)//传引用
	{
		cout << endl << "test multiset.........." << endl;
		multiset<string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++)
		{
			try
			{
				snprintf(buf, 10, "%d", rand());
				c.insert(string(buf));//buf是一个char数组，需要转化为string类型，才能放入vector中
			}//如果系统无法再分配空间了，就会引发异常
			catch (exception& p)//捕获了异常，抓住了异常
			{
				cout << "i=" << i << " " << p.what() << endl;
				abort();//退出程序
			}

		}
		cout << "milli-seconds:" << clock() - timeStart << endl;
		cout << "c.size() = " << c.size() << endl;
		cout << "c.max_size() = " << c.max_size() << endl;

     string target = get_a_target_string();
		timeStart = clock();
		auto flag = ::find(c.begin(), c.end(), target);
		cout << "::find().milli-seconds:" << clock() - timeStart << endl;
		if (flag != c.end())
			cout << "found," << *flag << endl;
		else
			cout << "not found" << endl;
		timeStart = clock();
		flag = c.find(target);
		cout << "c.find(target),milli-seconds:" << clock() - timeStart << endl;
		if (flag != c.end())
			cout << "found," << *flag << endl;
		else
			cout << "not found" << endl;
	}
}

#include<map>
#include<string>
#include<cstdlib>//qsort,bsearch,abort
#include<cstdio>//snprintf
#include<iostream>
#include<ctime>
#include<stdexcept>//抛出异常
namespace jj07
{
	void test_multimap(long& value)//传引用
	{
		cout << endl << "test multimap.........." << endl;
		multimap <long,string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++)
		{
			try
			{
				snprintf(buf, 10, "%d", rand());
				c.insert( pair<long, string> (i, buf));
			}
			catch (exception& p)//捕获了异常，抓住了异常
			{
				cout << "i=" << i << " " << p.what() << endl;
				abort();//退出程序
			}

		}
		cout << "milli-seconds:" << clock() - timeStart << endl;
		cout << "c.size() = " << c.size() << endl;
		cout << "c.max_size() = " << c.max_size() << endl;

		long target = get_a_target_long();
		timeStart = clock();
		auto flag = c.find(target);
		cout << "c.find(target),milli-seconds:" << clock() - timeStart << endl;
		if (flag != c.end())
			cout << "found," << (*flag).second << endl;
		else
			cout << "not found" << endl;
	}
}

#include<unordered_set>
#include<cstdlib>//qsort,bsearch,abort
#include<cstdio>//snprintf
#include<iostream>
#include<string>
#include<ctime>
#include<algorithm>//算法，sort
#include<stdexcept>//抛出异常
namespace jj08
{
	void test_unordered_multiset(long& value)//传引用
	{
		cout << endl << "test unordered_multiset.........." << endl;
		unordered_multiset<string> c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++)
		{
			try
			{
				snprintf(buf, 10, "%d", rand());
				c.insert(string(buf));//buf是一个char数组，需要转化为string类型
			}//如果系统无法再分配空间了，就会引发异常
			catch (exception& p)//捕获了异常，抓住了异常
			{
				cout << "i=" << i << " " << p.what() << endl;
				abort();//退出程序
			}

		}
		cout << "milli-seconds:" << clock() - timeStart << endl;
		cout << "c.size() = " << c.size() << endl;
		cout << "c.max_size() = " << c.max_size() << endl;
		cout << "c.buket_count() = " << c.bucket_count() << endl;
		cout << "c.load_factor() = " << c.load_factor() << endl;
		cout << "c.max_bucket_count() = " << c.max_bucket_count() << endl;

		for (int i = 0; i < 20; i++) {
			cout << "bucket# " << i << " has " << c.bucket_size(i) << " elements " << endl;
		}

		string target = get_a_target_string();
		timeStart = clock();
		auto flag = ::find(c.begin(), c.end(), target);
		cout << "::find().milli-seconds:" << clock() - timeStart << endl;
		if (flag != c.end())
			cout << "found," << *flag << endl;
		else
			cout << "not found" << endl;
		timeStart = clock();
		flag = c.find(target);
		cout << "c.find(target),milli-seconds:" << clock() - timeStart << endl;
		if (flag != c.end())
			cout << "found," << *flag << endl;
		else
			cout << "not found" << endl;
	}
}


using namespace std;
int main() {
	srand((unsigned)time(0));
	long num, value;
	cout << "please choose your select :";
	cin >> num;
	if (num != 1) {
	   cout << "How many elements :";
	   cin >> value;
	}
	if (num == 1)
		jj01::test_array();
	else if (num == 2)
		jj02::test_vector(value);
	else if (num == 3)
		jj03::test_list(value);
	else if (num == 4)
		jj04::test_forward_list(value);
	else if (num == 5)
		jj05::test_deque(value);
	else if (num == 6)
		jj06::test_multiset(value);
	else if (num == 7)
		jj07::test_multimap(value);
	else if (num == 8)
		jj08::test_unordered_multiset(value);
	return 0;
}
