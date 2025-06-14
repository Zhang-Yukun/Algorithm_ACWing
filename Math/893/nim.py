def sg(x: int, ops: tuple, sg_value: list) -> int:
    if sg_value[x] != -1:
        return sg_value[x]
    s = set()
    for op in ops:
        if x >= op:
            s.add(sg(x - op, ops, sg_value))
    i = 0
    while i in s:
        i += 1
    sg_value[x] = i
    return i

if __name__ == "__main__":
    k = int(input())
    ops = tuple(map(int, input().split()))
    n = int(input())
    h = tuple(map(int, input().split()))
    sg_value = [-1] * (10 ** 4 + 10)
    res = 0
    for x in h:
        res ^= sg(x, ops, sg_value)
    if res:
        print("Yes")
    else:
        print("No")
