//
// Created by Asus on 03-07-2023.
//
//
// Created by Asus on 02-07-2023.
//
#include<iostream>
using namespace std;

int main()
{
    cout<<"hello"<<endl;
    cout<<"next line"<<endl;
    int age;
    cout<<"Enter your age:"<<endl;
    cin>>age;

    if(age>=18)
        cout<<"you can vote";
    else
        cout<<"Hey Kiddo! Come back after "<<18-age<<" Years";

    return 0;
}