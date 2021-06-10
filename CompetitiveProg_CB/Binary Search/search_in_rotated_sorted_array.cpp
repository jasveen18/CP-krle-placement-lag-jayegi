// Return index if element is present.
bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    if (n == 0)
        return false;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;

        // It means mid lies on first array.
        else if (nums[mid] >= nums[low]) {
            // 2 Case -> Element lies on the left or the right of the first partition
            if (nums[mid] >= target and nums[low] <= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Mid lies on 2nd array.
        else {
            if (nums[mid] <= target and target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}


// Return true if element is present. (Duplicates element are present.)
bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    if (n == 0)
        return false;

    while (low <= high) {
        // To avoid duplicates
        while (low < high and nums[low] == nums[low + 1])
            low++;
        while (low < high and nums[high] == nums[high - 1])
            high--;

        // Same as search in a rotated sorted array.
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;

        else if (nums[mid] >= nums[low]) {
            // 2 Case Element lies on the left or the right of the first partition
            if (nums[mid] >= target and nums[low] <= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {
            if (nums[mid] <= target and target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return false;
}