
#include "programs_21_30.h"

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

int find_name_score(const std::string& name) {
    int score = 0;
    for(const char& c : name) {
        score = score + (c - 'A' + 1);
    }
    return score;
}

std::string read_file(const std::string& file_name) {
    std::ifstream file(file_name);
    std::string line;
    std::string whole;
    if(file.is_open()) {
        while (getline(file, line)) {
            whole.append(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file!" << std::endl;
    }
    return whole;
}

/**
 * Question 21
 */
void find_amicable_numbers() {
    const auto start = std::chrono::steady_clock::now();
    std::unordered_map<int, int> my_map;
    int all_sum = 0;
    for (int i = 2; i <= 10000; i++) {
        int temp_sum = 0;
        for(int k = 1; k < i; k++) {
            if(i % k == 0) {
                temp_sum = temp_sum + k;
            }
        }
        if(my_map.contains(temp_sum) && my_map[temp_sum] == i) {
            my_map.emplace(std::make_pair(i, temp_sum));
            all_sum = all_sum + i + temp_sum;
        }
        my_map.emplace(std::make_pair(i, temp_sum));
    }
    std::cout << "Amicable Numbers:" << all_sum << std::endl;
    const auto end = std::chrono::steady_clock::now();
    const auto diff = end - start;
    //std::cout << std::chrono::duration<double, std::milli>(diff).count() << " ms" << std::endl;
}

/**
 * Question 22 NAMES SCORES
 */
void find_alphabetical_score() {
    std::string file_name = "../file_resources/0022_names.txt";
    std::string file_content = read_file(file_name);
    file_content.erase(remove(file_content.begin(), file_content.end(), '\"' ),file_content.end());
    std::vector<std::string> names;

    std::istringstream iss(file_content);
    std::string s;

    while (std::getline(iss, s, ',')) {
        names.push_back(s);
    }

    std::sort(names.begin(), names.end());
    int sum = 0;
    for(int i = 0; i < names.size(); i++) {
        int score = find_name_score(names[i]);
        sum = sum + (score * (i + 1));
    }
    std::cout << "Names Scores:" << sum << std::endl;
}

bool is_abundant(int num) {
    int divisor_sum = 0;
    for(int i = 1; i <= num - 1; i++) {
        if(num % i == 0) {
            divisor_sum = divisor_sum + i;
        }
    }
    if(divisor_sum > num) {
        return true;
    }
    return false;
}

void non_abundant_sums() {
    std::set<int> my_set;
    for(int i = 2; i <= 28123; i++) {
        if(is_abundant(i)) {
            my_set.emplace(i);
        }
    }

    std::vector my_vector(28123, false);

    for(const int num1 : my_set) {
        for(const int num2 : my_set) {
            int possible_sum = num1 + num2;
            if(possible_sum > 28123) {
                break;
            }
            my_vector[possible_sum - 1] = true;
        }
    }
    int sum = 0;
    for(int i = 0; i < my_vector.size(); i++) {
        if(!my_vector[i]) {
            sum = sum + i + 1;
        }
    }

    std::cout << "Non Abundant Sums:" << sum << std::endl;
}

int factorial(int n) {
    int result = 1;
    if(n == 0 || n == 1) {
        return 1;
    }
    while(n >= 1) {
        result = result * n;
        n = n - 1;
    }
    return result;
}

/**
 * Question 24
 * https://projecteuler.net/problem=24
 */
void lexicographic_permutations() {
    std::vector<std::string> num_vec = {"0","1","2","3","4","5","6","7","8","9"};

    int count = 1000000;
    std::string my_result = "";
    while(count > 1) {
        const int len_vec = num_vec.size();
        // how many different combinations to the right?
        const int combinations = factorial(len_vec - 1);
        int index_to_remove = 0;
        if(count > combinations) {
            const int division = count / combinations;
            const int reminder = count % combinations;
            if(reminder > 0) {
                count = reminder;
                index_to_remove = division;
            } else {
                count = combinations;
                index_to_remove = division - 1;
            }
        }
        my_result.append(num_vec[index_to_remove]);
        num_vec.erase(num_vec.begin() + index_to_remove);
    }
    for(std::string s : num_vec) {
        my_result.append(s);
    }
    std::cout << "Lexicographic Permutations:" << my_result << std::endl;
}

