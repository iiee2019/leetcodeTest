
int cmp(const void* _a, const void* _b) {
    int *a = _a, *b = (int*)_b;
    return *a == *b ? 0 : *a > *b ? 1 : -1;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size,
               int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    *returnSize = 0;
    int* intersection = (int*)malloc(sizeof(int) * fmin(nums1Size, nums2Size));
    int index1 = 0, index2 = 0;
    while (index1 < nums1Size && index2 < nums2Size) {
        if (nums1[index1] < nums2[index2]) {
            index1++;
        } else if (nums1[index1] > nums2[index2]) {
            index2++;
        } else {
            intersection[(*returnSize)++] = nums1[index1];
            index1++;
            index2++;
        }
    }
    return intersection;
}
