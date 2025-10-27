#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map; //value -> index

    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        //check if the complement exists in map
        if(map.find(complement) != map.end()) {
            return {
                map[complement], i
            };
        }
        //store current number and its index
        map[nums[i]] = i;
    }
    return {}; //solution not found
}

int main() {
    std::vector<int> nums = {6, 12, 2, 7};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if(!result.empty()) {
        std::cout << "Indices " << result[0] << ", " << result[1] << std::endl;
        std::cout << "Values " << nums[result[0]] << " + " << nums[result[1]]
        << " = " << target << std::endl;
    } else {
        std::cout << "No Solution Found" << std::endl;
    } return 0;
}