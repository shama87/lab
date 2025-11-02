#include <iostream>
#include <limits>
void findMinMax(const int arr[], int size, int& minVal, int& maxVal) {

    if (size <= 0) {

        minVal = 0;
        maxVal = 0;
        std::cerr << "Error: Array is empty or size is non-positive." << std::endl;
        return;
    }
    minVal = std::numeric_limits<int>::max();
    maxVal = std::numeric_limits<int>::min();

   for (int i = 0; i < size; ++i) {

        if (arr[i] < minVal) {
            minVal = arr[i];
        }


        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
}

int main() {

    int data[] = {40, 17, 86, -5, -97, 10, 51};
    int n = sizeof(data) / sizeof(data[0]);


    int minimum, maximum;
    findMinMax(data, n, minimum, maximum);

    if (n > 0) {
        std::cout << "The array elements are: ";
        for (int i = 0; i < n; ++i) {
            std::cout << data[i] << (i == n - 1 ? "" : ", ");
        }
        std::cout << "\n" << std::endl;
        std::cout << "Minimum value found: " << minimum << "" << std::endl;
        std::cout << "Maximum value found: " << maximum << "" << std::endl;
    }

    return 0;
}
