#include "std.hpp"

void print_map(std::map<char, int> map, std::string name)
{
	std::cout << name << ":\n";
	for (std::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << std::endl;
	std::cout << std::endl;
}

void print_size(std::map<char, int> map, std::string name)
{
	std::cout << name << " size: " << map.size() << std::endl;
	std::cout << name << " empty() (1: true 0: false): " << map.empty() << std::endl;
	std::cout << std::endl;
} 

void map_constructors()
{
	print_title("CONSTRUCTOR", "map");
	
	std::map<char, int> map;
	print_size(map, "map");

	print_title("COPY CONSTRUCTOR (copy of range)", "map");
	
	std::map<char, int> map_copy;
	map_copy.insert(std::make_pair('a', 1));
	print_size(map_copy, "map_copy");
	print_map(map_copy, "map_copy");

	map_copy.insert(std::make_pair('c', 13));
	print_size(map_copy, "map_copy");
	print_map(map_copy, "map_copy");
	
	map_copy.insert(std::make_pair('j', 3));
	print_size(map_copy, "map_copy");
	print_map(map_copy, "map_copy");

	print_title("FILL", "map");

	std::map<char, int> fill(map_copy.begin(), map_copy.end());
	print_size(fill, "fill");
	print_map(fill, "fill");

	print_title("ASSIGNATION OPERATOR", "map");

	std::map<char, int> oper = fill;
	print_size(oper, "operator");
	print_map(oper, "operator");
}

void map_iterator()
{
	std::map<char, int> m1;
	int a = 1;
	for (int i = 65; i < 73; i++, a++)
		m1.insert(std::make_pair(i, a));

	print_title("ITERATORS TESTS", "map");
	
	std::cout << "map::(iterator): " << std::endl;
	for (std::map<char, int>::iterator it = m1.begin(); it != m1.end(); it++)
	std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "map::(const_iterator): " << std::endl;
	for (std::map<char, int>::const_iterator it = m1.begin(); it != m1.end(); it++)
	std::cout << (*it).first << " = " << (*it).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "map::(reverse_iterator): " << std::endl;
	for (std::map<char, int>::reverse_iterator rit = m1.rbegin(); rit != m1.rend(); rit++)
	std::cout << (*rit).first << " = " << (*rit).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
	
	std::cout << "map::(const_reverse_iterator): " << std::endl;
	for (std::map<char, int>::const_reverse_iterator rit = m1.rbegin(); rit != m1.rend(); rit++)
	std::cout << (*rit).first << " = " << (*rit).second << ", ";
	std::cout << std::endl;
	std::cout << "\n" << std::endl;
}

void map_capacity()
{
	print_title("ACCESSOR AND MEMBER FUNCTIONS , size, empty", "map");

	std::map<char, int> len;
	int c = 'a';
	for (int i = 14; i <= 19; i++, c++)
	{
		len.insert(std::make_pair(c, i));
	}
	print_map(len, "map");
	print_size(len, "map");

	std::cout << std::endl;
}

void map_access()
{
	print_title("ELEMENT ACCESS", "map");
	
	std::map<std::string, char> src;
	
	src.insert(std::make_pair("BTC", 'a'));
	src.insert(std::make_pair("ETH", 'b'));
	src.insert(std::make_pair("DOGE", 'c'));

	std::cout << LET << "src: [\"BTC\"] == " << src["BTC"] << std::endl;

	std::cout << std::endl;
}

void map_modifiers(int i)
{
	
	if (i == 0)
	{
		print_title("MAP INSERT(position, val)" , "map");
		std::map<char,int> mymap;

		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('z',200) );

		std::pair<std::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second == false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		std::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, std::pair<char,int>('b',300));
		mymap.insert (it, std::pair<char,int>('c',400));

		std::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;
	}
}

void map_erase(int i)
{
	if (!i)
	{
		print_title("MAP ERASE(key)", "map");	
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase(it);

		mymap.erase('c');

		it=mymap.find('e');
		mymap.erase(it, mymap.end() );

		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;
	}
}

