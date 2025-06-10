eps = 1e-9
def cr(n: float):
    l = -100.0
    r = 100.0
    m = 0.0
    res = 0.0
    while l < r:
        if (res - n < eps) and (res - n > -eps):
            return m
        elif res < n:
            l = m
        else:
            r = m
        m = (l + r) / 2
        res = m * m * m


if __name__ == "__main__":
    n = float(input())
    print(f"{cr(n):.6f}")
