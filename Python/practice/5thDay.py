import numpy as np

a = np.array([1, 1, 2, 3, 4, 5, 5 ,5, 5, 7, 8, 9, 10, 11, 24, 100])

b = np.unique(a)

print("1.", b)

print("2. 최대 :", np.max(b), ", 최소 :", np.min(b), ", 평균 :", np.mean(b))

print("3. 합 :", np.sum(b))

print("4. 중앙 :", np.median(a))





import pandas as pd

c = pd.Series([1, 2, 3, 4], index= ["a", "b", "c", "d"])
print(c)
print(c["b"])
print(c[2])


temp_index = ["a", "b", "c", "d"]
d = pd.Series([1, 2, 3, 4], index = temp_index)
e = pd.Series([5, 6, 7, 8], index = temp_index)

f = pd.DataFrame(
    {
        "점심" : d,
        "저녁" : e
    }
)

print(f)



bab_index = ["아침", "점심", "저녁"]
bab_data = {
    "종수" : [10, 20, 30],
    "지원" : [50, 60, 70]
}

bab = pd.DataFrame(bab_data, columns=["종수", "지원"], index= bab_index)
print(bab)