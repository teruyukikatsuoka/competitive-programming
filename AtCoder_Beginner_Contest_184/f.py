import sys
import re
#from collections import deque
#from collections import defaultdict
import bisect #二分探索
#import math
sys.setrecursionlimit(10**7)
def I(): return int(sys.stdin.readline().rstrip())
def MI(): return map(int,sys.stdin.readline().rstrip().split())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def LI2(): return list(map(int,sys.stdin.readline().rstrip()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())
def LS2(): return list(sys.stdin.readline().rstrip())

#1次元の配列
# list(map(int, input().split()))
#2次元の配列
# [list(map(int, input().split())) for i in range()]
#wsl pypy3 ファイル名

n,t = MI()
a = LI()

l = [0]
r = [0]

for i in a[:20]:
    for j in range(len(l)):
        l.append(i + l[j])
l.sort()

for i in a[20:]:
    for j in range(len(r)):
        r.append(i + r[j])
r.sort()
        
ans = 0
for x in l:
    if x > t:
        continue
    
    ans = max(ans, x + r[bisect.bisect_right(r, t - x) - 1])

print(ans)