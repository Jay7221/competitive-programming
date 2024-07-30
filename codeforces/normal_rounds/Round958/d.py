import sys
import threading

INF = 1e30 + 7
NUM_ROUNDS = 3

def dfs(u, p):
    for j in range(NUM_ROUNDS):
        dp[u][j] = (j + 1) * a[u]

    for child in adj[u]:
        if child != p:
            dfs(child, u)
            for j in range(NUM_ROUNDS):
                tmp = INF
                for k in range(NUM_ROUNDS):
                    if k != j:
                        tmp = min(tmp, dp[child][k])
                dp[u][j] += tmp

def solve():
    global adj, a, dp
    n = int(input_data[current_pos[0]])
    current_pos[0] += 1

    a = list(map(int, input_data[current_pos[0]:current_pos[0] + n]))
    current_pos[0] += n
    dp = [[0] * NUM_ROUNDS for _ in range(n)]
    adj = [[] for _ in range(n)]

    for _ in range(n - 1):
        x, y = map(int, input_data[current_pos[0]:current_pos[0] + 2])
        current_pos[0] += 2
        x -= 1
        y -= 1
        adj[x].append(y)
        adj[y].append(x)

    dfs(0, -1)

    ans = min(dp[0])
    results.append(ans)

def main():
    global input_data, current_pos, results
    input_data = sys.stdin.read().split()
    current_pos = [0]
    results = []
    
    tc = int(input_data[current_pos[0]])
    current_pos[0] += 1
    for t in range(tc):
        solve()
    
    sys.stdout.write('\n'.join(map(str, results)) + '\n')

if __name__ == "__main__":
    threading.Thread(target=main).start()
