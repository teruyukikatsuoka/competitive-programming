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

#PyPyだとTLEします
def dfs(s):
    seen[s] = True
    for nt in g[s]:
        if seen[nt]:
            if color[nt] == color[s]:
                print('0')
                exit()
        else:
            color[nt] = -color[s] #色を1，－1として判別する
            cnt[color[nt]] += 1
            dfs(nt)
        
n, m = map(int, input().split())
g = [[] for _ in range(n)]
seen = [False]*n
color = [0]*n
for i in range(m):
    u,v = map(int, input().split())
    u-=1;v-=1
    g[u].append(v)
    g[v].append(u)

ans = n*(n-1)//2 - m
for i in range(n):
    if seen[i]:
        continue
    color[i] = 1
    cnt = [0,1,0]
    dfs(i)
    ans -= cnt[1]*(cnt[1]-1)//2
    ans -= cnt[-1]*(cnt[-1]-1)//2
    
print(ans)