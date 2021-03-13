#include <iostream>
#include <string>
#include <cstring>
#include <time.h>
#include <iomanip>
#include <iterator>
#include <experimental/iterator>
#include <chrono>

using namespace std;

void findNemo(char x[]);
void findNemo2(char x[]);
void findNemo3(char x[]);
void findNemo4(string str[], int n);

int main(){
    // char a[] = {"Raunak"};
    // cout<<a[1]<<endl;

    char x[] = {"Nemo"};
    string str[] = {"Ram", "Shyam", "Bharat", "Shatru", "Nemo"};
    int n = std::end(str) - std::begin(str);

    findNemo(x);
    findNemo2(x);
    findNemo3(x);
    findNemo4(str, n);

    return 0;
}

void findNemo(char x[]){
    cout<<"-------Copying using char pointer & for loop-------"<<endl;
    
    cout<<"*x: "<<*x<<endl;
    size_t len = strlen(x);
    char *c = new char[len+1];
    string s{};
    // *c = x[0];
    // *(c+1) = x[1];

    for(int i=0; i<len;i++)
        c[i] = x[i];

    s = c; //Directly char 'c' can't be compared with any string values since bth are incompatible types.
    if(s == "Nemo")
        {cout<<"Found Nemo!!!"<<endl;}
    else
        {cout<<"Couldn't find Nemo!!!"<<endl;}

}


void findNemo2(char x[]){

    cout<<"-------Copying using char pointer & strcpy()-------"<<endl;
    size_t len = strlen(x);
    char* ret = new char[len+1];

    strcpy(ret, x);    //strcpy() method is used here
    ret[len+1] = '\0';
    cout<<ret<<endl;
    if(ret == "Nemo")
        cout<<"Found Nemo!!!"<<endl;
    else
        cout<<"Couldn't find Nemo!!!"<<endl;
    
}

void findNemo3(char x[]){
    cout<<"-------Copying using string & for loop-------"<<endl;
    size_t len = strlen(x);
    string s;
    time_t start, end; 

    time(&start); //Takes the clock's value and stores in variable 'start'.
    for(int i=0; i<strlen(x) ;i++)
        s += x[i]; //Copies the value of 'x' char by char and stores it in string variable.
    
    cout<<s<<endl;
    if(s == "Nemo"){
        cout<<"Found Nemo!!!"<<endl;
        time(&end); //Takes the clock's value and stores in variable 'end'. 
        cout << "Time taken by program is : " << fixed << (end - start)<< setprecision(5)<<" sec"<<endl;
    }
    else{
        cout<<"Couldn't find Nemo!!!"<<endl; 
    }   
}

void findNemo4(string str[], int n){
    cout<<"-------Finding in string array-------"<<endl;
    int x=0;

    const auto begin = chrono::high_resolution_clock::now();    //Another high resolution clock.
    
    for(int i=0; i<n;i++){
        if(str[i] == "Nemo"){
            x=1;
            break;
        }
        else
            x=0;
    }

    const auto end = chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    cout << "Time taken by program is : " << fixed <<ms<<" millisec"<<endl;
    
    if(x==1)
        cout<<"Found Nemo"<<endl;
    else
        cout<<"Couldn't find Nemo"<<endl;
}
