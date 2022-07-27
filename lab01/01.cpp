#include <iostream>
#include <iomanip>
#include <cstdlib>



int getAverage(int* array, int n)
{
	int ave = 0;
	for(int i = 0; i<n; i++)
		ave += array[i];

	return ave/n;

}

int main(void)
{
	int* nums;
	int count=0;

	srand((unsigned int)time(NULL));

	while(1){
		std::cout << "input array size(1-10000)" << std::endl;
		std::cin  >> count;

		if(count <= 10000 && count >= 1) break;
	}

	nums = new int[count];

	for(int i = 0; i<count; i++) {
		nums[i] = rand() % 100;
	}

	std::cout << "Data : \n";
	for(int i = 0; i<count; i++) {
		std::cout << std::setw(3) << nums[i];
		if(i%20 == 19 ) std::cout <<  "\n";
		else if(i==count-1)	std::cout <<  "\n";
	}

	std::cout << "Average : " << getAverage(nums, count) << std::endl;
	delete[] nums;

	return 0;
}