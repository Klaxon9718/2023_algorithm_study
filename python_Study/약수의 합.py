# 약수를 구하기 위한 함수
def cal (val):
    for i in range(val):
        if(val % i ==0):    
            plus +=  i
    return plus



#dynamic programming
def dpf (val):
        if val == 1 :
            dp[0] = 1
            return dp[0]
        if val == 2 :
            dp[1] = 3
            return  dp[1]
        dp[val - 1] = dp[val- 2] + cal(val)
        return dp[val - 1]



######MAIN########
test_case = int(input())

arr = []

dp = [10000000]

for i in range(test_case):
    arr.append(int(input()))

for val in arr:
    result = dpf(val)
    print (result)
