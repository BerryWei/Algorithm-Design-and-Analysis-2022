#include <iostream>
#include <algorithm>

using namespace std;
struct Point
{

    double x;
    double y;
	int xx;
	int yy;
    Point() = default;
    Point(double X, double Y, int XX, int YY): x(X), y(Y), xx(XX), yy(YY) {}
    ~Point(){};
};
struct greater_than_key
{
    inline bool operator() (const Point& A1, const Point& A2)
    {
		
		
		//if( (A1.x - A2.x) <= 1E-3)
		if( (A1.x - A2.x <= 2.22045e-016  && A1.x - A2.x >= 0))
		{
			return A1.y <A2.y;
		}
        return (A1.x > A2.x);
    }
}; // big --> small 






// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
int mergeSort(Point *array, int const begin, int const end)
{
	int invCount = 0;
	if (begin >= end)
		return 0; // Returns recursively

	int mid = (begin+end) / 2;
	invCount += mergeSort(array, begin, mid);
	invCount += mergeSort(array, mid + 1, end);
	
	// Merge stage
	int inversion = 0;
	int i = begin;
	int j = mid+1;
	int k = 0;
	Point *temp = new Point[end-begin+1];
	while (i <= mid && j <= end)
	{
		if(array[i].y <= array[j].y)
		{
			temp[k++] = array[i++];
			inversion += (end-j+1);
			// check if same x
			for(int idx = j; idx<=end;idx++)
			{
				if(array[i-1].xx == array[idx].xx)
				{
					inversion--;
				}
			}
		}else
		{
			temp[k++] = array[j++];
		}		
	}
	while(i<=mid)
		temp[k++] = array[i++];
	while(j<=end)
		temp[k++] = array[j++];
	k = 0;
	for(int i=begin; i<=end; i++)
		array[i] = temp[k++];
	delete [] temp;
	return inversion + invCount;
	



	return invCount;
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
	cout << "l: " << l << endl;
	cout << "r: " << r << endl; 
    for(int i=0; i<n; i++)
    {
        cin >> xArr[i] >> yArr[i];
    }
    // Do transform to A and B
    double *A = new double[n];
    double *B = new double[n];
    for(int i = 0; i<n; i++)
    {
        A[i] = static_cast<double>(yArr[i]) - r * xArr[i];
        B[i] = static_cast<double>(yArr[i]) - l * xArr[i];
    }
    
	// (A,B) --> AB
    Point *AB = new Point[n];
    for(int i = 0; i<n;i++)
    {
        AB[i] = Point(A[i], B[i], xArr[i], yArr[i]);
    }

    // Sort by x first;
    sort(AB, AB + n, greater_than_key() );
/*
	for(int i = 0;i<n; i++)
	{
		cout << AB[i].x << ", " << AB[i].y  << endl;
 	}
	*/

	// have been checked !!
/*
	for(int i = 0;i<n; i++)
	{
		cout << AB[i].x << ", " << AB[i].y   << ", " << AB[i].xx << ", " << AB[i].yy <<  endl;
 	}
*/
	
	

    // Counting inversion problems
    
	int c = mergeSort(AB, 0, n-1);

    cout << c << endl;

	



    return 0;
}