//Phatela,Lakshay
// UTA id: 1001440149
// December - 10 - 2016 
//Subset Problem

#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>

using namespace std;

int space = 0;
int space1 = 0;
int n, t, p = 0, z=0;
int a[1000];
vector<int> b;
vector<int> c;
vector<int> d;
vector<vector<int>> s;

bool sortcol(const vector<int>& v1,	const vector<int>& v2) //REFERENCE: www.geeksforgeeks.org/sorting-2d-vector-in-c-set-1-by-row-and-column
{
	return v1[0] < v2[0];
}//sortcol()                   

void unique_funct(vector<vector<int>>&s)
{
	vector<vector<int>> temp1;
	vector <int> temp2;
	temp2.push_back(s[0][0]);
	temp2.push_back(s[0][1]);
	temp1.push_back(temp2);
	unsigned int q = 1;
	for (unsigned int k = 1; k < s.size(); k++)
	{
		if (temp1[q-1][0] != s[k][0])
		{
			q++;
			vector <int> temp;
			temp.push_back(s[k][0]);
			temp.push_back(s[k][1]);
			temp1.push_back(temp);
			space = space + 8;
		}
	}
	s.swap(temp1);
}//unique_funct()

void merge1(vector<int> &e, vector<int> &f)
{
	unsigned int i;

	for (i = 0; i < e.size(); i++)
	{
		d.push_back(e[i]);
		space = space + 4;
	}

	for (i = 0; i < f.size(); i++)
	{
		d.push_back(f[i]);
		space = space + 4;
	}

	//starting of backtracking 

	for (unsigned int k = 0; k < d.size(); k++)
	{
		vector <int> temp;
		temp.push_back(d[k]);
		temp.push_back(z);
		s.push_back(temp);
		space = space + 8;
	}

	sort(s.begin(), s.end(), sortcol);

	unique_funct(s);

	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());
	
	cout << "List " << p << " for " << a[p] << " has " << s.size() << " elements." << endl;
	p++;
	
	b.swap(d);
}//merge1()

void merge2(vector<int> &e, vector<int> &f)
{
	unsigned int i;

	for (i = 0; i < e.size(); i++)
	{
		d.push_back(e[i]);
		space = space + 4;
	}

	for (i = 0; i < f.size(); i++)
	{
		d.push_back(f[i]);
		space = space + 4;
	}

	//starting of backtracking 

	for (unsigned int k = 0; k < d.size(); k++)
	{
		vector <int> temp;
		temp.push_back(d[k]);
		temp.push_back(z);
		s.push_back(temp);
		space = space + 8;
	}

	sort(s.begin(), s.end(), sortcol);

	unique_funct(s);

	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());

	cout << "List " << p << " for " << a[p] << " has " << s.size() << " elements." << endl;
	p=p+2;

	b.swap(d);
}//merge2()

void SubSet(vector<vector<int>> &s) 
{
	int array[100][2];
	int sum = t;
	int n1=0;
	while (sum != 0)
	{
		if (t != s[s.size() - 1][0])
		{
			cout << endl<<"Subset Does Not Exist."<<endl;
			break;
		}
		else
		{
			for (unsigned int i = 0; i < s.size(); i++)
			{
				if (s[i][0] == sum)
				{
					array[n1][1] = s[i][1];
					array[n1][0] = a[s[i][1]];
				}
			}
			sum = sum - array[n1][0];
			n1++;
		}
	}
	for (int j = 0; j < n1; j++)
		cout << array[j][0] << " (" << array[j][1] << ")" << endl;
}//SubSet()

int main()
{
	int i;
	space1 = space1 + 2;
	unsigned int j;
	space = space + 2;

	cin >> n >> t;
	space1 = space1 + 8;

	if (t == 0)
	{
		cout << "Subset is {0}";
		_getch();
		exit(-1);
	}

	if (n == 0 && t != 0)
	{
		cout << "NO subset";
		_getch();
		exit(-1);
	}
	

	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i > 0)
		{
			if (a[i] < a[i - 1])
			{
				cout << "Enter the numbers in incresing order.";
				_getch();
				exit(-1);
			}
		}
	}
	space1 = space1 + 100;

//code for version 1
    clock_t begin = clock();

	b.push_back(0);
	space = space + 4;

	for (z = 0; z < n; z++)
	{
		for (j = 0; j < b.size(); j++)
		{
			if(b[j]+a[z]<=t)
				c.push_back(b[j]+a[z]);
		}
		
		merge1(b, c);
		
		c.clear();
	}
	space = space1 + space;
	cout <<"Subset that sums to " << t <<endl;

	SubSet(s);
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Version 1 CPU: " << time_spent << endl;
	cout << "Version 1 maximim bytes used: " <<space<< endl;

	d.clear();
	b.clear();
	s.clear();
	p = 0;
	z = 0;
	space = space1;

// code for version 2a 
	clock_t begin1 = clock();

	b.push_back(0);

	for (z = 0; z < n/2; z++)
	{
		for (j = 0; j < b.size(); j++)
		{
			if (b[j] + a[z] <= t)
				c.push_back(b[j] + a[z]);
		}

		merge1(b, c);

		c.clear();
	}
	cout <<endl<< "Subset that sums to " << t << endl;
	cout << "Using inputs 0 to " << (n / 2)<<endl ;
	SubSet(s);

	d.clear();
	s.clear();
	b.clear();
	p = 0;
	z = 0;
	b.push_back(0);

	for (z = n/2; z < n; z++)
	{
		for (j = 0; j < b.size(); j++)
		{
			if (b[j] + a[z] <= t)
				c.push_back(b[j] + a[z]);
		}

		merge1(b, c);

		c.clear();
	}
	cout << "Using inputs " << (n / 2) + 1 << " to " << n << endl;
	SubSet(s);

	clock_t end1 = clock();
	double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	cout << "Version 2a CPU: " << time_spent1 << endl;
	cout << "Version 2a maximim bytes used: "<<space<<endl;

	d.clear();
	s.clear();
	b.clear();
	space = space1;
	p = 0;
	z = 0;

//code for version 2b
   clock_t begin2 = clock();

	b.push_back(0);

	for (z = 0; z < n; z++)
	{
		if (z % 2 == 0)
		{
			for (j = 0; j < b.size(); j++)
			{
				if (b[j] + a[z] <= t)
					c.push_back(b[j] + a[z]);
			}

			merge2(b, c);

			c.clear();
		}
	}

	cout << endl<<"Subset that sums to " << t << endl;
	cout << "Using even indexed inputs" << endl;
	SubSet(s);

	d.clear();
	b.clear();
	s.clear();
	z = 0;
	p = 1;

	b.push_back(0);

	for (z = 0; z < n; z++)
	{
		if (z % 2 != 0)
		{
			for (j = 0; j < b.size(); j++)
			{
				if (b[j] + a[z] <= t)
					c.push_back(b[j] + a[z]);
			}

			merge2(b, c);

			c.clear();
		}
	}
	cout << "Using odd indexed inputs" << endl;
	SubSet(s);

	clock_t end2 = clock();
	double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	cout << "Version 2b CPU: " << time_spent2 << endl;
	cout << "Version 2b maximim bytes used: " << space<<endl;

    _getch();
	return 0;
}//main()