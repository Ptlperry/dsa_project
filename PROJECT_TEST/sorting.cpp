#include <iostream>
#include <vector>
using namespace std;

void Merge(int arr[], int left, int mid, int right);
void MergeSort(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);
void display(int arr[], int n);

void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void QuickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = arr[right];
        int i = (left - 1);
        for (int j = left; j < right; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);
        int pi = i + 1;

        QuickSort(arr, left, pi - 1);
        QuickSort(arr, pi + 1, right);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    int n, choice;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    do
    {
        cout << endl
             << "--- Sorting --- " << endl;
        cout << endl
             << "Press 1 for Merge Sort" << endl;
        cout << "Press 2 for Quick Sort" << endl;
        cout << "Press 3 for Exit" << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            MergeSort(arr, 0, n - 1);
            cout << "Merge sort: ";
            display(arr, n);
            break;
        case 2:
            QuickSort(arr, 0, n - 1);
            cout << "Quick sort: ";
            display(arr, n);
            break;
        case 3:
            cout << "Exiting program!!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
