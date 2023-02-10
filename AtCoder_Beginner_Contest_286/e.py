import sys
import re
#from collections import deque
#from collections import defaultdict
#import bisect #二分探索
#import math
sys.setrecursionlimit(10**7)
def I(): return int(sys.stdin.readline().rstrip())
def MI(): return map(int,sys.stdin.readline().rstrip().split())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def LI2(): return list(map(int,sys.stdin.readline().rstrip()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())
def LS2(): return list(sys.stdin.readline().rstrip())

INF = 1e19
n = I()
a = LI()

dist = [[INF]*n for _ in range(n)]
value = [[0]*n for _ in range(n)]

s = [input() for _ in range(n)]

for i in range(n):
    for j, c in enumerate(s[i]):
        if c == "Y":
            dist[i][j] = 1
            value[i][j] = a[j]
        if i == j:
            dist[i][j] = 0
        
for k in range(n):
    for i in range(n):
        for j in range(n):            
            if dist[i][j] > dist[i][k] + dist[k][j]:
                dist[i][j] = dist[i][k] + dist[k][j]
                value[i][j] = value[i][k] + value[k][j]
                
            elif dist[i][j] == dist[i][k] + dist[k][j] and value[i][k] + value[k][j] > value[i][j]:
                value[i][j] = value[i][k] + value[k][j]
    
q = I()

for i in range(q):
    u,v = MI()
    u -= 1
    v -= 1
    if dist[u][v] != INF:
        print(dist[u][v], value[u][v]+a[u])
    else:
        print("Impossible")