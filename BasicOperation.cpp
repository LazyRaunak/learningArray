/* 
Operations on Array
-Lookup/Access : O(1)
-Push : O(1)
-Insert - O(n)
-Delete - O(n)

In case of dynamic arrays, if we need to add/ append elements to an array, we need to copy the array & then 
we create an extra space which is used for appending the the new element. Hence, 
-Appends : O(1) and in other cases it can be O(n).
*/

#include <iostream>
#include <iterator>
#include <bits/stdc++.h>

using namespace std;

void appendVec(vector<int> vec);
void popVec(vector<int> vec);
void removeVec(vector<int> vec);

int main()
{
    vector<int> vec{1, 2, 3, 4, 5};
    appendVec(vec);
    popVec(vec);
    removeVec(vec);

    return 0;
}

void appendVec(vector<int> vec)
{
    cout<<"------------------Pushing elements at back------------------"<<endl;
    vec.push_back(100);
    for(const auto elem:vec)
        cout<<elem<<" ";
    cout<<endl;
}

void popVec(vector<int> vec)
{
    cout<<"------------------Popping element------------------"<<endl;
    vec.pop_back();
    for(const auto elem:vec)
        cout<<elem<<" ";
    cout<<endl;    
}

void removeVec(vector<int> vec)
{
    cout<<"------------------Removing elements------------------"<<endl;
    int elem{0}, c{0};
    cout<<"Enter the element to remove: ";
    cin>>elem;

    for(int i = 0; i < vec.size(); i++) {
        if(vec[i]!=elem) {
            vec[c++] = vec[i];
        }
    }
    if(c == vec.size()) {
        cout<<"Element not found in array!"<<endl;
    }
    else {
        for(int i = 0; i < c; i++)
            cout<<vec[i]<<" ";
    }   

}
