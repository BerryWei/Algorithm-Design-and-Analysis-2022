#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
struct Point
{

    long long int x;
    long long int y;
	long long int cl;
	long long int cr;
    Point() = default;
    Point(long long int X, long long int Y, long long int CL, long long int CR): x(X), y(Y),cl(CL), cr(CR) {}
    ~Point(){};
};

struct cl_sort
{
    inline bool operator() (const Point& A1, const Point& A2)
    {
        return (A1.cl < A2.cl);
    }
};

struct x_sort
{
    inline bool operator() (const Point& A1, const Point& A2)
    {
        if(A1.cl ==  A2.cl)
            return (A1.x < A2.x);
    }
};

bool compare__(Point a, Point b)
{
    if(a.cl < b.cl)
    {
        return true;
    }else if(a.cl == b.cl)
    {
        if(a.x < b.x)
            return true;
    }
    return false;
}


long long  int mergeSort(Point *array, long long int  begin, long long int  end, long long int r1)
{
	
	if (begin == end)
		return 0; // Returns recursively

	long long int mid = (begin+end) / 2;
	long long int  first = mergeSort(array, begin, mid, r1);
	long long int  second = mergeSort(array, mid + 1, end, r1);
	
	// Merge stage
	long long int  inversion = 0;
	long long int  i = begin;
	long long int  j = mid+1;
	long long int  k = 0;
	Point *temp = new Point[end-begin+1];





	while (i <= mid && j <= end)
	{
		if(array[i].cr <= array[j].cr)
		{
			temp[k++] = array[i++];

			
		}else
		{
			temp[k++] = array[j++];
            inversion += (mid-i+1);
		}		
	}
	while(i<=mid)
		temp[k++] = array[i++];
	while(j<=end)
		temp[k++] = array[j++];
    
	k = 0;
	for(long long int  i=begin; i<=end; i++)
		array[i] = temp[k++];
	delete [] temp;
	return inversion + first + second;
}

int main(){
    long long int  n;
    cin >> n;
    long long int *xArr = new long long int[n];
    long long int  *yArr = new long long int [n];
    long long int  l1, l2, r1, r2;
    cin >> l1 >> l2 >> r1 >> r2;
    for(int i=0; i<n; i++)
    {
        cin >> xArr[i] >> yArr[i];
    }
    // 先對 L:  算投影 cl
    long long int  *cl = new long long int [n];
    long long int  *cr = new long long int [n];
    for(long long int i = 0; i<n; i++)
    {
        cl[i] = l2* yArr[i] - l1* xArr[i];
        cr[i] = r1* xArr[i] - r2* yArr[i];
    }
    Point *Group = new Point[n];
    for(long long int i = 0; i<n;i++)
    {
        Group[i] = Point(xArr[i], yArr[i], cl[i], cr[i]);
    }
    //for(int i=0; i<n;i++)
    //    cout << Group[i].x << ", " << Group[i].y << ", " << Group[i].cl << ", " << Group[i].cr << endl;

    sort(Group, Group + n, compare__ );

    //for(int i=0; i<n;i++)
    //    cout << Group[i].x << ", " << Group[i].y << ", " << Group[i].cl << ", " << Group[i].cr << endl;

    //sort(Group, Group + n, cl_sort() );
    // sort(Group, Group + n, x_sort() );
    //for(int i=0; i<n;i++)
    //    cout << Group[i].x << ", " << Group[i].y << ", " << Group[i].cl << ", " << Group[i].cr << endl;
	


	long long int c = mergeSort(Group, 0, n-1, r1);

    //cout << c << endl;
    std::cout << n*(n-1)/2 -c << endl;
	

	




    return 0;
}