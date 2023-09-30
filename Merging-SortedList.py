def merge_sorted_lists(list1, list2):
    # Initialize variables
    len1 = len(list1)
    len2 = len(list2)
    merged_list = [0] * (len1 + len2)
    i = j = k = 0

    # Merge the two sorted lists
    while i < len1 and j < len2:
        if list1[i] < list2[j]:
            merged_list[k] = list1[i]
            i += 1
        else:
            merged_list[k] = list2[j]
            j += 1
        k += 1

    # Copy remaining elements from list1, if any
    while i < len1:
        merged_list[k] = list1[i]
        i += 1
        k += 1

    # Copy remaining elements from list2, if any
    while j < len2:
        merged_list[k] = list2[j]
        j += 1
        k += 1

    return merged_list

# Example usage:
list1 = [1, 3, 5, 7]
list2 = [2, 4, 6, 8]
merged = merge_sorted_lists(list1, list2)
print(merged)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------              ------------------------                    ----------------------------                             ---------------------------------                  -------------------------------------          --------------------------------------

Input: You start with two sorted arrays (lists) as input, where each element in both lists is already in ascending order.

Initialization: Create a new array to store the merged result. This new array should have a size equal to the sum of the sizes of the two input arrays.

Pointers: Initialize three pointers: i, j, and k. i points to the current element in the first list, j points to the current element in the second list, and k points to the position in the merged array.

Comparison: Compare the elements at list1[i] and list2[j]. Choose the smaller element to be placed in the merged array at merged[k].

Increment: Move the pointer of the list from which you selected the element forward (increment i or j) and also increment k to move to the next position in the merged array.

Looping: Continue comparing and merging elements from both lists until you reach the end of either list. This ensures you maintain the sorted order in the merged array.

Remaining Elements: If one list has more elements to process after the other has been fully merged, simply copy the remaining elements into the merged array since they are already sorted.

Completing the Merge: Repeat the above process until you have processed all elements in both lists and have filled the merged array completely.

Output: The merged array now contains all elements from the two input arrays, sorted in ascending order.

Time Complexity: The time complexity of this merging algorithm is O(len1 + len2), where len1 and len2 are the lengths of the two input lists. This is because you iterate through both lists once while merging.
