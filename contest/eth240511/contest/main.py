def can_consume_k_mate(k, n, types, hours):
    type_count = {j: 0 for j in range(1, max(types) + 1)}
    available = [(hours[j], types[j]) for j in range(n)]
    available.sort(reverse=True)  # Sort by expiration time in descending order

    consumed_total = 0
    consumed_type = 0
    for i in range(n):
        time, type = available[i]
        if type_count[type] < k:
            consumed_total += 1
            type_count[type] += 1
            consumed_type += 1
            if consumed_type == k:
                consumed_type = 0

    return consumed_total

def max_mate_consumption(t, test_cases):
    for i in range(t):
        n, m = test_cases[i][0]
        types = test_cases[i][1]
        hours = test_cases[i][2]
        
        low, high = 0, n
        while low < high:
            mid = (low + high + 1) // 2
            if can_consume_k_mate(mid, n, types, hours) == n:
                low = mid
            else:
                high = mid - 1
        
        print(low)

# Input
t = int(input())
test_cases = []
for _ in range(t):
    n, m = map(int, input().split())
    types = list(map(int, input().split()))
    hours = list(map(int, input().split()))
    test_cases.append((n, m, types, hours))

# Output
max_mate_consumption(t, test_cases)
