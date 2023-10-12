class Solution {
private:
    int peakIndexInMountainArray(MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;

            if (mountainArr.get(mid1) < mountainArr.get(mid2)) {
                left = mid1 + 1;
            } else {
                right = mid2 - 1;
            }
        }
        return left;
    }

    int binarySearch(MountainArray& mountainArr, int target, int start, int end, bool reverse) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int midValue = mountainArr.get(mid);

            if (midValue == target) {
                return mid;
            }

            if (reverse) {
                if (midValue > target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if (midValue < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }

public: 
    // Binary search approach 
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = peakIndexInMountainArray(mountainArr);
        int result = binarySearch(mountainArr, target, 0, peak, false);

        if (result == -1) {
            result = binarySearch(mountainArr, target, peak, mountainArr.length() - 1, true);
        }

        return result;
    }
};
