ret = 0
for i in range(0,5):
    inp = input().replace(' ','').lower()
    ret += inp.count("ass")
print(ret)