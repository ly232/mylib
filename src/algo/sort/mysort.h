#ifndef _mysort_h
#define _mysort_h
#define MIN(a,b) (a<b)?a:b
namespace ns_lin_algo{
namespace sort{
/*
@Author: Lin Yang
my implmentation for various sort algorithms
*/
//merge sort
template <typename T>
void mergesort(T* a, int len){
	if (len<=1){
		return;
	}
	if (len==2){
		if (a[0]>a[1]){
			int tmp = a[0];
			a[0] = a[1];
			a[1] = tmp;
		}
		return;
	} else {
		int mid = len/2;
		mergesort(a, mid);
		mergesort(&a[mid], len-mid);
		int left_idx = 0;
		int right_idx = mid;
		T* a_copy = new T[len];
		try{
			for (int i=0; i<len; i++){
				if (left_idx==mid){
					if (right_idx<len){
						a_copy[i] = a[right_idx++];
						continue;
					} else {
						throw 1;
					}
				} else if (right_idx==len){
					if (left_idx<mid){
						a_copy[i] = a[left_idx++];
						continue;
					} else {
						throw 2;
					}
				} else if (a[left_idx]<a[right_idx]){
					a_copy[i] = a[left_idx++];
				} else {
					a_copy[i] = a[right_idx++];
				}
			}
			memcpy(a, a_copy, sizeof(T)*len);
			delete [] a_copy;
		} catch (int e){
			switch (e){
				case 1:
					std::cerr<<"right index out of bound"<<std::endl;
					break;
				case 2:
					std::cerr<<"lef index out of bound"<<std::endl;
					break;
				default:
					break;
			}
		}
	}
}

//min heap sort
template <typename T>
class MinHeap{
public:
	MinHeap(int maxlen):heap_size(0),arr_len(maxlen){
		data = new T[arr_len];
	};
	~MinHeap(){
		delete [] data;
	};
	void get_parent(int curr, T** parent){
		if (curr<1 || curr>heap_size || heap_size<=0 || arr_len < 0)
			return;
		if (curr==1)
			*parent = &(data[1]);
		else
			*parent = &(data[curr/2]);
	};
	void get_left(int curr, T** left){
		if (curr<1 || curr>heap_size || heap_size<=0 || arr_len < 0)
			return;
		int left_idx = curr*2;
		if (left_idx>heap_size)
			return;
		*left = &(data[left_idx]);
	};
	void get_right(int curr, T** right){
		if (curr<1 || curr>heap_size || heap_size<=0 || arr_len < 0)
			return;
		int right_idx = curr*2+1;
		if (right_idx>heap_size)
			return;
		*right = &(data[right_idx]);
	};
	void insert(const T& item){
		int new_idx = ++heap_size;
		//percolate up:
		while(1){
		std::cout<<"..."<<std::endl;
			T* tmp;
			get_parent(new_idx, &tmp);
			if (tmp==NULL){
				std::cerr<<"ERROR: get_parent returned NULL"<<std::endl;
				return;
			}
			if (*tmp < item || new_idx==1){
				data[new_idx] = item;
				return;
			}
			//swap parent and new index node:
			data[new_idx] = *tmp;
			new_idx /= 2;
		}
		return;
	};
private:
	T* data;
	int heap_size;
	int arr_len;
};

} //end namespace sort
} //end namespace ns_lin_algo
#endif