void map_swap(int i)
{
	if (!i)
	{
		print_title("MAP SWAP()", "map");
		std::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;
		print_map(foo, "foo before swap");

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		print_map(bar, "bar before swap");

		foo.swap(bar);

		std::cout << "foo after swap:\n";
		for (std::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;

		std::cout << "bar after swap:\n";
		for (std::map<char,int>::iterator it = bar.begin(); it !=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;
	}
	
}

void map_clear()
{
	print_title("MAP CLEAR", "map");
	std::map<int, int> tab;

	tab.insert(std::make_pair(1, 5));
	tab.insert(std::make_pair(3, 8));
	tab.insert(std::make_pair(5, 66));
	tab.insert(std::make_pair(13, 5));

	std::cout << LET "size: " << tab.size() << std::endl;
	std::cout << LET "empty() (1: true 0: false): " << tab.empty() << std::endl;
	tab.clear();
	std::cout << std::endl;
	std::cout << LET "After clear tab ..." << std::endl;
	std::cout << LET "size: " << tab.size() << std::endl;
	std::cout << std::endl;
}

void map_operations(int i)
{
	if (!i)
	{
		print_title("MAP COUNT(key)", "map");
		std::map<char,int> mymap;
		char c;

		mymap['a'] = 101;
		mymap['c'] = 202;
		mymap['f'] = 303;

		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
				std::cout << " is an element of mymap.\n";
			else 
				std::cout << " is not an element of mymap.\n";
			std::cout << std::endl;
		}
	}
}

void map_find()
{
	print_title("MAP FIND", "map");

	std::map<char, int> map;
	int c = 'a';
	for (int i = 1; i <= 26; i++, c++)
	{
		map.insert(std::make_pair(c, i));
	}

	std::map<char, int>::iterator find_a = map.find('c');
	std::map<char, int>::const_iterator find_z = map.find('u');
	std::cout << "find('c'): " << (*find_a).first << " = " << (*find_a).second << '\n';
	std::cout << "find('u'): " << (*find_z).first << " = " << (*find_z).second << '\n';
}

void map_bound(int i)
{
	print_title("MAP LOWER_BOUND AND UPPER_BOUND", "map");
	if (!i)
	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow = mymap.lower_bound('b');
		itup = mymap.upper_bound('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);

		for (std::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	else if (i == 2)
	{
		std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		std::pair<std::map<char,int>::iterator, std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
		std::cout << std::endl;
	}
}

void map_operators(int i)
{
	if (!i)
	{
		print_title("Operation", "Check all operation( true | false )");
		std::map<int, char> ott;
		std::map<int, char> mma;
		std::map<int, char> eve;

		ott.insert(std::make_pair(1, 'a'));
		ott.insert(std::make_pair(2, 'b'));
		ott.insert(std::make_pair(3, 'c'));

		mma.insert(std::make_pair(7, 'Z'));
		mma.insert(std::make_pair(8, 'Y'));
		mma.insert(std::make_pair(9, 'X'));
		mma.insert(std::make_pair(10, 'W'));
 
		eve.insert(std::make_pair(1, 'a'));
		eve.insert(std::make_pair(2, 'b'));
		eve.insert(std::make_pair(3, 'c'));
 
		std::cout << std::boolalpha;
 
		std::cout << "ott == mma returns " << (ott == mma) << '\n';
		std::cout << "ott != mma returns " << (ott != mma) << '\n';
		std::cout << "ott <  mma returns " << (ott < mma) << '\n';
		std::cout << "ott <= mma returns " << (ott <= mma) << '\n';
		std::cout << "ott >  mma returns " << (ott > mma) << '\n';
		std::cout << "ott >= mma returns " << (ott >= mma) << '\n';
 
		std::cout << '\n';

		std::cout << "ott == eve returns " << (ott == eve) << '\n';
		std::cout << "ott != eve returns " << (ott != eve) << '\n';
		std::cout << "ott <  eve returns " << (ott < eve) << '\n';
		std::cout << "ott <= eve returns " << (ott <= eve) << '\n';
		std::cout << "ott >  eve returns " << (ott > eve) << '\n';
		std::cout << "ott >= eve returns " << (ott >= eve) << '\n';
	}
}

void test_map()
{
	//int start = clock();

	map_constructors();
	map_iterator();
	map_capacity();
	map_access();
	map_modifiers(0);
	map_erase(0);
	map_swap(0);
	map_clear();
	map_operations(0);
	map_bound(0);
	map_bound(2);
	map_find();
	map_operators(0);

	std::cout << std::endl;
	//int end = clock();
	//std::cout << RED "Execution time (map): " OFF << ((float)end - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
}