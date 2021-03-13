#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <algorithm>   

using namespace std;

void logArray(int arr1[], int len1);
void copyArray(int arr1[], int arr2[], int len1, int len2);
void arrayToVectorSorted();
void findUniqueArray(int arr1[], int arr2[], int len1, int len2);

int main(){
    int arr1[] = {1, 3, 5, 7, 9, 1};
    int len1 = end(arr1) - begin(arr1);

    int arr2[] = {1, 0, 2, 4, 6, 8, 0};
    int len2 = end(arr2) - begin(arr2);
   
    int arr3[] = {1, 0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    set<int> set(begin(arr3), end(arr3)); //creates a set with unique sorted values.

    logArray(arr1, len1);
    copyArray(arr1, arr2, len1, len2);
    arrayToVectorSorted();
    findUniqueArray(arr1, arr2, len1, len2);
}

void logArray(int arr1[], int len1){
    cout<<"------------------------Logging all combination between 2 arrays------------------------"<<endl;
    for(int i=0; i<len1; i++){
        for(int j=1; j<len1; j++){
            cout<<"("<<arr1[i]<<", "<<arr1[j]<<") ";
        }
    }
    cout<<endl;
}

void copyArray(int arr1[], int arr2[], int len1, int len2)
{
    cout<<"------------------------Copying 2 arrays to a final array------------------------"<<endl;
    int len = len1 + len2;
    int bigArr[len];
    
    /*---------------------------------METHOD-1 TO COPY 2 ARRAYS---------------------------------*/
    // copy(arr1, arr1 + len1, bigArr);
    // copy(arr2, arr2 + len2, bigArr + len1);

    /*---------------------------------METHOD-2 TO COPY 2 ARRAYS---------------------------------*/
    copy(arr2, arr2 + len2, copy(arr1, arr1 + len1, bigArr));

    for(auto elem:bigArr)
        cout<<elem<<" ";
        cout<<endl;
}

void arrayToVectorSorted()
{
    cout<<"------------------------Converting arrays to vector & sorting------------------------"<<endl;
    int arr1[] = {1, 3, 5, 7, 9, 1};
    int arr2[] = {1, 0, 2, 4, 6, 8};

    int len1 = end(arr1) - begin(arr1);
    int len2 = end(arr2) - begin(arr2);
    
    std::vector<int> vec1(std::begin(arr1), std::end(arr1));
    std::vector<int> vec2(std::begin(arr2), std::end(arr2));

    vec1.insert( vec1.end(), vec2.begin(), vec2.end());

    sort(vec1.begin(), vec1.end());

    for(const auto elem:vec1)
        cout<<elem<<" ";
        cout<<endl;
}

void findUniqueArray(int arr1[], int arr2[], int len1, int len2)
{
    cout<<"--------------------Logging unique arrays & count of duplicate element--------------------"<<endl;
    int len = len1 + len2;
    int count{0};
    int bigArr[len];

    copy(arr2, arr2 + len2, copy(arr1, arr1 + len1, bigArr));
    set<int> s(bigArr, bigArr + len); //It prints the unique array
    
    for(const auto elem:s)
        cout<<elem<<" ";
    
    sort(bigArr, bigArr + len);
    for(int i=0; i<len; i++)
    {
        if(i < len - 1 && bigArr[i] == bigArr[i+1]) //It finds the no. of element that's duplicate
        {
            count++;
        }
    }
    cout<<endl<<"count: "<<count<<endl;
}