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
