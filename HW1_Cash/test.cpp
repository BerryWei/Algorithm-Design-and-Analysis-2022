#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int points[] = {23, 45, 56, 12, 34, 56};
    int key = 56;

    int x = sizeof(points) / sizeof(*points);

    bool present = std::find(points, points+x, key) != points + x;
    cout << "x: " << x << endl; 

    if (present){
        cout << "The element is present";
    }else{
        cout << "The element is not present";
    }
    return 0;
}