#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class ArrayContainer {
public:
    ArrayContainer(size_t size) : data(size) {}

    void fill() {
        for (auto& elem : data) {
            std::cin >> elem;
        }
    }

    void print() const {
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    int minElem() const {
        if (data.empty()) throw std::runtime_error("Array is empty");
        return *std::min_element(data.begin(), data.end(), [](int a, int b) {
            return std::abs(a) < std::abs(b);
            });
    }

    int NegSum() const {
        bool found_negative = false;
        int sum = 0;
        for (const auto& elem : data) {
            if (found_negative) {
                sum += std::abs(elem);
            }
            if (elem < 0) {
                found_negative = true;
            }
        }
        return sum;
    }

    void compr(int a, int b, int fill_value) {
        auto new_end = std::remove_if(data.begin(), data.end(), [a, b](int elem) {
            return elem >= a && elem <= b;
            });
        std::fill(new_end, data.end(), fill_value);
    }

private:
    std::vector<int> data;
};

int main() {
    size_t size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    ArrayContainer array(size);

    std::cout << "Fill the array with " << size << " elements: ";
    array.fill();

    std::cout << "Array elements: ";
    array.print();

    try {
        int min_abs_element = array.minElem();
        std::cout << "Minimum element by absolute value: " << min_abs_element << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    int sum_after_first_negative = array.NegSum();
    std::cout << "Sum of absolute values after the first negative element: " << sum_after_first_negative << std::endl;

    int a, b, fill_value;
    std::cout << "Enter the interval [a, b]: ";
    std::cin >> a >> b;
    std::cout << "Enter the fill value: ";
    std::cin >> fill_value;

    array.compr(a, b, fill_value);

    std::cout << "Compressed array: ";
    array.print();

    return 0;
}
