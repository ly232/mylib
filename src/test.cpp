#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include "pack/algo/sort/mysort.h"
using namespace std;
int main(){
	srand(time(NULL));
	const int len = 7;
	int a[len] = {15,8,21,9,191,2,9};
	ns_lin_algo::sort::mergesort(a,len);
	for (int i=0; i<len; i++){
		cout<<"a["<<i<<"]="<<a[i]<<endl;
	}
	cout<<"==========="<<endl;
	char b[len] = {'e','a','w','i','z','q','o'};
	ns_lin_algo::sort::mergesort(b,len);
	for (int i=0; i<len; i++){
		cout<<"b["<<i<<"]="<<b[i]<<endl;
	}
	cout<<"============"<<endl;
	ns_lin_algo::sort::MinHeap<int> mh_int(len);
	for (int i=0; i<len; i++){
		int r = rand()%10+1;
		cout<<"inserting: "<<r<<endl;
		mh_int.insert(r);
	}
	
	return 0;
}
