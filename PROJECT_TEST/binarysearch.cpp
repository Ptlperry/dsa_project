#include <iostream>
#include <vector>
using namespace std;

int Binary_Search(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    cout<<endl << "Enter the size of array: ";
    int n;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of array: ";
    {
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }
    cout << "Enter the element to search: ";

    int target;
    cin >> target;

    int result = Binary_Search(arr, target);
    cout << "Element at index is: " << result << endl;

    return 0;
}
