#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
struct Point
{

    double x;
    double y;
	double y0l;
	double y0r;
    Point() = default;
    Point(double X, double Y, double y0l_in, double y0r_in): x(X), y(Y), y0l(y0l_in), y0r(y0r_in) {}
    ~Point(){};
};
struct greater_than_key
{
    inline bool operator() (const Point& pt1, const Point& pt2)
    {
		if( pt1.y0 == pt2.y0r )
		{
			return pt1.x < pt2.x;
		}
		return pt1.y0r < pt2.y0r;
    }
}; // big --> small 

struct req0_key
{
    inline bool operator() (const Point& pt1, const Point& pt2)
    {
		
		
		
		if( pt1.y == pt2.y )
		{
			return pt1.x < pt2.x;
		}
        return (pt1.y > pt2.y);
    }
};

struct leq0_key
{
    inline bool operator() (const Point& pt1, const Point& pt2)
    {
		
		
		
		if( pt1.y == pt2.y )
		{
			return pt1.x < pt2.x;
		}
        return (pt1.y < pt2.y);
    }
};




int mergeSort(Point *pt, int const begin, int const end)
{
	int invCount = 0;
	if (begin >= end)
		return 0; // Returns recursively

	int mid = (begin+end) / 2;
	invCount += mergeSort(pt, begin, mid);
	invCount += mergeSort(pt, mid + 1, end);
	
	// Merge stage
	int inversion = 0;
	int i = begin;
	int j = mid+1;
	int k = 0;
	Point *temp = new Point[end-begin+1];
	while (i <= mid && j <= end)
	{

		if(pt[i].y0l <= pt[j].y0l)
		{
			temp[k++] = pt[i++];
		}else if(pt[i].y0l == pt[j].y0l){
			if(pt[i].y > pt[j].y)
			{
				temp[k++] = pt[i++];
				inversion++;
			}else{
				temp[k++] = pt[i++];
			}
		}else{
			temp[k++] = pt[j++];
			inversion += (mid-i+1);
		}		
	}
	while(i<=mid)
		temp[k++] = pt[i++];
	while(j<=end)
		temp[k++] = pt[j++];
	k = 0;
	for(int i=begin; i<=end; i++)
		pt[i] = temp[k++];

	delete [] temp;

	return inversion + invCount;
}

int mergeSortleq0(Point *pt, int const begin, int const end)
{
	int invCount = 0;
	if (begin >= end)
		return 0; // Returns recursively

	int mid = (begin+end) / 2;
	invCount += mergeSort(pt, begin, mid);
	invCount += mergeSort(pt, mid + 1, end);
	
	// Merge stage
	int inversion = 0;
	int i = begin;
	int j = mid+1;
	int k = 0;
	Point *temp = new Point[end-begin+1];
	while (i <= mid && j <= end)
	{
		if(pt[i].y0r <= pt[j].y0r)
		{
			temp[k++] = pt[i++];
		}else if(pt[i].y0r == pt[j].y0r){
			if(pt[i].y > pt[j].y)
			{
				temp[k++] = pt[i++];
				inversion++;
			}else{
				temp[k++] = pt[i++];
			}
		}else{
			temp[k++] = pt[j++];
			inversion += (mid-i+1);
		}		
	}
	while(i<=mid)
		temp[k++] = pt[i++];
	while(j<=end)
		temp[k++] = pt[j++];
	k = 0;
	for(int i=begin; i<=end; i++)
		pt[i] = temp[k++];

	delete [] temp;

	return inversion + invCount;
}








int main(){
    int n;
    cin >> n;
    int *xArr = new int[n];
    int *yArr = new int[n];
    int l1, l2, r1, r2;
    cin >> l1 >> l2 >> r1 >> r2;
    double l, r;
    l =  static_cast<double>(l1)/l2;
    r = static_cast<double>(r1)/r2;
    for(int i=0; i<n; i++)
    {
        cin >> xArr[i] >> yArr[i];
    }
    double *y0l = new double[n];
    double *y0r = new double[n];
    for(int i = 0; i<n; i++)
    {
        y0l[i] = static_cast<double>(l * xArr[i] - yArr[i]) / l;
        y0r[i] = static_cast<double>(r * xArr[i] - yArr[i]) / r;
    }

	
	// (y01) small -> large
    Point *pt = new Point[n];
    for(int i = 0; i<n;i++)
    {
        pt[i] = Point(xArr[i], yArr[i], y0l[i], y0r[i]);
    }



	if(r == 0 && l != 0){
		sort(pt, pt + n, req0_key() );
		

		
		int c = mergeSort(pt, 0, n-1);
		cout << n*(n-1)/2 -c << endl;
	}else if(r != 0 && l == 0){
		sort(pt, pt + n, leq0_key() );

		int c = mergeSortleq0(pt, 0, n-1);
		cout << n*(n-1)/2 -c << endl;

	}else{
		cout << "greater" << endl;
		sort(pt, pt + n, greater_than_key() );
		for(int i = 0;i<n; i++)
		{
			cout << pt[i].x << ", " << pt[i].y <<", " << pt[i].y0l << ", " << pt[i].y0r  << ", "   << endl;
		}

		int c = mergeSort(pt, 0, n-1);
		cout << n*(n-1)/2 -c << endl;
		for(int i = 0;i<n; i++)
		{
			cout << pt[i].x << ", " << pt[i].y <<", " << pt[i].y0l << ", " << pt[i].y0r  << ", "   << endl;
		}
		
	}

    return 0;
}