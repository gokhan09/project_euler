#include "programs11_20.h"

#include <map>
#include <unordered_map>

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void test_integer_division_truncation() {
    cout << "99/100=" << 99/100 << "\n";
    cout << "1/100=" << 1/100 << "\n";
    cout << "999/100=" << 999/100 << "\n";
}

vector<string> read_file_line_by_line(const string& file_name) {
    vector<string> result;
    ifstream file(file_name);
    string line;
    if(file.is_open()) {
        while (getline(file, line)) {
            result.push_back(line);
        }
        file.close();
    } else {
        cerr << "Unable to open file!" << endl;
    }
    return result;
}

/**
 * Problem 17
 */

int count_words() {

    unordered_map<int,int> number_map;
    number_map.insert(std::make_pair(1, 3));
    number_map.insert(std::make_pair(2, 3));
    number_map.insert(std::make_pair(3, 5));
    number_map.insert(std::make_pair(4, 4));
    number_map.insert(std::make_pair(5, 4));
    number_map.insert(std::make_pair(6, 3));
    number_map.insert(std::make_pair(7, 5));
    number_map.insert(std::make_pair(8, 5));
    number_map.insert(std::make_pair(9, 4));
    number_map.insert(std::make_pair(10, 3));
    number_map.insert(std::make_pair(11, 6));
    number_map.insert(std::make_pair(12, 6));
    number_map.insert(std::make_pair(13, 8));
    number_map.insert(std::make_pair(14, 8));
    number_map.insert(std::make_pair(15, 7));
    number_map.insert(std::make_pair(16, 7));
    number_map.insert(std::make_pair(17, 9));
    number_map.insert(std::make_pair(18, 8));
    number_map.insert(std::make_pair(19, 8));
    number_map.insert(std::make_pair(20, 6));
    number_map.insert(std::make_pair(30, 6));
    number_map.insert(std::make_pair(40, 5));
    number_map.insert(std::make_pair(50, 5));
    number_map.insert(std::make_pair(60, 5));
    number_map.insert(std::make_pair(70, 7));
    number_map.insert(std::make_pair(80, 6));
    number_map.insert(std::make_pair(90, 6));

    int sum = 0;

    for(int i = 1; i <= 999; i++) {
        int num = i;
        if(num / 100 > 0) {
            sum = sum + number_map[num / 100] + 7;
            if(num % 100 != 0) {
                sum = sum + 3; // add an 'and' here
                num = num - ((num / 100) * 100);
            } else {
                continue;
            }
        }
        if(number_map.contains(num)) {
            sum = sum + number_map[num];
            continue;
        }
        sum = sum + number_map[(num / 10) * 10];
        num = num - ((num / 10) * 10);
        sum = sum + number_map[num];
    }

    sum = sum + 11; // add one thousand

    return sum;
}

/**
 * Problem 18
 * @return int
 */
int maximum_path_sum_1() {
    const string file_name = "../file_resources/question_18.txt";
    const vector<string> result = read_file_line_by_line(file_name);

    vector<vector<int>> numbers;
    for(const string& s : result) {
        //cout << s << endl;
        istringstream ss(s);
        string token;
        vector<int> num_arr;
        while(getline(ss, token, ' ')) {
            num_arr.emplace_back(stoi(token));
        }
        numbers.emplace_back(num_arr);
    }
    int max_val = 0;
    for(size_t i = 1; i < numbers.size(); i++) {
        vector<int>& v = numbers[i];
        for(size_t k = 0; k < v.size(); k++) {
            if(k == 0) {
                v[k] = v[k] + numbers[i-1][0];
            } else if(k == v.size() - 1) {
                v[k] = v[k] + numbers[i-1][k-1];
            } else {
                v[k] = v[k] + max(numbers[i-1][k], numbers[i-1][k-1]);
            }
        }
    }

    for(size_t i = 0; i < numbers[numbers.size()-1].size(); i++) {
        max_val = max(numbers[numbers.size()-1][i], max_val);
    }
    return max_val;
}

void find_integral_yx2() {

    /**
     * we are going to find that
     */

    double incremental = 0.0000001;
    int k = 4;
    double sum = 0;
    for(double i = 0; i <= k; i = i + incremental) {
        sum = sum + (incremental * (i * i));
    }
    std::cout << "Result is:" << sum << std::endl;
    std::cout << "Exited integral calculation";
}