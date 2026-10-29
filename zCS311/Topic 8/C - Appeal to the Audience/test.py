import sys; 

sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")


n, k = map(int, input().split())
a = sorted(map(int, input().split()))
p = [int(input()) for _ in range(n-1)]
g = [[] for _ in range(n)]
for i in range(n-1): g[p[i]].append(i+1)

print(n, k)
print(a)
print(p)
print(g)


D = []
def trav(v, d):
    print("cur:", v)

    if not g[v]: 
        print("no chillun")
        print("return1:", v, 1)
        return 1

    m = []
    for u in g[v]: m.append(trav(u, d+1))
    k = max(m)

    print("for: ", v, " k: ", k, " | ", "m: ", m)

    for i in range(len(m)):
        if k == m[i]:
            for j in range(len(m)):
                if i != j: 
                    print("appending: ", m[j])
                    D.append(m[j])
            print("return2:", v, k+1)
            return k+1

    print("return3:", v)


D.append(trav(0, 0))

print("D orig: ", D)

t = sorted(D)
print(t)

t[-1] -= 1

print(t)

print(sum(x*y for x, y in zip(t, a)))